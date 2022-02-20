#include "parameters.h"
double m_eff, done;
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

int main(){


	int i, j, k, w, ij, percent=0, xx, yy;

	double coexist[n][15]; // media, p, sigma;

	double auxiliary[N][11];
	double *media, *p, *sigma;
		media = alloc(11);
		sigma = alloc(11);
		    p = alloc(11);



	for(k=0; k<n; k++){
		coexist[k][1] = 0.0;
	}

	seed = Seed;

	v_radius = weakness1;



	for(i=0; i<n; i++){ // v_radius
			for(k=0; k<N; k++){//seed


				richting_function();

				percent++;

				auxiliary[k][0]=mda0; // den_vacancies[xx]/(num_generations/2)
				auxiliary[k][1]=mda1;
				auxiliary[k][2]=mda2;
				auxiliary[k][3]=mda3;
				auxiliary[k][4]=mda6; //risk_predation1[xx]/(num_generations/2);
				auxiliary[k][5]=mda7; // ....
				auxiliary[k][6]=mda8; // ....
				auxiliary[k][7]=mda9; // ....
				auxiliary[k][8]=mda10; //
			




				done = 100.0*percent/(n*N);

				//printf("%e %d %d \n ", auxiliary[k],k,seed);

				printf("%e \n ", done);



				seed++;

			} // k



			for (xx=0; xx< 11; xx++){ // null matrix

				media[xx] = 0;

				sigma[xx] = 0;

				p[xx]=0;
  			}


			for(xx=0; xx<N; xx++){
				for(yy=0; yy<11; yy++){

					media[yy] += auxiliary[xx][yy]/N;

				}

			}



			for(xx=0; xx<N; xx++){
				for(yy=0; yy<11; yy++){

					p[yy]+= pow (auxiliary[xx][yy]-media[yy],2); //variancia
					sigma[yy] = sqrt(p[yy]/(N-1));				//desvio padrao
			        }

			}
			//printf("%e %e %e \n ", media, p, sigma);


//resumo da estatistica

			coexist[i][0] = v_radius;

			for(w=0; w<7; w++){

				coexist[i][w+1] = media[w];
				coexist[i][w+8] = sigma[w];

			}

			//fazer toda estatistica de novo para o proxima FRAQUEZA

 seed = Seed;


	v_radius+= weakness1;


   } // i

        FILE *out = fopen("statistics.dat", "w");

	fprintf(out,"# Table \n");

	for(i=0; i<n; i++){

                    fprintf(out,"%g %g %g %g %g %g %g %g %g %g %g %g %g %g %g", coexist[i][0], coexist[i][1], coexist[i][2], coexist[i][3], coexist[i][4], coexist[i][5], coexist[i][6], coexist[i][7], coexist[i][8], coexist[i][9], coexist[i][10], coexist[i][11], coexist[i][12], coexist[i][13], coexist[i][14]);

		fprintf(out,"\n");
	}

        fclose(out);
}
