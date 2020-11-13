cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.unit_tests)

set(SOURCES
  src/main.cpp 
)
set(FORMS_SOURCES
  src/forms/button.cpp 
  src/forms/check_box.cpp 
  src/forms/control.cpp 
  src/forms/form.cpp
  src/forms/lcd_label.cpp
  src/forms/list_box.cpp
  src/forms/main_menu.cpp
  src/forms/system_information.cpp
)
if (APPLE)
set(FORMS_SOURCES ${FORMS_SOURCES}
  src/forms/get_double_click_time.h 
  src/forms/get_double_click_time.mm 
)
endif()
set(FORMS_LAYOUT_SOURCES
  src/forms/layout/arranged_element_collection.cpp 
)
source_group(src FILES ${SOURCES})
source_group(src\\forms FILES ${FORMS_SOURCES})
source_group(src\\forms\\layout FILES ${FORMS_LAYOUT_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996")
endif ()

# Target
add_executable(${PROJECT_NAME} ${SOURCES} ${FORMS_SOURCES} ${FORMS_LAYOUT_SOURCES})
target_link_libraries(${PROJECT_NAME} xtd.forms ${XTD_FORMS_NATIVE_LIBRARY} ${XTD_NATIVE_LIBRARY} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tests")

# Tests
if (NOT DISABLE_FOMRS_TESTS)
  add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif ()