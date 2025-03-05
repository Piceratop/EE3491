CC = gcc


all: ex1_1 ex1_2 ex1_3 ex1_4 ex1_5 ex1_6 ex1_7

ex1_1: ex1_1.c
	$(CC) -o ex1_1 ex1_1.c

ex1_2: ex1_2.c
	$(CC) -o ex1_2 ex1_2.c

ex1_3: ex1_3.c
	$(CC) -o ex1_3 ex1_3.c

ex1_4: ex1_4.c
	$(CC) -o ex1_4 ex1_4.c

ex1_5: ex1_5.c
	$(CC) -o ex1_5 ex1_5.c

ex1_6: ex1_6/quadratic_solver.c ex1_6/get_coefficients.c ex1_6/solve.c ex1_6/print_solutions.c
	$(CC) -o ex1_6 ex1_6/quadratic_solver.c ex1_6/get_coefficients.c ex1_6/solve.c ex1_6/print_solutions.c

ex1_7: ex1_7.c
	$(CC) -o ex1_7 ex1_7.c

clean_window:
	del *.exe
