project (euler-lenna-james)

# Requried cmake version
cmake_minimum_required (VERSION 2.6)

# global needed variables
set(APPLICATION_NAME ${PROJECT_NAME})

set(APPLICATION_VERSION_MAJOR "0")
set(APPLICATION_VERSION_MINOR "0")
set(APPLICATION_VERSION_PATCH "0")

set(APPLICATION_VERSION "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}")
set(LIBRARY_VERSION ${APPLICATION_VERSION})

# SOVERSION scheme: CURRENT.AGE.REVISION
#   If there was an incompatible interface change:
#     Increment CURRENT. Set AGE and REVISION to 0
#   If there was a compatible interface change:
#     Increment AGE. Set REVISION to 0
#   If the source code was changed, but there were no interface changes:
#     Increment REVISION.
set(LIBRARY_SOVERSION "1.0.0")

# where to look first for cmake modules, before ${CMAKE_ROOT}/Modules/ is checked
set(CMAKE_MODULE_PATH
	${CMAKE_SOURCE_DIR}/cmake/Modules
)

# add definitions
include(DefineCMakeDefaults)
include(DefinePlatformDefaults)
include(DefineCompilerFlags)
include(DefineInstallationPaths)
include(DefineOptions.cmake)
include(CPackConfig.cmake)

# disallow in-source build
include(MacroEnsureOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build. 
Please create a separate build directory and run 'cmake /path/to/${PROJECT_NAME} [options]' there.")

# add macros
include(MacroAddPlugin)
include(MacroCopyFile)
include(MacroFindOrBuild)
include(MacroSetDefault)
include(language_support_v2)
include(MacroAddLinkFlags)

# settings
MacroSetDefault(BOOSTNUMERIBINDINGS_BUILD_FROM_SOURCE FALSE)
MacroSetDefault(STATIC_LINKING FALSE)
MacroSetDefault(IN_SRC_BUILD FALSE)

# built variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# only find static libraries
#if(STATIC_LINKING)
	#message(WARNING "static linking is not yet fully functional and will have linking errors")
	#if(WIN32)
		#set(CMAKE_FIND_LIBRARY_SUFFIXES .lib .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
	#else(WIN32)
		#set(CMAKE_FIND_LIBRARY_SUFFIXES .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
	#endif(WIN32)
#endif()

# set build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# enable languages
enable_language(C)
enable_language(CXX)
workaround_9220(Fortran Fortran_langurage_works)
if (Fortran_langurage_works)
	enable_language(Fortran OPTIONAL)
endif(Fortran_langurage_works)

# add make dist target
add_custom_target(dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)

# problems
add_executable(p18 src/p18.cpp)
add_executable(p27 src/p27.cpp)
add_executable(prime src/prime.cpp)

# installed programs
install(TARGETS p18 DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS prime DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
