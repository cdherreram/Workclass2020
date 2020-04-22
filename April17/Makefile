all: main_factorial.x

main_factorial.x : main_factorial.o factorial.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $<

test: example_catch.x

example_catch.x : example_catch.o factorial.o
	g++ $^ -o $@

#main_factorial.o : main_factorial.cpp
#	g++ -c $<

#factorial.o : factorial.cpp
#	g++ -c $<

clean:
	rm -f *.o *.x
