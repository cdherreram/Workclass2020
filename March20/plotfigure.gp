set key b r
set xlabel 'N'
set ylabel 'd%'
set log y
set title 'Percentual difference between equivalent sums'
set term pdf
set out "sumas.pdf"
plot 'datos.txt' u 1:2 w l t 'Sum2', '' u 1:3 w l t 'Sum3'