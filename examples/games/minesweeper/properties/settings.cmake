# Game settings
# =============

# if "true", minesweeper use original color otherwise, minesweeper use system color.
setting(original_color bool USER "true")

setting(marks bool USER "true")

# minesweeper::level :
# "0" : minesweeper::level::beginner
# "1" : minesweeper::level::intermediate
# "2" : minesweeper::level::expert
# "3" : minesweeper::level::custom
setting(level int USER "0")

setting(custom_height int USER "16")
setting(custom_width int USER "30")
setting(custom_mines int USER "99")

setting(beginner_high_scores_value int USER "999")
setting(beginner_high_scores_name std::string USER "\"Anonymous\"")

setting(intermediate_high_scores_value int USER "999")
setting(intermediate_high_scores_name std::string USER "\"Anonymous\"")

setting(expert_high_scores_value int USER "999")
setting(expert_high_scores_name std::string USER "\"Anonymous\"")
