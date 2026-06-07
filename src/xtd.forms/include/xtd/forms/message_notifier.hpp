#pragma once
#include "layout/arranged_element_collection.hpp"
#include "component.hpp"
#include "iwin32_window.hpp"
#include "message_notifier_button.hpp"
#include "notifier_appearance.hpp"
#include <xtd/drawing/icon>
#include <xtd/chrono>
#include <xtd/delegate>
#include <xtd/string>
#include <xtd/event>
#include <xtd/event_args>
#include <xtd/not_implemented_exception>
#include <xtd/optional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    // TODO: IMPL + move to seperate file
    class notifier_button_click_event_args : public xtd::event_args {
    public:
      //...
      explicit notifier_button_click_event_args(const message_notifier_button& button) : button_(button) {}
      
      [[nodiscard]] auto button() const noexcept -> xtd::forms::message_notifier_button {
        return button_;
      }
      
    private:
      message_notifier_button button_;
      //...
    };
    
    using notifier_button_click_event_handler = xtd::delegate<void(xtd::object& sender, const xtd::forms::notifier_button_click_event_args& e)>;
    
    
    // TODO: IMPL + move to seperate file
    class notifier_closed_event_args : public xtd::event_args {
    public:
      explicit notifier_closed_event_args(const std::optional<xtd::forms::message_notifier_button>& button) : button_(button) {}
      
      [[nodiscard]] auto button() const noexcept -> std::optional<xtd::forms::message_notifier_button> {
        return button_;
      }
      
      [[nodiscard]] auto close_on_timeout() const noexcept -> bool {
        return close_on_timeout_;
      }
      
      [[nodiscard]] auto close_on_click_message() const noexcept -> bool {
        return close_on_click_message_;
      }
      
    private:
      bool close_on_timeout_ = false;
      bool close_on_click_message_ = false;
      std::optional<xtd::forms::message_notifier_button> button_ = std::nullopt;
      //...
    };
    
    using notifier_closed_event_handler = xtd::delegate<void(xtd::object& sender, const xtd::forms::notifier_closed_event_args& e)>;
    
    
    class forms_export_ message_notifier final : public component {
    public:
      /// @name Public Aliases
      
      /// @{
      using message_notifier_button_collection = xtd::forms::layout::arranged_element_collection<xtd::forms::message_notifier_button_ref>;
      /// @}

      /// @name Public Constructors
      
      /// @{
      message_notifier() = default;
      /// @}

      /// @name Public Properties
      
      /// @{
      [[nodiscard]] auto buttons() const noexcept -> const message_notifier_button_collection& {return buttons_;}
      [[nodiscard]] auto buttons() noexcept -> message_notifier_button_collection& {return buttons_;}
      
      [[nodiscard]] auto close_timeout_enabled() const noexcept -> bool {return close_timeout_enabled_;}
      auto close_timeout_enabled(bool value) noexcept -> message_notifier& {close_timeout_enabled_ = value; return *this;}

      [[nodiscard]] auto close_timeout_interval() const noexcept -> std::chrono::milliseconds {return close_timeout_interval_;}
      auto close_timeout_interval(std::chrono::milliseconds value) noexcept -> message_notifier& {close_timeout_interval_ = value; return *this;}
      auto close_timeout_interval_milliseconds(xtd::int32 value) noexcept -> message_notifier& {close_timeout_interval_ = std::chrono::milliseconds(value); return *this;}
      
      [[nodiscard]] auto icon() const noexcept -> const xtd::drawing::image& {return icon_;}
      auto icon(const xtd::drawing::image& icon) noexcept -> message_notifier& {icon_ = icon; return *this;}
      auto icon(const xtd::drawing::icon& value) noexcept -> message_notifier& {icon_ = value.to_bitmap(); return *this;}
      
      [[nodiscard]] auto notifier_appearance() const noexcept -> xtd::forms::notifier_appearance {return notifier_appearance_;}
      auto notifier_appearance(xtd::forms::notifier_appearance value) noexcept -> message_notifier& {notifier_appearance_ = value; return *this;}

      [[nodiscard]] auto message() const noexcept -> const xtd::string& {return message_;}
      auto message(const xtd::string& value) noexcept -> message_notifier& {message_ = value; return *this;}

      [[nodiscard]] auto notifier_button_clicked() const noexcept -> std::optional<xtd::forms::message_notifier_button> {return notifier_button_clicked_;}
      
      [[nodiscard]] auto title() const noexcept -> const xtd::string& {return title_;}
      auto title(const xtd::string& value) noexcept -> message_notifier& {title_ = value; return *this;}
      /// @}

      /// @name Public Methods
      
      /// @{
      auto reset() -> void;
      
      auto show() -> void;
      auto show(const iwin32_window& owner) -> void;
      /// @}

      /// @name Public Events
      
      /// @{
      xtd::event<message_notifier, xtd::forms::notifier_closed_event_handler> notifier_closed;
      xtd::event<message_notifier, xtd::forms::notifier_button_click_event_handler> button_click;
      /// @}

    protected:
      /// @name Public Methods
      
      /// @{
      auto on_notifier_closed(const xtd::forms::notifier_closed_event_args& e) -> void {notifier_closed(*this, e);}
      auto on_button_click(const xtd::forms::notifier_button_click_event_args& e) -> void {button_click(*this, e);}
      /// @}

    private:
      xtd::string title_;
      xtd::string message_;
      xtd::drawing::image icon_ = xtd::drawing::image::empty;
      bool close_timeout_enabled_ = false;
      std::chrono::milliseconds close_timeout_interval_ = std::chrono::milliseconds(10'000);
      message_notifier_button_collection buttons_;
      std::optional<xtd::forms::message_notifier_button> notifier_button_clicked_ = std::nullopt;
      xtd::forms::notifier_appearance notifier_appearance_ = xtd::forms::notifier_appearance::standard;
    };
  }
}

