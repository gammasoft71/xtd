# Target application definitions
# ==============================

# The default namespace definition is used when the "property/resources.hpp" and "property/settings.hpp" files are generated so that they use the "ball" namespace.
target_default_namespace("ball")

# The target icon is used for the application and the main form.
target_icon("resources/ball")

# The target name is used to name the built application.
target_name("ball")

# The target startuo is the entry point definiton and generates the "property/startup.cpp" file wich contains the main method.
target_startup("ball::main_form::main" "src/ball.hpp")
