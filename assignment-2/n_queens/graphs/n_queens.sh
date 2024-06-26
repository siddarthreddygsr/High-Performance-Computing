
unset label
#set key above
#set key outside top center horizontal font ",3"
set autoscale
#set style line 1 linetype 2
set xrange [0:18]
set term pdf size 5,2.5
set output "merge.pdf" 
#set xtics ("1" 1,"2" 2,"4" 4,"8" 8,"16" 16,"32" 32,"64" 64,"128" 128) rotate by -90 font "bold,3" offset 0, graph 0.05
set xtics ("1" 1,"2" 2,"4" 4,"6" 6, "8" 8,"10" 10, "12" 12, "14" 14, "16" 16) rotate by -60 font "bold,3" offset 0, graph 0.01
set ytics font ",3"
#set yrange[0:0.15]
set xlabel "Number of Threads " font "Bold,3" 
set ylabel "Time (in s) " font "bold,3" 
set key at screen 0.78,0.58 font ",3" vertical sample 0.3 spacing 0.5 width 0.2 height 2.5 maxrows 1
set boxwidth 0.8
set style data histograms 
set style fill solid border 3
set multiplot layout 1,4
set title "N-queens (N=10) " font ",4" offset 0.2,0.2
set size 0.333,0.55
plot "10.dat" using 1:2 notitle with boxes ls 0.24 lt rgb "#FF0000", "10.dat" using 1:2 notitle with boxes ls 0.25 lt rgb "#00FF00"


set title "N-queens (N=12) " font ",4" offset 0.2,0.2
set size 0.333,0.55
plot "12.dat" using 1:2 notitle with boxes ls 0.24 lt rgb "#FF0000", "12.dat" using 1:2 notitle with boxes ls 0.25 lt rgb "#00FF00"

set title "N-queens (N=14) " font ",4" offset 0.2,0.2
set size 0.333,0.55
plot "14_op.dat" using 1:2 notitle with boxes ls 0.24 lt rgb "#FF0000", "14_op.dat" using 1:2 notitle with boxes ls 0.25 lt rgb "#00FF00"

set title "N-queens (N=16) " font ",4" offset 0.2,0.2
set size 0.333,0.55
plot "16_op.dat" using 1:2 notitle with boxes ls 0.24 lt rgb "#FF0000", "16_op.dat" using 1:2 notitle with boxes ls 0.25 lt rgb "#00FF00"

unset multiplot
