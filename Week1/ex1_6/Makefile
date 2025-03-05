CC = gcc


all: quadratic

quadratic: quadratic_solver.c get_coefficients.c solve.c print_solutions.c
	$(CC) -o quadratic quadratic_solver.c get_coefficients.c solve.c print_solutions.c -lm

clean_window:
	del quadratic.exe
