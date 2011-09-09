# library
set(eulerCommonSource
	PrimeFinder.cpp
	utilities.cpp
	matrix.cpp
	)
set(eulerCommonHeaders
	PrimeFinder.hpp
	utilities.hpp
	matrix.hpp
	)
add_library(eulerCommon SHARED ${eulerCommonSource})
target_link_libraries(eulerCommon ${GMP_LIBRARY} ${GMPXX_LIBRARY})

include_directories(${GMP_INCLUDE_DIR})
#link_libraries(${GMP_LIBRARY})

# problems

add_executable(bitmask bitmask.cpp)

add_executable(p2 p2.cpp)
target_link_libraries(p2 eulerCommon ${GMPXX_LIBRARY})

add_executable(fibs_test fibs_test.cpp)
target_link_libraries(fibs_test eulerCommon ${GMPXX_LIBRARY})

add_executable(gmp_test gmp_test.cpp)
target_link_libraries(gmp_test ${GMP_LIBRARY} ${GMPXX_LIBRARY})

add_executable(p18 p18.cpp)
target_link_libraries(p18 eulerCommon)

add_executable(p19 p19.cpp)

add_executable(p25 p25.cpp)
target_link_libraries(p25 eulerCommon ${GMP_LIBRARY} ${GMPXX_LIBRARY})

add_executable(p27 p27.cpp)
target_link_libraries(p27 eulerCommon)

add_executable(p29 p29.cpp)

add_executable(p36 p36.cpp)
target_link_libraries(p36 eulerCommon)

add_executable(p39 p39.cpp)

# F p297! 
#add_executable(p297 p297.cpp)
#target_link_libraries(p297 eulerCommon ${GMPXX_LIBRARY})

add_executable(prime prime.cpp)
target_link_libraries(prime eulerCommon)

add_executable(sudoku sudoku.cpp)
target_link_libraries(sudoku eulerCommon)

# installed programs
#install(TARGETS p18 DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS prime DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
