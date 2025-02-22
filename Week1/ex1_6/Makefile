CC = gcc


all: quadratic

quadratic: quadratic_solver.c get_coefficients.c solve.c print_solutions.c
	$(CC) -o quadratic quadratic_solver.c get_coefficients.c solve.c print_solutions.c

clean:
	del quadratic.exe || rm -f quadratic