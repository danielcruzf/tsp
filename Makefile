CXX = g++
CXXFLAGS = -Ofast -march=native -ffast-math -std=c++17 -ltbb#  -flto -funroll-loops -fopenmp

output: main.o getdata.o util.o
	${CXX} main.o getdata.o util.o -o output

getdata.o: getdata.hpp util.hpp
util.o: util.hpp
main.o: getdata.hpp util.hpp

clean:
	rm *.o output