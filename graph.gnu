set terminal png
set output 'max_path.png'

set xlabel "Size"
set autoscale

set ylabel "Time"
set title "Recursive maximum path"

set grid
set style data points

plot    'dat.tad' using 2:1 notitle with lines
