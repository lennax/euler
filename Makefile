CXXFLAGS = -g
CFLAGS = -g

help: 
	@echo "Select a problem to make."
	@grep ':' Makefile | sed -e /.*grep.*/d -e s/:.*//g -e /.*help.*/d
p18: p18.cpp
p27: p27.cpp
prime: prime.cpp
clean:
	rm -rf p18 prime
