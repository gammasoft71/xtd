#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdio>
#include <string>

#undef unix

namespace xtd::unix::macos {
  class shell_execute final {
  public:
    static std::string run(const std::string& file_name) {return run(file_name, {});}
    static std::string run(const std::string& file_name, const std::string& arguments) {
      const auto command = file_name + (arguments.empty() ? "" : (" " + arguments));
      auto file_stream = popen(command.c_str(), "r");
      if (file_stream == nullptr) return {};

      auto result = std::string {};
      while (!feof(file_stream)) {
        auto buffer = std::string(buffer_size, '\0');
        fread(buffer.data(), 1, buffer.size(), file_stream);
        result += buffer;
      }

      pclose(file_stream);
      return result;
    }

  private:
    shell_execute() = delete;
    static constexpr size_t buffer_size = 128;
  };
}
