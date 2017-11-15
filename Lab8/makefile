CXX = g++
CXXFLAGS =  -std=c++0x
CXXFLAGS +=   -Wall
CXXFLAGS +=   -pedantic-errors
CXXFLAGS +=   -g
#CXXFLAGS +=   -O3
LDFLAGS =  -lboost_date_time
OBJS = lab8Functions.o validateInput.o main.o
SRCS = lab8Functions.cpp validateInput.cpp main.cpp
HEADERS = lab8Functions.hpp validateInput.hpp
TXT = early.txt end.txt middle.txt numbers.txt

#target: dependencies
#rule to build
#

Lab8: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o Lab8

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c   $(@:.o=.cpp)

	
.PHONY: clean
clean:
	rm ${OBJS} Lab8

zip:
	zip -D ProjectName_Cooke_Emmet.zip ${HEADERS} ${SRCS} ${TXT} makefile
