# Settings file
# =============

# Remarks
# This file generates the "properties/settings.h" file, which is used to access the settings.

# Includes
setting_include("xtd/drawing/point")
setting_include("xtd/drawing/size")
setting_include("xtd/drawing/system_colors")

# User settings
setting(back_color xtd::drawing::color USER "xtd::drawing::system_colors::control()")
setting(location xtd::drawing::point USER "{100, 50}")
setting(size xtd::drawing::size USER "{335, 45}")

# Application settings
setting(text xtd::ustring APPLICATION "\"Settings example\"")
