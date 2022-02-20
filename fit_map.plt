#!/usr/bin/gnuplot

reset

name = sprintf("prey_nutrition")

set term pngcairo size 650,520 crop enhanced font 'Verdana,10'

name_out = sprintf("%s_fit.png", name)

set output name_out

set xl'{/Symbol b}'
set yl'm'

set style line 11 lc rgb '#696969' lt 1
set border 3 front ls 11
set tics nomirror
unset colorbox

name_data = sprintf("%s.dat", name)

f(x) = a*x+b

fit f(x) name_data using 1:($3==1 ? $2:1/0) via a,b



name_params = sprintf("params_%s.dat", name)

save var name_params

set key top left Left reverse samplen 3


plot name_data u (2):(1):(($3>0.39 && $3<0.61)? $3: NaN) ls 7 lc palette notitle, f(x) lw 2 t'best fit'


#plot name_data using 1:($3==1 ? $2:1/0) ls 7 t'data',\
#    f(x) lw 2 t'best fit'

system("rm -f fit.log")
