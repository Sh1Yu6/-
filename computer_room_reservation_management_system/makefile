src=$(wildcard *.cpp)
target=$(patsubst %.cpp, %.o, $(src))

all:$(target)
	g++ -std=c++17 $^ -o $@

%.o:%.cpp
	g++ -std=c++17 -c $< -o $@

clear:
	rm -rf $(target)

.PHNOY:clear
