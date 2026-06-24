# Settings file
# =============

# Remarks
# This file generates the "properties/settings.hpp" file, which is used to access the settings.

# Includes
setting_include("xtd/console_color")

# User settings
setting(back_color xtd::console_color USER "xtd::console_color::black")
setting(fore_color xtd::console_color USER "xtd::console_color::white")
setting(window_width xtd::uint32 USER "80")
setting(window_height xtd::uint32 USER "25")

# Application settings
setting(text xtd::string APPLICATION "\"Settings example\"")
