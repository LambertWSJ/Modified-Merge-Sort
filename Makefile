CC=gcc
FLAGS= -o3 -std=c99 -D_POSIX_SOURCE -D_GNU_SOURCE -fsplit-stack -g
LIST=list.c divide.c merge.c 
TRG=main

build:
	@$(CC) main.c $(LIST) $(FLAGS) -o $(TRG)

build_example:
	@$(CC) example.c $(LIST) $(FLAGS) -o example

run: build
	@./$(TRG)
	@gnuplot ./scripts/plot.gp

example: build_example
	@./example

clean:
	@rm -rf main example interval head_tail perf.* *.png *.txt ./data/*.txt ./plots/*.png
plot:
	gnuplot ./scripts/plot.gp
interval:	
	@$(CC) interval.c $(LIST) $(FLAGS) -o interval
	perf stat ./interval

head_tail:	
	@$(CC) interval.c $(LIST) $(FLAGS) -o head_tail
	perf stat ./head_tail
recursive:	
	@$(CC) recursive.c $(LIST) $(FLAGS) -o recursive
	perf stat ./recursive

addr:
	@$(CC) addr.c $(LIST) $(FLAGS) -o addr
	@./addr
	@rm -rf addr
	@gnuplot addr.gp
	@gnuplot rand_addr.gp