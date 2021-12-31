reset
set ylabel 'time(nsec)'
# set title 'Divide comparison'
set title 'Merge comparison'
# set title 'Merge Sort comparison'
set term png enhanced font 'Verdana,10'
set output './plots/benchmark.png'
set xlabel 'epochs'
data = './data/benchmark.txt'


# plot [][] data using 1 with line title 'fast-slow', \
# '' using 2 with line title 'div-single', \
# '' using 3 with line title 'div-sorted', \

plot [][] data using 1 with line title 'head-tail', \
'' using 2 with line title 'interval', \
'' using 3 with line title 'D-a-C', \



# plot [][] data using 1 with line title 'iterative', \
# '' using 2 with line title 'recursive', 