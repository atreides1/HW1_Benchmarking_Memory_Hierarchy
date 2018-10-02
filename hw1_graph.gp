plot "test.csv" using ($2/1024):4 pt 7 ps 1 title "Adjusted Mean Time", "test.csv"  using ($2/1024):3 pt 7 ps 1  title "Raw Mean Time"
set ylabel "Mean Time (ns)"
set xlabel "Buffer Length (KB)"
set title "Mean Time (ns) of n Random Accesses 10 times to Buffer of n Bytes"
set logscale x 2
replot

