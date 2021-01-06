#pragma once
#include "selector_map.h"
#include <xtd/argument_exception.h>
#include <xtd/format_exception.h>
#include <xtd/io/stream_reader.h>

namespace xtd {
  namespace html {
    namespace css {
      class parser {
      public:
        parser(std::istream& stream) {parse_text(xtd::io::stream_reader(stream).read_to_end());}
        parser(xtd::io::text_reader& text_reader) {parse_text(text_reader.read_to_end());}
        parser(const std::string& text) {parse_text(text);}
        
        const xtd::html::css::selector_map& selectors() const {return selectors_;}
        
      private:
        void parse_text(std::string text) {
          enum class parse_status {
            selector,
            key,
            value
          };
          parse_status status = parse_status::selector;
          auto start_index = 0UL;
          xtd::html::css::selector current_selector;
          std::string current_selector_name;
          std::string current_key;
          for (auto index = 0UL; index < text.size(); index++) {
            if (text[index] == '/' && text[index+1] == '*') {
              // Skip comments...
              index = xtd::strings::index_of(text, "*/", index+2);
              if (index == text.npos) throw xtd::format_exception("expected end comment", caller_info_);
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
              current_selector = xtd::html::css::selector();
              start_index = index + 1;
              status = parse_status::selector;
            } else if (status == parse_status::key && text[index] == ':') {
              current_key = xtd::strings::trim(xtd::strings::substring(text, start_index, index - start_index));
              if (current_key.empty()) throw xtd::format_exception("key cannot be empty", caller_info_);
              start_index = index + 1;
              status = parse_status::value;
            } else if (status == parse_status::value && text[index] == ';') {
              auto value = xtd::strings::trim(xtd::strings::substring(text, start_index, index - start_index));
              if (value.empty()) throw xtd::format_exception("value cannot be empty", caller_info_);
              start_index = index + 1;
              current_selector.properties()[current_key] = property(value);
              status = parse_status::key;
            }
          }
        }
        
        xtd::html::css::selector_map selectors_;
      };
    }
  }
}
