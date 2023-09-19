C� = g++
FLAGS = -g -ggdb3
DEBAG_FLAGS = -Wall -Wextra
ASSAN = -lasan -fsanitize=address

FLAGS += $(DEBAG_FLAGS)
#FLAGS += $(ASSAN)


all: onegin

function.o: functions.cpp
	$(C�) -c functions.cpp -o functions.o $(FLAGS)

main.o: main.cpp
	$(C�) -c main.cpp -o main.o $(FLAGS)

onegin: functions.o main.o
	$(C�)  functions.o main.o -o onegin $(FLAGS)