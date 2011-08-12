# library
set(eulerCommonSource
	PrimeFinder.cpp
	utilities.cpp
	)
set(eulerCommonHeaders
	PrimeFinder.hpp
	utilities.hpp
	)
add_library(eulerCommon SHARED ${eulerCommonSource})

include_directories(${GMP_INCLUDE_DIR})
#link_libraries(${GMP_LIBRARY})

# problems
#add_executable(p18 p18.cpp)

add_executable(matrix matrix.cpp)

add_executable(gmp_test gmp_test.cpp)
target_link_libraries(gmp_test ${GMP_LIBRARY} ${GMPXX_LIBRARY})

add_executable(p19 p19.cpp)

add_executable(p25 p25.cpp)
target_link_libraries(p25 eulerCommon ${GMP_LIBRARY} ${GMPXX_LIBRARY})

add_executable(p27 p27.cpp)
target_link_libraries(p27 eulerCommon)

add_executable(p29 p29.cpp)

add_executable(p36 p36.cpp)
target_link_libraries(p36 eulerCommon)

add_executable(prime prime.cpp)
target_link_libraries(prime eulerCommon)

# installed programs
#install(TARGETS p18 DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS prime DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
