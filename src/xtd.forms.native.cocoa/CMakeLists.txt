cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.native.cocoa VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.forms.native.cocoa.h
  include/xtd/xtd.forms.native.cocoa
)

set(XTD_FORMS_NATIVE_COCOA_SOURCES
  src/xtd/forms/native/cocoa/forms.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(src\\xtd\\forms\\native\\cocoa FILES ${XTD_FORMS_NATIVE_COCOA_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add packages
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa")

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_NATIVE_COCOA_SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.forms.native)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT xtd DESTINATION lib)
