/// @file
/// @brief Contains xtd::web::css::writer class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "selector_map.hpp"
#include "../../io/stream_writer.hpp"
#include "../../argument_exception.hpp"
#include "../../format_exception.hpp"
#include "../../object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      class css_writer : public object {
      public:
        /// @name Public Constructors
        
        /// @{
        css_writer(std::ostream& stream) : text_writer_(new xtd::io::stream_writer(stream)) {}
        css_writer(xtd::io::text_writer& text_writer) : text_writer_(&text_writer), delete_when_destroy_(false) {}
        css_writer(const xtd::string& path) : text_writer_(new xtd::io::stream_writer(path)) {}
        /// @}
        /// @cond
        ~css_writer() {if (delete_when_destroy_) delete text_writer_;}
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        [[nodiscard]] auto selectors() const noexcept -> const xtd::web::css::selector_map& {return selectors_;}
        [[nodiscard]] auto selectors() noexcept -> xtd::web::css::selector_map& {return selectors_;}
        auto selectors(const xtd::web::css::selector_map& selector) -> void {selectors_ = selector;}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        auto write() -> void {
          if (!text_writer_) return;
          for (const auto& selector : selectors_) {
            text_writer_->write_line("{} {{", selector.first);
            for (const auto& property : selector.second.properties())
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
