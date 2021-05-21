#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/console.h>
#include <xtd/native/console_color.h>
#include <xtd/native/console_special_key.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

#include <csignal>
#include <iostream>
#include <list>
#include <map>
#include <sstream>

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#if __APPLE__
#ifndef KIOCSOUND
const int32_t KIOCSOUND = 0x4B2F;
#endif
#else
#include <linux/kd.h>
#endif

using namespace xtd::native;

namespace {
  std::function<bool(int32_t)> user_cancel_callback;
  int32_t backColor = CONSOLE_COLOR_BLACK;
  int32_t foreColor = CONSOLE_COLOR_WHITE;
  bool cursor_visible = true;
  bool treat_control_c_as_input = false;
  std::string title;

  struct console_intercept_signals {
  private:
    console_intercept_signals() {
      for (auto signal : signal_keys_)
        ::signal(signal.first, console_intercept_signals::signal_handler);
    }
    
    ~console_intercept_signals() {
      for (auto signal : signal_keys_)
        ::signal(signal.first, SIG_DFL);
    }
    
    static void signal_handler(int32_t signal) {
      ::signal(signal, console_intercept_signals::signal_handler);
      //xtd::console_cancel_event_args console_cancel(false, signal_keys_[signal]);
      //xtd::console::__internal_cancel_key_press__(console_cancel);
      //if (console_cancel.cancel() == false) exit(EXIT_FAILURE);
      if (user_cancel_callback && user_cancel_callback(signal_keys_[signal]) == false) exit(EXIT_FAILURE);
    }

    static std::map<int32_t, int32_t> signal_keys_;
    static console_intercept_signals console_intercept_signals_;
  };

  std::map<int32_t, int32_t> console_intercept_signals::signal_keys_ {{SIGQUIT, CONSOLE_SPECIAL_KEY_CTRL_BS}, {SIGTSTP, CONSOLE_SPECIAL_KEY_CTRL_Z}, {SIGINT, CONSOLE_SPECIAL_KEY_CTRL_C}};
  console_intercept_signals console_intercept_signals::console_intercept_signals_;

  class terminal final {
  private:
    terminal() {
      termios termioAttributes;
      tcgetattr(0, &termioAttributes);
      backupedTermioAttributes = termioAttributes;
      termioAttributes.c_lflag &= ~ECHO;
      tcsetattr(0, TCSANOW, &termioAttributes);
    }
    
    ~terminal() {
      tcsetattr(0, TCSANOW, &backupedTermioAttributes);
      if (is_ansi_supported())
        std::cout << "\x1b]0;\x7" << std::flush;
    }
    
  public:
    int32_t getch() {
      if (peekCharacter != -1) {
        int8_t character = peekCharacter;
        peekCharacter = -1;
        return character;
      }
      
      termios termioAttributes;
      tcgetattr(0, &termioAttributes);
      termios backupedTermioAttributes = termioAttributes;
      termioAttributes.c_lflag &= ~ICANON;
      termioAttributes.c_cc[VTIME] = 0;
      termioAttributes.c_cc[VMIN] = 1;
      tcsetattr(0, TCSANOW, &termioAttributes);
      
      int8_t character = 0;
      while (read(0, &character, 1) != 1);
      
      tcsetattr(0, TCSANOW, &backupedTermioAttributes);
      
      return character;
    }
    
    bool key_available() {
      if (peekCharacter != -1)
        return true;
      
      termios termioAttributes;
      tcgetattr(0, &termioAttributes);
      termios backupedTermioAttributes = termioAttributes;
      termioAttributes.c_lflag &= ~ICANON;
      termioAttributes.c_cc[VTIME] = 0;
      termioAttributes.c_cc[VMIN] = 0;
      tcsetattr(0, TCSANOW, &termioAttributes);
      
      read(0, &peekCharacter, 1);
      
      tcsetattr(0, TCSANOW, &backupedTermioAttributes);
      
      return peekCharacter != -1;
    }
    
    static bool is_ansi_supported() {
      static std::string terminal = getenv("TERM") == nullptr ? "" : getenv("TERM");
      return isatty(fileno(stdout)) && (terminal == "xterm" || terminal == "xterm-color" || terminal == "xterm-256color" || terminal == "screen" || terminal == "screen-256color" || terminal == "linux" || terminal == "cygwin");
    }
    
    static terminal terminal_;
    
  private:
    int8_t peekCharacter {-1};
    termios backupedTermioAttributes;
  };
  
  terminal terminal::terminal_;

  class key_info {
  public:
    class input_list {
    public:
      input_list() {}
      input_list(const std::list<int32_t>& chars) : chars(chars) {}
      input_list(std::initializer_list<int32_t> il) : chars(il) {}
      input_list(const input_list& il) : chars(il.chars) {}
      
      input_list& operator =(const input_list& il) {
        chars = il.chars;
        return *this;
      }
      
      bool operator ==(const input_list& il) const {return chars == il.chars;}
      bool operator !=(const input_list& il) const {return chars != il.chars;}
      
      using const_iterator = std::list<int32_t>::const_iterator;
      using iterator = std::list<int32_t>::iterator;
      
      const_iterator cbegin() const {return chars.begin();}
      const_iterator cend() const {return chars.end();}
      const_iterator begin() const {return chars.begin();}
      iterator begin() {return chars.begin();}
      const_iterator end() const {return chars.end();}
      iterator end() {return chars.end();}
      
      void add(int32_t c) {chars.push_back(c);}
      void add_front(int32_t c) {chars.push_front(c);}
      void remove(int32_t c) {chars.remove(c);}
      int32_t count() const {return static_cast<int32_t>(chars.size());}
      int32_t pop() { int32_t c = chars.front();  chars.erase(chars.begin()); return c;}
      void clear() {chars.clear();}
      
      bool is_empty() const {return chars.empty();}
      
      std::string to_string() const {
        std::stringstream result;
        std::list<int32_t>::const_iterator iterator = chars.begin();
        while (iterator != chars.end()) {
          if (char(*iterator & 0xFF) == 27)
            result << "^[";
          else
            result << char(*iterator & 0xFF);
          iterator++;
        }
        return result.str();
      }
      
      static input_list parse(const std::string& value) {
        input_list result;
        std::string::const_iterator iterator = value.begin();
        while (iterator != value.end()) {
          if (*iterator == '^' &&  *(iterator + 1) == '[') {
            result.chars.push_back(27);
            iterator++;
          } else
            result.chars.push_back(*iterator);
          iterator++;
        }
        return result;
      }
      
    private:
      std::list<int32_t> chars;
    };
    
    key_info(const key_info& ki) : key_(ki.key_), key_char_(ki.key_char_), has_alt_modifier_(ki.has_alt_modifier_), has_control_modifier_(ki.has_control_modifier_), has_shift_modifier_(ki.has_shift_modifier_) {}
    
    key_info& operator =(const key_info& ki) {
      key_ = ki.key_;
      key_char_ = ki.key_char_;
      has_alt_modifier_ = ki.has_alt_modifier_;
      has_control_modifier_ = ki.has_control_modifier_;
      has_shift_modifier_ = ki.has_shift_modifier_;
      return *this;
    }
    
    static bool key_available() {return !inputs.is_empty() || terminal::terminal_.key_available();}
    
    static key_info read() {
      if (!inputs.is_empty())
        return to_key_info(inputs.pop());
      
      do
        inputs.add(terminal::terminal_.getch());
      while (terminal::terminal_.key_available());
      
      auto it = key_info::keys.find(inputs.to_string());
      if (it != key_info::keys.end()) {
        inputs.clear();
        return key_info(it->second.key, it->second.key_char, false, false, it->second.shift);
      }
      
      if (inputs.count() == 1)
        return to_key_info(inputs.pop());
      
      if (inputs.count() > 1 && *inputs.begin() != 27)
        return to_key_info(to_key(inputs));
      
      inputs.pop();
      return to_key_info(inputs.pop(), true);
    }
    
    int32_t key() const {return key_;}
    
    int32_t key_char() const {return key_char_;}
    
    bool has_alt_modifier() const {return has_alt_modifier_;}
    
    bool has_control_modifier() const {return has_control_modifier_;}
    
    bool has_shift_modifier() const {return has_shift_modifier_;}
    
    std::string to_string() const {
      std::stringstream result;
      result << "{key=" << std::hex << key_ << ", key_char=" << std::dec << static_cast<char>(key_char_) << ", has_alt_modifier=" << to_string(has_alt_modifier_) << ", has_control_modifier=" << to_string(has_control_modifier_) << ", has_shift_modifier=" << to_string(has_shift_modifier_) << "}";
      return result.str();
    }
    
  private:
    key_info() : key_(0), key_char_(0), has_alt_modifier_(false), has_control_modifier_(false), has_shift_modifier_(false) {}
    key_info(int32_t key, int32_t key_char) : key_(key), key_char_(key_char), has_alt_modifier_(false), has_control_modifier_(false), has_shift_modifier_(false) {}
    key_info(int32_t key, int32_t key_char, bool has_alt_modifier, bool has_control_modifier, bool has_shift_modifier) : key_(key), key_char_(key_char), has_alt_modifier_(has_alt_modifier), has_control_modifier_(has_control_modifier), has_shift_modifier_(has_shift_modifier) {}
    
    static std::string to_string(bool b) {return b ? "true" : "false";}
    
    static int32_t to_key(input_list& inputs) {
      int32_t key = 0;
      int32_t index = 1;
      for (auto c : inputs)
        key |= (c & 0xFF) << (8 * index--);
      inputs.clear();
      return key;
    }
    
    static key_info to_key_info(int32_t key) {
      return to_key_info(key, false);
    }
    
    static key_info to_key_info(int32_t key, bool alt) {
      // Ctrl + Space
      if (key == 0)
        return key_info(' ', ' ', false, true, false);
      
      // Ctrl + [a; z]
      if ((key >= 1 && key <= 7) || (key >= 10 && key <= 11) || (key >= 14 && key <= 18) || (key >= 20 && key <= 26))
        return key_info(key + 'A' - 1, key, false, true, false);
      
      switch (key) {
        case 50086 : return key_info(0, U'æ', alt, false, false);
        case 50054 : return key_info(0, U'Æ', alt, false, false);
        case 50079 : return key_info(0, U'ß', alt, false, false);
        case -1426005368 : return key_info(0, U'∫', alt, false, false);
        case 49833 : return key_info(0, U'©', alt, false, false);
        case 49826 : return key_info(0, U'¢', alt, false, false);
        case -2113871224 : return key_info(0, U'∂', alt, false, false);
        case -2046762360 : return key_info(0, U'∆', alt, false, false);
        case 50090 : return key_info(0, U'ê', alt, false, false);
        case 50058 : return key_info(0, U'Ê', alt, false, false);
        case 50834 : return key_info(0, U'ƒ', alt, false, false);
        case 49847 : return key_info(0, U'·', alt, false, false);
        case -2130645076 : return key_info(0, U'ﬁ', alt, false, false);
        case -2113867860 : return key_info(0, U'ﬂ', alt, false, false);
        case 50060 : return key_info(0, U'Ì', alt, false, false);
        case 50062 : return key_info(0, U'Î', alt, false, false);
        case 50094 : return key_info(0, U'î', alt, false, false);
        case 50095 : return key_info(0, U'ï', alt, false, false);
        case 50063 : return key_info(0, U'Ï', alt, false, false);
        case 50061 : return key_info(0, U'Í', alt, false, false);
        case 50056 : return key_info(0, U'È', alt, false, false);
        case 50059 : return key_info(0, U'Ë', alt, false, false);
        case 49836 : return key_info(0, U'¬', alt, false, false);
        case 49845 : return key_info(0, U'µ', alt, false, false);
        case 50067 : return key_info(0, U'Ó', alt, false, false);
        case 50353 : return key_info(0, U'ı', alt, false, false);
        case 50579 : return key_info(0, U'œ', alt, false, false);
        case 50578 : return key_info(0, U'Œ', alt, false, false);
        case 53120 : return key_info(0, U'π', alt, false, false);
        case -1895767416 : return key_info(0, U'∏', alt, false, false);
        case -1593777536 : return key_info(0, U'‡', alt, false, false);
        case 52905 : return key_info(0, U'Ω', alt, false, false);
        case 49838 : return key_info(0, U'®', alt, false, false);
        case -1577000316 : return key_info(0, U'‚', alt, false, false);
        case 50066 : return key_info(0, U'Ò', alt, false, false);
        case -1862212984 : return key_info(0, U'∑', alt, false, false);
        case -1610554752 : return key_info(0, U'†', alt, false, false);
        case -1711218048 : return key_info(0, U'™', alt, false, false);
        case 49850 : return key_info(0, U'º', alt, false, false);
        case 49834 : return key_info(0, U'ª', alt, false, false);
        case -1979653481 : return key_info(0, U'◊', alt, false, false);
        case -1711218040 : return key_info(0, U'√', alt, false, false);
        case -1191124352 : return key_info(0, U'‹', alt, false, false);
        case -1174347136 : return key_info(0, U'›', alt, false, false);
        case -2013207927 : return key_info(0, U'≈', alt, false, false);
        case -2080316799 : return key_info(0, U'⁄', alt, false, false);
        case 50074 : return key_info(0, U'Ú', alt, false, false);
        case 50616 : return key_info(0, U'Ÿ', alt, false, false);
        case 50050 : return key_info(0, U'Â', alt, false, false);
        case 50053 : return key_info(0, U'Å', alt, false, false);
        case 50089 : return key_info(0, U'é', alt, false, false);
        case 49831 : return key_info(0, U'§', alt, false, false);
        case 50088 : return key_info(0, U'è', alt, false, false);
        case 50087 : return key_info(0, U'ç', alt, false, false);
        case 50080 : return key_info(0, U'à', alt, false, false);
        case 49840 : return key_info(0, U'°', alt, false, false);
        case 50105 : return key_info(0, U'ù', alt, false, false);
        case 49827 : return key_info(0, U'£', alt, false, false);
        case -1577000320 : return key_info(0, U'•', alt, false, false);
        case -1090457693 : return key_info(0, U'', alt, false, false);
        case 49844 : return key_info(0, U'´', alt, false, false);
        case 50091 : return key_info(0, U'ë', alt, false, false);
        case -1644109184 : return key_info(0, U'„', alt, false, false);
        case -1677663616 : return key_info(0, U'“', alt, false, false);
        case -1660886400 : return key_info(0, U'”', alt, false, false);
        case -1744772480 : return key_info(0, U'‘', alt, false, false);
        case -1727995264 : return key_info(0, U'’', alt, false, false);
        case 49846 : return key_info(0, U'¶', alt, false, false);
        case 50085 : return key_info(0, U'å', alt, false, false);
        case 49835 : return key_info(0, U'«', alt, false, false);
        case 49851 : return key_info(0, U'»', alt, false, false);
        case 49825 : return key_info(0, U'¡', alt, false, false);
        case 50075 : return key_info(0, U'Û', alt, false, false);
        case 50055 : return key_info(0, U'Ç', alt, false, false);
        case 50049 : return key_info(0, U'Á', alt, false, false);
        case 50104 : return key_info(0, U'ø', alt, false, false);
        case 50072 : return key_info(0, U'Ø', alt, false, false);
        case -1811881344 : return key_info(0, U'—', alt, false, false);
        case -1828658560 : return key_info(0, U'–', alt, false, false);
        case -1543445879 : return key_info(0, U'≤', alt, false, false);
        case -1526668663 : return key_info(0, U'≥', alt, false, false);
        case 50100 : return key_info(0, U'ô', alt, false, false);
        case 50068 : return key_info(0, U'Ô', alt, false, false);
        case -1409228158 : return key_info(0, U'€', alt, false, false);
        case 50073 : return key_info(0, U'Ù', alt, false, false);
        case -1342119296 : return key_info(0, U'‰', alt, false, false);
        case -1644109176 : return key_info(0, U'∞', alt, false, false);
        case 49855 : return key_info(0, U'¿', alt, false, false);
        case -1509891456 : return key_info(0, U'…', alt, false, false);
        case 50103 : return key_info(0, U'÷', alt, false, false);
        case -1610554743 : return key_info(0, U'≠', alt, false, false);
        case 49841 : return key_info(0, U'±', alt, false, false);
      }
      
      if (key_info::keys.find(std::string(1, toupper((char)key))) != key_info::keys.end())
        return key_info(toupper(key), key, alt, false, key >= 'A' && key <= 'Z');
      
      return key_info(0, key, alt, false, key >= 'A' && key <= 'Z');
    }
    
    int32_t key_;
    int32_t key_char_;
    bool has_alt_modifier_;
    bool has_control_modifier_;
    bool has_shift_modifier_;
    struct key_key_char {
      int32_t key;
      int32_t key_char;
      bool alt;
      bool control;
      bool shift;
    };
    static std::map<std::string, key_key_char> keys;
    static input_list inputs;
  };
  
  key_info::input_list key_info::inputs;
  std::map<std::string, key_info::key_key_char> key_info::keys = {
    {"\x7F", {8, 0, false, false, false}}, // Backspace
    {"\x9", {9, 9, false, false, false}}, // Tab
    {"^[[Z", {9, 9, false, false, true}}, // Shift Tab
    {"\xC", {12, 12, false, false, false}}, // clear
    {"\xA", {13, 13, false, false, false}}, // Enter
    {"\x13", {19, 0, false, false, false}}, // Pause
    {"\x14", {20, 0, false, false, false}}, // Capslock
    {"^[", {27, 27, false, false, false}}, // Escape
    {" ", {32, 32, false, false, false}}, // Space
    {"^[[5~", {33, 0, false, false, false}}, // PgUp
    {"^[[6~", {34, 0, false, false, false}}, // PgDown
    {"^[[F", {35, 0, false, false, false}}, // End
    {"^[[H", {36, 0, false, false, false}}, // Home
    {"^[[D", {37, 0, false, false, false}}, // LeftArrow
    {"^[[A", {38, 0, false, false, false}}, // UpArrow
    {"^[[C", {39, 0, false, false, false}}, // RightArrow
    {"^[[B", {40, 0, false, false, false}}, // DownArrow
    //{"", {41, 0, false, false, false}}, // Select
    //{"", {42, 0, false, false, false}}, // Print
    //{"", {43, 0, false, false, false}}, // Execute
    //{"", {44, 0, false, false, false}}, // PrintScreen
    {"^[[2~", {45, 0, false, false, false}}, // Insert
    {"^[[3~", {46, 0, false, false, false}}, // Delete
    //{"", {47, 0, false, false, false}}, // Help
    {"0", {48, 48, false, false, false}}, // D0
    {"1", {49, 49, false, false, false}}, // D1
    {"2", {50, 50, false, false, false}}, // D2
    {"3", {51, 51, false, false, false}}, // D3
    {"4", {52, 52, false, false, false}}, // D4
    {"5", {53, 53, false, false, false}}, // D5
    {"6", {54, 54, false, false, false}}, // D6
    {"7", {55, 55, false, false, false}}, // D7
    {"8", {56, 56, false, false, false}}, // D8
    {"9", {57, 57, false, false, false}}, // D9
    {"A", {65, 65, false, false, true}}, // A
    {"B", {66, 66, false, false, true}}, // B
    {"C", {67, 67, false, false, true}}, // C
    {"D", {68, 68, false, false, true}}, // D
    {"E", {69, 69, false, false, true}}, // E
    {"F", {70, 70, false, false, true}}, // F
    {"G", {71, 71, false, false, true}}, // G
    {"H", {72, 72, false, false, true}}, // H
    {"I", {73, 73, false, false, true}}, // I
    {"J", {74, 74, false, false, true}}, // J
    {"K", {75, 75, false, false, true}}, // K
    {"L", {76, 76, false, false, true}}, // L
    {"M", {77, 77, false, false, true}}, // M
    {"N", {78, 78, false, false, true}}, // N
    {"O", {79, 79, false, false, true}}, // O
    {"P", {80, 80, false, false, true}}, // P
    {"Q", {81, 81, false, false, true}}, // Q
    {"R", {82, 82, false, false, true}}, // R
    {"S", {83, 83, false, false, true}}, // S
    {"T", {84, 84, false, false, true}}, // T
    {"U", {85, 85, false, false, true}}, // U
    {"V", {86, 86, false, false, true}}, // V
    {"W", {87, 87, false, false, true}}, // W
    {"X", {88, 88, false, false, true}}, // X
    {"Y", {89, 89, false, false, true}}, // Y
    {"Z", {90, 90, false, false, true}}, // Z
    //{"", {91, 0, false, false, false}}, // LeftWindows
    //{"", {92, 0, false, false, false}}, // RighttWindows
    //{"", {93, 0, false, false, false}}, // Applications
    //{"", {95, 0, false, false, false}}, // Sleep
    //{"", {96, 0, false, false, false}}, // NumPad0
    //{"", {97, 0, false, false, false}}, // NumPad1
    //{"", {98, 0, false, false, false}}, // NumPad2
    //{"", {99, 0, false, false, false}}, // NumPad3
    //{"", {100, 0, false, false, false}}, // NumPad4
    //{"", {101, 0, false, false, false}}, // NumPad5
    //{"", {102, 0, false, false, false}}, // NumPad6
    //{"", {103, 0, false, false, false}}, // NumPad7
    //{"", {104, 0, false, false, false}}, // NumPad8
    //{"", {105, 0, false, false, false}}, // NumPad9
    {"*", {106, 42, false, false, false}}, // Multiply
    {"+", {107, 43, false, false, false}}, // add
    //{",", {108, 44, false, false, false}}, // Separator
    {"-", {109, 45, false, false, false}}, // Subtract
    //{".", {110, 46, false, false, false}}, // Decimal
    {"/", {111, 47, false, false, false}}, // Divide
    {"^[OP", {112, 0, false, false, false}}, // F1
    {"^[OQ", {113, 0, false, false, false}}, // F2
    {"^[OR", {114, 0, false, false, false}}, // F3
    {"^[OS", {115, 0, false, false, false}}, // F4
    {"^[[15~", {116, 0, false, false, false}}, // F5
    {"^[[17~", {117, 0, false, false, false}}, // F6
    {"^[[18~", {118, 0, false, false, false}}, // F7
    {"^[[19~", {119, 0, false, false, false}}, // F8
    {"^[[20~", {120, 0, false, false, false}}, // F9
    {"^[[21~", {121, 0, false, false, false}}, // F10
    {"^[[23~", {122, 0, false, false, false}}, // F11
    {"^[[24~", {123, 0, false, false, false}}, // F12
    //{"", {124, 0, false, false, false}}, // F13
    //{"", {125, 0, false, false, false}}, // F14
    //{"", {126, 0, false, false, false}}, // F15
    //{"", {127, 0, false, false, false}}, // F16
    //{"", {128, 0, false, false, false}}, // F17
    //{"", {129, 0, false, false, false}}, // F18
    //{"", {130, 0, false, false, false}}, // F19
    //{"", {131, 0, false, false, false}}, // F20
    //{"", {132, 0, false, false, false}}, // F21
    //{"", {133, 0, false, false, false}}, // F22
    //{"", {133, 0, false, false, false}}, // F23
    //{"", {135, 0, false, false, false}}, // F24
    //{"", {166, 0, false, false, false}}, // BrowseBack
    //{"", {167, 0, false, false, false}}, // BrowseForward
    //{"", {168, 0, false, false, false}}, // BrowseRefresh
    //{"", {169, 0, false, false, false}}, // BrowseStop
    //{"", {170, 0, false, false, false}}, // BrowseSearch
    //{"", {171, 0, false, false, false}}, // BrowseFavorite
    //{"", {172, 0, false, false, false}}, // BrowseHome
    //{"", {173, 0, false, false, false}}, // VolumeMute
    //{"", {174, 0, false, false, false}}, // VolumeDown
    //{"", {175, 0, false, false, false}}, // VolumeUp
    //{"", {176, 0, false, false, false}}, // MediaNext
    //{"", {177, 0, false, false, false}}, // MediaPrevious
    //{"", {178, 0, false, false, false}}, // MediaStop
    //{"", {179, 0, false, false, false}}, // MediaPlay
    {"a", {65, U'a', false, false, false}}, // a
    {"b", {66, U'b', false, false, false}}, // b
    {"c", {67, U'c', false, false, false}}, // c
    {"d", {68, U'd', false, false, false}}, // d
    {"e", {69, U'e', false, false, false}}, // e
    {"f", {70, U'f', false, false, false}}, // f
    {"g", {71, U'g', false, false, false}}, // g
    {"h", {72, U'h', false, false, false}}, // h
    {"i", {73, U'i', false, false, false}}, // i
    {"j", {74, U'j', false, false, false}}, // j
    {"k", {75, U'k', false, false, false}}, // k
    {"l", {76, U'l', false, false, false}}, // l
    {"m", {77, U'm', false, false, false}}, // m
    {"n", {78, U'n', false, false, false}}, // n
    {"o", {79, U'o', false, false, false}}, // o
    {"p", {80, U'p', false, false, false}}, // p
    {"q", {81, U'q', false, false, false}}, // q
    {"r", {82, U'r', false, false, false}}, // r
    {"S", {83, U's', false, false, false}}, // s
    {"t", {84, U't', false, false, false}}, // T
    {"u", {85, U'u', false, false, false}}, // u
    {"v", {86, U'v', false, false, false}}, // v
    {"w", {87, U'w', false, false, false}}, // w
    {"x", {88, U'x', false, false, false}}, // x
    {"y", {89, U'y', false, false, false}}, // y
    {"z", {90, U'z', false, false, false}}, // z
  };
}

int32_t console::background_color() {
  return backColor;
}

void console::background_color(int32_t color) {
  static std::map<int32_t, const char*> colors {{CONSOLE_COLOR_BLACK, "\033[40m"}, {CONSOLE_COLOR_DARK_BLUE, "\033[44m"}, {CONSOLE_COLOR_DARK_GREEN, "\033[42m"}, {CONSOLE_COLOR_DARK_CYAN, "\033[46m"}, {CONSOLE_COLOR_DARK_RED, "\033[41m"}, {CONSOLE_COLOR_DARK_MAGENTA, "\033[45m"}, {CONSOLE_COLOR_DARK_YELLOW, "\033[43m"}, {CONSOLE_COLOR_GRAY, "\033[47m"}, {CONSOLE_COLOR_DARK_GRAY, "\033[100m"}, {CONSOLE_COLOR_BLUE, "\033[104m"}, {CONSOLE_COLOR_GREEN, "\033[102m"}, {CONSOLE_COLOR_CYAN, "\033[106m"}, {CONSOLE_COLOR_RED, "\033[101m"}, {CONSOLE_COLOR_MAGENTA, "\033[105m"}, {CONSOLE_COLOR_YELLOW, "\033[103m"}, {CONSOLE_COLOR_WHITE, "\033[107m"}};
  auto it = colors.find(color);
  if (!terminal::is_ansi_supported() && it != colors.end()) return;
  std::cout << it->second << std::flush;
  backColor = color;
}

void console::beep(uint32_t frequency, uint32_t duration) {
  if (frequency < 37 || frequency > 32767) return;
  
  int32_t fd = open("/dev/console", O_WRONLY);
  if (fd == -1)
    std::cout << "\a" << std::flush;
  else {
    if (ioctl(fd, KIOCSOUND, (int32_t)(1193180 / frequency)) < 0)
      std::cout << "\a" << std::flush;
    else {
      usleep(1000 * duration);
      ioctl(fd, KIOCSOUND, 0);
    }
    close(fd);
  }
}

int32_t console::buffer_height() {
  /// @todo console buffer Height on linux and macOS
  return console::window_height();
}

void console::buffer_height(int32_t height) {
  /// @todo set console buffer height on linux and macOS
}

int32_t console::buffer_width() {
  /// @todo console buffer Width on linux and macOS
  return console::window_width();
}

void console::buffer_width(int32_t width) {
  /// @todo set console buffer width on linux and macOS
}

bool console::caps_lock() {
  /// @todo caps lock status on linux and macOS
  return false;
}

void console::clear() {
  if (!terminal::is_ansi_supported()) return;
  std::cout << "\x1b[H\x1b[2J" << std::flush;
}

int32_t console::cursor_left() {
  if (!terminal::is_ansi_supported()) return 0;
  std::cout << "\x1b[6n" << std::flush;
  terminal::terminal_.getch();
  terminal::terminal_.getch();
  for (char c = terminal::terminal_.getch(); c != ';'; c = terminal::terminal_.getch());
  std::string left;
  for (char c = terminal::terminal_.getch(); c != 'R'; c = terminal::terminal_.getch())
    left.push_back(c);
  return atoi(left.c_str()) - 1;
}

int32_t console::cursor_size() {
  return 100;
}

void console::cursor_size(int32_t size) {
  if (terminal::is_ansi_supported()) {
    if (size < 50)
      std::cout << "\x1b[4 q" << std::flush;
    else
      std::cout << "\x1b[2 q" << std::flush;
  }
}

int32_t console::cursor_top() {
  if (!terminal::is_ansi_supported()) return 0;
  std::cout << "\x1b[6n" << std::flush;
  terminal::terminal_.getch();
  terminal::terminal_.getch();
  std::string top;
  for (char c = terminal::terminal_.getch(); c != ';'; c = terminal::terminal_.getch())
    top.push_back(c);
  for (char c = terminal::terminal_.getch(); c != 'R'; c = terminal::terminal_.getch());
  return atoi(top.c_str()) - 1;
}

bool console::cursor_visible() {
  return ::cursor_visible;
}

void console::cursor_visible(bool visible) {
  if (terminal::is_ansi_supported()) {
    ::cursor_visible = visible;
    std::cout << (::cursor_visible ? "\x1b[?25h" : "\x1b[?25l") << std::flush;
  }
}

int32_t console::foreground_color() {
  return foreColor;
}

void console::foreground_color(int32_t color) {
  static std::map<int32_t, const char*> colors {{CONSOLE_COLOR_BLACK, "\033[30m"}, {CONSOLE_COLOR_DARK_BLUE, "\033[34m"}, {CONSOLE_COLOR_DARK_GREEN, "\033[32m"}, {CONSOLE_COLOR_DARK_CYAN, "\033[36m"}, {CONSOLE_COLOR_DARK_RED, "\033[31m"}, {CONSOLE_COLOR_DARK_MAGENTA, "\033[35m"}, {CONSOLE_COLOR_DARK_YELLOW, "\033[33m"}, {CONSOLE_COLOR_GRAY, "\033[37m"}, {CONSOLE_COLOR_DARK_GRAY, "\033[90m"}, {CONSOLE_COLOR_BLUE, "\033[94m"}, {CONSOLE_COLOR_GREEN, "\033[92m"}, {CONSOLE_COLOR_CYAN, "\033[96m"}, {CONSOLE_COLOR_RED, "\033[91m"}, {CONSOLE_COLOR_MAGENTA, "\033[95m"}, {CONSOLE_COLOR_YELLOW, "\033[93m"}, {CONSOLE_COLOR_WHITE, "\033[97m"}};
  auto it = colors.find(color);
  if (!terminal::is_ansi_supported() && it != colors.end()) return;
  std::cout << it->second << std::flush;
  foreColor = color;
  return;
}

int32_t console::input_code_page() {
  /// @todo console input code page status on linux and macOS
  return 65001;
}

void console::input_code_page(int32_t codePage) {
  /// @todo set console input code page on linux and macOS
}

bool console::key_available() {
  return key_info::key_available();
}

int32_t console::largest_window_height() {
  return 1000;
}

int32_t console::largest_window_width() {
  return 1000;
}

bool console::number_lock() {
  /// @todo number lock status on linux and macOS
  return false;
}

int32_t console::output_code_page() {
  /// @todo console output code page status on linux and macOS
  return 65001;
}

void console::output_code_page(int32_t codePage) {
  /// @todo set console output code page on linux and macOS
}

void console::read_key(int32_t& key_char, int32_t& key_code, bool& alt, bool& shift, bool& ctrl) {
  key_info key_info = key_info::read();
  key_char = static_cast<int32_t>(key_info.key_char());
  key_code = static_cast<int32_t>(key_info.key());
  alt = key_info.has_alt_modifier();
  ctrl = key_info.has_control_modifier();
  shift = key_info.has_shift_modifier();
}

void console::register_user_cancel_callback(std::function<bool(int32_t)> user_cancel_callback) {
  ::user_cancel_callback = user_cancel_callback;
}

void console::reset_color() {
  if (!terminal::is_ansi_supported()) return;
  std::cout << "\033[49m\033[39m" << std::flush;
}

void console::set_cursor_position(int32_t left, int32_t top) {
  if (!terminal::is_ansi_supported()) return;
  std::cout << "\x1b[" << top + 1 << ";" << left + 1 << "f" << std::flush;
}

std::string console::title() {
  /// @todo get console get title on linux and macOS
  /*
   * Didn't work correctly!
  std::cout << "\x1b[21t" << std::endl;
  
  if (!terminal.KeyAvailable())
    return ::title;
  
  std::string title;
  for (char c = terminal.Getch(); terminal::terminal_.key_available(); c = terminal::terminal_.getch())
    title.push_back(c);
  return title; */
  return ::title;
}

void console::title(const std::string& title) {
  if (!terminal::is_ansi_supported()) return;
  ::title = title;
  std::cout << "\x1b]0;" << title.c_str() << "\x7" << std::flush;
}

bool console::treat_control_c_as_input() {
  return ::treat_control_c_as_input;
}

void console::treat_control_c_as_input(bool treat_control_c_as_input) {
  ::treat_control_c_as_input = treat_control_c_as_input;
}

void console::unregister_user_cancel_callback() {
  ::user_cancel_callback = nullptr;
}

int32_t console::window_left() {
  /// @todo get console window left on linux and macOS
  return 0;
}

int32_t console::window_height() {
  if (!terminal::is_ansi_supported()) return 24;
  int32_t top = console::cursor_top();
  console::set_cursor_position(console::cursor_left(), 999);
  int32_t height = console::cursor_top() + 1;
  console::set_cursor_position(console::cursor_left(), top);
  return height;
}

int32_t console::window_top() {
  /// @todo get console window top on linux and macOS
  return 0;
}

int32_t console::window_width() {
  if (!terminal::is_ansi_supported()) return 80;
  int32_t left = console::cursor_left();
  console::set_cursor_position(999, console::cursor_top());
  int32_t width = console::cursor_left() + 1;
  console::set_cursor_position(left, console::cursor_top());
  return width;
}
