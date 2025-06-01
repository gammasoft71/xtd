# Settings file
# =============

# Remarks
# This file generates the "properties/settings.hpp" file, which is used to access the settings.

# Represents the ball size in pixels.
setting(ball_size xtd::drawing::size USER "200, 200")

# Represents radial gradient brush colors.
setting(gradient_color1 xtd::drawing::color USER "xtd::drawing::color::from_argb(0xBC, 0, 0)")
setting(gradient_color2 xtd::drawing::color USER "xtd::drawing::color::from_argb(0xFF, 0xAA, 0x7E)")
