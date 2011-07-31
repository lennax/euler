help: 
	@echo "Select a problem to make."
	@grep ':' Makefile | sed -e /.*grep.*/d -e s/:.*//g -e /.*help.*/d
p18: p18.cpp
prime: prime.cpp
