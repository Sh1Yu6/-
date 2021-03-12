src = $(wildcard *.cpp)
target = $(patsubst %.cpp, %.o, $(src))

all: $(target)
	g++  -o $@ $^

%.o: %.cpp
	g++ -c -o $@ $<

clear:
	rm -rf $(target)

.PHNOY:clear
