cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.native.wxwidgets VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.forms.native.wxwidgets.hpp
  include/xtd/xtd.forms.native.wxwidgets
)

set(XTD_FORMS_NATIVE_WXWIDGETS_SOURCES
  src/xtd/forms/native/wxwidgets/application.cpp
  src/xtd/forms/native/wxwidgets/button.cpp
  src/xtd/forms/native/wxwidgets/check_box.cpp
  src/xtd/forms/native/wxwidgets/checked_list_box.cpp
  src/xtd/forms/native/wxwidgets/combo_box.cpp
  src/xtd/forms/native/wxwidgets/control.cpp
  src/xtd/forms/native/wxwidgets/cursor.cpp
  src/xtd/forms/native/wxwidgets/cursors.cpp
  src/xtd/forms/native/wxwidgets/control_handler.hpp
  src/xtd/forms/native/wxwidgets/form.cpp
  src/xtd/forms/native/wxwidgets/group_box.cpp
  src/xtd/forms/native/wxwidgets/hdc_wrapper.hpp
  src/xtd/forms/native/wxwidgets/label.cpp
  src/xtd/forms/native/wxwidgets/list_box.cpp
  src/xtd/forms/native/wxwidgets/message_box.cpp
  src/xtd/forms/native/wxwidgets/panel.cpp
  src/xtd/forms/native/wxwidgets/progress_bar.cpp
  src/xtd/forms/native/wxwidgets/radio_button.cpp
  src/xtd/forms/native/wxwidgets/screen.cpp
  src/xtd/forms/native/wxwidgets/text_box.cpp
  src/xtd/forms/native/wxwidgets/timer.cpp
  src/xtd/forms/native/wxwidgets/track_bar.cpp
  src/xtd/forms/native/wxwidgets/wx_application.hpp
  src/xtd/forms/native/wxwidgets/wx_button.hpp
  src/xtd/forms/native/wxwidgets/wx_check_box.hpp
  src/xtd/forms/native/wxwidgets/wx_checked_list_box.hpp
  src/xtd/forms/native/wxwidgets/wx_combo_box.hpp
  src/xtd/forms/native/wxwidgets/wx_control.hpp
  src/xtd/forms/native/wxwidgets/wx_form.hpp
  src/xtd/forms/native/wxwidgets/wx_group_box.hpp
  src/xtd/forms/native/wxwidgets/wx_label.hpp
  src/xtd/forms/native/wxwidgets/wx_list_box.hpp
  src/xtd/forms/native/wxwidgets/wx_panel.hpp
  src/xtd/forms/native/wxwidgets/wx_progress_bar.hpp
  src/xtd/forms/native/wxwidgets/wx_radio_button.hpp
  src/xtd/forms/native/wxwidgets/wx_text_box.hpp
  src/xtd/forms/native/wxwidgets/wx_timer.hpp
  src/xtd/forms/native/wxwidgets/wx_track_bar.hpp
)

if (APPLE)
  set(XTD_FORMS_NATIVE_WXWIDGETS_SOURCES ${XTD_FORMS_NATIVE_WXWIDGETS_SOURCES}
    src/xtd/forms/native/wxwidgets/cursor.mm
  )
endif()

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(src\\xtd\\forms\\native\\wxwidgets FILES ${XTD_FORMS_NATIVE_WXWIDGETS_SOURCES})

# Add packages
find_package(wxWidgets COMPONENTS base core html richtext xml)
include(${wxWidgets_USE_FILE})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_NATIVE_WXWIDGETS_SOURCES})
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.forms.native ${wxWidgets_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
