set xlabel 'x'
set ylabel 'Legendre polynomial'
set title 'Legendre polynomial for -1<x<1'
set term pdf
set out "legendre.pdf"
plot 'legendre.txt' w l