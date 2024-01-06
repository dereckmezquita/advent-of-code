#!/usr/bin/env python3
from typing import List
import time

file: str = "./2023/data/20231201-trebuchet.txt"

def main():
    sum: int = 0

    with open(file, "r") as f:
        for line in f:
            digits: List[int] = []

            for char in line:
                if char.isdigit():
                    digits.append(char)

            if len(digits) > 0:
                sum += int(digits[0] + digits[-1])

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