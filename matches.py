#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys

def main():
    # Read through the input one line at a time
    for line in sys.stdin:
        # Convert the line to a number
        n = int(line.strip())
        a = 0
        # Read through n more lines
        for i in range(n):
            # Convert the line to a number
            b = int(sys.stdin.readline().strip())
            # XOR the number with the current value of a
            a ^= b
        # If a is not zero, print Yes
        if a != 0:
            print("Yes")
        # Otherwise, print No
        else:
            print("No")

if __name__ == "__main__":
    main()