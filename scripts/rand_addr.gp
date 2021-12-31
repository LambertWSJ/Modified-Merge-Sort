reset
set title 'node address - shuffle'
set term png enhanced font 'Verdana,10'
set output 'rand_addr.png'
set xlabel 'n-th node'
set ylabel 'addr'
data = 'rand_addr.txt'


plot [][] data using 1 with line title 'addr'