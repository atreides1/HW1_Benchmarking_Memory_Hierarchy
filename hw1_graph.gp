plot "test.csv" using 1:3 title "Adjusted Mean Time", "test.csv"  using 1:2 title "Raw Mean Time"
set ylabel "Mean Time (ns)"
set xlabel "Buffer Length (Bytes)"
set title "Time (ns) of 1000 Random Accesses to Buffer of 'n' Bytes"
set logscale x 2
set logscale y 10
replot
