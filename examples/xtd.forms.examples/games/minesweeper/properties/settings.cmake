# Game settings
# =============

# Remarks
# This file generates the "properties/settings.h" file, which is used to access the settings.

# if "true", minesweeper use original color otherwise; otherwise minesweeper use system color.
setting(original_color bool USER "false")

# if "true", minesweeper shows ? marks; otherwise none.
setting(marks bool USER "true")

# Current level
setting(level minesweeper::level USER "minesweeper::level::beginner")

# Beginner level settings
setting(beginner_high_scores_value int USER "999")
setting(beginner_high_scores_name xtd::ustring USER "xtd::translator::translate(\"Anonymous\")")

# Intermediate level settings
setting(intermediate_high_scores_value int USER "999")
setting(intermediate_high_scores_name xtd::ustring USER "xtd::translator::translate(\"Anonymous\")")

# Expert level settings
setting(expert_high_scores_value int USER "999")
setting(expert_high_scores_name xtd::ustring USER "xtd::translator::translate(\"Anonymous\")")

# Custom level settings
setting(custom_height int USER "16")
setting(custom_width int USER "30")
setting(custom_mines int USER "99")
