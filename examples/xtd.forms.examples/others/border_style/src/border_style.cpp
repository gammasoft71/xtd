#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Border style example");
      client_size({700, 400});
      maximum_client_size(client_size());
      minimum_client_size(client_size());

      colored_panel.parent(*this);
      colored_panel.border_style(forms::border_style::fixed_3d);
      colored_panel.dock(dock_style::fill);

      label_with_none_border.border_style(forms::border_style::none).text_align(content_alignment::middle_center).text("none").location({20, 20}).size({150, 50}).parent(colored_panel);
      label_with_fixed_single_border.border_style(forms::border_style::fixed_single).text_align(content_alignment::middle_center).text("fixed_single").location({190, 20}).size({150, 50}).parent(colored_panel);
      label_with_thin_sunken_border.border_style(forms::border_style::thin_sunken).text_align(content_alignment::middle_center).text("thin_sunken /\nfixed_3d").location({360, 20}).size({150, 50}).parent(colored_panel);
      label_with_thin_raised_border.border_style(forms::border_style::thin_raised).text_align(content_alignment::middle_center).text("thin_raised").location({530, 20}).size({150, 50}).parent(colored_panel);
      label_with_bevel_sunken_border.border_style(forms::border_style::bevel_sunken).text_align(content_alignment::middle_center).text("bevel_sunken").location({20, 90}).size({150, 50}).parent(colored_panel);
      label_with_bevel_raised_border.border_style(forms::border_style::bevel_raised).text_align(content_alignment::middle_center).text("bevel_raised").location({190, 90}).size({150, 50}).parent(colored_panel);
      label_with_etched_border.border_style(forms::border_style::etched).text_align(content_alignment::middle_center).text("etched").location({360, 90}).size({150, 50}).parent(colored_panel);
      label_with_bump_border.border_style(forms::border_style::bump).text_align(content_alignment::middle_center).text("bump").location({530, 90}).size({150, 50}).parent(colored_panel);
      label_with_themed_border.border_style(forms::border_style::themed).text_align(content_alignment::middle_center).text("themed").location({20, 160}).size({150, 50}).parent(colored_panel);
      label_with_rounded_single_border.border_style(forms::border_style::rounded_single).text_align(content_alignment::middle_center).text("rounded_single").location({190, 160}).size({150, 50}).parent(colored_panel);
      label_with_dot_single_border.border_style(forms::border_style::dot_single).text_align(content_alignment::middle_center).text("dot_single").location({360, 160}).size({150, 50}).parent(colored_panel);
      label_with_dash_single_border.border_style(forms::border_style::dash_single).text_align(content_alignment::middle_center).text("dash_single").location({530, 160}).size({150, 50}).parent(colored_panel);
      label_with_dash_dot_single_border.border_style(forms::border_style::dash_dot_single).text_align(content_alignment::middle_center).text("dash_dot_single").location({20, 230}).size({150, 50}).parent(colored_panel);
      label_with_dash_dot_dot_single_border.border_style(forms::border_style::dash_dot_dot_single).text_align(content_alignment::middle_center).text("dash_dot_dot_single").location({190, 230}).size({150, 50}).parent(colored_panel);
      label_with_fixed_double_border.border_style(forms::border_style::fixed_double).text_align(content_alignment::middle_center).text("fixed_double").location({360, 230}).size({150, 50}).parent(colored_panel);

      control_panel.parent(*this);
      control_panel.border_style(forms::border_style::fixed_3d);
      control_panel.dock(dock_style::bottom);
      
      choose_color_label.parent(control_panel);
      choose_color_label.location({20, 37});
      choose_color_label.text("Choose color");

      colors.parent(control_panel);
      for (drawing::color color : colors::get_colors())
        colors.items().push_back({color.name(), color});
      colors.items()[0] = {back_color().name(), back_color()};
      colors.location({120, 35});
      colors.width(200);
      colors.selected_index_changed += [&] {
        auto color = as<drawing::color>(colors.selected_item().tag());
        colored_panel.back_color(color);
        colored_panel.fore_color(color.is_dark() ? control_paint::light(color, 2.0/3) : control_paint::dark(color, 2.0/3));
        lightness_label.text(ustring::format(("ligthness = {}"), color.get_lightness()));
      };
      colors.selected_index(0);
      
      lightness_label.parent(control_panel);
      lightness_label.auto_size(true);
      lightness_label.location({360, 37});
      lightness_label.text(ustring::format(("ligthness = {}"), colored_panel.back_color().get_lightness()));
    }
    
  private:
    panel colored_panel;
    label label_with_none_border;
    label label_with_fixed_single_border;
    label label_with_thin_sunken_border;
    label label_with_thin_raised_border;
    label label_with_bevel_sunken_border;
    label label_with_bevel_raised_border;
    label label_with_etched_border;
    label label_with_bump_border;
    label label_with_themed_border;
    label label_with_rounded_single_border;
    label label_with_dot_single_border;
    label label_with_dash_single_border;
    label label_with_dash_dot_single_border;
    label label_with_dash_dot_dot_single_border;
    label label_with_fixed_double_border;
    panel control_panel;
    label choose_color_label;
    choice colors;
    label lightness_label;
  };
}

int main() {
  application::run(examples::form1());
}
