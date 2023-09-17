COMPILER = g++ # TODO: Compilers are traditionally named $(CC) or $(CXX) in makefiles
FLAGS = -g -ggdb3
DOP_FLAGS = -Wall -Wextra # TODO: What is DOP_FLAGS? Use a better name!
ASSAN = -fsanitize=address

FLAGS += $(DOP_FLAGS)
# FLAGS += $(ASSAN)


all: onegin

# TODO: Don't .o depend on some headers? What will happend if you forget to include them?)
#       (also, is it possible to somehow write this shorter?)
function.o: functions.cpp
	$(COMPILER) -c functions.cpp -o functions.o $(FLAGS)

main.o: main.cpp
	$(COMPILER) -c main.cpp -o main.o $(FLAGS)

onegin: functions.o main.o
	$(COMPILER)  functions.o main.o -o onegin.exe $(FLAGS)

# TODO: Don't include binary files (e.g. .exe files), git wasn't designed to work with them,
#       they make repositories slow, big, and it's almost impossible to rebase with them.

#       Also, it's hard to sync them, and if you don't, what is the point?
