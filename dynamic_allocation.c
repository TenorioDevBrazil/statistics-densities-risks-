#include "parameters.h"

double *alloc(int size){
	double *vector;

	// allocated lines
	vector=(double *) malloc(sizeof(double) *size);

	// always test if the allocation was successful
	if(!vector){
		fprintf(stderr, "Error allocating vector !\n");
		exit(1);
	}

	return vector;
}
