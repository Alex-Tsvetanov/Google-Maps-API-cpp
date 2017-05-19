FLAGS=-lcurl -lcurlpp -ljsoncpp -std=c++11 -I.
GCC=g++

all: build
compile: 
	$(GCC) -c api.cpp $(FLAGS)
convert: 
	ar rvs api.a api.o
build: compile convert
clear: 
	rm api.o api.a
