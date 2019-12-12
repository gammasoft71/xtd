#include <vector>
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  enum class operation_status {
    none,
    running,
    succeed,
    failed
  };

  class operation : public user_control {
  public:
    operation() {this->size_ = default_size();}
    
    operation_status status() const {return status_;}
    void status(operation_status status) {
      if (status_ != status) {
        status_ = status;
        invalidate();
      }
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      user_control::on_paint(e);
      e.graphics().fill_rectangle(solid_brush(system_colors::control()), 1, 1, 28, 28);
      switch (this->status()) {
        case operation_status::none: break;
        case operation_status::running: e.graphics().draw_string(u8"☞", drawing::font(default_font().name(), 18, font_style::italic), solid_brush(color::medium_purple), 0, 0); break;
        case operation_status::succeed: e.graphics().draw_string(u8"√", drawing::font(default_font().name(), 18, font_style::italic), solid_brush(color::green), 2, 0); break;
        case operation_status::failed: e.graphics().draw_string(u8"X", drawing::font(default_font().name(), 18, font_style::italic), solid_brush(color::red), 5, 0); break;
      }
      e.graphics().draw_line(pen(color::dark_gray), point(1, 1), point(28, 1));
      e.graphics().draw_line(pen(color::dark_gray), point(1, 1), point(1, 28));
      e.graphics().draw_line(pen(color::white), point(1, 28), point(28, 28));
      e.graphics().draw_line(pen(color::white), point(28, 1), point(28, 28));
      e.graphics().draw_string(this->text(), default_font(), solid_brush(system_colors::control_text()), 35, 5);
    }

    drawing::size default_size() const override {return {150, 30};}

  private:
    operation_status status_ = operation_status::none;
  };
    
  class form1 : public form {
  public:
    form1() {
      text("User control example");

      operations[0].parent(*this);
      operations[0].status(operation_status::succeed);
      operations[0].text("First operation");
      operations[0].location({5, 5});
      operations[0].click += {*this, &form1::on_operation_click};
      
      operations[1].parent(*this);
      operations[1].status(operation_status::failed);
      operations[1].text("Second operation");
      operations[1].location({5, 35});
      operations[1].click += {*this, &form1::on_operation_click};

      operations[2].parent(*this);
      operations[2].status(operation_status::running);
      operations[2].text("Third operation");
      operations[2].location({5, 65});
      operations[2].click += {*this, &form1::on_operation_click};

      operations[3].parent(*this);
      operations[3].status(operation_status::none);
      operations[3].text("Fourth operation");
      operations[3].location({5, 95});
      operations[3].click += {*this, &form1::on_operation_click};

      operations[4].parent(*this);
      operations[4].status(operation_status::none);
      operations[4].text("Fifth operation");
      operations[4].location({5, 125});
      operations[4].click += {*this, &form1::on_operation_click};
    }
    
  private:
    void on_operation_click(control& sender, const event_args& e) {
      examples::operation& operation = static_cast<examples::operation&>(sender);
      switch (operation.status()) {
        case operation_status::none: operation.status(operation_status::running); break;
        case operation_status::running: operation.status(operation_status::succeed); break;
        case operation_status::succeed: operation.status(operation_status::failed); break;
        case operation_status::failed: operation.status(operation_status::none); break;
      }
    }

    vector<operation> operations {5};
  };
}

int main() {
  application::run(examples::form1());
}
