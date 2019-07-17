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
  include/xtd/forms/control.hpp
  include/xtd/forms/form.hpp
  include/xtd/forms/key_event_args.hpp
  include/xtd/forms/key_event_handler.hpp
  include/xtd/forms/key_press_event_args.hpp
  include/xtd/forms/key_press_event_handler.hpp
  include/xtd/forms/keys.hpp
  include/xtd/forms/label.hpp
  include/xtd/forms/message.hpp
  include/xtd/forms/mouse_buttons.hpp
  include/xtd/forms/mouse_event_args.hpp
  include/xtd/forms/mouse_event_handler.hpp
  include/xtd/forms/window_messages.hpp
  include/xtd/forms/window_message_keys.hpp
)

set(XTD_FORMS_SOURCES
  src/xtd/forms/application.cpp
  src/xtd/forms/button.cpp
  src/xtd/forms/control.cpp
  src/xtd/forms/form.cpp
  src/xtd/forms/forms.cpp
  src/xtd/forms/label.cpp
  src/xtd/forms/message.cpp
  src/xtd/forms/window_messages.cpp
)

set(NATIVE_SOURCES
  src/native/application_api.hpp
  src/native/button_api.hpp
  src/native/control_api.hpp
  src/native/form_api.hpp
  src/native/label_api.hpp
)

set(NATIVE_WXWIDGETS_SOURCES
  src/native/wxwidgets/control_handler.hpp
  src/native/wxwidgets/application_wxwidgets.cpp
  src/native/wxwidgets/button_wxwidgets.cpp
  src/native/wxwidgets/control_wxwidgets.cpp
  src/native/wxwidgets/form_wxwidgets.cpp
  src/native/wxwidgets/label_wxwidgets.cpp
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
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_INCLUDES} ${XTD_FORMS_SOURCES} ${NATIVE_SOURCES} ${NATIVE_WXWIDGETS_SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.delegates xtd.diagnostics xtd.drawing xtd.environment xtd.io xtd.strings ${wxWidgets_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  "include(CMakeFindDependencyMacro)\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
  "\n"
  "find_package(xtd.delegates REQUIRED)\n"
  "find_package(xtd.diagnostics REQUIRED)\n"
  "find_package(xtd.drawing REQUIRED)\n"
  "find_package(xtd.environment REQUIRED)\n"
  "find_package(xtd.io REQUIRED)\n"
  "find_package(xtd.strings REQUIRED)\n"
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
