plot "test.csv" using 2:4 title "Adjusted Mean Time", "test.csv"  using 2:3 title "Raw Mean Time"
set ylabel "Mean Time (ns)"
set xlabel "Buffer Length (Bytes)"
set title "Mean Time (ns) of n Random Accesses 10 times to Buffer of n Bytes"
set logscale x 2
replot
