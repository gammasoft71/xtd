cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.native.fltk VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.forms.native.fltk.h
  include/xtd/xtd.forms.native.fltk
)

set(XTD_FORMS_NATIVE_FLTK_SOURCES
  src/xtd/forms/native/fltk/application.cpp
  src/xtd/forms/native/fltk/button.cpp
  src/xtd/forms/native/fltk/check_box.cpp
  src/xtd/forms/native/fltk/checked_list_box.cpp
  src/xtd/forms/native/fltk/control.cpp
  src/xtd/forms/native/fltk/color_dialog.cpp
  src/xtd/forms/native/fltk/combo_box.cpp
  src/xtd/forms/native/fltk/control_handler.h
  src/xtd/forms/native/fltk/cursor.cpp
  src/xtd/forms/native/fltk/cursors.cpp
  src/xtd/forms/native/fltk/fl_button.h
  src/xtd/forms/native/fltk/fl_check_box.h
  src/xtd/forms/native/fltk/fl_checked_list_box.h
  src/xtd/forms/native/fltk/fl_combo_box.h
  src/xtd/forms/native/fltk/fl_control.h
  src/xtd/forms/native/fltk/fl_font_chooser.h
  src/xtd/forms/native/fltk/fl_form.h
  src/xtd/forms/native/fltk/fl_group_box.h
  src/xtd/forms/native/fltk/fl_label.h
  src/xtd/forms/native/fltk/fl_list_box.h
  src/xtd/forms/native/fltk/fl_panel.h
  src/xtd/forms/native/fltk/fl_progress_bar.h
  src/xtd/forms/native/fltk/fl_radio_button.h
  src/xtd/forms/native/fltk/fl_tab_control.h
  src/xtd/forms/native/fltk/fl_tab_page.h
  src/xtd/forms/native/fltk/fl_text_box.h
  src/xtd/forms/native/fltk/fl_timer.h
  src/xtd/forms/native/fltk/fl_track_bar.h
  src/xtd/forms/native/fltk/fl_user_control.h
  src/xtd/forms/native/fltk/font_dialog.cpp
  src/xtd/forms/native/fltk/form.cpp
  src/xtd/forms/native/fltk/group_box.cpp
  src/xtd/forms/native/fltk/label.cpp
  src/xtd/forms/native/fltk/list_box.cpp
  src/xtd/forms/native/fltk/message_box.cpp
  src/xtd/forms/native/fltk/panel.cpp
  src/xtd/forms/native/fltk/progress_bar.cpp
  src/xtd/forms/native/fltk/radio_button.cpp
  src/xtd/forms/native/fltk/screen.cpp
  src/xtd/forms/native/fltk/tab_control.cpp
  src/xtd/forms/native/fltk/tab_page.cpp
  src/xtd/forms/native/fltk/text_box.cpp
  src/xtd/forms/native/fltk/timer.cpp
  src/xtd/forms/native/fltk/track_bar.cpp
  src/xtd/forms/native/fltk/user_control.cpp
)

if (APPLE)
  set(XTD_FORMS_NATIVE_FLTK_SOURCES ${XTD_FORMS_NATIVE_FLTK_SOURCES}
    src/xtd/forms/native/fltk/cursor.mm
  )
endif()

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(src\\xtd\\forms\\native\\fltk FILES ${XTD_FORMS_NATIVE_FLTK_SOURCES})

# Add packages
find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_NATIVE_FLTK_SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.forms.native ${FLTK_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  "include(CMakeFindDependencyMacro)\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
  "\n"
  "find_package(xtd.forms.native REQUIRED)\n"
  "find_package(wxWidgets REQUIRED)\n"
  "\n"
  "get_filename_component(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\" ABSOLUTE)\n"
  "get_filename_component(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\" ABSOLUTE)\n"
  "\n"
  "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME})\n"
  "set(${PROJECT_NAME}_FOUND TRUE)\n"
  "\n"
  "set(CMAKE_CXX_STANDARD 17)\n"
  "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
  "if (MSVC)\n"
  "  set(CMAKE_CXX_FLAGS \"\${CMAKE_CXX_FLAGS} /utf-8\")\n"
  "  set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup\")\n"
  "endif ()\n"
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)
install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
