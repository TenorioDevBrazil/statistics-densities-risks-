#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//#include <omp.h>
#include <gsl/gsl_rng.h>

// control parameters
#define Nx 100
#define Ny 100
#define num_generations 1500
#define initial_population Nx*Ny/5
#define num_files 10
#define num_interactions (num_generations*Nx*Ny)

#define Seed 223
#define dispersion 0.0








#define enters 500000
#define key_out 3 // grid →  1, layers →  2, both choices →  3


// control keys

#define ic_key       0 	// (0 → randomic, 1 →  specific) initial condition
#define c_key        0 	// correlation key (1 → on, 0 →  off)
#define mobility_5ey 0  // (0 → constant, 1 → taxis active, 2 → clever)



//  keys of directional moviment strategy

#define taxis_key 2		// (11 → randomic, 0 → empty space, 1 → prey, 2 → anticipation, 3 → refuge)
#define strategy_key2 11
#define strategy_key3 11
#define strategy_key4 11
#define strategy_key5 11


// intrinsic rate of growth of species

#define a1 1.0
#define a2 1.0
#define a3 1.0
#define a4 1.0
#define a5 1.0

// intraspecific competition parameter

#define b1 0.000
#define b2 0.000
#define b3 0.000

// interspecific competition parameter

#define c1 1.0
#define c2 1.0
#define c3 1.0
#define c4 1.0
#define c5 1.0


// mobility

#define mb 1.0
#define m1 mb
#define m2 mb
#define m3 mb
#define mi mb
#define m5 mb

// weakness

#define weakness1 0.7 //potencial de força, por exemplo 0.9 significa 90% de poder e 10% de fraqueza (pode variar de 0 a 1.0)
#define weakness2 0.7
#define weakness3 1.0
#define weakness4 1.0
#define weakness5 1.0  

// _____________statistics experiment:________________________________________________________
#define radius 0
#define n 2      // n*n is the number of simulations v_radius
#define N 5   // N is the number of simulations varying the seed

#define I_radius  1.0  //raio vai variar de 0 ate o 5 

#define kappa_kinesis_1 3.0

//________________________________________________________________________________________



// Probability


// probability parameters - species 1
#define pa 0.1
#define pc 0.1

#include "prototype.h"
