# xtd.drawing Development status

## In this section

* [Status information](#status-information)
* [xtd::drawing](#xtddrawing)
* [xtd::drawing::drawing2d](#xtddrawingdrawing2d)
* [xtd::drawing::imaging](#xtddrawingimaging)
* [xtd::drawing::text](#xtddrawingtext)

## Status information

* ![progress](/pictures/progress_ina.png) Not applicable
* ![progress](/pictures/progress0.png) Not started
* ![progress](/pictures/progress25.png) Started
* ![progress](/pictures/progress50.png) In progress
* ![progress](/pictures/progress75.png) Usable
* ![progress](/pictures/progress100.png) Complete

## xtd::drawing

| Name                                                                                                                              | Type         | Status                                 |
| --------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [bitmap](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/bitmap.hpp)                           | class        | ![progress](/pictures/progress100.png) |
| [brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/brush.hpp)                             | class        | ![progress](/pictures/progress100.png) |
| [brushes](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/brushes.hpp)                         | static class | ![progress](/pictures/progress100.png) |
| [buffered_graphics](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/buffered_graphics.hpp)     | class        | ![progress](/pictures/progress100.png) |
| [color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/color.hpp)                             | class        | ![progress](/pictures/progress100.png) |
| [colors](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/colors.hpp)                           | static class | ![progress](/pictures/progress100.png) |
| [dash_style](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/dash_style.hpp)                   | enumeration  | ![progress](/pictures/progress100.png) |
| [font](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/font.hpp)                               | class        | ![progress](/pictures/progress100.png) |
| [font_family](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/font_family.hpp)                 | class        | ![progress](/pictures/progress100.png) |
| [font_style](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/font_style.hpp)                   | enumeration  | ![progress](/pictures/progress100.png) |
| [graphics](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/graphics.hpp)                       | class        | ![progress](/pictures/progress100.png) |
| [graphics_unit](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/graphics_unit.hpp)             | enumeration  | ![progress](/pictures/progress100.png) |
| [hotkey_prefix](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/hotkey_prefix.hpp)             | enumeration  | ![progress](/pictures/progress100.png) |
| [icon](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/icon.hpp)                               | class        | ![progress](/pictures/progress100.png) |
| [image](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/image.hpp)                             | class        | ![progress](/pictures/progress100.png) |
| [known_color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/known_color.hpp)                 | enumeration  | ![progress](/pictures/progress100.png) |
| [pen](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/pen.hpp)                                 | class        | ![progress](/pictures/progress100.png) |
| [pens](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/pens.hpp)                               | static class | ![progress](/pictures/progress100.png) |
| [point](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/point.hpp)                             | class        | ![progress](/pictures/progress100.png) |
| [point_f](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/point_f.hpp)                         | class        | ![progress](/pictures/progress100.png) |
| [rectangle](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/rectangle.hpp)                     | class        | ![progress](/pictures/progress100.png) |
| [rectangle_f](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/rectangle_f.hpp)                 | class        | ![progress](/pictures/progress100.png) |
| [region](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/region.hpp)                           | class        | ![progress](/pictures/progress100.png) |
| [rotate_flip_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/rotate_flip_type.hpp)       | enumeration  | ![progress](/pictures/progress100.png) |
| [size](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/size.hpp)                               | class        | ![progress](/pictures/progress100.png) |
| [size_f](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/size_f.hpp)                           | class        | ![progress](/pictures/progress100.png) |
| [solid_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/solid_brush.hpp)                 | class        | ![progress](/pictures/progress100.png) |
| [string_alignment](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/string_alignment.hpp)       | enumeration  | ![progress](/pictures/progress100.png) |
| [string_format](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/string_format.hpp)             | class        | ![progress](/pictures/progress100.png) |
| [string_format_flags](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/string_format_flags.hpp) | enumeration  | ![progress](/pictures/progress100.png) |
| [string_trimming](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/string_trimming.hpp)         | enumeration  | ![progress](/pictures/progress100.png) |
| [system_brushes](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_brushes.hpp)           | static class | ![progress](/pictures/progress100.png) |
| [system_colors](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_colors.hpp)             | static class | ![progress](/pictures/progress100.png) |
| [system_fonts](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_fonts.hpp)               | static class | ![progress](/pictures/progress100.png) |
| [system_icons](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_icons.hpp)               | static class | ![progress](/pictures/progress100.png) |
| [system_images](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_images.hpp)             | static class | ![progress](/pictures/progress100.png) |
| [system_pens](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_pens.hpp)                 | static class | ![progress](/pictures/progress100.png) |
| [texture_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/texture_brush.hpp)             | class        | ![progress](/pictures/progress100.png) |

## xtd::drawing::drawing2d

| Name                                                                                                                                                  | Type         | Status                                 |
| ----------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [compisiting_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/compisiting_mode.hpp)                 | enumeration  | ![progress](/pictures/progress100.png) |
| [compisiting_quality](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/compisiting_quality.hpp)           | enumeration  | ![progress](/pictures/progress100.png) |
| [conical_gradient_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/conical_gradient_brush.hpp)     | class        | ![progress](/pictures/progress100.png) |
| [fill_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/fill_mode.hpp)                               | enumeration  | ![progress](/pictures/progress100.png) |
| [flush_intention](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/flush_intention.hpp)                   | enumeration  | ![progress](/pictures/progress100.png) |
| [gradient_stop](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/gradient_stop.hpp)                       | alias        | ![progress](/pictures/progress100.png) |
| [gradient_stop_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/gradient_stop_collection.hpp) | alias        | ![progress](/pictures/progress100.png) |
| [graphics_path](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/graphics_path.hpp)                       | class        | ![progress](/pictures/progress100.png) |
| [graphics_state](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/graphics_state.hpp)                     | class        | ![progress](/pictures/progress100.png) |
| [hatch_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/hatch_brush.hpp)                           | class        | ![progress](/pictures/progress100.png) |
| [hatch_style](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/hatch_style.hpp)                           | enumeration  | ![progress](/pictures/progress100.png) |
| [interpolation_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/interpolation_mode.hpp)             | enumeration  | ![progress](/pictures/progress100.png) |
| [line_cap](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/line_cap.hpp)                                 | enumeration  | ![progress](/pictures/progress100.png) |
| [line_join](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/line_join.hpp)                               | enumeration  | ![progress](/pictures/progress100.png) |
| [linear_gradient_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/linear_gradient_brush.hpp)       | class        | ![progress](/pictures/progress100.png) |
| [linear_gradient_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/linear_gradient_mode.hpp)         | enumeration  | ![progress](/pictures/progress100.png) |
| [matrix](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/matrix.hpp)                                     | class        | ![progress](/pictures/progress100.png) |
| [matrix_order](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/matrix_order.hpp)                         | enumeration  | ![progress](/pictures/progress100.png) |
| [pen_alignment](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/pen_alignment.hpp)                       | enumeration  | ![progress](/pictures/progress100.png) |
| [pen_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/pen_type.hpp)                                 | enumeration  | ![progress](/pictures/progress100.png) |
| [pixel_offset_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/pixel_offset_mode.hpp)               | enumeration  | ![progress](/pictures/progress100.png) |
| [radial_gradient_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/radial_gradient_brush.hpp)       | class        | ![progress](/pictures/progress100.png) |
| [smoothing_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/smoothing_mode.hpp)                     | enumeration  | ![progress](/pictures/progress100.png) |

## xtd::drawing::imaging

| Name                                                                                                                                                        | Type         | Status                                 |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [bitmap_data](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/bitmap_data.hpp)                                   | class        | ![progress](/pictures/progress100.png) |
| [color_palette](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/color_palette.hpp)                               | class        | ![progress](/pictures/progress100.png) |
| [encoder](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/encoder.hpp)                                           | class        | ![progress](/pictures/progress100.png) |
| [encoder_parameter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/encoder_parameter.hpp)                       | class        | ![progress](/pictures/progress100.png) |
| [encoder_parameter_value_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/encoder_parameter_value_type.hpp) | enumeration  | ![progress](/pictures/progress100.png) |
| [encoder_parameters](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/encoder_parameters.hpp)                     | class        | ![progress](/pictures/progress100.png) |
| [frame_dimension](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/frame_dimension.hpp)                           | class        | ![progress](/pictures/progress100.png) |
| [image_flags](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/image_flags.hpp)                                   | enumeration  | ![progress](/pictures/progress100.png) |
| [image_format](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/image_format.hpp)                                 | class        | ![progress](/pictures/progress100.png) |
| [image_lock_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/image_lock_mode.hpp)                           | enumeration  | ![progress](/pictures/progress100.png) |
| [pixel_format](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/pixel_format.hpp)                                 | enumeration  | ![progress](/pictures/progress100.png) |
| [property_item](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/property_item.hpp)                               | class        | ![progress](/pictures/progress100.png) |

## xtd::drawing::text

| Name                                                                                                                                               | Type         | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [font_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/font_collection.hpp)                     | class        | ![progress](/pictures/progress100.png) |
| [generic_font_families](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/generic_font_families.hpp)         | enumeration  | ![progress](/pictures/progress100.png) |
| [hotkey_prefix](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/hotkey_prefix.hpp)                         | enumeration  | ![progress](/pictures/progress100.png) |
| [installed_font_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/installed_font_collection.hpp) | class        | ![progress](/pictures/progress100.png) |
| [private_font_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/private_font_collection.hpp)     | class        | ![progress](/pictures/progress100.png) |
| [text_rendering_hint](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/text_rendering_hint.hpp)             | enumeration  | ![progress](/pictures/progress100.png) |

## See also

* [Development status](/docs/documentation/development_status)
* [Documentation](/docs/documentation)
