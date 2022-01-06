option(XTD_ADD_COMMAND_CPPCHECK "Add command cppcheck libraires" OFF)
option(XTD_DOWNLOAD_CPPCHECK "Download and build cppcheck from Github" OFF)
  
if (XTD_ADD_COMMAND_CPPCHECK)
  # cppcheck command line arguments
  list(APPEND CPPCHECK_ARGS
    --enable=warning,style,performance,portability
    --error-exitcode=1
    -j 8
    --language=c++
    --report-progress
    --std=c++14
    --suppressions-list=${CMAKE_BINARY_DIR}/cppcheck_false_positive
    --template='[{file}:{line}]: ({severity}) {{id}} {message}'
  )
  
  if (XTD_DOWNLOAD_CPPCHECK)
    ExternalProject_Add(cppcheck GIT_REPOSITORY https://github.com/danmar/cppcheck.git GIT_TAG 2.63 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
    set(CPPCHECK_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/cppcheck)
    set(CPPCHECK_PROJECT cppcheck)
  else()
    set(CPPCHECK_EXECUTABLE cppcheck)
  endif()
  
  # cppcheck All
  #list(APPEND CPPCHECK_ARGS_ALL ${CPPCHECK_ARGS} ${CMAKE_SOURCE_DIR}/src/xtd/src ${CMAKE_SOURCE_DIR}/src/xtd.core/src ${CMAKE_SOURCE_DIR}/src/xtd.drawing/src ${CMAKE_SOURCE_DIR}/src/xtd.forms/src ${CMAKE_SOURCE_DIR}/src/xtd.System.tunit/src)
  #configure_file(${CMAKE_SOURCE_DIR}/.cppcheck ${CMAKE_BINARY_DIR}/cppcheck_false_positive @ONLY)
  #add_custom_target(check COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_ALL} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})
  #set_target_properties(check PROPERTIES FOLDER commands)
  
  # cppcheck xtd
  list(APPEND CPPCHECK_ARGS_XTD ${CPPCHECK_ARGS} ${CMAKE_SOURCE_DIR}/src/xtd/src)
  configure_file(${CMAKE_SOURCE_DIR}/.cppcheck ${CMAKE_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(check.xtd COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_XTD} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})
  set_target_properties(check.xtd PROPERTIES FOLDER commands)
  
  # cppcheck xtd.core
  list(APPEND CPPCHECK_ARGS_XTD_CORE ${CPPCHECK_ARGS} ${CMAKE_SOURCE_DIR}/src/xtd.core/src)
  configure_file(${CMAKE_SOURCE_DIR}/.cppcheck ${CMAKE_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(check.xtd.core COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_XTD_CORE} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})
  set_target_properties(check.xtd.core PROPERTIES FOLDER commands)
  
  # cppcheck xtd.drawing
  list(APPEND CPPCHECK_ARGS_XTD_DRAWING ${CPPCHECK_ARGS} ${CMAKE_SOURCE_DIR}/src/xtd.drawing/src)
  configure_file(${CMAKE_SOURCE_DIR}/.cppcheck ${CMAKE_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(check.xtd.drawing COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_XTD_CORE} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})
  set_target_properties(check.xtd.drawing PROPERTIES FOLDER commands)
  
  # cppcheck xtd.forms
  list(APPEND CPPCHECK_ARGS_XTD_FORMS ${CPPCHECK_ARGS} ${CMAKE_SOURCE_DIR}/src/xtd.forms/src)
  configure_file(${CMAKE_SOURCE_DIR}/.cppcheck ${CMAKE_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(check.xtd.forms COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_XTD_CORE} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})
  set_target_properties(check.xtd.forms PROPERTIES FOLDER commands)
  endif ()
