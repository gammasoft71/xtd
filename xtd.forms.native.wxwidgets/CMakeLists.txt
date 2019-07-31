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
  src/xtd/forms/native/wxwidgets/control.cpp
  src/xtd/forms/native/wxwidgets/control_handler.hpp
  src/xtd/forms/native/wxwidgets/form.cpp
  src/xtd/forms/native/wxwidgets/label.cpp
  src/xtd/forms/native/wxwidgets/message_box.cpp
  src/xtd/forms/native/wxwidgets/text_box.cpp
  src/xtd/forms/native/wxwidgets/timer.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(src\\xtd\\forms\\native\\wxwidgets FILES ${XTD_FORMS_NATIVE_WXWIDGETS_SOURCES})

# Add packages
find_package(wxWidgets COMPONENTS base core html richtext xml)
include(${wxWidgets_USE_FILE})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_NATIVE_WXWIDGETS_SOURCES})
if (MSVC)
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
