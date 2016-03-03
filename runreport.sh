rm opt.txt orig.txt output.txt
perf record -e cache-misses  make plot
