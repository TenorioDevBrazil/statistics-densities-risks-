#include "parameters.h"

void output_grid(double *phi, int count){
        /////// out put to form the grid //////////////////////////////////////
        int i,j;
        char name[50];
        FILE *grid;
        
	sprintf(name,"database/data%d.dat",count);
	grid=fopen(name,"w");
	
	for(j=0;j<Ny;j++){
		for(i=0;i<Nx;i++)
			fprintf(grid,"%g ", phi[j*Nx+i]);
		
		fprintf(grid,"\n");
	}


        fclose(grid);
}

