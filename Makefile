FLAGS=-lcurl -lcurlpp -std=c++11 -I./internal_libs -I./external_libs
GCC=g++

all: build
compile: 
	$(GCC) -c api.cpp $(FLAGS)
convert: 
	ar rvs api.a api.o
build: compile convert
test_build:
	$(GCC) api.cpp -o api.exe $(FLAGS)
test_run:
	./api.exe 2> log
clear: 
	rm -f api.o api.a log api.exe
