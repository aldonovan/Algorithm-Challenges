

def mergesort (nums): 
    if len(nums) <= 1:
        return nums
    mid = len(nums) // 2
    leftList = nums[0:mid]
    rightList = nums[mid:]
    leftList = mergesort(leftList)
    rightList = mergesort(rightList)
    return merge(leftList, rightList)

def merge(leftList, rightList):
    newSortedList = []
    leftIndex = 0
    rightIndex = 0
    while leftIndex < len(leftList) and rightIndex < len(rightList):
        if leftList[leftIndex] <= rightList[rightIndex]:
            newSortedList.append(leftList[leftIndex])
            leftIndex += 1
        else:
            newSortedList.append(rightList[rightIndex])
            rightIndex += 1
    while leftIndex < len(leftList):
        newSortedList.append(leftList[leftIndex])
        leftIndex += 1
    while rightIndex < len(rightList):
        newSortedList.append(rightList[rightIndex])
        rightIndex += 1
    return newSortedList

newList = [2, 1, 0]
print(mergesort(newList))