cmake_minimum_required(VERSION 3.3)

#Project
project(xtdc-gui)
set(SOURCES
  src/main_form.h
  src/main_form.cpp
)
set(PROPERTIES
  properties/startup.cpp
)
# Options)
source_group(src FILES ${SOURCES})
source_group(properties FILES ${PROPERTIES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-D__XTD_FORMS_RESOURCES_PATH__="${CMAKE_INSTALL_PREFIX}")

# Target
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES} ${PROPERTIES})
target_link_libraries(${PROJECT_NAME} xtd.forms)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tools")

install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION bin)
