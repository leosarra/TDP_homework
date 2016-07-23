all:	matrix_main 
	
	
clean:	
	rm -rf *~ *.o matrix_main

vec_ops.o:	vec_ops.c vec_ops.h
	g++ -g  -c vec_ops.c

matrix_ops.o:	matrix_ops.c matrix_ops.h vec_ops.h
	g++ -g  -c matrix_ops.c -o matrix_ops.o

matrix_main.o:	matrix_main.c matrix_ops.h vec_ops.h
	g++ -g  -c matrix_main.c

matrix_main:	matrix_main.o matrix_ops.o vec_ops.o
	g++ -g  -o matrix_main matrix_main.o matrix_ops.o vec_ops.o

