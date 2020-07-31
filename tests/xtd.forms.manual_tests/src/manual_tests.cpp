#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

void on_menu_click(component& sender, const event_args& e) {
  cdebug << format("Clik on menu item : {}", static_cast<menu_item&>(sender).text()) << endl;
}

namespace xtd {
  namespace forms {
    class split_container;

    class splitter_panel : public xtd::forms::panel {
      friend class split_container;
      
    private:
      splitter_panel()  = default;
    };

    enum class splitter_style {
      draw_line = 0,
      update_childs = 1
    };

    class splitter : public xtd::forms::control {
    public:
      splitter() {
        size_ = default_size();
        dock(xtd::forms::dock_style::left);
      }

      using xtd::forms::control::dock;
      virtual control& dock(dock_style dock) override {
        if (control::dock() != dock_style::left && control::dock() == dock_style::right && control::dock() == dock_style::top && control::dock() == dock_style::bottom) throw std::invalid_argument("splitter control must be docked left, right, top, or bottom.");
        control::dock(dock);
        cursor(default_cursor());
        return *this;
      }
      
      virtual int min_size() const {return min_size_;}
      virtual splitter& min_size(int min_size) {
        if (min_size_ != min_size) {
          min_size_ = min_size;
        }
        return *this;
      }

      virtual xtd::forms::splitter_style splitter_style() const {return splitter_style_;}
      virtual splitter& splitter_style(xtd::forms::splitter_style splitter_style) {
        if (splitter_style_ != splitter_style) {
          splitter_style_ = splitter_style;
        }
        return *this;
      }

      /// @brief Gets the default cusros of the control.
      /// @return A cursor that represents the default cursor of the control.
      forms::cursor default_cursor() const override {return dock_ == dock_style::left || dock_ == dock_style::right ? xtd::forms::cursors::vsplit() : xtd::forms::cursors::hsplit();}

      /// @brief Gets the default size of the control.
      /// @return A size that represents the default size of the control.
      drawing::size default_size() const override {return {3, 3};}
      
    protected:
      void on_mouse_down(const mouse_event_args& e) override {
        control::on_mouse_down(e);
        mouse_down_location = control::dock() == dock_style::left || control::dock() == dock_style::right ? cursor::position().x() : cursor::position().y();
        if (parent().has_value()) {
          for(size_t index = 0; index < parent().value().get().controls().size(); index++) {
            if (parent().value().get().controls()[index].get() == *this) {
              if (index > 0) previous_control_cursor_ = (previous_control_ = &parent().value().get().controls()[index - 1].get())->cursor();
              if (index < parent().value().get().controls().size() -1) next_control_cursor_ = (next_control_ = &parent().value().get().controls()[index + 1].get())->cursor();
              break;
            }
          }
        }
        if (previous_control_) previous_control_->cursor(default_cursor());
        if (next_control_) next_control_->cursor(default_cursor());
      }
      
      void on_mouse_move(const mouse_event_args& e) override {
        control::on_mouse_move(e);
        if (previous_control_) previous_control_->cursor(default_cursor());
        if (next_control_) next_control_->cursor(default_cursor());
        if (mouse_down_location != -1 && next_control_) {
          if (splitter_style_ == splitter_style::draw_line) {
            
          } else {
            int new_size = (control::dock() == dock_style::left || control::dock() == dock_style::right ? (next_control_->width() + cursor::position().x()) : (next_control_->height() + cursor::position().y())) - mouse_down_location;
            if (new_size < min_size_) new_size = min_size_;
            if (control::dock() == dock_style::left || control::dock() == dock_style::right) next_control_->width(new_size);
            else next_control_->height(new_size);
            mouse_down_location = control::dock() == dock_style::left || control::dock() == dock_style::right ? cursor::position().x() : cursor::position().y();
          }
        }
      }

      void on_mouse_up(const mouse_event_args& e) override {
        control::on_mouse_up(e);
        if (previous_control_) previous_control_->cursor(previous_control_cursor_);
        if (next_control_) next_control_->cursor(previous_control_cursor_);
        if (mouse_down_location != -1 && parent().has_value() && next_control_) {
          int new_size = (control::dock() == dock_style::left || control::dock() == dock_style::right ? (next_control_->width() + cursor::position().x()) : (next_control_->height() + cursor::position().y())) - mouse_down_location;
          if (new_size < min_size_) new_size = min_size_;
          if (control::dock() == dock_style::left || control::dock() == dock_style::right) next_control_->width(new_size);
          else next_control_->height(new_size);
          mouse_down_location = -1;
        }
        previous_control_ = nullptr;
        next_control_ = nullptr;
      }
      
      void on_handle_created(const event_args& e) override {
        control::on_handle_created(e);
        parent().value().get().mouse_move +=  [&] {
          cdebug << "Mouse move..." << endl;
        };

      }
      
    private:
      int min_size_ = 25;
      //int min_size_extra = 25;
      //int split_position_ = -1;
      int mouse_down_location = -1;
      xtd::forms::splitter_style splitter_style_ = xtd::forms::splitter_style::update_childs;
      xtd::forms::cursor previous_control_cursor_;
      xtd::forms::cursor next_control_cursor_;
      control* previous_control_ = nullptr;
      control* next_control_ = nullptr;
    };

    class split_container : public  xtd::forms::scrollable_control {
    public:
      split_container() {
        can_focus_ = false;
        size_ = default_size();
        controls().push_back_range({panel2_, splitter_, panel1_});
        arrange_childs();
      }

      drawing::size default_size() const override {return {150, 100};}

      virtual int splitter_distance() const {return splitter_distance_;}
      
      virtual xtd::forms::orientation orientation() const {return orientation_;}
      virtual split_container& orientation(xtd::forms::orientation orientation) {
        if (orientation_ != orientation) {
          orientation_ = orientation;
          arrange_childs();
        }
        return *this;
      }
      
      virtual xtd::forms::splitter_style splitter_style() const {return splitter_.splitter_style();}
      virtual split_container& splitter_style(xtd::forms::splitter_style splitter_style) {
        if (splitter_.splitter_style() != splitter_style) {
          splitter_.splitter_style(splitter_style);
        }
        return *this;
      }
      
      virtual int splitter_width() const {return splitter_width_;}
      virtual split_container& splitter_width(int splitter_width) {
        if (splitter_width_ != splitter_width) {
          splitter_width_ = splitter_width;
          arrange_childs();
        }
        return *this;
      }

      virtual const splitter_panel& panel1() const {return panel1_;};
      virtual splitter_panel& panel1() {return panel1_;};
      virtual const splitter_panel& panel2() const {return panel2_;};
      virtual splitter_panel& panel2() {return panel2_;};

    protected:
      void on_resize(const event_args& e) override {
        xtd::forms::scrollable_control::on_resize(e);
      }

    private:
      void arrange_childs() {
        if (orientation_ == xtd::forms::orientation::vertical) {
          panel1_.dock(xtd::forms::dock_style::left);
          panel1_.width(splitter_distance_);
          splitter_.dock(xtd::forms::dock_style::left);
          splitter_.width(splitter_width_);
        } else {
          panel1_.dock(xtd::forms::dock_style::top);
          panel1_.height(splitter_distance_);
          splitter_.dock(xtd::forms::dock_style::top);
          splitter_.height(splitter_width_);
        }
        panel2_.dock(xtd::forms::dock_style::fill);
      }
      
      xtd::forms::orientation orientation_ = xtd::forms::orientation::vertical;
      splitter_panel panel1_;
      splitter splitter_;
      splitter_panel panel2_;
      int splitter_distance_ = 50;
      //int splitter_increment_ = 1;
      int splitter_width_ = 4;
    };
  }
}

int main() {
  /*
  main_menu menu;
  menu.menu_items().push_back("&File");
  menu.menu_items().push_back("&Edit");
  menu.menu_items().push_back("&View");
  menu.menu_items().push_back("&Window");
  menu.menu_items().push_back("&Help");
   */

  form form_main;
  form_main.text("Manual tests");
  //form_main.menu(menu);
  form_main.menu(forms::main_menu::create_standard_items([&](component& sender, const event_args& e) {
    cdebug << format("Clik on menu item : {}", static_cast<menu_item&>(sender).text()) << endl;
  }));
  //form_main.menu(nullptr);
  
  /*
  split_container splitter;
  splitter.parent(form_main);
  splitter.location({10, 10});
  //splitter.dock(dock_style::fill);
  //splitter.splitter_style(xtd::forms::splitter_style::update_childs);
  //splitter.orientation(xtd::forms::orientation::horzontal);
  splitter.splitter_width(1);
  
  splitter.panel1().border_style(forms::border_style::fixed_3d);
  splitter.panel2().border_style(forms::border_style::fixed_3d);
   */
  
  panel panel1;
  panel1.dock(dock_style::top);
  panel1.border_style(forms::border_style::fixed_3d);
  //panel1.width(50);

  splitter splitter;
  splitter.dock(dock_style::top);
  splitter.min_size(0);
  
  panel panel2;
  panel2.dock(dock_style::fill);
  panel2.border_style(forms::border_style::fixed_3d);

  form_main.controls().push_back_range({panel2, splitter, panel1});
  
  application::enable_menu_images();
  application::run(form_main);
}
