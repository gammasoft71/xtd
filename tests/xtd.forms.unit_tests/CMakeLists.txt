cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.unit_tests)

set(SOURCES
  src/main.cpp 
)
set(FORMS_SOURCES
  src/forms/control.cpp 
  src/forms/form.cpp
)
set(FORMS_LAYOUT_SOURCES
  src/forms/layout/arranged_element_collection.cpp 
)
source_group(src FILES ${SOURCES})
source_group(src\\forms FILES ${FORMS_SOURCES})
source_group(src\\forms\\layout FILES ${FORMS_LAYOUT_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target
add_executable(${PROJECT_NAME} ${SOURCES} ${FORMS_SOURCES} ${FORMS_LAYOUT_SOURCES})
target_link_libraries(${PROJECT_NAME} xtd.forms ${XTD_FORMS_NATIVE_LIBRARY} ${XTD_NATIVE_LIBRARY} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tests")

# Tests
#add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
