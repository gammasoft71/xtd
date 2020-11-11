#pragma once

#include <cstdint>
#include <memory>
#include <set>
#include <thread>
#include <xtd/xtd.delegates>
#include <xtd/xtd.diagnostics>
#include <xtd/forms/window_messages.hpp>
#include <xtd/forms/native/message_keys.hpp>
#include <xtd/forms/native/scroll_bar_styles.hpp>
#include <xtd/forms/native/virtual_keys.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>

namespace xtd {
  namespace forms {
    namespace native {
      class control_handler;
      
      template<typename TControl>
      class control_wrapper : public TControl {
      public:
       template<typename ...args_type>
        control_wrapper(control_handler* event_handler, args_type&& ...args) : TControl(args...), event_handler_(event_handler) {}
        
        
        virtual int32_t handle(int32_t event);
        
      private:
        intptr_t convert_to_virtual_key(intptr_t fl_key) {
          return fl_key;
        }
                
        control_handler* event_handler_;
        bool process_result_ = true;
        int32_t height_ = 0;
        int32_t width_ = 0;
      };
      
      class control_handler {
      public:
        control_handler() = default;
        virtual ~control_handler() {}

        template<typename control_type, typename ...args_type>
        void create(args_type&& ...args) {
          this->control_ = new control_wrapper<control_type>(this, args...);
          this->control_->user_data(this);
        }
        
        Fl_Widget* control() const {return this->control_;}
        void clear_control() {this->control_ = nullptr;}
        
        Fl_Cursor cursor() const {return this->cursor_;}
        void cursor(Fl_Cursor cursor) {this->cursor_ = cursor;}
        
        intptr_t call_def_wnd_proc(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle) {return this->def_wnd_proc(hwnd, msg, wparam, lparam, result, handle);}

        void destroy() {
          delete this->control_;
          this->control_ = nullptr;
          //this->def_wnd_proc -= {static_cast<control_wrapper<control_type>&>(*this->control_), &control_wrapper<control_type>::def_wnd_proc};
        }
        
        intptr_t send_message(intptr_t hwnd, intptr_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
          if (this->control_ == nullptr) return 0;
          //if (fl_application::message_filter(hwnd, msg, wparam, lparam, handle)) return this->call_def_wnd_proc(hwnd, msg, wparam, lparam, 1, handle);
          if (this->wnd_proc.is_empty()) return this->call_def_wnd_proc(hwnd, msg, wparam, lparam, 0, handle);

          //return this->wnd_proc(hwnd, msg, wparam, lparam, handle);
          intptr_t result = 0;
          for (auto& fct : this->wnd_proc.functions())
            if (this->control_ != nullptr && fct != nullptr) result = fct(hwnd, msg, wparam, lparam, handle);
          return result;
        }

        event<control_handler, delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>> wnd_proc;
        event<control_handler, delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t, intptr_t)>> def_wnd_proc;
        
      private:
        Fl_Widget* control_ = nullptr;
        Fl_Cursor cursor_ = FL_CURSOR_DEFAULT;
      };
    
      template<typename control_t>
      inline int32_t control_wrapper<control_t>::handle(int32_t event) {
        return this->control_t::handle(event);
        /*
        bool intercepted_event = this->control_t::handle(event) != 0;
        if (this->w() != this->width_ || this->h() != this->height_) {
          this->width_ = this->w();
          this->height_ = this->h();
          //this->event_handler_->send_message(...);
        }

        switch (event) {
          case FL_NO_EVENT: break;
          case FL_PUSH: break;
          case FL_RELEASE: break;
          case FL_ENTER: break;
          case FL_LEAVE: break;
          case FL_DRAG: break;
          case FL_FOCUS: break;
          case FL_UNFOCUS: break;
          case FL_KEYDOWN: break;
          case FL_KEYUP: break;
          case FL_CLOSE: break;
          case FL_MOVE: break;
          case FL_SHORTCUT: break;
          case FL_DEACTIVATE: break;
          case FL_ACTIVATE: break;
          case FL_HIDE: break;
          case FL_SHOW: break;
          case FL_PASTE: break;
          case FL_SELECTIONCLEAR: break;
          case FL_MOUSEWHEEL: break;
          case FL_DND_ENTER: break;
          case FL_DND_DRAG: break;
          case FL_DND_LEAVE: break;
          case FL_DND_RELEASE: break;
          case FL_SCREEN_CONFIGURATION_CHANGED: break;
          case FL_FULLSCREEN: break;
          default: cdebug << format("Event {} unknown !!!", event) << std::endl;
        }

        return intercepted_event;
        */
      }
    }
  }
}

