#!/bin/bash

date
NI=50  # number of simulations (initial conditions)
IS=1   # initial seed



for (( J = $IS; J < $IS+$NI; J++ ))
do
	echo -e "\n running $(($J-$IS+1))º rps"

     sed -i '/#define seed / s/.*/#define seed '$J'/' parameters.h

    make
	./execut


	mv database/densities.dat densities-$J.dat

done
date
