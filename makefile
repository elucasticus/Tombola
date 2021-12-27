CXX=g++
CPPFLAGS+=-Wall
HEADERS=$(wildcard *.hpp)
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)


main:$(OBJS)
	$(CXX) $(CPPFLAGS) -o main $^

main.o:main.cpp 
	$(CXX) $(CPPFLAGS) -c $^

tabellone.o:tabellone.cpp
	$(CXX) $(CPPFLAGS) -c $^


clean:
	@rm $(wildcard *.o) $(wildcard *.txt) main