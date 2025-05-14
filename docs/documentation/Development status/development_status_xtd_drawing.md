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

| Name                                                                                                                            | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [bitmap](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/bitmap.h)                           | class        | ![progress](/pictures/progress100.png) |
| [brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/brush.h)                             | class        | ![progress](/pictures/progress100.png) |
| [brushes](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/brushes.h)                         | static class | ![progress](/pictures/progress100.png) |
| [buffered_graphics](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/buffered_graphics.h)     | class        | ![progress](/pictures/progress100.png) |
| [color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/color.h)                             | class        | ![progress](/pictures/progress100.png) |
| [colors](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/colors.h)                           | static class | ![progress](/pictures/progress100.png) |
| [dash_style](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/dash_style.h)                   | enumeration  | ![progress](/pictures/progress100.png) |
| [font](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/font.h)                               | class        | ![progress](/pictures/progress100.png) |
| [font_family](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/font_family.h)                 | class        | ![progress](/pictures/progress100.png) |
| [font_style](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/font_style.h)                   | enumeration  | ![progress](/pictures/progress100.png) |
| [graphics](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/graphics.h)                       | class        | ![progress](/pictures/progress100.png) |
| [graphics_unit](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/graphics_unit.h)             | enumeration  | ![progress](/pictures/progress100.png) |
| [hotkey_prefix](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/hotkey_prefix.h)             | enumeration  | ![progress](/pictures/progress100.png) |
| [icon](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/icon.h)                               | class        | ![progress](/pictures/progress100.png) |
| [image](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/image.h)                             | class        | ![progress](/pictures/progress100.png) |
| [known_color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/known_color.h)                 | enumeration  | ![progress](/pictures/progress100.png) |
| [pen](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/pen.h)                                 | class        | ![progress](/pictures/progress100.png) |
| [pens](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/pens.h)                               | static class | ![progress](/pictures/progress100.png) |
| [point](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/point.h)                             | class        | ![progress](/pictures/progress100.png) |
| [point_f](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/point_f.h)                         | class        | ![progress](/pictures/progress100.png) |
| [rectangle](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/rectangle.h)                     | class        | ![progress](/pictures/progress100.png) |
| [rectangle_f](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/rectangle_f.h)                 | class        | ![progress](/pictures/progress100.png) |
| [region](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/region.h)                           | class        | ![progress](/pictures/progress100.png) |
| [rotate_flip_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/rotate_flip_type.h)       | enumeration  | ![progress](/pictures/progress100.png) |
| [size](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/size.h)                               | class        | ![progress](/pictures/progress100.png) |
| [size_f](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/size_f.h)                           | class        | ![progress](/pictures/progress100.png) |
| [solid_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/solid_brush.h)                 | class        | ![progress](/pictures/progress100.png) |
| [string_alignment](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/string_alignment.h)       | enumeration  | ![progress](/pictures/progress100.png) |
| [string_format](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/string_format.h)             | class        | ![progress](/pictures/progress100.png) |
| [string_format_flags](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/string_format_flags.h) | enumeration  | ![progress](/pictures/progress100.png) |
| [string_trimming](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/string_trimming.h)         | enumeration  | ![progress](/pictures/progress100.png) |
| [system_brushes](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_brushes.h)           | static class | ![progress](/pictures/progress100.png) |
| [system_colors](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_colors.h)             | static class | ![progress](/pictures/progress100.png) |
| [system_fonts](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_fonts.h)               | static class | ![progress](/pictures/progress100.png) |
| [system_icons](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_icons.h)               | static class | ![progress](/pictures/progress100.png) |
| [system_images](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_images.h)             | static class | ![progress](/pictures/progress100.png) |
| [system_pens](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/system_pens.h)                 | static class | ![progress](/pictures/progress100.png) |
| [texture_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/texture_brush.h)             | class        | ![progress](/pictures/progress100.png) |

## xtd::drawing::drawing2d

| Name                                                                                                                                                | Type         | Status                                 |
| --------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [compisiting_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/compisiting_mode.h)                 | enumeration  | ![progress](/pictures/progress100.png) |
| [compisiting_quality](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/compisiting_quality.h)           | enumeration  | ![progress](/pictures/progress100.png) |
| [conical_gradient_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/conical_gradient_brush.h)     | class        | ![progress](/pictures/progress100.png) |
| [fill_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/fill_mode.h)                               | enumeration  | ![progress](/pictures/progress100.png) |
| [flush_intention](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/flush_intention.h)                   | enumeration  | ![progress](/pictures/progress100.png) |
| [gradient_stop](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/gradient_stop.h)                       | alias        | ![progress](/pictures/progress100.png) |
| [gradient_stop_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/gradient_stop_collection.h) | alias        | ![progress](/pictures/progress100.png) |
| [graphics_path](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/graphics_path.h)                       | class        | ![progress](/pictures/progress100.png) |
| [graphics_state](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/graphics_state.h)                     | class        | ![progress](/pictures/progress100.png) |
| [hatch_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/hatch_brush.h)                           | class        | ![progress](/pictures/progress100.png) |
| [hatch_style](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/hatch_style.h)                           | enumeration  | ![progress](/pictures/progress100.png) |
| [interpolation_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/interpolation_mode.h)             | enumeration  | ![progress](/pictures/progress100.png) |
| [line_cap](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/line_cap.h)                                 | enumeration  | ![progress](/pictures/progress100.png) |
| [line_join](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/line_join.h)                               | enumeration  | ![progress](/pictures/progress100.png) |
| [linear_gradient_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/linear_gradient_brush.h)       | class        | ![progress](/pictures/progress100.png) |
| [linear_gradient_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/linear_gradient_mode.h)         | enumeration  | ![progress](/pictures/progress100.png) |
| [matrix](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/matrix.h)                                     | class        | ![progress](/pictures/progress100.png) |
| [matrix_order](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/matrix_order.h)                         | enumeration  | ![progress](/pictures/progress100.png) |
| [pen_alignment](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/pen_alignment.h)                       | enumeration  | ![progress](/pictures/progress100.png) |
| [pen_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/pen_type.h)                                 | enumeration  | ![progress](/pictures/progress100.png) |
| [pixel_offset_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/pixel_offset_mode.h)               | enumeration  | ![progress](/pictures/progress100.png) |
| [radial_gradient_brush](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/radial_gradient_brush.h)       | class        | ![progress](/pictures/progress100.png) |
| [smoothing_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/drawing2d/smoothing_mode.h)                     | enumeration  | ![progress](/pictures/progress100.png) |

## xtd::drawing::imaging

| Name                                                                                                                                                      | Type         | Status                                 |
| --------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [bitmap_data](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/bitmap_data.h)                                   | class        | ![progress](/pictures/progress100.png) |
| [color_palette](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/color_palette.h)                               | class        | ![progress](/pictures/progress100.png) |
| [encoder](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/encoder.h)                                           | class        | ![progress](/pictures/progress100.png) |
| [encoder_parameter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/encoder_parameter.h)                       | class        | ![progress](/pictures/progress100.png) |
| [encoder_parameter_value_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/encoder_parameter_value_type.h) | enumeration  | ![progress](/pictures/progress100.png) |
| [encoder_parameters](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/encoder_parameters.h)                     | class        | ![progress](/pictures/progress100.png) |
| [frame_dimension](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/frame_dimension.h)                           | class        | ![progress](/pictures/progress100.png) |
| [image_flags](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/image_flags.h)                                   | enumeration  | ![progress](/pictures/progress100.png) |
| [image_format](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/image_format.h)                                 | class        | ![progress](/pictures/progress100.png) |
| [image_lock_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/image_lock_mode.h)                           | enumeration  | ![progress](/pictures/progress100.png) |
| [pixel_format](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/pixel_format.h)                                 | enumeration  | ![progress](/pictures/progress100.png) |
| [property_item](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/imaging/property_item.h)                               | class        | ![progress](/pictures/progress100.png) |

## xtd::drawing::text

| Name                                                                                                                                             | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------------------------ | ------------ | -------------------------------------- |
| [font_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/font_collection.h)                     | class        | ![progress](/pictures/progress100.png) |
| [generic_font_families](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/generic_font_families.h)         | enumeration  | ![progress](/pictures/progress100.png) |
| [hotkey_prefix](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/hotkey_prefix.h)                         | enumeration  | ![progress](/pictures/progress100.png) |
| [installed_font_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/installed_font_collection.h) | class        | ![progress](/pictures/progress100.png) |
| [private_font_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/private_font_collection.h)     | class        | ![progress](/pictures/progress100.png) |
| [text_rendering_hint](https://github.com/gammasoft71/xtd/tree/master/src/xtd.drawing/include/xtd/drawing/text/text_rendering_hint.h)             | enumeration  | ![progress](/pictures/progress100.png) |

## See also

* [Development status](/docs/documentation/Development%20status)
* [Documentation](/docs/documentation)
