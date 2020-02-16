#include <xtd/xtd.forms>

namespace test_forms {
  namespace properties {
    class settings : public xtd::forms::component {
    public:
      settings() : settings(true) {}
      static settings& default_settings() {
        static settings default_settings;
        return default_settings;
      }
      
      xtd::drawing::color back_color() const {return back_color_;}
      void back_color(const xtd::drawing::color& back_color) {back_color_ = back_color;}
      
      xtd::drawing::point location() const {return location_;}
      void location(const xtd::drawing::point& location) {location_ = location;}
      
      xtd::drawing::size size() const {return size_;}
      void size(const xtd::drawing::size& size) {size_ = size;}

      std::string text() const {return "Settings2 example";}

      void reload() {
        back_color_ = settings_.read("back_color", back_color_);
        location_ = settings_.read("location", location_);
        size_ = settings_.read("size", size_);
      }
      
      void reset() {
        settings_.reset();
        *this = settings(false);
        reload();
      }
      
      void save() {
        settings_.write("back_color", back_color_);
        settings_.write("location", location_);
        settings_.write("size", size_);
        settings_.save();
      }
      
    private:
      settings(bool load) {if (load) reload();}
      xtd::forms::settings settings_;
      xtd::drawing::color back_color_ {xtd::drawing::system_colors::control()};
      xtd::drawing::point location_ {100, 50};
      xtd::drawing::size size_ {360, 80};
    };
  }
}

