#!/bin/bash

MAKEARGS="-j8"

function menu {
	while [ 1 ] 
	do
		echo -n "Please enter your choice: " && read OPT
		echo 
		echo 1. in_source_build: is used for development.
		echo 2. install_build: is used for building before final installation to the system.
		echo 3. grab_debian_dependencies: installs all the required packages for debian based systems -- ubuntu maverick/ debian squeeze,lenny
		echo 4. package_source: creates a source package for distribution
		echo 5. package: creates binary packages for distribution
		echo 6. remake: calls make again after project has been configured as install or in source build
		echo 7. clean: removes the build directory 
		echo 8. end
	done
}

function in_source_build {
	echo you chose in source build
	mkdir -p build && cd build && cmake -DIN_SRC_BUILD:bool=TRUE .. && make $MAKEARGS
	exit 0
}
function install_build {
	echo you chose install build
	mkdir -p build && cd build && cmake .. && make $MAKEARGS
	exit 0
}
function grab_debian_dependencies {
	echo you chose to install debian dependencies
	sudo apt-get install cmake
	exit 0
}
function remake {
	echo you chose to recall make on the previously configured build
	cd build && make $MAKEARGS
	exit 0	
}
function package_source {
	echo you chose to package the source
	install_build && make package_source
	exit 0	
}
function package {
	echo you chose to package the binary
	install_build && make package
	exit 0
}
function clean {
	echo you chose to clean the build 
	rm -rf build
}
function end_program {
	exit 0
}


if [ $# = 1 ]
then 
	OPT=$1
else
	menu
fi

case $OPT in 
	1 ) in_source_build;;
	2 ) install_build;;
	3 ) grab_debian_dependencies;;
	4 ) remake;;
    5 ) package_source;;
	6 ) package;;
	7 ) clean;;
	8 ) end_program;;	
esac


