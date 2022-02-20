
#include "parameters.h"

//Calculating the direction


void taxis(){

	
	int sum_1_L=0,sum_2_L=0, sum_3_L=0, sum_4_L=0, sum_5_L=0, sum_0_L=0;
	int sum_1_N=0,sum_2_N=0, sum_3_N=0, sum_4_N=0, sum_5_N=0, sum_0_N=0;
	int sum_1_S=0,sum_2_S=0, sum_3_S=0, sum_4_S=0, sum_5_S=0, sum_0_S=0;
	int sum_1_O=0,sum_2_O=0, sum_3_O=0, sum_4_O=0, sum_5_O=0, sum_0_O=0;

	int x,y, dx,dy, direction;
	double gsl_direction, focus;

	
	const gsl_rng_type *T;
	gsl_rng *r;
	gsl_rng_env_setup();
	T=gsl_rng_default;
	r=gsl_rng_alloc(T);
	gsl_rng_set(r,seed);
	
			
	
	//computing the focus


	

		if(taxis_key == 0){
			
			focus = taxis_key;
		}

		else if(taxis_key >= 1 && taxis_key <= 3){

			focus = ((int) phi[active] + taxis_key)%5;
	
		
				if(focus == 0.0){

					focus = 5.0;

			} 
			
		}
			
			 //printf("%e \n" , focus);


	// computing the values of local densities
				
				for(x=(i-v_radius); x<=(i+v_radius); x++){
					for(y=(j-v_radius); y<=(j+v_radius); y++){
						if((pow((x-i),2)+pow((y-j),2)) <= pow(v_radius,2)){
							

		



				//EAST
				if (y >= (j+tan(-0.785)*(x-i)) && y<=(j+tan(0.785)*(x-i))){ //direction 1
					
					dx = (x+Nx)%Nx;
					dy = (y+Ny)%Ny;
		
				
				if (phi[dy*Nx+dx] == focus){


					
				sum_0_L++;

 				



				}}
				
				
				//NORTH
				if (y >= (j+tan(-0.785)*(x-i)) && y >= (j+tan(0.785)*(x-i))){//direction  3
				dx = (x+Nx)%Nx;
				dy = (y+Ny)%Ny;

							
		
				if (phi[dy*Nx+dx] == focus){
				sum_0_N++;
						
				
				}}	


				//WEST
				if (y <= (j+tan(-0.785)*(x-i)) && y >= (j+tan(0.785)*(x-i))){//direction 5
				dx = (x+Nx)%Nx;
				dy = (y+Ny)%Ny;



					
				if (phi[dy*Nx+dx] == focus){
				sum_0_O++;
					
				}}
				



				//SOUTH
				if (y <= (j+tan(-0.785)*(x-i)) && y <= (j+tan(0.785)*(x-i))){//direction 7
				dx = (x+Nx)%Nx;
				dy = (y+Ny)%Ny;
				
								
				if (phi[dy*Nx+dx] == focus){
				sum_0_S++;
				
				}}



				}}} //end of sums








// beginning of decision

//only one direction with empty spaces

if(sum_0_L ==0 && sum_0_N ==0 && sum_0_O == 0 && sum_0_S == 0){
direction = 0;
}

else if(sum_0_L !=0 && sum_0_N ==0 && sum_0_O == 0 && sum_0_S == 0){
direction = 1;
}

else if(sum_0_L ==0 && sum_0_N !=0 && sum_0_O == 0 && sum_0_S == 0){
direction = 2;
}

else if(sum_0_L ==0 && sum_0_N ==0 && sum_0_O != 0 && sum_0_S == 0){
direction = 3;
}

else if(sum_0_L ==0 && sum_0_N ==0 && sum_0_O == 0 && sum_0_S != 0){
direction = 4;
}



//two directions with empty spaces

else if(sum_0_L !=0 && sum_0_N !=0 && sum_0_O == 0 && sum_0_S == 0){

        if(sum_0_L>sum_0_N){
        direction = 1;
        }
        else if(sum_0_N>sum_0_L){
          direction = 2;
          }
        else if(sum_0_L==sum_0_N){

        gsl_direction = gsl_rng_uniform(r);
              if(gsl_direction<0.5){
                  direction = 1;
                  }
                  else{
                  direction = 2;
                  }

        }
}

//


else if(sum_0_L !=0 && sum_0_N ==0 && sum_0_O != 0 && sum_0_S == 0){

            if(sum_0_L>sum_0_O){
            direction = 1;
            }
            else if(sum_0_O>sum_0_L){
              direction = 3;
              }
            else if(sum_0_L==sum_0_O){

            gsl_direction = gsl_rng_uniform(r);
                if(gsl_direction<0.5){
                    direction = 1;
                    }
                    else{
                    direction = 3;
                    }

          }
}

else if(sum_0_L !=0 && sum_0_N ==0 && sum_0_O == 0 && sum_0_S != 0){

              if(sum_0_L>sum_0_S){
              direction = 1;
              }
              else if(sum_0_S>sum_0_L){
                direction = 4;
                }
              else if(sum_0_L==sum_0_S){

            gsl_direction = gsl_rng_uniform(r);
                  if(gsl_direction<0.5){
                      direction = 1;
                      }
                      else{
                      direction = 4;
                      }

            }
}

else if(sum_0_L ==0 && sum_0_N !=0 && sum_0_O != 0 && sum_0_S == 0){

                if(sum_0_N>sum_0_O){
                direction = 2;
                }
                else if(sum_0_O>sum_0_N){
                  direction = 3;
                  }
                else if(sum_0_N==sum_0_O){

              gsl_direction = gsl_rng_uniform(r);
                    if(gsl_direction<0.5){
                        direction = 2;
                        }
                        else{
                        direction = 3;
                        }

              }
}

else if(sum_0_L ==0 && sum_0_N !=0 && sum_0_O == 0 && sum_0_S != 0){

              if(sum_0_N>sum_0_S){
              direction = 2;
              }
              else if(sum_0_S>sum_0_N){
                direction = 4;
                }
              else if(sum_0_N==sum_0_S){

            gsl_direction = gsl_rng_uniform(r);
                  if(gsl_direction<0.5){
                      direction = 2;
                      }
                      else{
                      direction = 4;
                      }

            }
}

else if(sum_0_L ==0 && sum_0_N ==0 && sum_0_O != 0 && sum_0_S != 0){

              if(sum_0_O>sum_0_S){
              direction = 3;
              }
              else if(sum_0_S>sum_0_O){
                direction = 4;
                }
              else if(sum_0_O==sum_0_S){

            gsl_direction = gsl_rng_uniform(r);
                  if(gsl_direction<0.5){
                      direction = 3;
                      }
                      else{
                      direction = 4;
                      }

            }
}// end of two directions



else if(sum_0_L !=0 && sum_0_N !=0 && sum_0_O != 0 && sum_0_S == 0){

            if(sum_0_L>sum_0_N && sum_0_L>sum_0_O){
                    direction = 1;
            }
            else if(sum_0_N>sum_0_L && sum_0_N>sum_0_O){
                    direction = 2;
            }
            else if(sum_0_O>sum_0_L && sum_0_O>sum_0_N){
                    direction = 3;
            }
            else if(sum_0_L==sum_0_N && sum_0_L!=sum_0_O){

                    gsl_direction = gsl_rng_uniform(r);
                      if(gsl_direction<0.5){
                          direction = 1;
                          }
                          else{
                          direction = 2;
                          }

            }

          else if(sum_0_L==sum_0_O && sum_0_L!=sum_0_N){

                  gsl_direction = gsl_rng_uniform(r);
                    if(gsl_direction<0.5){
                        direction = 1;
                        }
                        else{
                        direction = 3;
                        }

          }

          else if(sum_0_N==sum_0_O && sum_0_L!=sum_0_N){

                  gsl_direction = gsl_rng_uniform(r);
                    if(gsl_direction<0.5){
                        direction = 2;
                        }
                        else{
                        direction = 3;
                        }

                }

        else if(sum_0_N==sum_0_O && sum_0_L==sum_0_N){

                      gsl_direction = gsl_rng_uniform(r);
                        if(gsl_direction<0.33){
                            direction = 1;
                            }
                        if(gsl_direction>=0.333 && gsl_direction<0.666){
                            direction = 2;
                            }
                        else{
                            direction = 3;
                            }

                    }


}




else if(sum_0_L !=0 && sum_0_N !=0 && sum_0_O == 0 && sum_0_S != 0){

          if(sum_0_L>sum_0_N && sum_0_L>sum_0_S){
               direction = 1;
          }
          else if(sum_0_N>sum_0_L && sum_0_N>sum_0_S){
               direction = 2;
          }
          else if(sum_0_S>sum_0_L && sum_0_S>sum_0_N){
               direction = 4;
          }
          else if(sum_0_L==sum_0_N && sum_0_L!=sum_0_O){

                  gsl_direction = gsl_rng_uniform(r);
                    if(gsl_direction<0.5){
                        direction = 1;
                        }
                        else{
                        direction = 2;
                        }

                }

          else if(sum_0_L==sum_0_S && sum_0_L!=sum_0_N){

                  gsl_direction = gsl_rng_uniform(r);
                    if(gsl_direction<0.5){
                        direction = 1;
                        }
                        else{
                        direction = 4;
                        }

                }

          else if(sum_0_N==sum_0_S && sum_0_L!=sum_0_N){

                  gsl_direction = gsl_rng_uniform(r);
                    if(gsl_direction<0.5){
                        direction = 2;
                        }
                        else{
                        direction = 4;
                        }

                }

            else if(sum_0_L==sum_0_N && sum_0_L==sum_0_S){

                          gsl_direction = gsl_rng_uniform(r);
                            if(gsl_direction<0.33){
                                direction = 1;
                                }
                            if(gsl_direction>=0.333 && gsl_direction<0.666){
                                direction = 2;
                                }
                            else{
                                direction = 4;
                                }

                        }


}






else if(sum_0_L !=0 && sum_0_N ==0 && sum_0_O != 0 && sum_0_S != 0){

              if(sum_0_L>sum_0_O && sum_0_L>sum_0_S){
                     direction = 1;
              }
              else if(sum_0_O>sum_0_L && sum_0_O>sum_0_S){
                     direction = 3;
              }
              else if(sum_0_S>sum_0_L && sum_0_S>sum_0_O){
                     direction = 4;
              }
              else if(sum_0_L==sum_0_O && sum_0_L!=sum_0_S){

                      gsl_direction = gsl_rng_uniform(r);
                        if(gsl_direction<0.5){
                            direction = 1;
                            }
                            else{
                            direction = 3;
                            }

                    }

              else if(sum_0_L==sum_0_S && sum_0_L!=sum_0_O){

                      gsl_direction = gsl_rng_uniform(r);
                        if(gsl_direction<0.5){
                            direction = 1;
                            }
                            else{
                            direction = 4;
                            }

                    }

              else if(sum_0_O==sum_0_S && sum_0_L!=sum_0_O){

                      gsl_direction = gsl_rng_uniform(r);
                        if(gsl_direction<0.5){
                            direction = 3;
                            }
                            else{
                            direction = 4;
                            }

                    }

              else if(sum_0_L==sum_0_O && sum_0_L==sum_0_S){

                            gsl_direction = gsl_rng_uniform(r);
                              if(gsl_direction<0.33){
                                  direction = 1;
                                  }
                              if(gsl_direction>=0.333 && gsl_direction<0.666){
                                  direction = 3;
                                  }
                              else{
                                  direction = 4;
                                  }

                          }


}



else if(sum_0_L ==0 && sum_0_N !=0 && sum_0_O != 0 && sum_0_S != 0){

                  if(sum_0_N>sum_0_O && sum_0_N>sum_0_S){
                  direction = 2;
                  }
                  else if(sum_0_O>sum_0_N && sum_0_O>sum_0_S){
                    direction = 3;
                    }
                  else if(sum_0_S>sum_0_N && sum_0_S>sum_0_O){
                      direction = 4;
                      }
                  else if(sum_0_N==sum_0_O && sum_0_N!=sum_0_S){

                          gsl_direction = gsl_rng_uniform(r);
                            if(gsl_direction<0.5){
                                direction = 2;
                                }
                                else{
                                direction = 3;
                                }

                        }

                  else if(sum_0_N==sum_0_S && sum_0_N!=sum_0_O){

                          gsl_direction = gsl_rng_uniform(r);
                            if(gsl_direction<0.5){
                                direction = 2;
                                }
                                else{
                                direction = 4;
                                }

                        }

                  else if(sum_0_O==sum_0_S && sum_0_O!=sum_0_N){

                          gsl_direction = gsl_rng_uniform(r);
                            if(gsl_direction<0.5){
                                direction = 3;
                                }
                                else{
                                direction = 4;
                                }

                        }

                  else if(sum_0_N==sum_0_O && sum_0_N==sum_0_S){

                                gsl_direction = gsl_rng_uniform(r);
                                  if(gsl_direction<0.33){
                                      direction = 2;
                                      }
                                  if(gsl_direction>=0.333 && gsl_direction<0.666){
                                      direction = 3;
                                      }
                                  else{
                                      direction = 4;
                                      }

                              }


		}



		//choosing the passive

				if (direction==1){
				passive=j*Nx+(i+1)%Nx;
				}
				else if (direction==2){
				passive=((j+1)%Ny)*Nx+i;
				}
				else if (direction==3){
				passive=j*Nx+(i-1+Nx)%Nx;
				}
				else if (direction==4){
					passive=((j-1+Ny)%Ny)*Nx+i;
				}




	gsl_rng_free(r);




	} //end of void
