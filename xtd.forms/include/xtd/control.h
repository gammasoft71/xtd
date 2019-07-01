#pragma once
#include <string>
#include <xtd/event_args.hpp>
#include <xtd/event_handler.hpp>
#include <xtd/point.h>
#include <xtd/size.h>

namespace xtd {
  namespace forms {
    class control {
    public:
      static const control null;
      
      control() {}
      
      virtual intptr_t handle() const {return this->handle_;}
      
      virtual xtd::drawing::point location() const {return this->location_;}
      virtual void location(const xtd::drawing::point& location);

      virtual const control& parent() const {return *this->parent_;}
      virtual void parent(const control& parent);

      virtual const std::string& text() const {return this->text_;}
      virtual void text(const std::string& text);

      void create_control() {
        if (!this->handle_)
          create_handle();
      }

      virtual void create_handle();
      
      virtual void on_create_control();
      
      virtual void on_handle_created(const xtd::event_args& e);
      
      virtual void on_handle_destroyed(const xtd::event_args& e);

      virtual void on_location_changed(const xtd::event_args& e);
      
      virtual void on_parent_changed(const xtd::event_args& e);
      
      virtual void on_text_changed(const xtd::event_args& e);
      
      virtual void on_visible_changed(const xtd::event_args& e);
      
      virtual void show();
      
      xtd::event_handler<control> handle_created;
      xtd::event_handler<control> handle_destroyed;
      xtd::event_handler<control> location_changed;
      xtd::event_handler<control> parent_changed;
      xtd::event_handler<control> text_changed;
      xtd::event_handler<control> visible_changed;

    protected:
      intptr_t handle_ = 0;
      xtd::drawing::point location_;
      control* parent_ = const_cast<control*>(&control::null);
      std::string text_;
      xtd::drawing::size size_;
      bool visible_ = true;
    };
  }
}
