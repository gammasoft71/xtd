| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# xtd.drawing Development status

## In this section

* [Status information](#status-information)
* [xtd::drawing](#xtddrawing)
* [xtd::drawing::drawing2d](#xtddrawingdrawing2d)
* [xtd::drawing::imaging](#xtddrawingimaging)
* [xtd::drawing::text](#xtddrawingtext)

## Status information

* ![progress](pictures/progress_ina.png) Not applicable
* ![progress](pictures/progress0.png) Not started
* ![progress](pictures/progress25.png) Started
* ![progress](pictures/progress50.png) In progress
* ![progress](pictures/progress75.png) Usable
* ![progress](pictures/progress100.png) Complete

## xtd::drawing

| Name                                                                                | Type         | Status                                |
| ----------------------------------------------------------------------------------- | ------------ | ------------------------------------- |
| [bitmap](../src/xtd.drawing/include/xtd/drawing/bitmap.h)                           | class        | ![progress](pictures/progress100.png) |
| [brush](../src/xtd.drawing/include/xtd/drawing/brush.h)                             | class        | ![progress](pictures/progress100.png) |
| [brushes](../src/xtd.drawing/include/xtd/drawing/brushes.h)                         | static class | ![progress](pictures/progress100.png) |
| [buffered_graphics](../src/xtd.drawing/include/xtd/drawing/buffered_graphics.h)     | class        | ![progress](pictures/progress100.png) |
| [color](../src/xtd.drawing/include/xtd/drawing/color.h)                             | class        | ![progress](pictures/progress100.png) |
| [colors](../src/xtd.drawing/include/xtd/drawing/colors.h)                           | static class | ![progress](pictures/progress100.png) |
| [font](../src/xtd.drawing/include/xtd/drawing/font.h)                               | class        | ![progress](pictures/progress100.png) |
| [font_family](../src/xtd.drawing/include/xtd/drawing/font_family.h)                 | class        | ![progress](pictures/progress100.png) |
| [font_style](../src/xtd.drawing/include/xtd/drawing/font_style.h)                   | enumeration  | ![progress](pictures/progress100.png) |
| [graphics](../src/xtd.drawing/include/xtd/drawing/graphics.h)                       | class        | ![progress](pictures/progress100.png) |
| [graphics_unit](../src/xtd.drawing/include/xtd/drawing/graphics_unit.h)             | enumeration  | ![progress](pictures/progress100.png) |
| [hotkey_prefix](../src/xtd.drawing/include/xtd/drawing/hotkey_prefix.h)             | enumeration  | ![progress](pictures/progress100.png) |
| [icon](../src/xtd.drawing/include/xtd/drawing/icon.h)                               | class        | ![progress](pictures/progress100.png) |
| [image](../src/xtd.drawing/include/xtd/drawing/image.h)                             | class        | ![progress](pictures/progress100.png) |
| [known_color](../src/xtd.drawing/include/xtd/drawing/known_color.h)                 | enumeration  | ![progress](pictures/progress100.png) |
| [pen](../src/xtd.drawing/include/xtd/drawing/pen.h)                                 | class        | ![progress](pictures/progress100.png) |
| [pens](../src/xtd.drawing/include/xtd/drawing/pens.h)                               | static class | ![progress](pictures/progress100.png) |
| [point](../src/xtd.drawing/include/xtd/drawing/point.h)                             | class        | ![progress](pictures/progress100.png) |
| [point_f](../src/xtd.drawing/include/xtd/drawing/point_f.h)                         | class        | ![progress](pictures/progress100.png) |
| [rectangle](../src/xtd.drawing/include/xtd/drawing/rectangle.h)                     | class        | ![progress](pictures/progress100.png) |
| [rectangle_f](../src/xtd.drawing/include/xtd/drawing/rectangle_f.h)                 | class        | ![progress](pictures/progress100.png) |
| [region](../src/xtd.drawing/include/xtd/drawing/region.h)                           | class        | ![progress](pictures/progress100.png) |
| [rotate_flip_type](../src/xtd.drawing/include/xtd/drawing/rotate_flip_type.h)       | enumeration  | ![progress](pictures/progress100.png) |
| [size](../src/xtd.drawing/include/xtd/drawing/size.h)                               | class        | ![progress](pictures/progress100.png) |
| [size_f](../src/xtd.drawing/include/xtd/drawing/size_f.h)                           | class        | ![progress](pictures/progress100.png) |
| [solid_brush](../src/xtd.drawing/include/xtd/drawing/solid_brush.h)                 | class        | ![progress](pictures/progress100.png) |
| [string_alignment](../src/xtd.drawing/include/xtd/drawing/string_alignment.h)       | enumeration  | ![progress](pictures/progress100.png) |
| [string_format](../src/xtd.drawing/include/xtd/drawing/string_format.h)             | class        | ![progress](pictures/progress100.png) |
| [string_format_flags](../src/xtd.drawing/include/xtd/drawing/string_format_flags.h) | enumeration  | ![progress](pictures/progress100.png) |
| [string_trimming](../src/xtd.drawing/include/xtd/drawing/string_trimming.h)         | enumeration  | ![progress](pictures/progress100.png) |
| [system_brushes](../src/xtd.drawing/include/xtd/drawing/system_brushes.h)           | static class | ![progress](pictures/progress100.png) |
| [system_colors](../src/xtd.drawing/include/xtd/drawing/system_colors.h)             | static class | ![progress](pictures/progress100.png) |
| [system_fonts](../src/xtd.drawing/include/xtd/drawing/system_fonts.h)               | static class | ![progress](pictures/progress100.png) |
| [system_icons](../src/xtd.drawing/include/xtd/drawing/system_icons.h)               | static class | ![progress](pictures/progress100.png) |
| [system_images](../src/xtd.drawing/include/xtd/drawing/system_images.h)             | static class | ![progress](pictures/progress100.png) |
| [system_pens](../src/xtd.drawing/include/xtd/drawing/system_pens.h)                 | static class | ![progress](pictures/progress100.png) |
| [texts](../src/xtd.drawing/include/xtd/drawing/texts.h)               | static class | ![progress](pictures/progress100.png) |
| [texture_brush](../src/xtd.drawing/include/xtd/drawing/texture_brush.h)             | class        | ![progress](pictures/progress100.png) |

## xtd::drawing::drawing2d

| Name                                                                                                     | Type         | Status                                |
| -------------------------------------------------------------------------------------------------------- | ------------ | ------------------------------------- |
| [compisiting_mode](../src/xtd.drawing/include/xtd/drawing/drawing_2d/compisiting_mode.h)                 | enumeration  | ![progress](pictures/progress100.png) |
| [compisiting_quality](../src/xtd.drawing/include/xtd/drawing/drawing_2d/compisiting_quality.h)           | enumeration  | ![progress](pictures/progress100.png) |
| [conical_gradient_brush](../src/xtd.drawing/include/xtd/drawing/drawing_2d/conical_gradient_brush.h)     | class        | ![progress](pictures/progress100.png) |
| [fill_mode](../src/xtd.drawing/include/xtd/drawing/drawing_2d/fill_mode.h)                               | enumeration  | ![progress](pictures/progress100.png) |
| [flush_intention](../src/xtd.drawing/include/xtd/drawing/drawing_2d/flush_intention.h)                   | enumeration  | ![progress](pictures/progress100.png) |
| [dash_style](../src/xtd.drawing/include/xtd/drawing/drawing_2d/dash_style.h)                             | enumeration  | ![progress](pictures/progress100.png) |
| [gradient_stop](../src/xtd.drawing/include/xtd/drawing/drawing_2d/gradient_stop.h)                       | alias        | ![progress](pictures/progress100.png) |
| [gradient_stop_collection](../src/xtd.drawing/include/xtd/drawing/drawing_2d/gradient_stop_collection.h) | alias        | ![progress](pictures/progress100.png) |
| [graphics_path](../src/xtd.drawing/include/xtd/drawing/drawing_2d/graphics_path.h)                       | class        | ![progress](pictures/progress100.png) |
| [graphics_state](../src/xtd.drawing/include/xtd/drawing/drawing_2d/graphics_state.h)                     | class        | ![progress](pictures/progress100.png) |
| [hatch_brush](../src/xtd.drawing/include/xtd/drawing/drawing_2d/hatch_brush.h)                           | class        | ![progress](pictures/progress100.png) |
| [hatch_style](../src/xtd.drawing/include/xtd/drawing/drawing_2d/hatch_style.h)                           | enumeration  | ![progress](pictures/progress100.png) |
| [interpolation_mode](../src/xtd.drawing/include/xtd/drawing/drawing_2d/interpolation_mode.h)             | enumeration  | ![progress](pictures/progress100.png) |
| [line_cap](../src/xtd.drawing/include/xtd/drawing/drawing_2d/line_cap.h)                                 | enumeration  | ![progress](pictures/progress100.png) |
| [line_join](../src/xtd.drawing/include/xtd/drawing/drawing_2d/line_join.h)                               | enumeration  | ![progress](pictures/progress100.png) |
| [linear_gradient_brush](../src/xtd.drawing/include/xtd/drawing/drawing_2d/linear_gradient_brush.h)       | class        | ![progress](pictures/progress100.png) |
| [linear_gradient_mode](../src/xtd.drawing/include/xtd/drawing/drawing_2d/linear_gradient_mode.h)         | enumeration  | ![progress](pictures/progress100.png) |
| [matrix](../src/xtd.drawing/include/xtd/drawing/drawing_2d/matrix.h)                                     | class        | ![progress](pictures/progress100.png) |
| [matrix_order](../src/xtd.drawing/include/xtd/drawing/drawing_2d/matrix_order.h)                         | enumeration  | ![progress](pictures/progress100.png) |
| [pen_alignment](../src/xtd.drawing/include/xtd/drawing/drawing_2d/pen_alignment.h)                       | enumeration  | ![progress](pictures/progress100.png) |
| [pen_type](../src/xtd.drawing/include/xtd/drawing/drawing_2d/pen_type.h)                                 | enumeration  | ![progress](pictures/progress100.png) |
| [pixel_offset_mode](../src/xtd.drawing/include/xtd/drawing/drawing_2d/pixel_offset_mode.h)               | enumeration  | ![progress](pictures/progress100.png) |
| [radial_gradient_brush](../src/xtd.drawing/include/xtd/drawing/drawing_2d/radial_gradient_brush.h)       | class        | ![progress](pictures/progress100.png) |
| [smoothing_mode](../src/xtd.drawing/include/xtd/drawing/drawing_2d/smoothing_mode.h)                     | enumeration  | ![progress](pictures/progress100.png) |

## xtd::drawing::imaging

| Name                                                                                                          | Type         | Status                                |
| ------------------------------------------------------------------------------------------------------------- | ------------ | ------------------------------------- |
| [bitmap_data](../src/xtd.drawing/include/xtd/drawing/imaging/bitmap_data.h)                                   | class        | ![progress](pictures/progress100.png) |
| [color_palette](../src/xtd.drawing/include/xtd/drawing/imaging/color_palette.h)                               | class        | ![progress](pictures/progress100.png) |
| [encoder](../src/xtd.drawing/include/xtd/drawing/imaging/encoder.h)                                           | class        | ![progress](pictures/progress100.png) |
| [encoder_parameter](../src/xtd.drawing/include/xtd/drawing/imaging/encoder_parameter.h)                       | class        | ![progress](pictures/progress100.png) |
| [encoder_parameter_value_type](../src/xtd.drawing/include/xtd/drawing/imaging/encoder_parameter_value_type.h) | enumeration  | ![progress](pictures/progress100.png) |
| [encoder_parameters](../src/xtd.drawing/include/xtd/drawing/imaging/encoder_parameters.h)                     | class        | ![progress](pictures/progress100.png) |
| [frame_dimension](../src/xtd.drawing/include/xtd/drawing/imaging/frame_dimension.h)                           | class        | ![progress](pictures/progress100.png) |
| [image_flags](../src/xtd.drawing/include/xtd/drawing/imaging/image_flags.h)                                   | enumeration  | ![progress](pictures/progress100.png) |
| [image_format](../src/xtd.drawing/include/xtd/drawing/imaging/image_format.h)                                 | class        | ![progress](pictures/progress100.png) |
| [image_lock_mode](../src/xtd.drawing/include/xtd/drawing/imaging/image_lock_mode.h)                           | enumeration  | ![progress](pictures/progress100.png) |
| [pixel_format](../src/xtd.drawing/include/xtd/drawing/imaging/pixel_format.h)                                 | enumeration  | ![progress](pictures/progress100.png) |
| [property_item](../src/xtd.drawing/include/xtd/drawing/imaging/property_item.h)                               | class        | ![progress](pictures/progress100.png) |

## xtd::drawing::text

| Name                                                                                                 | Type         | Status                                |
| ---------------------------------------------------------------------------------------------------- | ------------ | ------------------------------------- |
| [font_collection](../src/xtd.drawing/include/xtd/drawing/text/font_collection.h)                     | class        | ![progress](pictures/progress100.png) |
| [generic_font_families](../src/xtd.drawing/include/xtd/drawing/text/generic_font_families.h)         | enumeration  | ![progress](pictures/progress100.png) |
| [hotkey_prefix](../src/xtd.drawing/include/xtd/drawing/text/hotkey_prefix.h)                         | enumeration  | ![progress](pictures/progress100.png) |
| [installed_font_collection](../src/xtd.drawing/include/xtd/drawing/text/installed_font_collection.h) | class        | ![progress](pictures/progress100.png) |
| [private_font_collection](../src/xtd.drawing/include/xtd/drawing/text/private_font_collection.h)     | class        | ![progress](pictures/progress100.png) |
| [text_rendering_hint](../src/xtd.drawing/include/xtd/drawing/text/text_rendering_hint.h)             | enumeration  | ![progress](pictures/progress100.png) |

## See also

* [Development status](development_status.md)
* [Documentation](documentation.md)

__________________________________________________________________________________________

© 2025 Gammasoft.

