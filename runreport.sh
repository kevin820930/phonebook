echo 1 | sudo tee /proc/sys/vm/drop_caches
rm opt.txt orig.txt output.txt
#perf stat -e cache-misses  make plot
perf stat -e cache-misses make cache-test
