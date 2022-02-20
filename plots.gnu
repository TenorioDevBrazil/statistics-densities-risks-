#!/usr/bin/gnuplot

reset

Nx= 200
Ny= 200
Nf= 100
Ng= 4000

############## plot densities #################
set term png size 560,370 enhanced font 'Verdana, 9'

set xl'Radius'
set yl'Mean Density'

set xr[0:4] 
#set yr[0.15:0.3]

# define axis
set style line 11 lc rgb '#2f4f4f' lt 1
set border 3 back ls 11
set tics nomirror

# define grid
#set style line 12 lc rgb '#2f4f4f' lt 0 lw 1
#set grid back ls 12

# color line definitions
set style line 1 lc rgb 'red' lt 1 lw 4 pt 2.5 ps 1.0 #  orange    
set style line 2 lc rgb 'blue' lt 1 lw 4 pt 2.5 ps 1.0 #  orange    
set style line 3 lc rgb 'green' lt 1 lw 4 pt 2.5 ps 1.0 #  orange    
set style line 4 lc rgb 'yellow' lt 1 lw 4 pt 2.5 ps 1.0 #  orange
set style line 5 lc rgb 'purple' lt 1 lw 4 pt 2.5 ps 1.0 #  orange    
set style line 6 lc rgb 'pink' lt 1 lw 4 pt 2.5 ps 1.0 #  orange    
    

set out'statistics.png'

plot 'statistics.dat' u 1:2 ls 1 t 'Empty space',\
      'statistics.dat' u 1:3 ls 2 t '1',\
	'statistics.dat' u 1:4 ls 3 t '2',\
	'statistics.dat' u 1:5 ls 4 t '3',\
	'statistics.dat' u 1:6 ls 4 t '4',\
	'statistics.dat' u 1:7 ls 4 t '5'



