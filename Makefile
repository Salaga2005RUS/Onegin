COMPILER = g++
FLAGS = -g -ggdb3
DOP_FLAGS = -Wall -Wextra
ASSAN = -fsanitize=address

FLAGS += $(DOP_FLAGS)
# FLAGS += $(ASSAN)


all: onegin

function.o: functions.cpp
	$(COMPILER) -c functions.cpp -o functions.o $(FLAGS)

main.o: main.cpp
	$(COMPILER) -c main.cpp -o main.o $(FLAGS)

onegin: functions.o main.o
	$(COMPILER)  functions.o main.o -o onegin.exe $(FLAGS)