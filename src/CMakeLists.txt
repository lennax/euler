# library
set(eulerCommonSource
	PrimeFinder.cpp
	)
set(eulerCommonHeaders
	PrimeFinder.hpp
	)
add_library(eulerCommon SHARED ${eulerCommonSource})

# problems
add_executable(p18 p18.cpp)

add_executable(p19 p19.cpp)

add_executable(p27 p27.cpp)
target_link_libraries(p27 eulerCommon)

add_executable(p29 p29.cpp)

add_executable(p36 p36.cpp)

add_executable(prime prime.cpp)
target_link_libraries(prime eulerCommon)

# installed programs
install(TARGETS p18 DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS prime DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
