rm opt.txt orig.txt output.txt
echo 1 | sudo tee /proc/sys/vm/drop_caches
make plot
eog runtime.png
