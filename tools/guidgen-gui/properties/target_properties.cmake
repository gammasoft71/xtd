target_default_namespace("guidgen_gui")
target_icon(resources/guidgen-gui)
target_display(ON)
target_startup("guidgen_gui::main_form" src/main_form.h)
