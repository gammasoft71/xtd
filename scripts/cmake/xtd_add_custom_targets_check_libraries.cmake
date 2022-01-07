option(XTD_ENABLE_CPPCHECK "Enable run cppcheck command" OFF)
option(XTD_DOWNLOAD_CPPCHECK "Download and build cppcheck from Github" OFF)
  
if (XTD_ENABLE_CPPCHECK)
  # cppcheck command line arguments
  list(APPEND CPPCHECK_ARGS
    --enable=warning,style,performance,portability
    --error-exitcode=1
    -j 8
    --language=c++
    --report-progress
    --std=c++17
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
  
  # RUN_CPPCHECK
  list(APPEND CPPCHECK_ARGS_ALL ${CPPCHECK_ARGS} ${CMAKE_SOURCE_DIR}/src)
  configure_file(${CMAKE_SOURCE_DIR}/.cppcheck ${CMAKE_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(RUN_CPPCHECK COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_ALL} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})
  set_target_properties(RUN_CPPCHECK PROPERTIES FOLDER commands)
endif ()
