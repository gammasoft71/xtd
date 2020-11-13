cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core VERSION 1.0.0)
set(XTD_INCLUDES
  include/xtd/__opaque_environment.h
  include/xtd/action.h
  include/xtd/argument_exception.h
  include/xtd/argument_null_exception.h
  include/xtd/argument_out_of_range_exception.h
  include/xtd/arithmetic_exception.h
  include/xtd/bit_converter.h
  include/xtd/block_scope.h
  include/xtd/caller_info.h
  include/xtd/delegate.h
  include/xtd/divided_by_zero_exception.h
  include/xtd/domain_exception.h
  include/xtd/environment.h
  include/xtd/environment_variable_target.h
  include/xtd/event.h
  include/xtd/event_args.h
  include/xtd/event_handler.h
  include/xtd/format.h
  include/xtd/format_exception.h
  include/xtd/func.h
  include/xtd/guid.h
  include/xtd/icomparable.h
  include/xtd/iequatable.h
  include/xtd/index_out_of_range_exception.h
  include/xtd/interface.h
  include/xtd/invalid_cast_exception.h
  include/xtd/invalid_operation_exception.h
  include/xtd/invalid_program_exception.h
  include/xtd/istring.h
  include/xtd/length_exception.h
  include/xtd/literals.h
  include/xtd/nameof.h
  include/xtd/not_finite_number_exception.h
  include/xtd/not_implemented_exception.h
  include/xtd/not_supported_exception.h
  include/xtd/null_pointer_exception.h
  include/xtd/number_styles.h
  include/xtd/object.h
  include/xtd/operation_canceled_exception.h
  include/xtd/operating_system.h
  include/xtd/overflow_exception.h
  include/xtd/overload.h
  include/xtd/parse.h
  include/xtd/platform_id.h
  include/xtd/platform_not_supported_exception.h
  include/xtd/predicate.h
  include/xtd/startup.h
  include/xtd/static.h
  include/xtd/string_comparison.h
  include/xtd/string_split_options.h
  include/xtd/strings.h
  include/xtd/system_exception.h
  include/xtd/time_out_exception.h
  include/xtd/to_string.h
  include/xtd/typeof.h
  include/xtd/underflow_exception.h
  include/xtd/unused.h
  include/xtd/using.h
  include/xtd/va_args_comma.h
  include/xtd/version.h
  include/xtd/xml_syntax_exception.h
  include/xtd/xtd.core
  include/xtd/xtd.core.h
)
set(XTD_COLLECTIONS_INCLUDES
  include/xtd/collections/any_pair.h
  include/xtd/collections/key_not_found_exception.h
  include/xtd/collections/vector_list.h
)
set(XTD_COLLECTIONS_SPECIALIZED_INCLUDES
  include/xtd/collections/specialized/string_map.h
  include/xtd/collections/specialized/string_pair.h
  include/xtd/collections/specialized/string_vector.h
)
set(XTD_DIAGNOSTICS_INCLUDES
  include/xtd/diagnostics/console_trace_listener.h
  include/xtd/diagnostics/cdebug.h
  include/xtd/diagnostics/ctrace.h
  include/xtd/diagnostics/debug.h
  include/xtd/diagnostics/debugstreambuf.h
  include/xtd/diagnostics/default_trace_listener.h
  include/xtd/diagnostics/event_type_filter.h
  include/xtd/diagnostics/ostream_trace_listener.h
  include/xtd/diagnostics/process.h
  include/xtd/diagnostics/process_start_info.h
  include/xtd/diagnostics/process_window_style.h
  include/xtd/diagnostics/source_filter.h
  include/xtd/diagnostics/source_levels.h
  include/xtd/diagnostics/source_switch.h
  include/xtd/diagnostics/switch_base.h
  include/xtd/diagnostics/trace.h
  include/xtd/diagnostics/trace_event_cache.h
  include/xtd/diagnostics/trace_event_type.h
  include/xtd/diagnostics/trace_filter.h
  include/xtd/diagnostics/trace_level.h
  include/xtd/diagnostics/trace_listener.h
  include/xtd/diagnostics/trace_listener_collection.h
  include/xtd/diagnostics/trace_options.h
  include/xtd/diagnostics/trace_source.h
  include/xtd/diagnostics/trace_switch.h
  include/xtd/diagnostics/tracestreambuf.h
)
set(XTD_DOCS_INCLUDES
  include/xtd/docs/format_page.h
  include/xtd/docs/main_page.h
)
set(XTD_INTERNAL_INCLUDES
  include/xtd/internal/__binary_formater.h
  include/xtd/internal/__boolean_formater.h
  include/xtd/internal/__character_formater.h
  include/xtd/internal/__currency_formater.h
  include/xtd/internal/__date_time_formater.h
  include/xtd/internal/__duration_formater.h
  include/xtd/internal/__enum_formater.h
  include/xtd/internal/__fixed_point_formater.h
  include/xtd/internal/__format.h
  include/xtd/internal/__format_information.h
  include/xtd/internal/__format_stringer.h
  include/xtd/internal/__natural_formater.h
  include/xtd/internal/__numeric_formater.h
  include/xtd/internal/__string_formater.h
)
set(XTD_IO_INCLUDES
  include/xtd/io/cnull.h
  include/xtd/io/directory_not_found_exception.h
  include/xtd/io/drive_not_found_exception.h
  include/xtd/io/end_of_stream_exception.h
  include/xtd/io/file.h
  include/xtd/io/file_attributes.h
  include/xtd/io/file_format_exception.h
  include/xtd/io/file_load_exception.h
  include/xtd/io/file_not_found_exception.h
  include/xtd/io/ioexception.h
  include/xtd/io/path.h
  include/xtd/io/path_too_long_exception.h
)
set(XTD_SOURCES
  src/xtd/__opaque_environment_gcc.cpp
  src/xtd/__opaque_environment_win32.cpp
  src/xtd/bit_converter.cpp
  src/xtd/environment.cpp
  src/xtd/event_args.cpp
  src/xtd/guid.cpp
  src/xtd/strings.cpp
  src/xtd/system_exception.cpp
)
set(XTD_DIAGNOSTICS_SOURCES
  src/xtd/diagnostics/debug.cpp
  src/xtd/diagnostics/default_trace_listener_gcc.cpp
  src/xtd/diagnostics/default_trace_listener_win32.cpp
  src/xtd/diagnostics/process.cpp
  src/xtd/diagnostics/process_start_info.cpp
  src/xtd/diagnostics/trace.cpp
)
set(XTD_IO_SOURCES
  src/xtd/io/file_gcc.cpp
  src/xtd/io/file_win32.cpp
  src/xtd/io/path_gcc.cpp
  src/xtd/io/path_win32.cpp
)
source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\collections FILES ${XTD_COLLECTIONS_INCLUDES})
source_group(include\\xtd\\collections\\specialized FILES ${XTD_COLLECTIONS_SPECIALIZED_INCLUDES})
source_group(include\\xtd\\diagnostics FILES ${XTD_DIAGNOSTICS_INCLUDES})
source_group(include\\xtd\\docs FILES ${XTD_DOCS_INCLUDES})
source_group(include\\xtd\\internal FILES ${XTD_INTERNAL_INCLUDES})
source_group(include\\xtd\\io FILES ${XTD_IO_INCLUDES})
source_group(src\\xtd FILES ${XTD_SOURCES})
source_group(src\\xtd\\diagnostics FILES ${XTD_DIAGNOSTICS_SOURCES})
source_group(src\\xtd\\io FILES ${XTD_IO_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_COLLECTIONS_INCLUDES} ${XTD_COLLECTIONS_SPECIALIZED_INCLUDES} ${XTD_DIAGNOSTICS_INCLUDES} ${XTD_DOCS_INCLUDES} ${XTD_INTERNAL_INCLUDES} ${XTD_IO_INCLUDES} ${XTD_SOURCES} ${XTD_DIAGNOSTICS_SOURCES} ${XTD_IO_SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include> PUBLIC ${UUID_INCLUDE_DIRS})
if(MSVC)
  target_link_libraries(${PROJECT_NAME} rpcrt4)
elseif (APPLE)
  target_link_libraries(${PROJECT_NAME})
elseif (ANDROID)
  target_link_libraries(${PROJECT_NAME})
elseif (UNIX)
  target_link_libraries(${PROJECT_NAME} uuid)
endif ()
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
