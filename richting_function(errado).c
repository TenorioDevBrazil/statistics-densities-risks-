#include "parameters.h"




void taxis();
void richting_function(){


double *alloc(int);


	

	

	double *den_species1, *den_species2, *den_species3, *den_infected, *den_species5, *den_vacancies;
	double *risk_predation1;
	double *risk_predation2;
	double *risk_predation3;
	double *risk_predation4;
	double *risk_predation5;


	//densities of individuals and vacancies
	den_species1 = alloc(num_generations);
	den_species2 = alloc(num_generations);
  	den_species3 = alloc(num_generations);
	den_infected = alloc(num_generations);
	den_species5 = alloc(num_generations);
	den_vacancies = alloc(num_generations);

	risk_predation1 = alloc(num_generations);
	risk_predation2 = alloc(num_generations);
	risk_predation3 = alloc(num_generations);
	risk_predation4 = alloc(num_generations);
	risk_predation5 = alloc(num_generations);


	double *phi;
	phi = alloc(Nx*Ny);

	// initial conditions
	init_cond(phi);

	// difinitions random GSL
        const gsl_rng_type *T;
        gsl_rng *r;
        gsl_rng_env_setup();
        T=gsl_rng_default;
        r=gsl_rng_alloc(T);
	gsl_rng_set(r,seed);

	int i,j,k; // auxiliary coordinate variables
	//int x,y, dx,dy;

	int key; // auxiliary variable for successful interactions
	double temp; // temporary variable to mobility of the species
	double gsl_action;
	double gsl_passive, gsl_dispersion;

	
	int counter_interac = 0; // interactions counter
	int count1=0, count2=0; // auxiliary variable for successful interactions
	 counter1=initial_population;
	 counter2=initial_population;
	 counter3=initial_population;
	 counter4=initial_population;
	 counter5=initial_population; // desities counters

	    // initial population for predation risk		
	
	    int n1_0, n2_0, n3_0, n4_0,n5_0;
	    n1_0 = counter1;
	    n2_0 = counter2;
	    n3_0 = counter3;
	    n4_0 = counter4;
	    n5_0 = counter5;

	    int n_predations1, n_predations2, n_predations3,n_predations4,n_predations5;
	    n_predations1=0;
	    n_predations2=0;
	    n_predations3=0;
	    n_predations4=0;
	    n_predations5=0;

	
	//printf("%d %f \n ", strategy_key1, v_radius);
	
	
	//printf(" %e %d \n ", v_radius, radius);

	

	while(counter_interac < num_interactions){




		// choosing the active individual
		do{
			i = gsl_rng_uniform(r)*Nx;
			j = gsl_rng_uniform(r)*Ny;

			active = j*Nx+i;

		}while(phi[active] == 0.0);


		// sorting the passive position
		gsl_passive = gsl_rng_uniform(r);


		if(gsl_passive<0.25)
			passive=((j+1)%Ny)*Nx+i; //NORTH

		else if(gsl_passive>=0.25 && gsl_passive<0.5)
			passive=((j-1+Ny)%Ny)*Nx+i; // SOUTH

		else if(gsl_passive>=0.50 && gsl_passive<0.75)
			passive=j*Nx+(i+1)%Nx; // EAST

		else
			passive=j*Nx+(i-1+Nx)%Nx; //WEST



		key = counter_interac;

		// sorting the action of active
		gsl_action=gsl_rng_uniform(r);

		if(phi[active]==1.0){ // species 1

	

			if(gsl_action<pa1){ // reproduction
				if(phi[passive]==0.0){
					phi[passive]=1.0;
					counter_interac++;
					counter1++;
					
				}
			}



			else if(gsl_action>=(pa1) && gsl_action<(pa1+pc1)){ // intercompetition
				if(phi[passive]==2.0){
					phi[passive]=0.0;
					counter_interac++;
					counter2--;
          				n_predations2++;
				
			}
          	}


			else{  // mobility
				


			gsl_dispersion = gsl_rng_uniform(r);
		
			
				if(gsl_dispersion < dispersion){//

					// strategy mode off


					}

				else{

					// strategy mode on

					if(strategy_key1 != 11){

					// strategy: taxis		


					taxis(phi,i,j,active, strategy_key1);
				
				}


				// strategy: random walk

			}//




				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;



	}// end of mobility
}// end of species 1

		 else if(phi[active]==2.0){ // species 2

			if(gsl_action<pa2){ // reproduction
				if(phi[passive]==0.0){
					phi[passive]=2.0;
					counter_interac++;
					counter2++;
					
				}
			}


			else if(gsl_action>=(pa2) && gsl_action<(pa2+pc2)){ // intercompetition
				if(phi[passive]==3.0){
					phi[passive]=0.0;
					counter_interac++;
					counter3--;
          				n_predations3++;
				}
          	}


			else{
				if(strategy_key2 != 11){

				
					taxis(phi,i,j,active, strategy_key2);
				
				}


				 // mobility
				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;
			}






			}




		else if(phi[active]==3.0){ // species 3

		    if(gsl_action<pa3){ // reproduction
		        if(phi[passive]==0.0){
		            phi[passive]=3.0;
		            counter_interac++;
		            counter3++;
			   
		        }
		    }

			
		else if(gsl_action>=(pa3) && gsl_action<(pa3+pc3)){ // intercompetition
				if(phi[passive]==4.0){
					phi[passive]=0.0;
					counter_interac++;
					counter4--;
          				n_predations4++;
				}
          	}

		    else{ // mobility


			if(strategy_key3 != 11){
				
				taxis(phi,i,j,active, strategy_key3);
				
				}


		        temp=phi[passive];
		        phi[passive]=phi[active];
		        phi[active]=temp;
		        counter_interac++;
		    }

		}


		else if(phi[active]==4.0){ // species 4

			if(gsl_action<pa4){ // reproduction
				if(phi[passive]==0.0){
					phi[passive]=4.0;
					counter_interac++;
					counter4++;
				}
			}


				
		else if(gsl_action>=(pa4) && gsl_action<(pa4+pc4)){ // intercompetition
				if(phi[passive]==5.0){
					phi[passive]=0.0;
					counter_interac++;
					counter5--;
          				n_predations5++;
				}
          	}
			
			else{ // mobility
		
				 
				if(strategy_key4 != 11){
				
					taxis(phi,i,j,active, strategy_key4);
				
				}
		

				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;
			}

		}



		


		else if(phi[active]==5.0){ // species 5

			if(gsl_action<pa5){ // reproduction
				if(phi[passive]==0.0){
					phi[passive]=5.0;
					counter_interac++;
					
					counter5++;
				}
			}


				
		else if(gsl_action>=(pa5) && gsl_action<(pa5+pc5)){ // intercompetition
				if(phi[passive]==1.0){
					phi[passive]=0.0;
					counter_interac++;
					counter1--;
          				n_predations1++;
				}
          	}

			
			else{ // mobility

				
				if(strategy_key5 != 11){
						
					taxis(phi,i,j,active, strategy_key5);
				
				}

				
				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;
			}

		}
		




		
		// condition for a successful interaction
		if(counter_interac != key){

			// condition to the number of files allowed
			if((counter_interac % (num_interactions/num_files)) == 0.0){
				// recording the grid data
				output_grid(phi,count1);

				count1++;
			}

			// condition to the number of data allowed
			if((counter_interac % (Nx*Ny)) == 0.0){
				den_species1[count2] = (double)counter1/(Nx*Ny);
				den_species2[count2] = (double)counter2/(Nx*Ny);
                		den_species3[count2] = (double)counter3/(Nx*Ny);
				den_infected[count2] = (double)counter4/(Nx*Ny);
				den_species5[count2] = (double)counter5/(Nx*Ny);
				den_vacancies[count2] =(1.0-den_species1[count2]-den_species2[count2]-den_species3[count2]-den_infected[count2]-den_species5[count2]);
				

				risk_predation1[count2]=(double)n_predations1/(n1_0);
				risk_predation2[count2]=(double)n_predations2/(n2_0);
				risk_predation3[count2]=(double)n_predations3/(n3_0);
				risk_predation4[count2]=(double)n_predations4/(n4_0);
				risk_predation5[count2]=(double)n_predations5/(n5_0);
					count2++;
				n_predations1=0;
				n1_0 = counter1;
				n_predations2=0;
				n2_0 = counter2;
				n_predations3=0;
				n3_0 = counter3;
				n_predations4=0;		
				n4_0 = counter4;
				n_predations5=0;		
				n5_0 = counter5;


			}

		}


		
				if(counter1 == 0 || counter2 == 0 || counter3 == 0 || counter4 == 0 || counter5 == 0){
	
					printf("%d %d %d %d %d %d\n" , counter1, counter2, counter3, counter4, counter5, seed);
			
					break;
			}

	} // while-key



			
		            
		


		mda1=0.0;
		mda2=0.0;
		mda3=0.0;
		mda4=0.0;
		mda5=0.0;
		mda0=0.0;

			int l;



	    printf("%d \n" , num_generations);

			for(l=(num_generations/2); l<num_generations; l++){
				mda1 += den_species1[l]/(num_generations/2);
				mda2 += den_species2[l]/(num_generations/2);
				mda3 += den_species3[l]/(num_generations/2);
				mda4 += den_infected[l]/(num_generations/2);
				mda5 += den_species5[l]/(num_generations/2);
				mda0 += den_vacancies[l]/(num_generations/2);
		        }



				printf("%f %f %f %f %f %f %d %d \n" , mda1, mda2, mda3, mda4, mda5, mda0, seed, count2);


	// recording the densities data
	output_densities(den_species1, den_species2, den_species3, den_infected, den_species5,den_vacancies,risk_predation1, risk_predation2, risk_predation3, risk_predation4, risk_predation5);
	gsl_rng_free(r);

	free(risk_predation1);
	free(risk_predation2);
	free(risk_predation3);
	free(risk_predation4);
	free(risk_predation5);

	free(phi);
	free(den_species1);
	free(den_species2);
        free(den_species3);
	free(den_infected);
	free(den_species5);
	free(den_vacancies);


}
