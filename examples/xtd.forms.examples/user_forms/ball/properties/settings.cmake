# Settings file
# =============

# Remarks
# This file generates the "properties/settings.hpp" file, which is used to access the settings.

# Represents the ball size in pixels.
setting(size xtd::drawing::size USER "200, 200")

# Represents the color of ball.
setting(color xtd::drawing::color USER "xtd::drawing::color::from_argb(0xBC, 0, 0)")

# Represents the color of the ball's light poin.
setting(light_point_color xtd::drawing::color USER "xtd::drawing::color::from_argb(0xFF, 0xAA, 0x7E)")
