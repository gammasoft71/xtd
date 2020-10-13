cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.diagnostics VERSION 1.0.0)
set(XTD_INCLUDES
  include/xtd/xtd.diagnostics
  include/xtd/xtd.diagnostics.h
)
set(XTD_DIAGNOSTICS_INCLUDES
  include/xtd/diagnostics/console_trace_listener.h
  include/xtd/diagnostics/cdebug.h
  include/xtd/diagnostics/ctrace.h
  include/xtd/diagnostics/debug.h
  include/xtd/diagnostics/debugstreambuf.h
  include/xtd/diagnostics/default_trace_listener.h
  include/xtd/diagnostics/ostream_trace_listener.h
  include/xtd/diagnostics/trace.h
  include/xtd/diagnostics/trace_event_cache.h
  include/xtd/diagnostics/trace_event_type.h
  include/xtd/diagnostics/trace_level.h
  include/xtd/diagnostics/trace_listener.h
  include/xtd/diagnostics/trace_listener_collection.h
  include/xtd/diagnostics/trace_options.h
  include/xtd/diagnostics/trace_switch.h
  include/xtd/diagnostics/tracestreambuf.h
)
set(SOURCES
  src/debug.cpp
  src/diagnostics.cpp
  src/default_trace_listener_gcc.cpp
  src/default_trace_listener_win32.cpp
  src/trace.cpp
)
source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\diagnostics FILES ${XTD_DIAGNOSTICS_INCLUDES})
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_DIAGNOSTICS_INCLUDES} ${SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include> PUBLIC ${UUID_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} xtd.io xtd.strings)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
