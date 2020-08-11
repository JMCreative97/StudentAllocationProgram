#Makefile
# the C++ compiler
 CXX = g++ 
 CXXVERSION = $(shell g++ --version | grep ^g++ | sed 's/^.* //g')

CXXFLAGS = -O0 -g3 -std=c++14 

ifeq "$(CXXVERSION)" "4.6.3" 
	CXXFLAGS += -std=c++0x 
else 
	CXXFLAGS += -std=c++11
endif 

All: all 
all: main 

main: main.cpp Student.o Project.o Staff.o
	$(CXX) $(CXXFLAGS) main.cpp -o main

Student.o: Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -c Student.cpp -o Student.o

Project.o: Project.cpp Project.h
	$(CXX) $(CXXFLAGS) -c Project.cpp -o Project.o

Staff.o: Staff.cpp Staff.h
	$(CXX) $(CXXFLAGS) -c Staff.cpp -o Staff.o
	
deepclean: 
	rm -f *~ *.o *.gch main *.exe *.stackdump

clean: 
	-rm -f *~ *.o *.gch *.stackdump 