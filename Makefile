CXX = g++
CXX_FLAGS = -std=c++17 -Wall


all:	clean compile run
	
	

clean:
	rm -rf *.o
	rm -rf *.out

run:
	./main.out

compile:
	$(CXX) $(CXX_FLAGS) -c src/main.cpp src/vec3.cpp src/Scene1.cpp src/Scene2.cpp
	$(CXX) $(CXX_FLAGS) -o main.out main.o vec3.o Scene1.o Scene2.o