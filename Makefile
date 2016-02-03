
INCLUDEPATH=-I /usr/include/glib-2.0/ -I /usr/lib/i386-linux-gnu/glib-2.0/include/

LDLIBS=-lfl -lc -lglib-2.0

EXECUTABLE=t1

all : $(EXECUTABLE)

 
$(EXECUTABLE) : parse.tab.o $(EXECUTABLE).yy.o main.o 
	g++ -o t1 parse.tab.o $(EXECUTABLE).yy.o main.o $(LDLIBS)
	
$(EXECUTABLE).yy.o : $(EXECUTABLE).yy.c
	g++ -c $(INCLUDEPATH) -o $(EXECUTABLE).yy.o $(EXECUTABLE).yy.c  

main.o : main.cpp parse.tab.c
	g++ -x c++ -c $(INCLUDEPATH) -o main.o main.cpp

$(EXECUTABLE).yy.c : $(EXECUTABLE).l 
	flex --outfile=$(EXECUTABLE).yy.c $(EXECUTABLE).l

parse.tab.o : parse.tab.c
	g++ -c $(INCLUDEPATH) -o parse.tab.o parse.tab.c
	
parse.tab.c : parse.y 
	bison -d -v parse.y

clean :
	rm -f $(EXECUTABLE).yy.c
	rm -f $(EXECUTABLE).yy.o
	rm -f parse.tab.c
	rm -f parse.tab.o
	rm -f parse.tab.h
	rm -f main.o
	rm -f $(EXECUTABLE)

test :
	./$(EXECUTABLE) < test.bas
	

