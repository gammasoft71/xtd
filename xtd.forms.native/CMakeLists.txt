cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.native VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.forms.native.hpp
  include/xtd/xtd.forms.native
)

set(XTD_FORMS_INCLUDES
  include/xtd/forms/create_params.hpp
  include/xtd/forms/window_messages.hpp
)

set(XTD_FORMS_NATIVE_INCLUDES
  include/xtd/forms/native/application.hpp
  include/xtd/forms/native/button.hpp
  include/xtd/forms/native/check_box.hpp
  include/xtd/forms/native/control.hpp
  include/xtd/forms/native/form.hpp
  include/xtd/forms/native/group_box.hpp
  include/xtd/forms/native/label.hpp
  include/xtd/forms/native/list_box.hpp
  include/xtd/forms/native/message_box.hpp
  include/xtd/forms/native/panel.hpp
  include/xtd/forms/native/progress_bar.hpp
  include/xtd/forms/native/radio_button.hpp
  include/xtd/forms/native/screen.hpp
  include/xtd/forms/native/text_box.hpp
  include/xtd/forms/native/timer.hpp
  include/xtd/forms/native/track_bar.hpp
  include/xtd/forms/native/window_button.hpp
  include/xtd/forms/native/window_list_box.hpp
  include/xtd/forms/native/window_message_box.hpp
  include/xtd/forms/native/window_message_keys.hpp
  include/xtd/forms/native/window_progress_bar.hpp
  include/xtd/forms/native/window_scroll_bar.hpp
  include/xtd/forms/native/window_static.hpp
  include/xtd/forms/native/window_styles.hpp
  include/xtd/forms/native/window_track_bar.hpp
)

set(SOURCES
  src/xtd.forms.native.cpp
)

set(XTD_FORMS_NATIVE_SOURCES
  src/xtd/forms/window_messages.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\forms FILES ${XTD_FORMS_INCLUDES})
source_group(include\\xtd\\forms\\native FILES ${XTD_FORMS_NATIVE_INCLUDES})
source_group(src FILES ${SOURCES})
source_group(src\\xtd\\forms\native FILES ${XTD_FORMS_NATIVE_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_INCLUDES} ${XTD_FORMS_NATIVE_INCLUDES} ${SOURCES} ${XTD_FORMS_NATIVE_SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.delegates xtd.diagnostics xtd.drawing xtd.environment xtd.io xtd.strings)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
