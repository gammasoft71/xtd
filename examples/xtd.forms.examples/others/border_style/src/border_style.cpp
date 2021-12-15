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

      label1.border_style(forms::border_style::none).text_align(content_alignment::middle_center).text(ustring::format("{}", label1.border_style())).location({20, 20}).size({150, 50}).parent(colored_panel);
      label2.border_style(forms::border_style::fixed_single).text_align(content_alignment::middle_center).text(ustring::format("{}", label2.border_style())).location({190, 20}).size({150, 50}).parent(colored_panel);
      label3.border_style(forms::border_style::thin_sunken).text_align(content_alignment::middle_center).text(ustring::format("{} /\nfixed_3d", label3.border_style())).location({360, 20}).size({150, 50}).parent(colored_panel);
      label4.border_style(forms::border_style::thin_raised).text_align(content_alignment::middle_center).text(ustring::format("{}", label4.border_style())).location({530, 20}).size({150, 50}).parent(colored_panel);
      label5.border_style(forms::border_style::bevel_sunken).text_align(content_alignment::middle_center).text(ustring::format("{}", label5.border_style())).location({20, 90}).size({150, 50}).parent(colored_panel);
      label6.border_style(forms::border_style::bevel_raised).text_align(content_alignment::middle_center).text(ustring::format("{}", label6.border_style())).location({190, 90}).size({150, 50}).parent(colored_panel);
      label7.border_style(forms::border_style::etched).text_align(content_alignment::middle_center).text(ustring::format("{}", label7.border_style())).location({360, 90}).size({150, 50}).parent(colored_panel);
      label8.border_style(forms::border_style::bump).text_align(content_alignment::middle_center).text(ustring::format("{}", label8.border_style())).location({530, 90}).size({150, 50}).parent(colored_panel);
      label9.border_style(forms::border_style::themed).text_align(content_alignment::middle_center).text(ustring::format("{}", label9.border_style())).location({20, 160}).size({150, 50}).parent(colored_panel);
      label10.border_style(forms::border_style::rounded_single).text_align(content_alignment::middle_center).text(ustring::format("{}", label10.border_style())).location({190, 160}).size({150, 50}).parent(colored_panel);
      label11.border_style(forms::border_style::dot_single).text_align(content_alignment::middle_center).text(ustring::format("{}", label11.border_style())).location({360, 160}).size({150, 50}).parent(colored_panel);
      label12.border_style(forms::border_style::dash_single).text_align(content_alignment::middle_center).text(ustring::format("{}", label12.border_style())).location({530, 160}).size({150, 50}).parent(colored_panel);
      label13.border_style(forms::border_style::dash_dot_single).text_align(content_alignment::middle_center).text(ustring::format("{}", label13.border_style())).location({20, 230}).size({150, 50}).parent(colored_panel);
      label14.border_style(forms::border_style::dash_dot_dot_single).text_align(content_alignment::middle_center).text(ustring::format("{}", label14.border_style())).location({190, 230}).size({150, 50}).parent(colored_panel);
      label15.border_style(forms::border_style::fixed_double).text_align(content_alignment::middle_center).text(ustring::format("{}", label15.border_style())).location({360, 230}).size({150, 50}).parent(colored_panel);

      control_panel.parent(*this);
      control_panel.border_style(forms::border_style::fixed_3d);
      control_panel.dock(dock_style::bottom);
      
      choose_color_label.parent(control_panel);
      choose_color_label.location({20, 37});
      choose_color_label.text("Choose color");

      colors.parent(control_panel);
      for (drawing::color color : colors::get_colors())
        colors.items().push_back({color.name(), color});
      colors.items()[0] = {back_color().name(), back_color()}; // Replace transparent color by control color.
      colors.location({120, 35});
      colors.width(200);
      colors.selected_index_changed += [&] {
        auto color = as<drawing::color>(colors.selected_item().tag());
        colored_panel.back_color(color);
        colored_panel.fore_color(color.is_dark() ? control_paint::light(color, 2.0/3) : control_paint::dark(color, 2.0/3));
      };
      colors.selected_index(0);
    }
    
  private:
    panel colored_panel;
    label label1;
    label label2;
    label label3;
    label label4;
    label label5;
    label label6;
    label label7;
    label label8;
    label label9;
    label label10;
    label label11;
    label label12;
    label label13;
    label label14;
    label label15;
    panel control_panel;
    label choose_color_label;
    choice colors;
  };
}

int main() {
  application::run(examples::form1());
}
