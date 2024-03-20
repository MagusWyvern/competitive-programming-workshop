'''
input:
4 1 // 4 computers, max distance 1
0 1 // computer 0 is at (0, 1)
0 2 // computer 1 is at (0, 2)
0 3 // computer 2 is at (0, 3)
0 4 // computer 3 is at (0, 4)
O 1 // repairing computer 1
O 2 // repairing computer 2
O 4 // repairing computer 4
S 1 4 // checking if computer 1 can communicate with computer 4
O 3 // repairing computer 3
S 1 4 // checking if computer 1 can communicate with computer 4

output:
FAIL
SUCCESS
'''

COMPUTER_COUNT = int(input())



