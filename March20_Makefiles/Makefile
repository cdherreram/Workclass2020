# $^ ->  todas las dependencias
# $< -> primera dependencia
# $@ -> nombre del target

CXX = g++
GN = 
CXXFLAGS= -fsanitize=address

all : suma.x datos.txt suma.pdf

suma.x : substractive.cpp
	$(CXX) $(CXXFLAGS) substractive.cpp -o suma.x

datos.txt : suma.x
	./$^ > $@

suma.pdf : datos.txt plotfigure.gp
	gnuplot plotfigure.gp

clean :
	rm -f datos.txt suma.x a.out suma.pdf *~
