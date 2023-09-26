#include "../../../../include/xtd/forms/style_sheets/control"
#include "../../../../include/xtd/forms/style_sheets/style_sheet"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

bool style_sheets::control::auto_ellipsis() const noexcept {
  return auto_ellipsis_;
}

style_sheets::control& style_sheets::control::auto_ellipsis(bool value) noexcept {
  auto_ellipsis_ = value;
  return *this;
}

const drawing::color& style_sheets::control::background_color() const noexcept {
  return background_color_;
}

style_sheets::control& style_sheets::control::background_color(const drawing::color& value) noexcept {
  background_color_ = value;
  return *this;
}

const style_sheets::background_image& style_sheets::control::background_image() const noexcept {
  return background_image_;
}

style_sheets::control& style_sheets::control::background_image(const style_sheets::background_image& value) noexcept {
  background_image_ = value;
  return *this;
}

const xtd::forms::style_sheets::border_color& style_sheets::control::border_color() const noexcept {
  return border_color_;
}

style_sheets::control& style_sheets::control::border_color(const xtd::forms::style_sheets::border_color& value) noexcept {
  border_color_ = value;
  return *this;
}

xtd::forms::style_sheets::border_radius style_sheets::control::border_radius() const noexcept {
  return border_radius_;
}

style_sheets::control& style_sheets::control::border_radius(const xtd::forms::style_sheets::border_radius& value) noexcept {
  border_radius_ = value;
  return *this;
}

xtd::forms::style_sheets::border_style style_sheets::control::border_style() const noexcept {
  return border_style_;
}

style_sheets::control& style_sheets::control::border_style(xtd::forms::style_sheets::border_style value) noexcept {
  border_style_ = value;
  return *this;
}

xtd::forms::style_sheets::border_width style_sheets::control::border_width() const noexcept {
  return border_width_;
}

style_sheets::control& style_sheets::control::border_width(xtd::forms::style_sheets::border_width value) noexcept {
  border_width_ = value;
  return *this;
}

optional<length> style_sheets::control::height() const noexcept {
  return height_;
}

style_sheets::control& style_sheets::control::height(const std::optional<length>& value) noexcept {
  height_ = value;
  return *this;
}

xtd::forms::content_alignment style_sheets::control::image_alignment() const noexcept {
  return image_alignment_;
}

style_sheets::control& style_sheets::control::image_alignment(xtd::forms::content_alignment value) noexcept {
  image_alignment_ = value;
  return *this;
}

const style_sheets::margin& style_sheets::control::margin() const noexcept {
  return margin_;
}

style_sheets::control& style_sheets::control::margin(const style_sheets::margin& value) noexcept {
  margin_ = value;
  return *this;
}

const xtd::forms::style_sheets::outline_color& style_sheets::control::outline_color() const noexcept {
  return outline_color_;
}

style_sheets::control& style_sheets::control::outline_color(const xtd::forms::style_sheets::outline_color& value) noexcept {
  outline_color_ = value;
  return *this;
}

xtd::forms::style_sheets::outline_offset style_sheets::control::outline_offset() const noexcept {
  return outline_offset_;
}

style_sheets::control& style_sheets::control::outline_offset(xtd::forms::style_sheets::outline_offset value) noexcept {
  outline_offset_ = value;
  return *this;
}

xtd::forms::style_sheets::outline_radius style_sheets::control::outline_radius() const noexcept {
  return outline_radius_;
}

style_sheets::control& style_sheets::control::outline_radius(xtd::forms::style_sheets::outline_radius value) noexcept {
  outline_radius_ = value;
  return *this;
}

xtd::forms::style_sheets::outline_style style_sheets::control::outline_style() const noexcept {
  return outline_style_;
}

style_sheets::control& style_sheets::control::outline_style(xtd::forms::style_sheets::outline_style value) noexcept {
  outline_style_ = value;
  return *this;
}

xtd::forms::style_sheets::outline_width style_sheets::control::outline_width() const noexcept {
  return outline_width_;
}

style_sheets::control& style_sheets::control::outline_width(xtd::forms::style_sheets::outline_width value) noexcept {
  outline_width_ = value;
  return *this;
}

const style_sheets::padding& style_sheets::control::padding() const noexcept {
  return padding_;
}

style_sheets::control& style_sheets::control::padding(const style_sheets::padding& value) noexcept {
  padding_ = value;
  return *this;
}

xtd::forms::style_sheets::shadows style_sheets::control::shadows() const noexcept {
  return shadows_;
}

style_sheets::control& style_sheets::control::shadows(const xtd::forms::style_sheets::shadows& value) noexcept {
  shadows_ = value;
  return *this;
}

content_alignment style_sheets::control::text_alignment() const noexcept {
  return text_alignment_;
}

style_sheets::control& style_sheets::control::text_alignment(content_alignment value) noexcept {
  text_alignment_ = value;
  return *this;
}

optional<length> style_sheets::control::width() const noexcept {
  return width_;
}

style_sheets::control& style_sheets::control::width(optional<length> value) noexcept {
  width_ = value;
  return *this;
}

xtd::forms::style_sheets::white_space style_sheets::control::white_space() const noexcept {
  return white_space_;
}

style_sheets::control& style_sheets::control::white_space(xtd::forms::style_sheets::white_space value) noexcept {
  white_space_ = value;
  return *this;
}

const drawing::color& style_sheets::control::color() const noexcept {
  return color_;
}

style_sheets::control& style_sheets::control::color(const drawing::color& value) noexcept {
  color_ = value;
  return *this;
}

text_decoration style_sheets::control::decoration() const noexcept {
  return decoration_;
}

style_sheets::control& style_sheets::control::decoration(text_decoration value) noexcept {
  decoration_ = value;
  return *this;
}

text_transformation style_sheets::control::transformation() const noexcept {
  return transformation_;
}

style_sheets::control& style_sheets::control::transformation(text_transformation value) noexcept {
  transformation_ = value;
  return *this;
}

const font& style_sheets::control::font() const noexcept {
  return font_;
}

style_sheets::control& style_sheets::control::font(const drawing::font& value) noexcept {
  font_ = value;
  return *this;
}

bool style_sheets::control::equals(const style_sheets::control& other) const noexcept {
  return margin_ == other.margin_ && border_style_ == other.border_style_ && border_color_ == other.border_color_ && border_width_ == other.border_width_ && border_radius_ == other.border_radius_ && padding_ == other.padding_ && background_color_ == other.background_color_ && background_image_ == other.background_image_ && width_ == other.width_ && height_ == other.height_ && color_ == other.color_ && text_alignment_ == other.text_alignment_ && font_ == other.font_ && decoration_ == other.decoration_ && transformation_ == other.transformation_;
}

xtd::drawing::color style_sheets::control::get_solid_background_color() const noexcept {
  auto back_color = background_color();
  if (back_color == drawing::color::empty && background_image().colors().size() >= 1) back_color = background_image().colors()[0];
  if (back_color == drawing::color::empty) back_color = style_sheets::style_sheet::current_style_sheet().system_colors().button_face();
  if (back_color.a() != 255) back_color = style_sheets::style_sheet::current_style_sheet().system_colors().control();
  if (back_color.a() != 255) back_color = style_sheets::style_sheet::current_style_sheet().system_colors().window();
  return back_color;
}

rectangle style_sheets::control::get_border_rectangle(const rectangle& bounds) const noexcept {
  auto bounds_rect = bounds;
  if (width() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), margin().left().get_pixels(bounds) + (border_style().left() != border_type::none ? border_width().left().get_pixels(bounds) : 0) + padding().left().get_pixels(bounds) + width().value().get_pixels(bounds) + padding().right().get_pixels(bounds) + (border_style().right() != border_type::none ? border_width().right().get_pixels(bounds) : 0) + margin().right().get_pixels(bounds), bounds_rect.height());
  if (height() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), bounds_rect.width(), margin().top().get_pixels(bounds) + (border_style().top() != border_type::none ? border_width().top().get_pixels(bounds) : 0) + padding().top().get_pixels(bounds) + height().value().get_pixels(bounds) + padding().bottom().get_pixels(bounds) + (border_style().bottom() != border_type::none ? border_width().bottom().get_pixels(bounds) : 0) + margin().bottom().get_pixels(bounds));
  
  auto border_rect = rectangle::offset(bounds_rect, margin().left().get_pixels(bounds), margin().top().get_pixels(bounds));
  border_rect = rectangle::add(border_rect, -margin().right().get_pixels(bounds) - margin().left().get_pixels(bounds), -margin().bottom().get_pixels(bounds) - margin().top().get_pixels(bounds));
  return border_rect;
}

rectangle style_sheets::control::get_outline_rectangle(const rectangle& bounds) const noexcept {
  auto border_rect = get_border_rectangle(bounds);
  auto outline_rect = rectangle::from_ltrb(border_rect.left() - outline_offset().left().get_pixels(bounds), border_rect.top() - outline_offset().top().get_pixels(bounds), border_rect.right() + outline_offset().right().get_pixels(bounds),  border_rect.bottom() + outline_offset().bottom().get_pixels(bounds));
  outline_rect.inflate({1, 1});
  return outline_rect;
}

rectangle style_sheets::control::get_fill_rectangle(const rectangle& bounds) const noexcept {
  auto fill_rect = rectangle::offset(get_border_rectangle(bounds), (border_style().left() != border_type::none ? border_width().left().get_pixels(bounds) : 0), (border_style().top() != border_type::none ? border_width().top().get_pixels(bounds) : 0));
  fill_rect = rectangle::add(fill_rect, -(border_style().left() != border_type::none ? border_width().left().get_pixels(bounds) : 0) - (border_style().right() != border_type::none ? border_width().right().get_pixels(bounds) : 0), -(border_style().top() != border_type::none ? border_width().top().get_pixels(bounds) : 0) - (border_style().bottom() != border_type::none ? border_width().bottom().get_pixels(bounds) : 0));
  return fill_rect;
}

rectangle style_sheets::control::get_content_rectangle(const rectangle& bounds) const noexcept {
  auto content_rect = rectangle::offset(get_fill_rectangle(bounds), padding().left().get_pixels(bounds), padding().top().get_pixels(bounds));
  content_rect = rectangle::add(content_rect, -padding().left().get_pixels(bounds) - padding().right().get_pixels(bounds), -padding().top().get_pixels(bounds) - padding().bottom().get_pixels(bounds));
  return content_rect;
}

string_format style_sheets::control::control::make_string_format() const noexcept {
  auto format = string_format {};
  format.line_alignment(xtd::drawing::string_alignment::center);
  format.alignment(xtd::drawing::string_alignment::center);
  
  if (text_alignment() == content_alignment::top_left) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (text_alignment() == content_alignment::top_center) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (text_alignment() == content_alignment::top_right) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::far);
  }
  
  if (text_alignment() == content_alignment::middle_left) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (text_alignment() == content_alignment::middle_center) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (text_alignment() == content_alignment::middle_right) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::far);
  }
  
  if (text_alignment() == content_alignment::bottom_left) {
    format.line_alignment(xtd::drawing::string_alignment::far);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (text_alignment() == content_alignment::bottom_center) {
    format.line_alignment(xtd::drawing::string_alignment::far);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (text_alignment() == content_alignment::bottom_right) {
    format.alignment(xtd::drawing::string_alignment::far);
    format.line_alignment(xtd::drawing::string_alignment::far);
  }
  
  if (white_space() == xtd::forms::style_sheets::white_space::no_wrap)
    format.format_flags(format.format_flags() | xtd::drawing::string_format_flags::no_wrap);
    
  format.hotkey_prefix(xtd::drawing::text::hotkey_prefix::hide);
  if (auto_ellipsis()) {
    format.trimming(xtd::drawing::string_trimming::ellipsis_character);
    format.format_flags(format.format_flags() | xtd::drawing::string_format_flags::no_wrap);
  }
  
  return format;
}
