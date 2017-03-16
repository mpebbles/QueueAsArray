# Makefile for QueueAsArray.c

FLAGS   = -std=c99 -Wall
SOURCES = QueueAsArray.c
OBJECTS = QueueAsArray.o
EXEBIN  = QueueAsArray

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)
check :
	valgrind --leak-check=full ./$(EXEBIN)