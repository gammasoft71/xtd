#pragma once
#include <string>

namespace xtd {
  namespace forms {
    class control {
    public:
      static const control null;
      control() {}
      
      virtual intptr_t handle() const {return this->handle_;}

      virtual const control& parent() const {return *this->parent_;}
      virtual void parent(const control&);

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
      control* parent_ = const_cast<control*>(&control::null);
      std::string text_;
    };
  }
}
