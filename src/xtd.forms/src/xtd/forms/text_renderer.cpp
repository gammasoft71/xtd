#include "../../../include/xtd/forms/text_renderer.h"
#include <xtd/drawing/string_format.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

void text_renderer::draw_text(xtd::drawing::graphics& g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const text_data& data) {
  //std::vector<size_t> hotkey_prefix_locations;
  //xtd::ustring text_without_hotkey_prefix = get_hotkey_prefix_locations(text, hotkey_prefix_locations);
  //if ((text_format & xtd::forms::text_format_flags::prefix_only) == xtd::forms::text_format_flags::prefix_only && hotkey_prefix_locations.size()) g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[0], 1), xtd::drawing::font(font, xtd::drawing::font_style::underline), xtd::drawing::solid_brush(text_color), button_rect, control_paint::string_format(text_format));
  //else g.draw_string(text, font, xtd::drawing::solid_brush(text_color), button_rect, xtd::forms::control_paint::string_format(text_format));
  g.draw_string(text, data.font(), color_property::make_brush(data.color()), bounds, text_data::make_string_format(data));
}

xtd::ustring text_renderer::get_hotkey_prefix_locations(const xtd::ustring& str, std::vector<size_t>& locations) {
  auto offset = 0U;
  for (auto index = 0U; index < str.size(); index++) {
    if (str[index] == '&' && str[index + 1] != '&')
      locations.push_back(index + offset);
    else if (str[index] == '&' && str[index + 1] == '&') {
      offset -= 2;
      ++index;
    }
  }
  auto new_str = str.replace("&&", "&");
  for (auto index = 0U; index < locations.size(); ++index)
    new_str = new_str.remove(locations[index], 1);
  return new_str;
}
