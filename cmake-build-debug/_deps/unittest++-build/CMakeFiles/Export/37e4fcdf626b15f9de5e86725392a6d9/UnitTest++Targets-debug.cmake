#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "UnitTest++::UnitTest++" for configuration "Debug"
set_property(TARGET UnitTest++::UnitTest++ APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(UnitTest++::UnitTest++ PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libUnitTest++-d.a"
  )

list(APPEND _cmake_import_check_targets UnitTest++::UnitTest++ )
list(APPEND _cmake_import_check_files_for_UnitTest++::UnitTest++ "${_IMPORT_PREFIX}/lib/libUnitTest++-d.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
