#pragma once
#include <functional>
#include <map>
#include <string>
#include <xtd/event_args.hpp>
#include <xtd/event_handler.hpp>
#include <xtd/point.hpp>
#include <xtd/size.hpp>

#include "message.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class control {
    public:
      static const control null;
      
      control() {}
      virtual ~control();

      virtual intptr_t handle() const {return this->handle_;}

      virtual xtd::drawing::size client_size() const {return this->client_size_;}
      virtual void client_size(const xtd::drawing::size& size);

      virtual xtd::drawing::size default_size() const {return{0, 0};}

      virtual xtd::drawing::point location() const {return this->location_;}
      virtual void location(const xtd::drawing::point& location);

      virtual control& parent() const {return *this->parent_;}
      virtual void parent(const control& parent);

      virtual xtd::drawing::size size() const {return this->size_;}
      virtual void size(const xtd::drawing::size& size);
      
      virtual const std::string& text() const {return this->text_;}
      virtual void text(const std::string& text);
      
      virtual bool visible() const {return this->visible_;}
      virtual void visible(bool visible);
      
      void create_control();
      
      virtual void hide() {this->visible(false);}

      virtual void create_handle();
      
      xtd::forms::control& from_child_handle(intptr_t handle);

      xtd::forms::control& from_handle(intptr_t handle);

      virtual void on_client_size_changed(const xtd::event_args& e);
      
      virtual void on_create_control();
      
      virtual void on_handle_created(const xtd::event_args& e);
      
      virtual void on_handle_destroyed(const xtd::event_args& e);

      virtual void on_location_changed(const xtd::event_args& e);
      
      virtual void on_parent_changed(const xtd::event_args& e);
 
      virtual void on_size_changed(const xtd::event_args& e);

      virtual void on_text_changed(const xtd::event_args& e);
      
      virtual void on_visible_changed(const xtd::event_args& e);
      
      virtual void show() {this->visible(true);}
      
      virtual void wnd_proc(xtd::forms::message& message);
      
      xtd::event_handler<control> client_size_changed;
      
      xtd::event_handler<control> handle_created;
      
      xtd::event_handler<control> handle_destroyed;
      
      xtd::event_handler<control> location_changed;
      
      xtd::event_handler<control> parent_changed;
      
      xtd::event_handler<control> size_changed;
      
      xtd::event_handler<control> text_changed;
      
      xtd::event_handler<control> visible_changed;

    protected:
      void get_properties();
      xtd::drawing::size client_size_;
      intptr_t handle_ = 0;
      static std::map<intptr_t, xtd::forms::control*> handles_;
      xtd::drawing::point location_;
      control* parent_ = const_cast<control*>(&control::null);
      xtd::drawing::size size_;
      std::string text_;
      bool visible_ = true;
      
    private:
      
    };
  }
}
