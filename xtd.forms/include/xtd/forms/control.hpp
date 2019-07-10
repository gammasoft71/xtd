#pragma once
#include <functional>
#include <map>
#include <string>
#include <xtd/event_args.hpp>
#include <xtd/event_handler.hpp>
#include <xtd/point.hpp>
#include <xtd/size.hpp>

#include "mouse_event_handler.hpp"
#include "message.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class control {
    private:
      enum class state {
        empty = 0,
        double_click_fired = 0b1,
        mouse_entered = 0x10,
      };
    public:
      static const control null;
      
      control() = default;
      
      virtual ~control();

      virtual xtd::drawing::size client_size() const {return this->client_size_;}
      virtual void client_size(const xtd::drawing::size& size);

      virtual xtd::drawing::size default_size() const {return{0, 0};}

      virtual intptr_t handle() const;
      
      virtual int height() const {return this->size_.height();}
      virtual void height(int height) {this->size({this->size_.width(), height});}
      
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

      virtual int width() const {return this->size_.width();}
      virtual void width(int width) {this->size({width, this->size_.height()});}
      
      virtual int x() const {return this->location_.x();}
      virtual void x(int x) {this->size({x, this->location_.y()});}
      
      virtual int y() const {return this->location_.y();}
      virtual void y(int y) {this->size({this->location_.x(), y});}
      
      void create_control();
      
      virtual void hide() {this->visible(false);}

      virtual void create_handle();
      
      xtd::forms::control& from_child_handle(intptr_t handle);

      xtd::forms::control& from_handle(intptr_t handle);
      
      bool is_null() const;
      
      virtual void on_click(const xtd::event_args& e);

      virtual void on_client_size_changed(const xtd::event_args& e);

      virtual void on_create_control();

      virtual void on_double_click(const xtd::event_args& e);
      
      virtual void on_got_focus(const xtd::event_args& e);
      
      virtual void on_handle_created(const xtd::event_args& e);
      
      virtual void on_handle_destroyed(const xtd::event_args& e);

      virtual void on_location_changed(const xtd::event_args& e);
      
      virtual void on_lost_focus(const xtd::event_args& e);
      
      virtual void on_mouse_click(const xtd::forms::mouse_event_args& e);
      
      virtual void on_mouse_double_click(const xtd::forms::mouse_event_args& e);

      virtual void on_mouse_down(const xtd::forms::mouse_event_args& e);

      virtual void on_mouse_enter(const xtd::event_args& e);
      
      virtual void on_mouse_leave(const xtd::event_args& e);
      
      virtual void on_mouse_move(const xtd::forms::mouse_event_args& e);

      virtual void on_mouse_up(const xtd::forms::mouse_event_args& e);

      virtual void on_mouse_wheel(const xtd::forms::mouse_event_args& e);

      virtual void on_parent_changed(const xtd::event_args& e);
 
      virtual void on_size_changed(const xtd::event_args& e);

      virtual void on_text_changed(const xtd::event_args& e);
      
      virtual void on_visible_changed(const xtd::event_args& e);
      
      intptr_t send_message(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam);
      
      virtual void show() {this->visible(true);}
      
      virtual void wnd_proc(xtd::forms::message& message);
      
      xtd::event_handler<control> click;
      
      xtd::event_handler<control> client_size_changed;
      
      xtd::event_handler<control> double_click;

      xtd::event_handler<control> got_focus;
      
      xtd::event_handler<control> handle_created;
      
      xtd::event_handler<control> handle_destroyed;
      
      xtd::event_handler<control> location_changed;
      
      xtd::event_handler<control> lost_focus;
      
      xtd::forms::mouse_event_handler<control> mouse_click;
      
      xtd::forms::mouse_event_handler<control> mouse_double_click;
      
      xtd::forms::mouse_event_handler<control> mouse_down;
      
      xtd::event_handler<control> mouse_enter;
      
      xtd::event_handler<control> mouse_leave;
      
      xtd::forms::mouse_event_handler<control> mouse_move;
      
      xtd::forms::mouse_event_handler<control> mouse_up;
      
      xtd::forms::mouse_event_handler<control> mouse_wheel;
      
      xtd::event_handler<control> parent_changed;
      
      xtd::event_handler<control> size_changed;
      
      xtd::event_handler<control> text_changed;
      
      xtd::event_handler<control> visible_changed;

      intptr_t __get_handle__() const {return this->handle_;}
      
    protected:
      virtual void def_wnd_proc(xtd::forms::message& message);
      
      void get_properties();
      void set_properties();
      xtd::drawing::size client_size_ {-1, -1};
      intptr_t handle_ = 0;
      static std::map<intptr_t, xtd::forms::control*> handles_;
      xtd::drawing::point location_ {-1, -1};
      control* parent_ = const_cast<control*>(&control::null);
      xtd::drawing::size size_ {-1, -1};
      std::string text_;
      bool visible_ = true;
      xtd::forms::control::state state_ = state::empty;
      
    private:
      bool get_state(xtd::forms::control::state flag) const {return ((int)this->state_ & (int)flag) == (int)flag;}
      void set_state(xtd::forms::control::state flag, bool value) { this->state_ = value ? (xtd::forms::control::state)((int)this->state_ | (int)flag) : (xtd::forms::control::state)((int)this->state_ & ~(int)flag); }
      void wm_kill_focus(xtd::forms::message& message);
      void wm_mouse_down(xtd::forms::message& message);
      void wm_mouse_double_click(xtd::forms::message& message);
      void wm_mouse_enter(xtd::forms::message& message);
      void wm_mouse_leave(xtd::forms::message& message);
      void wm_mouse_up(xtd::forms::message& message);
      void wm_mouse_move(xtd::forms::message& message);
      void wm_set_focus(xtd::forms::message& message);
      void wm_mouse_wheel(xtd::forms::message& message);
    };
  }
}
