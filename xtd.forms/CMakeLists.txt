cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.forms.hpp
  include/xtd/xtd.forms
)

set(XTD_FORMS_INCLUDES
  include/xtd/forms/application.hpp
  include/xtd/forms/application_informations.hpp
  include/xtd/forms/button.hpp
  include/xtd/forms/cancel_event_args.hpp
  include/xtd/forms/close_reason.hpp
  include/xtd/forms/control.hpp
  include/xtd/forms/dialog_result.hpp
  include/xtd/forms/form.hpp
  include/xtd/forms/form_closed_event_args.hpp
  include/xtd/forms/form_closed_event_handler.hpp
  include/xtd/forms/form_closing_event_args.hpp
  include/xtd/forms/form_closing_event_handler.hpp
  include/xtd/forms/key_event_args.hpp
  include/xtd/forms/key_event_handler.hpp
  include/xtd/forms/key_press_event_args.hpp
  include/xtd/forms/key_press_event_handler.hpp
  include/xtd/forms/keys.hpp
  include/xtd/forms/label.hpp
  include/xtd/forms/message.hpp
  include/xtd/forms/message_box.hpp
  include/xtd/forms/message_box_buttons.hpp
  include/xtd/forms/message_box_default_button.hpp
  include/xtd/forms/message_box_icon.hpp
  include/xtd/forms/message_box_options.hpp
  include/xtd/forms/mouse_buttons.hpp
  include/xtd/forms/mouse_event_args.hpp
  include/xtd/forms/mouse_event_handler.hpp
  include/xtd/forms/text_box.hpp
  include/xtd/forms/timer.hpp
)

set(XTD_FORMS_SOURCES
  src/xtd/forms/application.cpp
  src/xtd/forms/button.cpp
  src/xtd/forms/control.cpp
  src/xtd/forms/form.cpp
  src/xtd/forms/label.cpp
  src/xtd/forms/message.cpp
  src/xtd/forms/message_box.cpp
  src/xtd/forms/text_box.cpp
  src/xtd/forms/timer.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\forms FILES ${XTD_FORMS_INCLUDES})
source_group(src\\xtd\\forms FILES ${XTD_FORMS_SOURCES})
source_group(src\\native FILES ${NATIVE_SOURCES})
source_group(src\\native\\wxwidgets FILES ${NATIVE_WXWIDGETS_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

# Add packages
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_INCLUDES} ${XTD_FORMS_SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.delegates xtd.diagnostics xtd.drawing xtd.environment xtd.forms.native.wxwidgets xtd.io xtd.strings ${wxWidgets_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS xtd.forms EXPORT ${PROJECT_NAME} DESTINATION lib)
