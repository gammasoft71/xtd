target_categories(Development)
target_default_namespace("xtdc_gui")
target_icon("resources/xtdc-gui")
target_display(ON)
target_startup(xtdc_gui::main_form::main "src/main_form.hpp")
