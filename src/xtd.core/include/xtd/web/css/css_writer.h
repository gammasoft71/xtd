/// @file
/// @brief Contains xtd::web::css::writer class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "selector_map"
#include "../../io/stream_writer"
#include "../../argument_exception"
#include "../../format_exception"
#include "../../object"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      class css_writer : public object {
      public:
        /// @name Constructors
        
        /// @{
        css_writer(std::ostream& stream) : text_writer_(new xtd::io::stream_writer(stream)) {}
        css_writer(xtd::io::text_writer& text_writer) : text_writer_(&text_writer), delete_when_destroy_(false) {}
        css_writer(const xtd::ustring& path) : text_writer_(new xtd::io::stream_writer(path)) {}
        /// @}
        /// @cond
        ~css_writer() {if (delete_when_destroy_) delete text_writer_;}
        /// @endcond
        
        /// @name Properties
        
        /// @{
        const xtd::web::css::selector_map& selectors() const noexcept {return selectors_;}
        xtd::web::css::selector_map& selectors() noexcept {return selectors_;}
        void selectors(const xtd::web::css::selector_map& selector) {selectors_ = selector;}
        /// @}
        
        /// @name Methods
        
        /// @{
        void write() {
          if (!text_writer_) return;
          for (auto selector : selectors_) {
            text_writer_->write_line("{} {{", selector.first);
            for (auto property : selector.second.properties())
              text_writer_->write_line("  {}: {};", property.first, property.second);
            text_writer_->write_line("}");
          }
        }
        /// @}
        
      private:
        xtd::web::css::selector_map selectors_;
        xtd::io::text_writer* text_writer_ = nullptr;
        bool delete_when_destroy_ = true;
      };
    }
  }
}
