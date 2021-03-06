#pragma once
#include "selector_map.h"
#include <xtd/argument_exception.h>
#include <xtd/format_exception.h>
#include <xtd/io/stream_writer.h>

namespace xtd {
  namespace html {
    namespace css {
      class writer {
      public:
        writer(std::ostream& stream) : text_writer_(new xtd::io::stream_writer(stream)) {}
        writer(xtd::io::text_writer& text_writer) : text_writer_(&text_writer), delete_when_destroy_(false) {}
        writer(const std::string& path) : text_writer_(new xtd::io::stream_writer(path)) {}
        ~writer() {
          if (delete_when_destroy_ && text_writer_) delete text_writer_;
        }
        
        const xtd::html::css::selector_map& selectors() const {return selectors_;}
        xtd::html::css::selector_map& selectors() {return selectors_;}
        void selectors(const xtd::html::css::selector_map& selector) {selectors_ = selector;}
        
        void write() {
          if (!text_writer_) return;
          for (auto selector : selectors_) {
            text_writer_->write_line("{} {{", selector.first);
            for (auto property : selector.second.properties())
              text_writer_->write_line("  {}: {};", property.first, property.second);
            text_writer_->write_line("}");
          }
        }

      private:
        xtd::html::css::selector_map selectors_;
        xtd::io::text_writer* text_writer_ = nullptr;
        bool delete_when_destroy_ = true;
      };
    }
  }
}
