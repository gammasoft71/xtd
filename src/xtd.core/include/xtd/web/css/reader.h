/// @file
/// @brief Contains xtd::web::css::reader class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "selector_map.h"
#include "../../argument_exception.h"
#include "../../format_exception.h"
#include "../../object.h"
#include "../..//io/stream_reader.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes and interfaces that enable browser-server communication. This namespace includes the http_request class, which provides extensive information about the current HTTP request; the http_response class, which manages HTTP output to the client; and the http_server_utility class, which provides access to server-side utilities and processes. xtd::web also includes classes for cookie manipulation, file transfer, exception information, and output cache control.
  namespace web {
    namespace css {
      class reader : public object {
      public:
        reader(std::istream& stream) {parse_text(xtd::io::stream_reader(stream).read_to_end());}
        reader(xtd::io::text_reader& text_reader) {parse_text(text_reader.read_to_end());}
        reader(const std::string& text) {parse_text(text);}
        
        const xtd::web::css::selector_map& selectors() const {return selectors_;}
        
      private:
        void parse_text(std::string text) {
          enum class parse_status {
            selector,
            key,
            value
          };
          parse_status status = parse_status::selector;
          size_t start_index = 0;
          xtd::web::css::selector current_selector;
          std::string current_selector_name;
          std::string current_key;
          for (size_t index = 0; index < text.size(); index++) {
            if (text[index] == '/' && text[index+1] == '*') {
              // Skip comments...
              index = xtd::strings::index_of(text, "*/", index+2);
              if (index == text.npos) throw xtd::format_exception("expected end comment", current_stack_frame_);
              index++;
              start_index = index + 1;
              continue;
            } else if (status == parse_status::selector && text[index] == '{') {
              current_selector_name = xtd::strings::trim(xtd::strings::substring(text, start_index, index - start_index));
              current_selector.name(xtd::strings::trim(xtd::strings::substring(text, start_index, index - start_index)));
              start_index = index + 1;
              status = parse_status::key;
            } else if (status == parse_status::key && text[index] == '}') {
              selectors_[current_selector_name] = current_selector;
              current_selector = xtd::web::css::selector();
              start_index = index + 1;
              status = parse_status::selector;
            } else if (status == parse_status::key && text[index] == ':') {
              current_key = xtd::strings::trim(xtd::strings::substring(text, start_index, index - start_index));
              if (current_key.empty()) throw xtd::format_exception("key cannot be empty", current_stack_frame_);
              start_index = index + 1;
              status = parse_status::value;
            } else if (status == parse_status::value && text[index] == ';') {
              auto value = xtd::strings::trim(xtd::strings::substring(text, start_index, index - start_index));
              if (value.empty()) throw xtd::format_exception("value cannot be empty", current_stack_frame_);
              start_index = index + 1;
              current_selector.properties()[current_key] = property(value);
              status = parse_status::key;
            }
          }
        }
        
        xtd::web::css::selector_map selectors_;
      };
    }
  }
}
