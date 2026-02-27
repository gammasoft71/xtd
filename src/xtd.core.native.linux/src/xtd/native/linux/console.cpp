#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/console>
#include <xtd/native/console_color>
#include <xtd/native/console_special_key>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <csignal>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <sstream>
#include <vector>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#if defined(__XTD_USE_ASOUND__)
#define ALSA_PCM_NEW_HW_PARAMS_API
#include <alsa/asoundlib.h>
#include <linux/kd.h>
#endif

using namespace std;
using namespace xtd::native;

namespace {
  auto treat_control_c_as_input = false;
  vector<int32_t> signal_couter_;
  function<bool(int32_t)> user_cancel_callback;
  
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
    
    static auto signal_handler(int32_t signal) -> void {
      ::signal(signal, console_intercept_signals::signal_handler);
      if (treat_control_c_as_input) signal_couter_.push_back(signal_keys_[signal]);
      else if (user_cancel_callback && user_cancel_callback(signal_keys_[signal]) == false) exit(EXIT_FAILURE);
    }
    
    // The SIGINT signal catcher conflicts with with xtd::environment::cancel_interrupt signal...
    inline static map<int32_t, int32_t> signal_keys_ {{SIGQUIT, CONSOLE_SPECIAL_KEY_CTRL_BS}, {SIGTSTP, CONSOLE_SPECIAL_KEY_CTRL_Z}/*, {SIGINT, CONSOLE_SPECIAL_KEY_CTRL_C}*/};
    static console_intercept_signals console_intercept_signals_;
  };
  
  console_intercept_signals console_intercept_signals::console_intercept_signals_;
  
  class terminal final {
  public:
    auto echo(bool on) -> bool {
      auto status = termios {};
      tcgetattr(0, &status);
      if (on) status.c_lflag |= ECHO;
      else status.c_lflag &= ~ECHO;
      return tcsetattr(0, TCSANOW, &status) == 0;
    }
    
    auto icanon(bool on) -> bool {
      auto status = termios {};
      tcgetattr(0, &status);
      if (on) status.c_lflag |= ICANON;
      else status.c_lflag &= ~ICANON;
      status.c_cc[VMIN] = on ? 1 : 0;
      status.c_cc[VTIME] = 0; // Can be discarded.
      return tcsetattr(0, TCSANOW, &status) == 0;
    }
    
    auto getch() -> int32_t {
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
    
    auto key_available() -> bool {
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
    
    static auto is_ansi_supported() -> bool {
      static auto terminal = string {getenv("TERM") == nullptr ? "" : getenv("TERM")};
      return isatty(fileno(stdout)) && (terminal == "xterm" || terminal == "xterm-color" || terminal == "xterm-256color" || terminal == "screen" || terminal == "screen-256color" || terminal == "linux" || terminal == "cygwin");
    }
    
    auto reset_terminal_mode() -> void {
      pop_status();
      reset_colors_and_attributes();
    }
    
    static terminal terminal_;
    
  private:
    terminal() {
      push_status();
      echo(false);
      icanon(true);
    }
    ~terminal() {
      reset_terminal_mode();
    }
    
    auto reset_colors_and_attributes() -> void {
      if (is_ansi_supported()) cout << "\x1b]0;\x7" << flush;
    }
    
    auto push_status() -> termios {
      auto status = termios {};
      tcgetattr(0, &status);
      statuses.push_back(status);
      return status;
    }
    
    auto pop_status() -> termios {
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
    vector<termios> statuses;
  };
  
  terminal terminal::terminal_;
  
  class key_info {
  public:
    class input_list {
    public:
      input_list() {}
      explicit input_list(const list<int32_t>& chars) : chars(chars) {}
      explicit input_list(initializer_list<int32_t> il) : chars(il) {}
      input_list(const input_list& il) : chars(il.chars) {}
      
      auto operator =(const input_list& il) -> input_list& {
        chars = il.chars;
        return *this;
      }
      
      auto operator ==(const input_list& il) const noexcept -> bool {return chars == il.chars;}
      auto operator !=(const input_list& il) const  -> bool {return chars != il.chars;}
      
      using const_iterator = list<int32_t>::const_iterator;
      using iterator = list<int32_t>::iterator;
      
      auto cbegin() const -> const_iterator {return chars.begin();}
      auto cend() const -> const_iterator {return chars.end();}
      auto begin() const -> const_iterator {return chars.begin();}
      auto begin() -> iterator {return chars.begin();}
      auto end() const -> const_iterator {return chars.end();}
      auto end() -> iterator {return chars.end();}
      
      auto add(int32_t c) -> void {chars.push_back(c);}
      auto add_front(int32_t c) -> void {chars.push_front(c);}
      auto remove(int32_t c) -> void {chars.remove(c);}
      auto count() const -> int32_t {return static_cast<int32_t>(chars.size());}
      auto pop() -> int32_t { int32_t c = chars.front();  chars.erase(chars.begin()); return c;}
      auto clear() -> void {chars.clear();}
      
      auto is_empty() const -> bool {return chars.empty();}
      
      auto to_string() const -> string {
        stringstream result;
        list<int32_t>::const_iterator iterator = chars.begin();
        while (iterator != chars.end()) {
          if (char(*iterator & 0xFF) == 27)
            result << "^[";
          else
            result << char(*iterator & 0xFF);
          ++iterator;
        }
        return result.str();
      }
      
      static auto parse(const string& value) -> input_list {
        input_list result;
        string::const_iterator iterator = value.begin();
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
      list<int32_t> chars;
    };
    
    key_info(const key_info& ki) : key_(ki.key_), key_char_(ki.key_char_), has_alt_modifier_(ki.has_alt_modifier_), has_control_modifier_(ki.has_control_modifier_), has_shift_modifier_(ki.has_shift_modifier_) {}
    
    auto operator =(const key_info& ki) -> key_info& {
      key_ = ki.key_;
      key_char_ = ki.key_char_;
      has_alt_modifier_ = ki.has_alt_modifier_;
      has_control_modifier_ = ki.has_control_modifier_;
      has_shift_modifier_ = ki.has_shift_modifier_;
      return *this;
    }
    
    static auto key_available() -> bool {return !signal_couter_.empty() || !inputs.is_empty() || terminal::terminal_.key_available();}
    
    static auto read() -> key_info {
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
    
    auto key() const -> char32_t {return key_;}
    auto key_char() const -> char32_t {return key_char_;}
    auto has_alt_modifier() const -> bool {return has_alt_modifier_;}
    auto has_control_modifier() const -> bool {return has_control_modifier_;}
    auto has_shift_modifier() const -> bool {return has_shift_modifier_;}
    
    auto to_string() const -> string {
      stringstream result;
      result << "{key=" << hex << static_cast<int32_t>(key_) << ", key_char=" << dec << static_cast<char>(key_char_) << ", has_alt_modifier=" << to_string(has_alt_modifier_) << ", has_control_modifier=" << to_string(has_control_modifier_) << ", has_shift_modifier=" << to_string(has_shift_modifier_) << "}";
      return result.str();
    }
    
  private:
    key_info() : key_(U'0'), key_char_(U'0'), has_alt_modifier_(false), has_control_modifier_(false), has_shift_modifier_(false) {}
    key_info(int32_t key, int32_t key_char) : key_(key), key_char_(key_char), has_alt_modifier_(false), has_control_modifier_(false), has_shift_modifier_(false) {}
    key_info(int32_t key, int32_t key_char, bool has_alt_modifier, bool has_control_modifier, bool has_shift_modifier) : key_(key), key_char_(key_char), has_alt_modifier_(has_alt_modifier), has_control_modifier_(has_control_modifier), has_shift_modifier_(has_shift_modifier) {}
    
    static auto to_string(bool b) -> string {return b ? "true" : "false";}
    
    static auto to_key(input_list& inputs) -> int32_t {
      int32_t result = 0;
      int32_t index = 1;
      for (auto c : inputs)
        result |= (c & 0xFF) << (8 * index--);
      inputs.clear();
      return result;
    }
    
    static auto to_key_info(int32_t key) -> key_info {
      return to_key_info(key, false);
    }
    
    static auto to_key_info(int32_t key, bool alt) -> key_info {
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
      
      if (key_info::keys.find(string(1, toupper((char)key))) != key_info::keys.end())
        return key_info(toupper(key), key, alt, false, key >= 'A' && key <= 'Z');
        
      return key_info(0, key, alt, false, key >= 'A' && key <= 'Z');
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
    static map<string, key_key_char> keys;
    static input_list inputs;
  };
  
  key_info::input_list key_info::inputs;
  map<string, key_info::key_key_char> key_info::keys = {
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
  string title;
  auto window_height = 25;
  auto window_left = 0;
  auto window_top = 0;
  auto window_width = 80;
}

auto console::background_color() -> int32_t {
  return ::background_color;
}

auto console::background_color(int32_t color) -> bool {
  static auto colors = map<int32_t, const char*> {{CONSOLE_COLOR_DEFAULT, "\x1b[49m"}, {CONSOLE_COLOR_BLACK, "\x1b[40m"}, {CONSOLE_COLOR_DARK_BLUE, "\x1b[44m"}, {CONSOLE_COLOR_DARK_GREEN, "\x1b[42m"}, {CONSOLE_COLOR_DARK_CYAN, "\x1b[46m"}, {CONSOLE_COLOR_DARK_RED, "\x1b[41m"}, {CONSOLE_COLOR_DARK_MAGENTA, "\x1b[45m"}, {CONSOLE_COLOR_DARK_YELLOW, "\x1b[43m"}, {CONSOLE_COLOR_GRAY, "\x1b[47m"}, {CONSOLE_COLOR_DARK_GRAY, "\x1b[100m"}, {CONSOLE_COLOR_BLUE, "\x1b[104m"}, {CONSOLE_COLOR_GREEN, "\x1b[102m"}, {CONSOLE_COLOR_CYAN, "\x1b[106m"}, {CONSOLE_COLOR_RED, "\x1b[101m"}, {CONSOLE_COLOR_MAGENTA, "\x1b[105m"}, {CONSOLE_COLOR_YELLOW, "\x1b[103m"}, {CONSOLE_COLOR_WHITE, "\x1b[107m"}};
  auto it = colors.find(color);
  if (it == colors.end()) return false;
  ::background_color = color;
  if (terminal::is_ansi_supported()) cout << it->second << flush;
  return true;
}

namespace {
  class audio {
  public:
    static auto beep(uint32_t frequency, uint32_t duration) -> bool {
      auto& a = get_instance();
      lock_guard<mutex> lock {a.mutex_};
      #if defined(__XTD_USE_ASOUND__)
      if (!pcm_handle || frequency < 37 || frequency > 32767) return false;
      
      unsigned int total_frames = (duration / 1000.0) * sample_rate;
      unsigned int frames_per_buffer = sample_rate / 10; // ex: buffer for 100ms
      unsigned char* buffer = new unsigned char[frames_per_buffer];
      
      for (unsigned int frame_index = 0; frame_index < total_frames; frame_index += frames_per_buffer) {
        snd_pcm_prepare(pcm_handle);
        for (unsigned int buffer_index = 0; buffer_index < frames_per_buffer; ++buffer_index)
          buffer[buffer_index] = (buffer_index % (sample_rate / frequency) < (sample_rate / frequency) / 2) ? 255 : 0;
          
        int written_frames = snd_pcm_writei(pcm_handle, buffer, frames_per_buffer);
        if (written_frames < 0) snd_pcm_recover(pcm_handle, written_frames, 0);
      }
      
      delete[] buffer;
      return true;
      #else
      return frequency >= 37 && frequency <= 32767;
      #endif
    }
    
  private:
    audio() noexcept {
      #if defined(__XTD_USE_ASOUND__)
      if (snd_pcm_open(&pcm_handle, "default", SND_PCM_STREAM_PLAYBACK, 0)) return;
      if (snd_pcm_set_params(pcm_handle, SND_PCM_FORMAT_U8, SND_PCM_ACCESS_RW_INTERLEAVED, 1, sample_rate, 1, 20000) < 0) {
        snd_pcm_close(pcm_handle);
        pcm_handle = nullptr;
      }
      #endif
    }
    
    ~audio() noexcept {
      #if defined(__XTD_USE_ASOUND__)
      if (pcm_handle) snd_pcm_close(pcm_handle);
      #endif
    }
    
    static auto get_instance() -> audio& {
      static audio instance;
      return instance;
    }
    
    mutex mutex_;
    inline static constexpr auto sample_rate = 8000u;
    #if defined(__XTD_USE_ASOUND__)
    inline static snd_pcm_t* pcm_handle = nullptr;
    #endif
  };
}

auto console::beep(uint32_t frequency, uint32_t duration) -> bool {
  return audio::beep(frequency, duration);
}

auto console::buffer_height() -> int32_t {
  /// @todo console buffer Height on linux
  if (::buffer_height == -1) ::buffer_height = console::window_height();
  return ::buffer_height;
}

auto console::buffer_height(int32_t height) -> bool {
  /// @todo set console buffer height on linux
  ::buffer_height = height;
  return true;
}

auto console::buffer_width() -> int32_t {
  /// @todo console buffer Width on linux
  if (::buffer_width == -1) ::buffer_width = console::window_width();
  return ::buffer_width;
}

auto console::buffer_width(int32_t width) -> bool {
  /// @todo set console buffer width on linux
  ::buffer_width = width;
  return true;
}

auto console::caps_lock() -> bool {
  /// @todo caps lock status on linux
  return ::caps_lock;
}

auto console::clear() -> bool {
  if (terminal::is_ansi_supported()) cout << "\x1b[H\x1b[2J" << flush;
  return set_cursor_position(0, 0);
}

auto console::cursor_left() -> int32_t {
  if (!terminal::is_ansi_supported()) return ::cursor_left;
  cout << "\x1b[6n" << flush;
  terminal::terminal_.getch();
  terminal::terminal_.getch();
  for (char c = terminal::terminal_.getch(); c != ';'; c = terminal::terminal_.getch());
  string left;
  for (char c = terminal::terminal_.getch(); c != 'R'; c = terminal::terminal_.getch())
    left.push_back(c);
  ::cursor_left = atoi(left.c_str()) - 1;
  return ::cursor_left;
}

auto console::cursor_size() -> int32_t {
  return ::cursor_size;
}

auto console::cursor_size(int32_t size) -> bool {
  ::cursor_size = size;
  if (!terminal::is_ansi_supported()) return true;
  if (size < 50) cout << "\x1b[4 q" << flush;
  else cout << "\x1b[2 q" << flush;
  return true;
}

auto console::cursor_top() -> int32_t {
  if (!terminal::is_ansi_supported()) return ::cursor_top;
  cout << "\x1b[6n" << flush;
  terminal::terminal_.getch();
  terminal::terminal_.getch();
  string top;
  for (char c = terminal::terminal_.getch(); c != ';'; c = terminal::terminal_.getch())
    top.push_back(c);
  for (char c = terminal::terminal_.getch(); c != 'R'; c = terminal::terminal_.getch());
  ::cursor_top = atoi(top.c_str()) - 1;
  return ::cursor_top;
}

auto console::cursor_visible() -> bool {
  return ::cursor_visible;
}

auto console::cursor_visible(bool visible) -> bool {
  ::cursor_visible = visible;
  if (terminal::is_ansi_supported()) cout << (::cursor_visible ? "\x1b[?25h" : "\x1b[?25l") << flush;
  return true;
}

auto console::echo(bool on) -> bool {
  if (!terminal::is_ansi_supported()) return false;
  return terminal::terminal_.echo(on);
}

auto console::foreground_color() -> int32_t {
  return ::foreground_color;
}

auto console::foreground_color(int32_t color) -> bool {
  static auto colors = map<int32_t, const char*> {{CONSOLE_COLOR_DEFAULT, "\x1b[39m"}, {CONSOLE_COLOR_BLACK, "\x1b[30m"}, {CONSOLE_COLOR_DARK_BLUE, "\x1b[34m"}, {CONSOLE_COLOR_DARK_GREEN, "\x1b[32m"}, {CONSOLE_COLOR_DARK_CYAN, "\x1b[36m"}, {CONSOLE_COLOR_DARK_RED, "\x1b[31m"}, {CONSOLE_COLOR_DARK_MAGENTA, "\x1b[35m"}, {CONSOLE_COLOR_DARK_YELLOW, "\x1b[33m"}, {CONSOLE_COLOR_GRAY, "\x1b[37m"}, {CONSOLE_COLOR_DARK_GRAY, "\x1b[90m"}, {CONSOLE_COLOR_BLUE, "\x1b[94m"}, {CONSOLE_COLOR_GREEN, "\x1b[92m"}, {CONSOLE_COLOR_CYAN, "\x1b[96m"}, {CONSOLE_COLOR_RED, "\x1b[91m"}, {CONSOLE_COLOR_MAGENTA, "\x1b[95m"}, {CONSOLE_COLOR_YELLOW, "\x1b[93m"}, {CONSOLE_COLOR_WHITE, "\x1b[97m"}};
  auto it = colors.find(color);
  if (it == colors.end()) return false;
  ::foreground_color = color;
  if (terminal::is_ansi_supported()) cout << it->second << flush;
  return true;
}

auto console::input_code_page() -> int32_t {
  // There is no way to define the console input code page under linux.
  // By default, the console input code page is in UTF-8.
  return ::input_code_page;
}

auto console::input_code_page(int32_t code_page) -> bool {
  // There is no way to define the console input code page under linux.
  // By default, the console input code page is in UTF-8.
  ::input_code_page = code_page;
  return true;
}

auto console::key_available() -> bool {
  return key_info::key_available();
}

auto console::largest_window_height() -> int32_t {
  return ::largest_window_height;
}

auto console::largest_window_width() -> int32_t {
  return ::largest_window_width;
}

auto console::number_lock() -> bool {
  /// @todo number lock status on linux
  return ::number_lock;
}

auto console::output_code_page() -> int32_t {
  // There is no way to define the console output code page under linux.
  // By default, the console output code page is in UTF-8.
  return ::output_code_page;
}

auto console::output_code_page(int32_t code_page) -> bool {
  // There is no way to define the console output code page under linux.
  // By default, the console output code page is in UTF-8.
  ::output_code_page = code_page;
  return true;
}

auto console::read_key(char32_t& key_char, char32_t& key_code, bool& alt, bool& shift, bool& ctrl) -> void {
  key_info key_info = key_info::read();
  key_char = key_info.key_char();
  key_code = key_info.key();
  alt = key_info.has_alt_modifier();
  ctrl = key_info.has_control_modifier();
  shift = key_info.has_shift_modifier();
}

auto console::register_user_cancel_callback(function<bool(int32_t)> user_cancel_callback) -> void {
  ::user_cancel_callback = user_cancel_callback;
}

auto console::reset_color() -> bool {
  return console::background_color(CONSOLE_COLOR_DEFAULT) && console::foreground_color(CONSOLE_COLOR_DEFAULT);
}

auto console::reset_console() -> bool {
  terminal::terminal_.reset_terminal_mode();
  return console::background_color(CONSOLE_COLOR_DEFAULT) && console::foreground_color(CONSOLE_COLOR_DEFAULT);
}

auto console::set_cursor_position(int32_t left, int32_t top) -> bool {
  ::cursor_left = left;
  ::cursor_top = top;
  if (terminal::is_ansi_supported()) cout << "\x1b[" << top + 1 << ";" << left + 1 << "f" << flush;
  return true;
}

auto console::title() -> string {
  /// @todo get console get title on linux
  /** Didn't work correctly!
   cout << "\x1b[21t" << endl;
  
   if (!terminal.key_available()) return ::title;
  
   string title;
   for (auto c = terminal.getch(); terminal::terminal_.key_available(); c = terminal::terminal_.getch())
     title.push_back(static_cast<char>(c));
   return title;
   */
  return ::title;
}

auto console::title(const string& title) -> bool {
  ::title = title;
  if (terminal::is_ansi_supported()) cout << "\x1b]0;" << title.c_str() << "\x7" << flush;
  return true;
}

auto console::treat_control_c_as_input() -> bool {
  return ::treat_control_c_as_input;
}

auto console::treat_control_c_as_input(bool treat_control_c_as_input) -> bool {
  ::treat_control_c_as_input = treat_control_c_as_input;
  return true;
}

auto console::window_height() -> int32_t {
  if (!terminal::is_ansi_supported()) return ::window_height;
  auto top = console::cursor_top();
  console::set_cursor_position(console::cursor_left(), 999);
  auto height = console::cursor_top() + 1;
  console::set_cursor_position(console::cursor_left(), top);
  ::window_height = height;
  return ::window_height;
}

auto console::window_height(int32_t height) -> bool {
  /// @todo set console window height on linux
  ::window_height = height;
  return true;
}

auto console::window_left() -> int32_t {
  /// @todo get console window left on linux
  return ::window_left;
}

auto console::window_left(int32_t left) -> bool {
  /// @todo set console window left on linux
  ::window_left = left;
  return true;
}

auto console::window_top() -> int32_t {
  /// @todo get console window top on linux
  return ::window_top;
}

auto console::window_top(int32_t top) -> bool {
  /// @todo set console window top on linux
  ::window_top = top;
  return true;
}

auto console::window_width() -> int32_t {
  if (!terminal::is_ansi_supported()) return ::window_width;
  auto left = console::cursor_left();
  console::set_cursor_position(999, console::cursor_top());
  auto width = console::cursor_left() + 1;
  console::set_cursor_position(left, console::cursor_top());
  ::window_width = width;
  return ::window_width;
}

auto console::window_width(int32_t width) -> bool {
  /// @todo set console window width on linux
  ::window_width = width;
  return true;
}
