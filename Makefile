CC=gcc
FLAGS= -os -std=c99 -D_POSIX_SOURCE -D_GNU_SOURCE -fsplit-stack -g
LIST=list.c divide.c merge.c 
TRG=main

build:
	@$(CC) main.c $(LIST) $(FLAGS) -o $(TRG)

build_example:
	@$(CC) example.c $(LIST) $(FLAGS) -o example

run: build
	@./$(TRG)
	@gnuplot plot.gp

example: build_example
	@./example

clean:
	@rm -rf main example interval head_tail perf.*

interval:	
	@$(CC) interval.c $(LIST) $(FLAGS) -o interval
	perf stat ./interval

head_tail:	
	@$(CC) interval.c $(LIST) $(FLAGS) -o head_tail
	perf stat ./head_tail

