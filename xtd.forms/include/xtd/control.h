#pragma once
#include <string>

namespace xtd {
  namespace forms {
    class control {
    public:
      control() {create_control();}
      
      virtual intptr_t handle() const {return this->handle_;}
      
      virtual const std::string& text() const {return this->text_;}
      virtual void text(const std::string& text);

      void create_control() {
        if (!this->handle_)
          create_handle();
      }

      virtual void create_handle();
      
      virtual void show() const;
      
    protected:
      intptr_t handle_ = 0;
      intptr_t parent_ = 0;
      std::string text_;
    };
  }
}
