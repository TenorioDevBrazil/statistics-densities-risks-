#include "parameters.h"

int *alloc_i(int size){
	int *vector;

	// allocated lines
	vector=(int *) malloc(sizeof(int) *size);

	// always test if the allocation was successful
	if(!vector){
		fprintf(stderr, "Error allocating vector !\n");
		exit(1);
	}

	return vector;
}
