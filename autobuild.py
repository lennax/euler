#!/usr/bin/python 

import sys # for sys.argv[]
import os # for os.system()

def in_source_build():
	print "You chose in source build"
	os.system("mkdir -p build && cd build && cmake -DIN_SRC_BUILD::bool=TRUE .. && make -j8")

def install_build():
	print "You chose install build"
	os.system("mkdir -p build && cd build && cmake .. && make -j8")

def grab_debian_dependencies():
	print "You chose to install Debian dependencies"
	os.system("sudo apt-get install cmake")

def remake():
	print "You chose to recall make on the previously configured build"
	os.system("cd build && make -j8")

def package_source():
	print "You chose to package the source"
	os.system("mkdir -p build && cd build && cmake .. && make -j8 && make package_source")

def package():
	print "You chose to package the binary"
	os.system("mkdir -p build && cd build && cmake .. && make -j8 && make package")

def clean():
	print "You chose to clean the build"
	os.system("rm -rf build")

if len(sys.argv) == 2:
	opt = sys.argv[1]
	#print "Command line option: %s" % (sys.argv[1])
else:
	print "1. in_source_build: is used for development."
	print "2. install_build: is used for building before final installation to the system."
	print "3. grab_debian_dependencies: installs all the required packages for debian based systems (ubuntu maverick/ debian squeeze,lenny)"
	print "4. package_source: creates a source package for distribution"
	print "5. package: creates binary packages for distribution"
	print "6. remake: calls make again after project has been configured as install or in source build"
	print "7. clean: removes the build directory"
	print "8. end"
	opt = raw_input("Please choose an option: ")
	#print "Input option: %s" % (s)

opt = int(opt)

if (opt == 1):
	in_source_build()
elif (opt == 2):
	install_build()
elif (opt == 3): 
	grab_debian_dependencies()
elif (opt == 4):
	remake()
elif (opt == 5):
	package_source()
elif (opt == 6):
	package()
elif (opt == 7):
	clean()
elif (opt == 8):
	raise SystemExit

#print "Run cmake..."
#os.system("cmake --version")

makeargs="-j8"



#for i in range(len(sys.argv)):
	#print "sys.argv[%d] = %s" % (i, sys.argv[i])


