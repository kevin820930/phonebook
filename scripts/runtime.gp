reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.100]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.15):($2+0.005):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'optimized'  , \
'' using ($0+0.1):($3+0.010):3 with labels title ' ', \
'' using 4:xtic(1) with histogram title 'optimized 2', \
'' using ($0+0.30):($4+0.02):4 with labels title ' '
