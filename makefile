compiler = gcc
#compiler = gcc-4.9

flags = -O3

lib = -lm -lgsl -lgslcblas 

arc = main.c  richting_function.c  alloc_i.c  alloc_d.c  init_cond.c output_densities.c output_grid.c 
     

all:
	 @${compiler} ${flags} ${arc} ${lib} -o executable
