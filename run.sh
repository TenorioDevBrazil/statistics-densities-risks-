#!/bin/bash

rm -f database/*.dat
rm -f plots/*.png
rm -f *.png
rm -f *.mp4

echo -e "\ncompiling...\n"

make

echo -e "running..."

time ./execut

# copy variables of the archive 'parameters.h'
Nx=$(sed -n '/#define Nx / p' parameters.h | cut -f3 -d' ')
Ny=$(sed -n '/#define Ny / p' parameters.h | cut -f3 -d' ')
Nf=$(sed -n '/#define num_files / p' parameters.h | cut -f3 -d' ')
Ng=$(sed -n '/#define num_generations / p' parameters.h | cut -f3 -d' ')

key_out=$(sed -n '/#define key_out / p' parameters.h | cut -f3 -d' ')

# rewrite variables in the archive 'grid.plt'
sed -i '/Nx = / s/.*/Nx = '$Nx'/' grid.plt
sed -i '/Ny = / s/.*/Ny = '$Ny'/' grid.plt
sed -i '/Nf = / s/.*/Nf = '$Nf'/' grid.plt
sed -i '/Ng = / s/.*/Ng = '$Ng'/' grid.plt
sed -i '/key_out = / s/.*/key_out = '$key_out'/' grid.plt

echo -e "\nplotting the data... \n"

gnuplot grid.plt

echo -e "making the videos...\n"

#if (( $(echo "$key_out == 1" | bc) || $(echo "$key_out == 3" | bc) )); then

#ffmpeg -r 15 -i plots/grid%d.png grid.mp4

#else if (( $(echo "$key_out == 2" | bc) || $(echo "$key_out == 3" | bc) )); then

	ffmpeg -r 5 -i plots/layers%d.png layers.mp4
	ffmpeg -r 5 -i plots/grid%d.png grid.mp4
#fi

rm -f execut

echo -e "\nfinished !\n"
