#pragma once
#include "native/control_api.h"
#include <string>

namespace xtd {
  namespace forms {
    class control {
    public:
      control() {create_control();}
      
      virtual intptr_t handle() const {return this->handle_;}
      
      virtual const std::string& text() const {return this->text_;}
      virtual void text(const std::string& text) {
        if (this->text_ != text) {
          native::control_api::text(this->handle_, text);
          this->text_ = text;
        }
      }

      void create_control() {
        if (!this->handle_)
          create_handle();
      }

      virtual void create_handle() { this->handle_ = native::control_api::create(this->parent_);}

    protected:
      intptr_t handle_ = 0;
      intptr_t parent_ = 0;
      std::string text_;
    };
  }
}
