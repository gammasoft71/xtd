# See http://astyle.sourceforge.net for more information

# Options
option(XTD_ENABLE_RUN_ASTYLE "Enable run astyle (format) command" ON)
option(XTD_DOWNLOAD_ASTYLE "Download and build astyle from Github" OFF)

if (XTD_ENABLE_RUN_ASTYLE)
  # astyle command line arguments
  list(APPEND ASTYLE_ARGS
    --style=java
    --lineend=linux
    --indent=spaces=2
    --attach-namespaces
    --attach-classes
    --attach-inlines
    --attach-extern-c
    --attach-closing-while
    --fill-empty-lines
    --indent-namespaces
    --indent-after-parens
    --indent-preproc-define
    --indent-preproc-cond
    --indent-col1-comments
    --indent-switches
    --pad-oper
    --pad-comma
    --pad-header
    --unpad-paren
    --align-pointer=type
    --align-reference=type
    --remove-braces
    --keep-one-line-blocks
    --keep-one-line-statements
    --convert-tabs
    --close-templates
    --suffix=none
    --recursive
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.mm
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/tests/*.cpp
    ${CMAKE_SOURCE_DIR}/tests/*.h
    ${CMAKE_SOURCE_DIR}/examples/*.cpp
    ${CMAKE_SOURCE_DIR}/examples/*.h
  )
  
  if (XTD_DOWNLOAD_ASTYLE)
    ExternalProject_Add(astyle GIT_REPOSITORY https://github.com/Bareflank/astyle.git GIT_TAG v1.2 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
    set(ASTYLE_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/astyle)
    set(ASTYLE_PROJECT astyle)
  else()
    set(ASTYLE_EXECUTABLE astyle)
  endif()

  # RUN_ASTYLE  
  add_custom_target(RUN_ASTYLE COMMAND ${ASTYLE_EXECUTABLE} ${ASTYLE_ARGS} COMMENT "running astyle" DEPENDS ${ASTYLE_PROJECT})
  set_target_properties(RUN_ASTYLE PROPERTIES FOLDER commands)
endif ()
