#!/usr/bin/env python3
import time

file: str = "./2023/data/20231201-trebuchet.txt"

def main():
    sum = 0

    with open(file, "r") as f:
        for line in f:

            true_idx = []
            for idx, val in enumerate(line):
                val = val.isdigit()
                if val:
                    true_idx.append(idx)

            min_val = line[min(true_idx)]
            max_val = line[max(true_idx)]

            sum += int(min_val + max_val)
            
    print(sum)

# Number of iterations
n = 10
total_time = 0

for _ in range(n):
    start_time = time.time()
    main()
    end_time = time.time()
    total_time += (end_time - start_time)

average_time = total_time / n
print("Average execution time over", n, "iterations:", average_time, "seconds")