# Target application definitions
# ==============================

# The default namespace definition is used when the "property/resources.h" and "property/settings.h" files are generated so that they use the "minesweeper" namespace.
target_default_namespace("minesweeper")

# The target icon is used for the application and the main form.
target_icon("resources/minesweeper")

# The target name is used to name the built application.
target_name("minesweeper")

# The target startuo is the entry point definiton and generates the "property/startup.cpp" file wich contains the main method.
target_startup("minesweeper::minesweeper_form::main" "src/minesweeper.h")
