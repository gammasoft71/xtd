/// @file
/// @brief Contains cursors appearances page.

/// @page CursorsAppearancesPage Cursors appearances
/// @brief Contains cursors appearances.
///
/// Shows xtd::forms::cursors appearance on Windows, Linux Gnome and macOS Operating Systems.
///
/// | Name                       | Value                                  | Windows                             | Linux Gnome                         | macOS                               |
/// |----------------------------|----------------------------------------|-------------------------------------|-------------------------------------|-------------------------------------|
/// | Application starting       | xtd::forms::cursors::app_starting      | @image html app_starting_w.png      | @image html app_starting_g.png      | @image html app_starting_m.png      |
/// | Arrow                      | xtd::forms::cursors::arrow             | @image html arrow_w.png             | @image html arrow_g.png             | @image html arrow_m.png             |
/// | Cell                       | xtd::forms::cursors::disappearing_item | @image html cell_w.png              | @image html cell_g.png              | @image html cell_m.png              |
/// | Closed ha nd               | xtd::forms::cursors::closed_hand       | @image html closed_hand_w.png       | @image html closed_hand_g.png       | @image html closed_hand_m.png       |
/// | Contextual menu            | xtd::forms::cursors::contextual_menu   | @image html contextual_menu_w.png   | @image html contextual_menu_g.png   | @image html contextual_menu_m.png   |
/// | Cross                      | xtd::forms::cursors::cross             | @image html cross_w.png             | @image html cross_g.png             | @image html cross_m.png             |
/// | Default                    | xtd::forms::cursors::arrow             | @image html arrow_w.png             | @image html arrow_g.png             | @image html arrow_m.png             |
/// | Disappearing item          | xtd::forms::cursors::disappearing_item | @image html disappearing_item_w.png | @image html disappearing_item_g.png | @image html disappearing_item_m.png |
/// | Drag copy                  | xtd::forms::cursors::drag_copy         | @image html drag_copy_w.png         | @image html drag_copy_g.png         | @image html drag_copy_m.png         |
/// | Drag link                  | xtd::forms::cursors::drag_link         | @image html drag_link_w.png         | @image html drag_link_g.png         | @image html drag_link_m.png         |
/// | Hand                       | xtd::forms::cursors::hand              | @image html hand_w.png              | @image html hand_g.png              | @image html hand_m.png              |
/// | Help                       | xtd::forms::cursors::hsplit            | @image html help_w.png              | @image html help_g.png              | @image html help_m.png              |
/// | Horizonatl split           | xtd::forms::cursors::hsplit            | @image html hsplit_w.png            | @image html hsplit_g.png            | @image html hsplit_m.png            |
/// | I beam                     | xtd::forms::cursors::ibeam             | @image html ibeam_w.png             | @image html ibeam_g.png             | @image html ibeam_m.png             |
/// | No                         | xtd::forms::cursors::no                | @image html no_w.png                | @image html no_g.png                | @image html no_m.png                |
/// | No drag                    | xtd::forms::cursors::no_drag           | @image html no_drag_w.png           | @image html no_drag_g.png           | @image html no_drag_m.png           |
/// | No move 2d                 | xtd::forms::cursors::no_move_2d        | @image html no_move_2d_w.png        | @image html no_move_2d_g.png        | @image html no_move_2d_m.png        |
/// | No move horizontal         | xtd::forms::cursors::no_move_horiz     | @image html no_move_horiz_w.png.    | @image html no_move_horiz_g.png     | @image html no_move_horiz_m.png     |
/// | No move vertical           | xtd::forms::cursors::no_move_vert      | @image html no_move_vert_w.png.     | @image html no_move_vert_g.png      | @image html no_move_vert_m.png      |
/// | Open hand                  | xtd::forms::cursors::open_hand         | @image html open_hand_w.png         | @image html open_hand_g.png         | @image html open_hand_m.png         |
/// | Pan east                   | xtd::forms::cursors::pan_east          | @image html pan_east_w.png          | @image html pan_east_g.png          | @image html pan_east_m.png          |
/// | Pan north east             | xtd::forms::cursors::pan_ne            | @image html pan_ne_w.png            | @image html pan_ne_g.png            | @image html pan_ne_m.png            |
/// | Pan_north                  | xtd::forms::cursors::pan_north         | @image html pan_north_w.png         | @image html pan_north_g.png         | @image html pan_north_m.png         |
/// | Pan_north west             | xtd::forms::cursors::pan_nw            | @image html pan_nw_w.png            | @image html pan_nw_g.png            | @image html pan_nw_m.png            |
/// | Pan_south east             | xtd::forms::cursors::pan_se            | @image html pan_se_w.png            | @image html pan_se_g.png            | @image html pan_se_m.png            |
/// | Pan_south                  | xtd::forms::cursors::pan_south         | @image html pan_south_w.png         | @image html pan_south_g.png         | @image html pan_south_m.png         |
/// | Pan_south west             | xtd::forms::cursors::pan_sw            | @image html pan_sw_w.png            | @image html pan_sw_g.png            | @image html pan_sw_m.png            |
/// | Pan_west                   | xtd::forms::cursors::pan_west          | @image html pan_west_w.png          | @image html pan_west_g.png          | @image html pan_west_m.png          |
/// | Size all                   | xtd::forms::cursors::size_all          | @image html size_all_w.png          | @image html size_all_g.png          | @image html size_all_m.png          |
/// | Size north-east south-west | xtd::forms::cursors::size_nesw         | @image html size_nesw_w.png         | @image html size_nesw_g.png         | @image html size_nesw_m.png         |
/// | Size_north south           | xtd::forms::cursors::size_ns           | @image html size_ns_w.png           | @image html size_ns_g.png           | @image html size_ns_m.png           |
/// | size_north-west south-east | xtd::forms::cursors::size_nwse         | @image html size_nwse_w.png         | @image html size_nwse_g.png         | @image html size_nwse_m.png         |
/// | size_west east             | xtd::forms::cursors::size_we           | @image html size_we_w.png           | @image html size_we_g.png           | @image html size_we_m.png           |
/// | Up arrow                   | xtd::forms::cursors::up_arrow          | @image html up_arrow_w.png          | @image html up_arrow_g.png          | @image html up_arrow_m.png          |
/// | Vertical I beam            | xtd::forms::cursors::vibeam            | @image html vibeam_w.png            | @image html vibeam_g.png            | @image html vibeam_m.png            |
/// | Vertical split             | xtd::forms::cursors::vsplit            | @image html vsplit_w.png            | @image html vsplit_g.png            | @image html vsplit_m.png            |
/// | Wait                       | xtd::forms::cursors::wait_cursor       | @image html wait_cursor_w.png       | @image html wait_cursor_g.png       | @image html wait_cursor_m.png       |
/// | Zoom in                    | xtd::forms::cursors::zoom_in           | @image html zoom_in_w.png           | @image html zoom_in_g.png           | @image html zoom_in_m.png           |
/// | Zoom out                   | xtd::forms::cursors::zoom_out          | @image html zoom_out_w.png          | @image html zoom_out_g.png          | @image html zoom_out_m.png          |
