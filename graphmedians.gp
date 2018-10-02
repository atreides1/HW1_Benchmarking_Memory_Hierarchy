plot "medadjusted.csv" using ($2/1024):4 pt 7 ps 1 title "Median of Recorded Adjusted Mean Times" w lp
set ylabel "Mean Time (ns)"
set xlabel "Buffer Length (KB)"
set title "Mean Time (ns) of n Random Accesses 10 times to Buffer of n Bytes"
set logscale x 2
replot
