# Install script for directory: /home/willsong/advdb/src/dbt2

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/bin/dbt2-client;/bin/dbt2-datagen;/bin/dbt2-driver;/bin/dbt2-transaction-test;/bin/dbt2-generate-report;/bin/dbt2-get-os-info;/bin/dbt2-post-process;/bin/dbt2-run-workload;/bin/dbt2-sysstats;/bin/dbt2-plot-transaction-rate;/bin/dbt2-sqlite-build-db;/bin/dbt2-sqlite-plans;/bin/dbt2-sqlite-start-db;/bin/dbt2-sqlite-stop-db")
FILE(INSTALL DESTINATION "/bin" TYPE PROGRAM FILES
    "/home/willsong/advdb/src/dbt2/bin/dbt2-client"
    "/home/willsong/advdb/src/dbt2/bin/dbt2-datagen"
    "/home/willsong/advdb/src/dbt2/bin/dbt2-driver"
    "/home/willsong/advdb/src/dbt2/bin/dbt2-transaction-test"
    "/home/willsong/advdb/src/dbt2/bin/dbt2-generate-report"
    "/home/willsong/advdb/src/dbt2/bin/dbt2-get-os-info"
    "/home/willsong/advdb/src/dbt2/bin/dbt2-post-process"
    "/home/willsong/advdb/src/dbt2/bin/dbt2-run-workload"
    "/home/willsong/advdb/src/dbt2/bin/dbt2-sysstats"
    "/home/willsong/advdb/src/dbt2/bin/dbt2-plot-transaction-rate"
    "/home/willsong/advdb/src/dbt2/bin/sqlite/dbt2-sqlite-build-db"
    "/home/willsong/advdb/src/dbt2/bin/sqlite/dbt2-sqlite-plans"
    "/home/willsong/advdb/src/dbt2/bin/sqlite/dbt2-sqlite-start-db"
    "/home/willsong/advdb/src/dbt2/bin/sqlite/dbt2-sqlite-stop-db"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/willsong/advdb/src/dbt2/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/willsong/advdb/src/dbt2/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
