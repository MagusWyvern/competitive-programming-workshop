'''
New Zealand currency consists of $100, $50, $20, $10, and $5 notes and $2, $1, 50c, 20c, 10c and 5c
coins. Write a program that will determine, for any given amount, in how many ways that amount
may be made up. Changing the order of listing does not increase the count. Thus 20c may be made
up in 4 ways: 1×20c, 2×10c, 10c+2×5c, and 4×5c.

Input
Input will consist of a series of real numbers no greater than $300.00 each on a separate line. Each
amount will be valid, that is will be a multiple of 5c. The file will be terminated by a line containing
zero (0.00).

Output
Output will consist of a line for each of the amounts in the input, each line consisting of the amount
of money (with two decimal places and right justified in a field of width 6), followed by the number of
ways in which that amount may be made up, right justified in a field of width 17.

Sample Input
0.20
2.00
0.00

Sample Output
0.20 4
2.00 293
'''

# For each line of input, check if it is 0.00. If it is, break out of the loop.

while True:
    amount = float(input())
    if amount == 0.00:
        break

    ways = 1

    # 

