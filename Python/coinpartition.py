def numPartitions(coins):
    partitionSet = set()
    part = []
    numHelper(coins, part, partitionSet)
    return len(partitionSet)

def numHelper(remaining, part, partitionSet):
    if remaining == 0:
        newPart = part[:]
        newPart.sort()
        partitionSet.add(tuple(newPart))
        return
    for i in range(1, remaining + 1):
        part.append(i)
        numHelper(remaining - i, part, partitionSet)
        part.pop()

print(numPartitions(23))
