#!/usr/bin/gnuplot

reset

name = sprintf("statistics")

set term png size 650,520 enhanced font 'Verdana,10'

name_out = sprintf("%s.png", name)

set output name_out

set yl '{dispersion}'
set xl '{radius}'

set style line 11 lc rgb '#696969' lt 1
set border 3 front ls 11
set tics nomirror

set cbl'Coexistence Probability  '

set cbr[0:1]
set palette defined ( 0 "#000090",\
                      1 "#000fff",\
                      2 "#0090ff",\
                      3 "#0fffee",\
                      4 "#90ff70",\
                      5 "#ffee00",\
                      6 "#ff7000",\
                      7 "#ee0000",\
                      8 "#7f0000")

f(x) = -50*x/(x-1)

#set xr[0:1]

name_data = sprintf("<sort -g -k3 %s.dat", name)
plot name_data u 1:2:3 ls 5 lw 2 lc palette notitle

#plot name_data u ($2/($2+50)):($1/1):3 ls 5 lw 12 lc palette notitle
#plot name_data u ($2/25):($1/25):(($3>0.45 && $3<0.55)? $3: NaN) ls 7 lc palette notitle
