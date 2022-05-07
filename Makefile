FLAGS = -pedantic-errors -std=c++11

Game.o: Game.cpp Game.h
	g++ $(FLAGS) -c $<

execution.o: execution.cpp execution.h
	g++ $(FLAGS) -c $<

main.o: main.cpp Game.h execution.h
	g++ $(FLAGS) -c $<

main: Game.o execution.o main.o
	g++ $(FLAGS) $^ -o $@

clean: 
	rm -f main main.o execution.o Game.o

.PHONY: clean
