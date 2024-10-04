#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/console>
#include <xtd/native/console_color>
#include <xtd/native/console_special_key>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <AudioUnit/AudioUnit.h>
#include <csignal>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <vector>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

using namespace xtd::native;

namespace {
  auto treat_control_c_as_input = false;
  auto signal_couter_ = std::vector<int32_t> {};
  auto user_cancel_callback = std::function<bool(int32_t)> {};
  
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
      if (treat_control_c_as_input) signal_couter_.push_back(signal_keys_[signal]);
      else if (user_cancel_callback && user_cancel_callback(signal_keys_[signal]) == false) exit(EXIT_FAILURE);
    }
    
    // The SIGINT signal catcher conflicts with with xtd::environment::cancel_interrupt signal...
    inline static std::map<int32_t, int32_t> signal_keys_ {{SIGQUIT, CONSOLE_SPECIAL_KEY_CTRL_BS}, {SIGTSTP, CONSOLE_SPECIAL_KEY_CTRL_Z}/*, {SIGINT, CONSOLE_SPECIAL_KEY_CTRL_C}*/};
    static console_intercept_signals console_intercept_signals_;
  };
  
  console_intercept_signals console_intercept_signals::console_intercept_signals_;
  
  class terminal final {
  public:
    bool echo(bool on) {
      auto status = termios {};
      tcgetattr(0, &status);
      if (on) status.c_lflag |= ECHO;
      else status.c_lflag &= ~ECHO;
      return tcsetattr(0, TCSANOW, &status) == 0;
    }
    
    bool icanon(bool on) {
      auto status = termios {};
      tcgetattr(0, &status);
      if (on) status.c_lflag |= ICANON;
      else status.c_lflag &= ~ICANON;
      status.c_cc[VMIN] = on ? 1 : 0;
      status.c_cc[VTIME] = 0; // Can be discarded.
      return tcsetattr(0, TCSANOW, &status) == 0;
    }

    int32_t getch() {
      if (peek_character != -1) {
        auto character = peek_character;
        peek_character = -1;
        return character;
      }
      
      push_status();
      echo(false);
      icanon(false);

      auto character = '\0';
      while (read(0, &character, 1) != 1);

      pop_status();
      return character;
    }
    
    bool key_available() {
      if (peek_character != -1)
        return true;
        
      push_status();
      echo(false);
      icanon(false);
      
      if (read(0, &peek_character, 1) == -1) {
        pop_status();
        return false;
      }
      
      pop_status();
      return peek_character != -1;
    }
    
    static bool is_ansi_supported() {
      static auto terminal = std::string {getenv("TERM") == nullptr ? "" : getenv("TERM")};
      return isatty(fileno(stdout)) && (terminal == "xterm" || terminal == "xterm-color" || terminal == "xterm-256color" || terminal == "screen" || terminal == "screen-256color" || terminal == "linux" || terminal == "cygwin");
    }
    
    static terminal terminal_;
    
  private:
    terminal() {
      push_status();
      echo(false);
      icanon(true);
    }
    ~terminal() {
      pop_status();
      reset_colors_and_attributes();
    }
    
    void reset_colors_and_attributes() {
      if (is_ansi_supported()) std::cout << "\x1b]0;\x7" << std::flush;
    }

    termios push_status() {
      auto status = termios {};
      tcgetattr(0, &status);
      statuses.push_back(status);
      return status;
    }
    
    termios pop_status() {
      if (statuses.size() == 0) {
        auto status = termios {};
        tcgetattr(0, &status);
        return status;
      }
      auto status = statuses.back();
      statuses.pop_back();
      tcsetattr(0, TCSANOW, &status);
      return status;
    }
    

    int8_t peek_character {-1};
    std::vector<termios> statuses;
  };
  
  terminal terminal::terminal_;
  
  class key_info {
  public:
    class input_list {
    public:
      input_list() {}
      explicit input_list(const std::list<int32_t>& chars) : chars(chars) {}
      explicit input_list(std::initializer_list<int32_t> il) : chars(il) {}
      input_list(const input_list& il) : chars(il.chars) {}
      
      input_list& operator =(const input_list& il) {
        chars = il.chars;
        return *this;
      }
      
      bool operator ==(const input_list& il) const noexcept {return chars == il.chars;}
      bool operator !=(const input_list& il) const noexcept {return chars != il.chars;}
      
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
        auto result = std::stringstream {};
        auto iterator = chars.begin();
        while (iterator != chars.end()) {
          if (static_cast<char>(*iterator & 0xFF) == 27)
            result << "^[";
          else
            result << static_cast<char>(*iterator & 0xFF);
          ++iterator;
        }
        return result.str();
      }
      
      static input_list parse(const std::string& value) {
        auto result = input_list {};
        auto iterator = value.begin();
        while (iterator != value.end()) {
          if (*iterator == '^' && (iterator + 1) != value.end() && *(iterator + 1) == '[') {
            result.chars.push_back(27);
            ++iterator;
          } else
            result.chars.push_back(*iterator);
          ++iterator;
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
    
    static bool key_available() {return !signal_couter_.empty() || !inputs.is_empty() || terminal::terminal_.key_available();}
    
    static key_info read() {
      if (!signal_couter_.empty()) {
        auto k = signal_couter_[0];
        signal_couter_.erase(signal_couter_.begin());
        switch (k) {
          case CONSOLE_SPECIAL_KEY_CTRL_C: return key_info('C', '\x03', false, true, false);
          case CONSOLE_SPECIAL_KEY_CTRL_BS: return key_info('\\', '\x1C', false, true, false);
          case CONSOLE_SPECIAL_KEY_CTRL_Z: return key_info('Z', '\x1A', false, true, false);
        }
      }
      if (!inputs.is_empty()) return to_key_info(inputs.pop());
      
      do
        inputs.add(terminal::terminal_.getch());
      while (terminal::terminal_.key_available());
      
      auto it = key_info::keys.find(inputs.to_string());
      if (it != key_info::keys.end()) {
        inputs.clear();
        return key_info(it->second.key, it->second.key_char, false, false, it->second.shift);
      }
      
      if (inputs.count() == 1) return to_key_info(inputs.pop());
      if (inputs.count() > 1 && *inputs.begin() != 27) return to_key_info(to_key(inputs));
      
      inputs.pop();
      return to_key_info(inputs.pop(), true);
    }
    
    char32_t key() const {return key_;}
    char32_t key_char() const {return key_char_;}
    bool has_alt_modifier() const {return has_alt_modifier_;}
    bool has_control_modifier() const {return has_control_modifier_;}
    bool has_shift_modifier() const {return has_shift_modifier_;}
    
    std::string to_string() const {
      auto result = std::stringstream {};
      result << "{key=" << std::hex << static_cast<int32_t>(key_) << ", key_char=" << std::dec << static_cast<char>(key_char_) << ", has_alt_modifier=" << to_string(has_alt_modifier_) << ", has_control_modifier=" << to_string(has_control_modifier_) << ", has_shift_modifier=" << to_string(has_shift_modifier_) << "}";
      return result.str();
    }
    
  private:
    key_info() : key_(U'0'), key_char_(U'0'), has_alt_modifier_(false), has_control_modifier_(false), has_shift_modifier_(false) {}
    key_info(int32_t key, int32_t key_char) : key_(key), key_char_(key_char), has_alt_modifier_(false), has_control_modifier_(false), has_shift_modifier_(false) {}
    key_info(int32_t key, int32_t key_char, bool has_alt_modifier, bool has_control_modifier, bool has_shift_modifier) : key_(key), key_char_(key_char), has_alt_modifier_(has_alt_modifier), has_control_modifier_(has_control_modifier), has_shift_modifier_(has_shift_modifier) {}
    
    static std::string to_string(bool b) {return b ? "true" : "false";}
    
    static int32_t to_key(input_list& inputs) {
      auto result = 0;
      auto index = 1;
      for (auto c : inputs)
        result |= (c & 0xFF) << (8 * index--);
      inputs.clear();
      return result;
    }
    
    static key_info to_key_info(int32_t key) {
      return to_key_info(key, false);
    }
    
    static key_info to_key_info(int32_t key, bool alt) {
      // Ctrl + Space
      if (key == 0) return key_info {' ', ' ', false, true, false};
      
      // Ctrl + [a; z]
      if ((key >= 1 && key <= 7) || (key >= 10 && key <= 11) || (key >= 14 && key <= 18) || (key >= 20 && key <= 26))
        return key_info {key + 'A' - 1, key, false, true, false};
      
      switch (key) {
        case 50086 : return key_info {0, U'æ', alt, false, false};
        case 50054 : return key_info {0, U'Æ', alt, false, false};
      case 50079 : return key_info {0, U'ß', alt, false, false};
        case -1426005368 : return key_info {0, U'∫', alt, false, false};
        case 49833 : return key_info {0, U'©', alt, false, false};
        case 49826 : return key_info {0, U'¢', alt, false, false};
        case -2113871224 : return key_info {0, U'∂', alt, false, false};
        case -2046762360 : return key_info {0, U'∆', alt, false, false};
        case 50090 : return key_info {0, U'ê', alt, false, false};
        case 50058 : return key_info {0, U'Ê', alt, false, false};
        case 50834 : return key_info {0, U'ƒ', alt, false, false};
        case 49847 : return key_info {0, U'·', alt, false, false};
        case -2130645076 : return key_info {0, U'ﬁ', alt, false, false};
        case -2113867860 : return key_info {0, U'ﬂ', alt, false, false};
        case 50060 : return key_info {0, U'Ì', alt, false, false};
        case 50062 : return key_info {0, U'Î', alt, false, false};
        case 50094 : return key_info {0, U'î', alt, false, false};
        case 50095 : return key_info {0, U'ï', alt, false, false};
        case 50063 : return key_info {0, U'Ï', alt, false, false};
        case 50061 : return key_info {0, U'Í', alt, false, false};
        case 50056 : return key_info {0, U'È', alt, false, false};
        case 50059 : return key_info {0, U'Ë', alt, false, false};
        case 49836 : return key_info {0, U'¬', alt, false, false};
        case 49845 : return key_info {0, U'µ', alt, false, false};
        case 50067 : return key_info {0, U'Ó', alt, false, false};
        case 50353 : return key_info {0, U'ı', alt, false, false};
        case 50579 : return key_info {0, U'œ', alt, false, false};
        case 50578 : return key_info {0, U'Œ', alt, false, false};
        case 53120 : return key_info {0, U'π', alt, false, false};
        case -1895767416 : return key_info {0, U'∏', alt, false, false};
        case -1593777536 : return key_info {0, U'‡', alt, false, false};
        case 52905 : return key_info {0, U'Ω', alt, false, false};
        case 49838 : return key_info {0, U'®', alt, false, false};
        case -1577000316 : return key_info {0, U'‚', alt, false, false};
        case 50066 : return key_info {0, U'Ò', alt, false, false};
        case -1862212984 : return key_info {0, U'∑', alt, false, false};
        case -1610554752 : return key_info {0, U'†', alt, false, false};
        case -1711218048 : return key_info {0, U'™', alt, false, false};
        case 49850 : return key_info {0, U'º', alt, false, false};
        case 49834 : return key_info {0, U'ª', alt, false, false};
        case -1979653481 : return key_info {0, U'◊', alt, false, false};
        case -1711218040 : return key_info {0, U'√', alt, false, false};
        case -1191124352 : return key_info {0, U'‹', alt, false, false};
        case -1174347136 : return key_info {0, U'›', alt, false, false};
        case -2013207927 : return key_info {0, U'≈', alt, false, false};
        case -2080316799 : return key_info {0, U'⁄', alt, false, false};
        case 50074 : return key_info {0, U'Ú', alt, false, false};
        case 50616 : return key_info {0, U'Ÿ', alt, false, false};
        case 50050 : return key_info {0, U'Â', alt, false, false};
        case 50053 : return key_info {0, U'Å', alt, false, false};
        case 50089 : return key_info {0, U'é', alt, false, false};
        case 49831 : return key_info {0, U'§', alt, false, false};
        case 50088 : return key_info {0, U'è', alt, false, false};
        case 50087 : return key_info {0, U'ç', alt, false, false};
        case 50080 : return key_info {0, U'à', alt, false, false};
        case 49840 : return key_info {0, U'°', alt, false, false};
        case 50105 : return key_info {0, U'ù', alt, false, false};
        case 49827 : return key_info {0, U'£', alt, false, false};
        case -1577000320 : return key_info {0, U'•', alt, false, false};
        case -1090457693 : return key_info {0, U'', alt, false, false};
        case 49844 : return key_info {0, U'´', alt, false, false};
        case 50091 : return key_info {0, U'ë', alt, false, false};
        case -1644109184 : return key_info {0, U'„', alt, false, false};
        case -1677663616 : return key_info {0, U'"', alt, false, false};
        case -1660886400 : return key_info {0, U'"', alt, false, false};
        case -1744772480 : return key_info {0, U'‘', alt, false, false};
        case -1727995264 : return key_info {0, U'’', alt, false, false};
        case 49846 : return key_info {0, U'¶', alt, false, false};
        case 50085 : return key_info {0, U'å', alt, false, false};
        case 49835 : return key_info {0, U'«', alt, false, false};
        case 49851 : return key_info {0, U'»', alt, false, false};
        case 49825 : return key_info {0, U'¡', alt, false, false};
        case 50075 : return key_info {0, U'Û', alt, false, false};
        case 50055 : return key_info {0, U'Ç', alt, false, false};
        case 50049 : return key_info {0, U'Á', alt, false, false};
        case 50104 : return key_info {0, U'ø', alt, false, false};
        case 50072 : return key_info {0, U'Ø', alt, false, false};
        case -1811881344 : return key_info {0, U'—', alt, false, false};
        case -1828658560 : return key_info {0, U'–', alt, false, false};
        case -1543445879 : return key_info {0, U'≤', alt, false, false};
        case -1526668663 : return key_info {0, U'≥', alt, false, false};
        case 50100 : return key_info {0, U'ô', alt, false, false};
        case 50068 : return key_info {0, U'Ô', alt, false, false};
        case -1409228158 : return key_info {0, U'€', alt, false, false};
        case 50073 : return key_info {0, U'Ù', alt, false, false};
        case -1342119296 : return key_info {0, U'‰', alt, false, false};
        case -1644109176 : return key_info {0, U'∞', alt, false, false};
        case 49855 : return key_info {0, U'¿', alt, false, false};
        case -1509891456 : return key_info {0, U'…', alt, false, false};
        case 50103 : return key_info {0, U'÷', alt, false, false};
        case -1610554743 : return key_info {0, U'≠', alt, false, false};
        case 49841 : return key_info {0, U'±', alt, false, false};
      }
      
      if (key_info::keys.find(std::string(1, toupper((char)key))) != key_info::keys.end())
        return key_info {toupper(key), key, alt, false, key >= 'A' && key <= 'Z'};
        
      return key_info {0, key, alt, false, key >= 'A' && key <= 'Z'};
    }
    
    char32_t key_;
    char32_t key_char_;
    bool has_alt_modifier_;
    bool has_control_modifier_;
    bool has_shift_modifier_;
    struct key_key_char {
      [[maybe_unused]] char32_t key;
      [[maybe_unused]] char32_t key_char;
      [[maybe_unused]] bool alt;
      [[maybe_unused]] bool control;
      [[maybe_unused]] bool shift;
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
    //{"", {92, 0, false, false, false}}, // RightWindows
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
  
  auto background_color = CONSOLE_COLOR_DEFAULT;
  auto foreground_color = CONSOLE_COLOR_DEFAULT;
  auto buffer_height = -1;
  auto buffer_width = -1;
  auto caps_lock = false;
  auto cursor_left = 0;
  auto cursor_size = 100;
  auto cursor_top = 0;
  auto cursor_visible = true;
  auto input_code_page = 65001;
  auto largest_window_height = 1000;
  auto largest_window_width = 1000;
  auto number_lock = true;
  auto output_code_page = 65001;
  std::string title;
  auto window_height = 25;
  auto window_left = 0;
  auto window_top = 0;
  auto window_width = 80;
}

int32_t console::background_color() {
  return ::background_color;
}

bool console::background_color(int32_t color) {
  static auto colors = std::map<int32_t, const char*> {{CONSOLE_COLOR_DEFAULT, "\x1b[49m"}, {CONSOLE_COLOR_BLACK, "\x1b[40m"}, {CONSOLE_COLOR_DARK_BLUE, "\x1b[44m"}, {CONSOLE_COLOR_DARK_GREEN, "\x1b[42m"}, {CONSOLE_COLOR_DARK_CYAN, "\x1b[46m"}, {CONSOLE_COLOR_DARK_RED, "\x1b[41m"}, {CONSOLE_COLOR_DARK_MAGENTA, "\x1b[45m"}, {CONSOLE_COLOR_DARK_YELLOW, "\x1b[43m"}, {CONSOLE_COLOR_GRAY, "\x1b[47m"}, {CONSOLE_COLOR_DARK_GRAY, "\x1b[100m"}, {CONSOLE_COLOR_BLUE, "\x1b[104m"}, {CONSOLE_COLOR_GREEN, "\x1b[102m"}, {CONSOLE_COLOR_CYAN, "\x1b[106m"}, {CONSOLE_COLOR_RED, "\x1b[101m"}, {CONSOLE_COLOR_MAGENTA, "\x1b[105m"}, {CONSOLE_COLOR_YELLOW, "\x1b[103m"}, {CONSOLE_COLOR_WHITE, "\x1b[107m"}};
  auto it = colors.find(color);
  if (it == colors.end()) return false;
  ::background_color = color;
  if (terminal::is_ansi_supported()) std::cout << it->second << std::flush;
  return true;
}

namespace {
  class audio {
  public:
    audio() noexcept {
      auto audio_component_description = AudioComponentDescription {kAudioUnitType_Output, kAudioUnitSubType_DefaultOutput, kAudioUnitManufacturer_Apple, 0, 0};
      if (AudioComponentInstanceNew(AudioComponentFindNext(nullptr, &audio_component_description), &audio_unit) != noErr) return;
      
      auto au_render_callback_struct = AURenderCallbackStruct {&audio::au_renderer_proc, nullptr};
      if (AudioUnitSetProperty(audio_unit, kAudioUnitProperty_SetRenderCallback, kAudioUnitScope_Input, 0, &au_render_callback_struct, sizeof(au_render_callback_struct)) != noErr) return;

      auto audio_stream_basic_description = AudioStreamBasicDescription {simple_rate, kAudioFormatLinearPCM, 0, 1, 1, 1, 1, bits_per_channel, 0};
      if (AudioUnitSetProperty(audio_unit, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, 0, &audio_stream_basic_description, sizeof(audio_stream_basic_description)) != noErr) return;

      if (AudioUnitInitialize(audio_unit) != noErr) return;
      if (AudioOutputUnitStart(audio_unit) != noErr) return;
      initialized = true;
    }
    
    ~audio() noexcept {
      if (!initialized) return;
      if (AudioOutputUnitStop(audio_unit) != noErr) return;
      if (AudioUnitUninitialize(audio_unit) != noErr) return;
    }
    
    static bool beep(uint32_t frequency, uint32_t duration) {
      if (!initialized || frequency < 37 || frequency > 32767) return false;
      
      dispatch_semaphore_wait(idle_semaphore, DISPATCH_TIME_FOREVER);
      
      beep_freq = frequency;
      beep_samples = (duration / 1000.0) * simple_rate;
      
      dispatch_semaphore_signal(start_playing_semaphore);
      dispatch_semaphore_wait(end_playing_semaphore, DISPATCH_TIME_FOREVER);
      dispatch_semaphore_signal(idle_semaphore);
      return true;
    }
    
  private:
    static OSStatus au_renderer_proc(void* in_ref_con, AudioUnitRenderActionFlags* io_action_flags, const AudioTimeStamp* in_time_stamp, uint32_t in_bus_number, uint32_t in_number_frames, AudioBufferList* io_data) {
      static auto counter = 0;
      while (counter == 0) {
        dispatch_semaphore_wait(start_playing_semaphore, DISPATCH_TIME_FOREVER);
        counter = beep_samples;
      }
      
      for (auto frames_index = 0u; frames_index < in_number_frames; ++frames_index) {
        static unsigned char theta = 0;
        reinterpret_cast<unsigned char*>(io_data->mBuffers[0].mData)[frames_index] = (theta < simple_rate / (2 * beep_freq)) ? 255 : 0;
        theta = (theta + 1) % (simple_rate / beep_freq);
        if (--counter == 0) {
          theta = 0;
          counter = 0;
          dispatch_semaphore_signal(end_playing_semaphore);
          break;
        }
      }
      return 0;
    }
    
    inline static constexpr int32_t simple_rate = 8000;
    inline static constexpr int32_t bits_per_channel = 8;
    inline static dispatch_semaphore_t idle_semaphore = dispatch_semaphore_create(1);
    inline static dispatch_semaphore_t start_playing_semaphore = dispatch_semaphore_create(0);
    inline static dispatch_semaphore_t end_playing_semaphore = dispatch_semaphore_create(0);
    inline static AudioUnit audio_unit;
    inline static unsigned int beep_freq = 0;
    inline static int32_t beep_samples = 0;
    inline static bool initialized = false;
  } __audio__;
}

bool console::beep(uint32_t frequency, uint32_t duration) {
  return audio::beep(frequency, duration);
}

int32_t console::buffer_height() {
  /// @todo console buffer Height on linux and macOS
  if (::buffer_height == -1) ::buffer_height = console::window_height();
  return ::buffer_height;
}

bool console::buffer_height(int32_t height) {
  /// @todo set console buffer height on linux and macOS
  ::buffer_height = height;
  return true;
}

int32_t console::buffer_width() {
  /// @todo console buffer Width on linux and macOS
  if (::buffer_width == -1) ::buffer_width = console::window_width();
  return ::buffer_width;
}

bool console::buffer_width(int32_t width) {
  /// @todo set console buffer width on linux and macOS
  ::buffer_width = width;
  return true;
}

bool console::caps_lock() {
  /// @todo caps lock status on linux and macOS
  return ::caps_lock;
}

bool console::clear() {
  if (terminal::is_ansi_supported()) std::cout << "\x1b[H\x1b[2J" << std::flush;
  return set_cursor_position(0, 0);
}

int32_t console::cursor_left() {
  if (!terminal::is_ansi_supported()) return ::cursor_left;
  std::cout << "\x1b[6n" << std::flush;
  terminal::terminal_.getch();
  terminal::terminal_.getch();
  for (char c = terminal::terminal_.getch(); c != ';'; c = terminal::terminal_.getch());
  std::string left;
  for (char c = terminal::terminal_.getch(); c != 'R'; c = terminal::terminal_.getch())
    left.push_back(c);
  ::cursor_left = atoi(left.c_str()) - 1;
  return ::cursor_left;
}

int32_t console::cursor_size() {
  return ::cursor_size;
}

bool console::cursor_size(int32_t size) {
  ::cursor_size = size;
  if (!terminal::is_ansi_supported()) return true;
  if (size < 50) std::cout << "\x1b[4 q" << std::flush;
  else std::cout << "\x1b[2 q" << std::flush;
  return true;
}

int32_t console::cursor_top() {
  if (!terminal::is_ansi_supported()) return ::cursor_top;
  std::cout << "\x1b[6n" << std::flush;
  terminal::terminal_.getch();
  terminal::terminal_.getch();
  auto top = std::string {};
  for (char c = terminal::terminal_.getch(); c != ';'; c = terminal::terminal_.getch())
    top.push_back(c);
  for (char c = terminal::terminal_.getch(); c != 'R'; c = terminal::terminal_.getch());
  ::cursor_top = atoi(top.c_str()) - 1;
  return ::cursor_top;
}

bool console::cursor_visible() {
  return ::cursor_visible;
}

bool console::cursor_visible(bool visible) {
  ::cursor_visible = visible;
  if (terminal::is_ansi_supported()) std::cout << (::cursor_visible ? "\x1b[?25h" : "\x1b[?25l") << std::flush;
  return true;
}

int32_t console::foreground_color() {
  return ::foreground_color;
}

bool console::echo(bool on) {
  return terminal::terminal_.echo(on);
}

bool console::foreground_color(int32_t color) {
  static auto colors = std::map<int32_t, const char*> {{CONSOLE_COLOR_DEFAULT, "\x1b[39m"}, {CONSOLE_COLOR_BLACK, "\x1b[30m"}, {CONSOLE_COLOR_DARK_BLUE, "\x1b[34m"}, {CONSOLE_COLOR_DARK_GREEN, "\x1b[32m"}, {CONSOLE_COLOR_DARK_CYAN, "\x1b[36m"}, {CONSOLE_COLOR_DARK_RED, "\x1b[31m"}, {CONSOLE_COLOR_DARK_MAGENTA, "\x1b[35m"}, {CONSOLE_COLOR_DARK_YELLOW, "\x1b[33m"}, {CONSOLE_COLOR_GRAY, "\x1b[37m"}, {CONSOLE_COLOR_DARK_GRAY, "\x1b[90m"}, {CONSOLE_COLOR_BLUE, "\x1b[94m"}, {CONSOLE_COLOR_GREEN, "\x1b[92m"}, {CONSOLE_COLOR_CYAN, "\x1b[96m"}, {CONSOLE_COLOR_RED, "\x1b[91m"}, {CONSOLE_COLOR_MAGENTA, "\x1b[95m"}, {CONSOLE_COLOR_YELLOW, "\x1b[93m"}, {CONSOLE_COLOR_WHITE, "\x1b[97m"}};
  auto it = colors.find(color);
  if (it == colors.end()) return false;
  ::foreground_color = color;
  if (terminal::is_ansi_supported()) std::cout << it->second << std::flush;
  return true;
}

int32_t console::input_code_page() {
  // There is no way to define the console input code page under macOS.
  // By default, the console input code page is in UTF-8.
  return ::input_code_page;
}

bool console::input_code_page(int32_t code_page) {
  // There is no way to define the console input code page under macOS.
  // By default, the console input code page is in UTF-8.
  ::input_code_page = code_page;
  return true;
}

bool console::key_available() {
  return key_info::key_available();
}

int32_t console::largest_window_height() {
  return ::largest_window_height;
}

int32_t console::largest_window_width() {
  return ::largest_window_width;
}

bool console::number_lock() {
  /// @todo number lock status on linux and macOS
  return ::number_lock;
}

int32_t console::output_code_page() {
  // There is no way to define the console output code page under macOS.
  // By default, the console output code page is in UTF-8.
  return ::output_code_page;
}

bool console::output_code_page(int32_t code_page) {
  // There is no way to define the console output code page under macOS.
  // By default, the console output code page is in UTF-8.
  ::output_code_page = code_page;
  return true;
}

void console::read_key(char32_t& key_char, char32_t& key_code, bool& alt, bool& shift, bool& ctrl) {
  auto key_info = key_info::read();
  key_char = key_info.key_char();
  key_code = key_info.key();
  alt = key_info.has_alt_modifier();
  ctrl = key_info.has_control_modifier();
  shift = key_info.has_shift_modifier();
}

void console::register_user_cancel_callback(std::function<bool(int32_t)> user_cancel_callback) {
  ::user_cancel_callback = user_cancel_callback;
}

bool console::reset_color() {
  return console::background_color(CONSOLE_COLOR_DEFAULT) && console::foreground_color(CONSOLE_COLOR_DEFAULT);
}

bool console::set_cursor_position(int32_t left, int32_t top) {
  ::cursor_left = left;
  ::cursor_top = top;
  if (terminal::is_ansi_supported()) std::cout << "\x1b[" << top + 1 << ";" << left + 1 << "f" << std::flush;
  return true;
}

std::string console::title() {
  /// @todo get console get title on linux and macOS
  /** Didn't work correctly!
   std::cout << "\x1b[21t" << std::endl;
  
   if (!terminal.key_available()) return ::title;
  
   std::string title;
   for (auto c = terminal.getch(); terminal::terminal_.key_available(); c = terminal::terminal_.getch())
     title.push_back(static_cast<char>(c));
   return title;
   */
  return ::title;
}

bool console::title(const std::string& title) {
  ::title = title;
  if (terminal::is_ansi_supported()) std::cout << "\x1b]0;" << title.c_str() << "\x7" << std::flush;
  return true;
}

bool console::treat_control_c_as_input() {
  return ::treat_control_c_as_input;
}

bool console::treat_control_c_as_input(bool treat_control_c_as_input) {
  ::treat_control_c_as_input = treat_control_c_as_input;
  return true;
}

int32_t console::window_height() {
  if (!terminal::is_ansi_supported()) return ::window_height;
  auto top = console::cursor_top();
  console::set_cursor_position(console::cursor_left(), 999);
  auto height = console::cursor_top() + 1;
  console::set_cursor_position(console::cursor_left(), top);
  ::window_height = height;
  return ::window_height;
}

bool console::window_height(int32_t height) {
  /// @todo set console window height on linux and macOS
  ::window_height = height;
  return true;
}

int32_t console::window_left() {
  /// @todo get console window left on linux and macOS
  return ::window_left;
}

bool console::window_left(int32_t left) {
  /// @todo set console window left on linux and macOS
  ::window_left = left;
  return true;
}

int32_t console::window_top() {
  /// @todo get console window top on linux and macOS
  return ::window_top;
}

bool console::window_top(int32_t top) {
  /// @todo set console window top on linux and macOS
  ::window_top = top;
  return true;
}

int32_t console::window_width() {
  if (!terminal::is_ansi_supported()) return ::window_width;
  auto left = console::cursor_left();
  console::set_cursor_position(999, console::cursor_top());
  auto width = console::cursor_left() + 1;
  console::set_cursor_position(left, console::cursor_top());
  ::window_width = width;
  return ::window_width;
}

bool console::window_width(int32_t width) {
  /// @todo set console window width on linux and macOS
  ::window_width = width;
  return true;
}
