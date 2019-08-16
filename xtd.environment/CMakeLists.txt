cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.environment VERSION 1.0.0)
set(INCLUDES
  include/xtd/__opaque_environment.hpp
  include/xtd/environment.hpp
  include/xtd/environment_variable_target.hpp
  include/xtd/guid.hpp
  include/xtd/operating_system.hpp
  include/xtd/platform_id.hpp
  include/xtd/version.hpp
  include/xtd/xtd.environment
  include/xtd/xtd.environment.hpp
)
set(SOURCES
  src/__opaque_environment_gcc.cpp
  src/__opaque_environment_win32.cpp
  src/environment.cpp
  src/guid.cpp
)
source_group(include FILES ${INCLUDES})
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${INCLUDES} ${SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include> PUBLIC ${UUID_INCLUDE_DIRS})
if(MSVC)
  target_link_libraries(${PROJECT_NAME} xtd.io xtd.strings rpcrt4)
elseif (APPLE)
  target_link_libraries(${PROJECT_NAME} xtd.io xtd.strings)
elseif (ANDROID)
  target_link_libraries(${PROJECT_NAME} xtd.io xtd.strings)
elseif (UNIX)
  target_link_libraries(${PROJECT_NAME} xtd.io xtd.strings uuid)
endif ()
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
