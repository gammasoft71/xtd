cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core VERSION 1.0.0)
set(XTD_INCLUDES
  include/xtd/__opaque_environment.h
  include/xtd/argument_exception.h
  include/xtd/argument_null_exception.h
  include/xtd/argument_out_of_range_exception.h
  include/xtd/arithmetic_exception.h
  include/xtd/bit_converter.h
  include/xtd/block_scope.h
  include/xtd/caller_info.h
  include/xtd/divided_by_zero_exception.h
  include/xtd/domain_exception.h
  include/xtd/environment.h
  include/xtd/environment_variable_target.h
  include/xtd/format_exception.h
  include/xtd/guid.h
  include/xtd/icomparable.h
  include/xtd/iequatable.h
  include/xtd/index_out_of_range_exception.h
  include/xtd/interface.h
  include/xtd/literals.h
  include/xtd/nameof.h
  include/xtd/not_finite_number_exception.h
  include/xtd/object.h
  include/xtd/operating_system.h
  include/xtd/overflow_exception.h
  include/xtd/platform_id.h
  include/xtd/startup.h
  include/xtd/static.h
  include/xtd/system_exception.h
  include/xtd/typeof.h
  include/xtd/underflow_exception.h
  include/xtd/unused.h
  include/xtd/using.h
  include/xtd/va_args_comma.h
  include/xtd/version.h
  include/xtd/xtd.core
  include/xtd/xtd.core.h
)
set(XTD_COLLECTIONS_INCLUDES
  include/xtd/collections/any_pair.h
  include/xtd/collections/vector_list.h
)
set(XTD_COLLECTIONS_SPECIALIZED_INCLUDES
  include/xtd/collections/specialized/string_map.h
  include/xtd/collections/specialized/string_pair.h
  include/xtd/collections/specialized/string_vector.h
)
set(XTD_IO_INCLUDES
  include/xtd/io/directory_not_found_exception.h
  include/xtd/io/drive_not_found_exception.h
  include/xtd/io/end_of_stream_exception.h
  include/xtd/io/file_format_exception.h
  include/xtd/io/file_load_exception.h
  include/xtd/io/file_not_found_exception.h
  include/xtd/io/ioexception.h
  include/xtd/io/path_too_long_exception.h
)
set(SOURCES
  src/__opaque_environment_gcc.cpp
  src/__opaque_environment_win32.cpp
  src/bit_converter.cpp
  src/environment.cpp
  src/guid.cpp
)
source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\collections FILES ${XTD_COLLECTIONS_INCLUDES})
source_group(include\\xtd\\collections\\specialized FILES ${XTD_COLLECTIONS_SPECIALIZED_INCLUDES})
source_group(include\\xtd\\io FILES ${XTD_IO_INCLUDES})
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_COLLECTIONS_INCLUDES} ${XTD_COLLECTIONS_SPECIALIZED_INCLUDES} ${XTD_IO_INCLUDES} ${SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include> PUBLIC ${UUID_INCLUDE_DIRS})
if(MSVC)
  target_link_libraries(${PROJECT_NAME} xtd.delegates xtd.io xtd.strings rpcrt4)
elseif (APPLE)
  target_link_libraries(${PROJECT_NAME} xtd.delegates xtd.io xtd.strings)
elseif (ANDROID)
  target_link_libraries(${PROJECT_NAME} xtd.delegates xtd.io xtd.strings)
elseif (UNIX)
  target_link_libraries(${PROJECT_NAME} xtd.delegates xtd.io xtd.strings uuid)
endif ()
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
