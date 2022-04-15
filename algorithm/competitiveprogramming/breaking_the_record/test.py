#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'breakingRecords' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY scores as parameter.
#

def breakingRecords(scores):
    worst_time = 0
    best_time = 0
    highest = -1
    lowest = 100000001
    for score in scores:
        if (score>highest):
            best_time = best_time +1 
            highest = score
        if (score<lowest):
            worst_time = worst_time +1
            lowest = score
    worst_time -=1
    best_time -=1
    result = [best_time,worst_time]
    return result 
if __name__ == '__main__':
    

    n = int(input().strip())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)
    print(result)
    
