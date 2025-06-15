# Settings file
# =============

# Remarks
# This file generates the "properties/settings.hpp" file, which is used to access the settings.

# Include files.
setting_include("xtd/drawing/color")
setting_include("xtd/drawing/point")
setting_include("xtd/drawing/size")

# Represents the ball size in pixels.
setting(size xtd::drawing::size USER "200, 200")

# Represents the color of ball.
setting(color xtd::drawing::color USER "xtd::drawing::color::from_argb(0xBC, 0, 0)")

# Represents the color of the ball's light poin.
setting(light_point_color xtd::drawing::color USER "xtd::drawing::color::from_argb(0xFF, 0xAA, 0x7E)")

# Represents the opacity in percent.
setting(opacity double USER "1.0")

# Represents the settings form location in pixels.
setting(settings_form_location xtd::drawing::point USER "200, 100")
