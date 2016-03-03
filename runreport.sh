echo 1 | sudo tee /proc/sys/vm/drop_caches
rm opt.txt orig.txt output.txt
perf record -e cache-misses  make plot
