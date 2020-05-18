#Makefile para ejecutar las funciones de la librería estandar
# $^ ->  todas las dependencias
# $< -> primera dependencia
# $@ -> nombre del target

CXX = g++
GP = gnuplot
CXXFLAGS = -std=c++17 -fsanitize=address

all : gamma.x legendre.x random.x legendre.txt legendre.pdf

gamma.x: gammaFunction.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

legendre.x: legendre.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

legendre.txt: legendre.x
	./$< > $@

legendre.pdf: legendre.cpp legendre.txt legendre.gp
	$(GP) legendre.gp

random.x: randomNumbers.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	rm -f *.out *.x *.txt *~
