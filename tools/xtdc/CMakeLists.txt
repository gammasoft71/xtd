cmake_minimum_required(VERSION 3.3)

#Project
project(xtdc)
set(SOURCES
  src/project_language.h
  src/project_management.h
  src/project_sdk.h
  src/project_type.h
  src/xtdc.cpp
)
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-D__XTD_FORMS_RESOURCES_PATH__="${CMAKE_INSTALL_PREFIX}")

# Target
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} xtd.core)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tools")

install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} RUNTIME DESTINATION bin RENAME xtd)
