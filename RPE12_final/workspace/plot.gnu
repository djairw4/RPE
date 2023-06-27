#!/usr/bin/gnuplot
#
# Plotting the data of file data.dat

reset

set terminal pngcairo size 350,262 enhanced font 'Verdana,10'
set output 'chart.png'

set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 1 linewidth 1

unset key

set xrange [-5:5]
set yrange [-5:5]

plot 'data.dat' with line linestyle 1