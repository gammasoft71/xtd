/// @file
/// @brief Contains xtd::web::css::writer class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "selector_map.h"
#include "../../argument_exception.h"
#include "../../format_exception.h"
#include "../../object.h"
#include "../../io/stream_writer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      class writer : public object {
      public:
        writer(std::ostream& stream) : text_writer_(new xtd::io::stream_writer(stream)) {}
        writer(xtd::io::text_writer& text_writer) : text_writer_(&text_writer), delete_when_destroy_(false) {}
        writer(const xtd::ustring& path) : text_writer_(new xtd::io::stream_writer(path)) {}
        ~writer() {
          if (delete_when_destroy_ && text_writer_) delete text_writer_;
        }
        
        const xtd::web::css::selector_map& selectors() const {return selectors_;}
        xtd::web::css::selector_map& selectors() {return selectors_;}
        void selectors(const xtd::web::css::selector_map& selector) {selectors_ = selector;}
        
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
        xtd::web::css::selector_map selectors_;
        xtd::io::text_writer* text_writer_ = nullptr;
        bool delete_when_destroy_ = true;
      };
    }
  }
}
