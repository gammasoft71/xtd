cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.strings VERSION 0.1.1)
set(INCLUDES
  include/xtd/__binary_formater.hpp
  include/xtd/__boolean_formater.hpp
  include/xtd/__character_formater.hpp
  include/xtd/__currency_formater.hpp
  include/xtd/__date_time_formater.hpp
  include/xtd/__duration_formater.hpp
  include/xtd/__enum_formater.hpp
  include/xtd/__fixed_point_formater.hpp
  include/xtd/__format.hpp
  include/xtd/__format_information.hpp
  include/xtd/__format_stringer.hpp
  include/xtd/__natural_formater.hpp
  include/xtd/__numeric_formater.hpp
  include/xtd/__string_formater.hpp
  include/xtd/istring.hpp
  include/xtd/format.hpp
  include/xtd/format_page.hpp
  include/xtd/main_page.hpp
  include/xtd/number_styles.hpp
  include/xtd/parse.hpp
  include/xtd/string_comparison.hpp
  include/xtd/string_split_options.hpp
  include/xtd/strings.hpp
  include/xtd/to_string.hpp
  include/xtd/xtd.strings
  include/xtd/xtd.strings.hpp
)
set(SOURCES
  src/strings.cpp
)
source_group(include FILES ${INCLUDES})
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
 add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

# Library properties
add_library(${PROJECT_NAME} STATIC ${INCLUDES} ${SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
