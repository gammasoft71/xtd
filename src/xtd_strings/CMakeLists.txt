cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.strings VERSION 0.1.1)
set(XTD_INCLUDES
  include/xtd/istring.h
  include/xtd/format.h
  include/xtd/number_styles.h
  include/xtd/parse.h
  include/xtd/string_comparison.h
  include/xtd/string_split_options.h
  include/xtd/strings.h
  include/xtd/to_string.h
  include/xtd/xtd.strings
  include/xtd/xtd.strings.h
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
set(XTD_SOURCES
  src/xtd/strings.cpp
)
source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\docs FILES ${XTD_DOCS_INCLUDES})
source_group(include\\xtd\\internal FILES ${XTD_INTERNAL_INCLUDES})
source_group(src FILES ${XTD_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_DOCS_INCLUDES} ${XTD_INTERNAL_INCLUDES} ${XTD_SOURCES})
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
