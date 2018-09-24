plot "test.csv" using 3 title "Adjusted Mean Time" with lp, \
"test.csv" using 2 title "Raw Mean Time" with lp, \
set ylabel "Mean Time (ns)"
set xlabel "Buffer Length (Bytes)"
set title "Time (ns) of 1000 Random Accesses to Buffer of 'n' Bytes"
set logscale x2
