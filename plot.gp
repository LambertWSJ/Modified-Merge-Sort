reset
set ylabel 'time(nsec)'
set title 'Performance comparison'
set term png enhanced font 'Verdana,10'
set output 'benchmark.png'
set xlabel 'experiment'
data = 'benchmark.txt'


plot [][] 'benchmark.txt' using 1 with line title 'rec', \
'' using 2 with line title 'head-tail', \
'' using 3 with line title 'interval', \


# plot [][] 'interval.txt' using 1 with line title 'interval'
# plot [][] 'head_tail.txt' using 1 with line title 'head_tail'
