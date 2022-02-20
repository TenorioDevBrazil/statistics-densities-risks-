#!/usr/bin/gnuplot

reset

set term pngcairo size 650,520 crop enhanced font 'Verdana,10'
set out'functions_m=ctt_r=3.png'

set xl'm'
set yl'{/Symbol b}'

set xr[0:1.5]
set yr[0:3.0]

#set key top left Left reverse samplen 3
set style line 11 lc rgb '#696969' lt 1
set border 3 front ls 11
set tics nomirror
unset colorbox

a1 = 0.839227245450045
b1 = -0.235548840105232

g1(x) = (x-b1)/a1;

a2 = 0.0594532052786051
b2 = -0.012974144557558

g2(x) = (x-b2)/a2;

plot g1(x) lw 2 t'mobility → const', g2(x) lw 2 t'mobility → radius=3'
