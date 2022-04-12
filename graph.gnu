set terminal png
set output "graph.png"

set xrange [0:4]

set yrange [0:16]

set key outside top

set ytics 1

set xtics 1

set ylabel "y"

set xlabel "x"

plot "./inside.txt" u 1:2 with points lw 3 pt 7 ps 1 title "point inside", "./outside.txt" u 1:2 with points lw 3 pt 7 ps 1 title "point outside"