/// @file
/// @brief Contains xtd::web::css::reader class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "selector_map.h"
#include "../..//io/stream_reader.h"
#include "../../argument_exception.h"
#include "../../format_exception.h"
#include "../../object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes and interfaces that enable browser-server communication. This namespace includes the http_request class, which provides extensive information about the current HTTP request; the http_response class, which manages HTTP output to the client; and the http_server_utility class, which provides access to server-side utilities and processes. xtd::web also includes classes for cookie manipulation, file transfer, exception information, and output cache control.
  namespace web {
    namespace css {
      class css_reader : public object {
      public:
        /// @name Public Constructors
        
        /// @{
        css_reader(std::istream& stream) {parse_text(xtd::io::stream_reader(stream).read_to_end());}
        css_reader(xtd::io::text_reader& text_reader) {parse_text(text_reader.read_to_end());}
        css_reader(const xtd::ustring& text) {parse_text(text);}
        /// @}
        
        /// @name Public Properties
        
        /// @{
        const xtd::web::css::selector_map& selectors() const noexcept {return selectors_;}
        /// @}
        
      private:
        void parse_text(const xtd::ustring& text) {
          enum class parse_status {
            selector,
            key,
            value
          };
          parse_status status = parse_status::selector;
          size_t start_index = 0;
          xtd::web::css::selector current_selector;
          xtd::ustring current_selector_name;
          xtd::ustring current_key;
          for (size_t index = 0; index < text.size(); index++) {
            if (text[index] == '/' && text[index + 1] == '*') {
              // Skip comments...
              index = text.index_of("*/", index + 2);
              if (index == text.npos) throw xtd::format_exception("expected end comment"_t, csf_);
              index++;
              start_index = index + 1;
              continue;
            } else if (status == parse_status::selector && text[index] == '{') {
              current_selector_name = text.substring(start_index, index - start_index).trim();
              current_selector.name(text.substring(start_index, index - start_index).trim());
              start_index = index + 1;
              status = parse_status::key;
            } else if (status == parse_status::key && text[index] == '}') {
              selectors_[current_selector_name] = current_selector;
              current_selector = xtd::web::css::selector();
              start_index = index + 1;
              status = parse_status::selector;
            } else if (status == parse_status::key && text[index] == ':') {
              current_key = text.substring(start_index, index - start_index).trim().to_lower();
              if (current_key.empty()) throw xtd::format_exception("key cannot be empty"_t, csf_);
              start_index = index + 1;
              status = parse_status::value;
            } else if (status == parse_status::value && text[index] == ';') {
              auto value = text.substring(start_index, index - start_index).trim();
              if (value.empty()) throw xtd::format_exception("value cannot be empty"_t, csf_);
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
