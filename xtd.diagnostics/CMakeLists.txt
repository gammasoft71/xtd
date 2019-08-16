cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.diagnostics VERSION 1.0.0)
set(XTD_INCLUDES
  include/xtd/xtd.diagnostics
  include/xtd/xtd.diagnostics.hpp
)
set(XTD_DIAGNOSTICS_INCLUDES
  include/xtd/diagnostics/console_trace_listener.hpp
  include/xtd/diagnostics/cdebug.hpp
  include/xtd/diagnostics/ctrace.hpp
  include/xtd/diagnostics/debug.hpp
  include/xtd/diagnostics/debugstreambuf.hpp
  include/xtd/diagnostics/default_trace_listener.hpp
  include/xtd/diagnostics/ostream_trace_listener.hpp
  include/xtd/diagnostics/trace.hpp
  include/xtd/diagnostics/trace_event_cache.hpp
  include/xtd/diagnostics/trace_event_type.hpp
  include/xtd/diagnostics/trace_listener.hpp
  include/xtd/diagnostics/trace_listener_collection.hpp
  include/xtd/diagnostics/trace_options.hpp
  include/xtd/diagnostics/tracestreambuf.hpp
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
target_link_libraries(${PROJECT_NAME} xtd.environment xtd.io xtd.strings)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
