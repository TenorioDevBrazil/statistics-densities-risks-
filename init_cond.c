#include "parameters.h"

void put_species(double *phi, int num_species, double point_number);

void init_cond(double *phi){
	int i,j;

	// filling in the grid with vacancies
		for(j=0;j<Ny;j++){

			for(i=0;i<Nx;i++){

                		phi[j*Nx+i]=0.0;

		}

	   }

	       // distributing the species on the lattice randomly
		put_species(phi,initial_population,1.0);
		put_species(phi,initial_population,2.0);
		put_species(phi,initial_population,3.0);
		put_species(phi,initial_population,4.0);
		put_species(phi,initial_population,5.0);
	//	put_species(phi,initial_population,4.0);
		//put_species(phi,initial_population,5.0);


              	output_grid(phi,0);
}

	void put_species(double *phi, int num_species, double point_number){
	int i,j; // spatial coordinates
	int position, counter=0;

	const gsl_rng_type *T;
	gsl_rng *r;
	gsl_rng_env_setup();
	T=gsl_rng_default;
	r=gsl_rng_alloc(T);
	gsl_rng_set(r,seed);

	while(counter<num_species){
		i=gsl_rng_uniform(r)*Nx;
		j=gsl_rng_uniform(r)*Ny;

		position=j*Nx+i;

		if(phi[position]==0.0){
			phi[position]=point_number;
			counter++;
		}
	   }

	gsl_rng_free(r);
}
