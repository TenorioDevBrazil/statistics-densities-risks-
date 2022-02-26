#include "parameters.h"


//void taxis();
void richting_function(){


double *alloc(int);


	double *den_species1, *den_species2, *den_species3,*den_species4,*den_species5, *den_vacancies;
	double *risk_predation1;
	double *risk_predation2;
	double *risk_predation3;
	double *risk_predation4;
	double *risk_predation5;



	//densities of individuals and vacancies
	den_species1 = alloc(num_generations);
	den_species2 = alloc(num_generations);
  	den_species3 = alloc(num_generations);
	den_species4 = alloc(num_generations);
	den_species5 = alloc(num_generations);
	den_vacancies = alloc(num_generations);

	risk_predation1 = alloc(num_generations);
	risk_predation2 = alloc(num_generations);
	risk_predation3 = alloc(num_generations);
	risk_predation4 = alloc(num_generations);
	risk_predation5 = alloc(num_generations);


		mda1=0.0;   mda6=0;
		mda2=0.0;   mda7=0;
		mda3=0.0;   mda8=0;
		mda4=0.0;   mda9=0;
		mda5=0.0;   mda10=0;
		mda0=0.0;	

	int sum_1, sum_2, sum_3;
	double xi_1;


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


	int i,j,k; // auxiliary coordinate variables
	//int x,y, dx,dy;

	int key; // auxiliary variable for successful interactions
	double temp; // temporary variable to mobility of the species
	double gsl_action;
	double gsl_passive, gsl_antipredatory,gsl_weakness;

	int counter_interac = 0; // interactions counter
	int count1=0, count2=0; // auxiliary variable for successful interactions
	int counter1=initial_population, counter2=initial_population, counter3=initial_population, counter4=initial_population, counter5=initial_population; // desities counters

	    // initial population for predation risk

	    int n1_0, n2_0, n3_0,n4_0,n5_0;
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

//printf("%d %d %d %d %d %d\n" , counter1, counter2, counter3,counter4,counter5, v_radius);
	while(counter_interac < num_interactions){

		// choosing the active individual
		do{
			i = gsl_rng_uniform(r)*Nx;
			j = gsl_rng_uniform(r)*Ny;

			active = j*Nx+i;

		}while(phi[active] == 0.0);


		// sorting the passive position
		gsl_passive = gsl_rng_uniform(r);


		if(gsl_passive<0.125)
			passive=((j+1)%Ny)*Nx+i;

		else if(gsl_passive>=0.125 && gsl_passive<0.250)
			passive=((j-1+Ny)%Ny)*Nx+i;

		else if(gsl_passive>=0.250 && gsl_passive<0.375)
			passive=j*Nx+(i+1)%Nx;

		else if(gsl_passive>=0.375 && gsl_passive<0.500)
			passive=j*Nx+(i-1+Nx)%Nx;

		else if(gsl_passive>=0.500 && gsl_passive<0.625)
			passive=((j+1)%Ny)*Nx+(i+1)%Nx;

		else if(gsl_passive>=0.625 && gsl_passive<0.750)
			passive=((j-1+Ny)%Ny)*Nx+(i-1+Nx)%Nx;

		else if(gsl_passive>=0.750 && gsl_passive<0.875)
			passive=((j+1)%Ny)*Nx+(i-1+Nx)%Nx;

		else
			passive=((j-1+Ny)%Ny)*Nx+(i+1)%Nx;

    //printf("%e\n" , pa1);

		key = counter_interac;

		// sorting the action of active
		gsl_action=gsl_rng_uniform(r);
		gsl_antipredatory=gsl_rng_uniform(r);
		gsl_weakness=gsl_rng_uniform(r);


		if(phi[active]==1.0){ // species 1

			if(gsl_action<pa){ // reproduction
				if(phi[passive]==0.0){
					phi[passive]=1.0;
					counter_interac++;
					counter1++;
				}
			}else if(gsl_action>=(pa) && gsl_action<(pa+pc)){ // intercompetition
				
				if(gsl_weakness<v_weakness){



				if(phi[passive]==2.0){ //1 consegue matar o 2

					phi[passive]=0.0;
					counter_interac++; //conta a interacao = acontecer alguma coisa
					counter2--; //diminuiu um individuo 2
					n_predations2++; //+ uma predacao do 2

				}
			} 
          		}else{  // mobility
				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;

			}// end of mobility

		}// end of species 1

		//-------------
		else if(phi[active]==2.0){ // species 2

			if(gsl_action<pa){ // reproduction
				if(phi[passive]==0.0){
					phi[passive]=2.0;
					counter_interac++;
					counter2++;
				}
			}else if(gsl_action>=(pa) && gsl_action<(pa+pc)){ // intercompetition
				
				if(gsl_weakness<v_weakness){



				if(phi[passive]==3.0){ //2 consegue matar o 3

					phi[passive]=0.0;
					counter_interac++; //conta a interacao = acontecer alguma coisa
					counter3--; //diminuiu um individuo 3
					n_predations3++; //+ uma predacao do 3

				}
			} 
          		}else{  // mobility
				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;

			}// end of mobility

		}// end of species 2

		//------------

		else if(phi[active]==3.0){ // species 3

			if(gsl_action<pa){ // reproduction
				if(phi[passive]==0.0){
					phi[passive]=3.0;
					counter_interac++;
					counter3++;
				}
			}else if(gsl_action>=(pa) && gsl_action<(pa+pc)){ // intercompetition
				
				if(gsl_weakness<weakness3){



				if(phi[passive]==4.0){ //3 consegue matar o 1

					phi[passive]=0.0;
					counter_interac++; //conta a interacao = acontecer alguma coisa
					counter4--; //diminuiu um individuo 4
					n_predations4++; //+ uma predacao do 4

				}
			} 
          		}else{  // mobility
				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;

			}// end of mobility

		}// end of species 3

		else if(phi[active]==4.0){ // species 4

			if(gsl_action<pa){ // reproduction
				if(phi[passive]==0.0){
					phi[passive]=4.0;
					counter_interac++;
					counter4++;
				}
			}else if(gsl_action>=(pa) && gsl_action<(pa+pc)){ // intercompetition
				
				if(gsl_weakness<weakness3){



				if(phi[passive]==5.0){ //3 consegue matar o 1

					phi[passive]=0.0;
					counter_interac++; //conta a interacao = acontecer alguma coisa
					counter5--; //diminuiu um individuo 5
					n_predations5++; //+ uma predacao do 5

				}
			} 
          		}else{  // mobility
				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;

			}// end of mobility

			

		}// end of species 4

		else if(phi[active]==5.0){ // species 5

			if(gsl_action<pa){ // reproduction
				if(phi[passive]==0.0){
					phi[passive]=5.0;
					counter_interac++;
					counter5++;
				}
			}else if(gsl_action>=(pa) && gsl_action<(pa+pc)){ // intercompetition
				
				if(gsl_weakness<weakness3){



				if(phi[passive]==1.0){ //3 consegue matar o 1

					phi[passive]=0.0;
					counter_interac++; //conta a interacao = acontecer alguma coisa
					counter1--; //diminuiu um individuo 1
					n_predations1++; //+ uma predacao do 1

				}
			} 
          		}else{  // mobility
				temp=phi[passive];
				phi[passive]=phi[active];
				phi[active]=temp;
				counter_interac++;

			}// end of mobility

			

		}// end of species 5


		

		//-------------------------------------
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
				den_species4[count2] = (double)counter4/(Nx*Ny);
				den_species5[count2] = (double)counter5/(Nx*Ny);
				den_vacancies[count2] =(1.0-den_species1[count2]-den_species2[count2]-den_species3[count2]-den_species4[count2]-den_species5[count2]);


				risk_predation1[count2]=(double)n_predations1/(n1_0);
				risk_predation2[count2]=(double)n_predations2/(n2_0);
				risk_predation3[count2]=(double)n_predations3/(n3_0);
				risk_predation4[count2]=(double)n_predations4/(n3_0);
				risk_predation5[count2]=(double)n_predations5/(n3_0);

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


				if(counter1 == 0 || counter2 == 0 || counter3 == 0|| counter4 == 0|| counter5 == 0){

	printf("%d %d %d %d %d %e \n" , counter1, counter2, counter3,counter4,counter5, v_weakness);

			break;
		}


	} // while-key




		int xx;
		xx=0;
		mda1=0.0;
		mda2=0.0;
		mda3=0.0;
		mda4=0.0;
		mda5=0.0;
		mda6=0.0;
		mda7=0.0;
		mda8=0.0;
		mda9=0.0;
		mda0=0.0;
		mda10=0.0;




			for(xx=(num_generations/2); xx<num_generations; xx++){
				mda1 += den_species1[xx]/(num_generations/2);
				mda2 += den_species2[xx]/(num_generations/2);
				mda3 += den_species3[xx]/(num_generations/2);
				mda4 += den_species4[xx]/(num_generations/2);
				mda5 += den_species5[xx]/(num_generations/2);
				mda0 += den_vacancies[xx]/(num_generations/2);
				mda6 += risk_predation1[xx]/(num_generations/2);
				mda7 += risk_predation2[xx]/(num_generations/2);
				mda8 += risk_predation3[xx]/(num_generations/2);
				mda9 += risk_predation4[xx]/(num_generations/2);
				mda10 += risk_predation5[xx]/(num_generations/2);


		        }

		 printf("%f %f %f %f %f %f %d %f %f %f %f %f\n",mda1, mda2, mda3,mda4,mda5,mda0, seed, mda6, mda7, mda8,mda9,mda10);




	// recording the densities data
	//output_densities(den_species1, den_species2, den_species3, den_infected, den_species5,den_vacancies,risk_predation1, risk_predation2, risk_predation3, risk_predation4, risk_predation5);
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
	free(den_species4);
	free(den_species5);
	free(den_vacancies);
}
