from math import log as log

#Largest Exponential
largeNumberFile = open('p099_base_exp.txt', 'r')
lines = largeNumberFile.readlines()
largestNumberLine = 0
largestLogSum= 0 
largestBase= 0
largestExponent= 0
for index, line in enumerate(lines):
    numbers = [int(number) for number in line.split(",")]
    logSum = log(numbers[1]) + log(log(numbers[0]))
    if logSum > largestLogSum:
        largestLogSum = logSum
        largestNumberLine = index + 1
        largestBase = numbers[0]
        largestExponent = numbers[1]
print("The largest number in the file was found on line " + str(largestNumberLine))
print("The largest number in the file is " + str(largestBase) + " raised to the " + str(largestExponent) + "th power!")