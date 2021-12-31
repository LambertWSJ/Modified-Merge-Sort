reset
set title 'node address'
set term png enhanced font 'Verdana,10'
set output 'addr.png'
set xlabel 'n-th node'
set ylabel 'addr'
data = 'addr.txt'


plot [][] data using 1 with line title 'addr'