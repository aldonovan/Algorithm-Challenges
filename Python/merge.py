def mergeSort(arr):
    n = len(arr)
    if n == 1:
        return arr
    left = arr[0:n//2]
    right = arr[n//2:]
    sortedLeft = mergeSort(left)
    sortedRight = mergeSort(right)
    return merge(sortedLeft, sortedRight)

def merge(left, right):
    L = 0
    R = 0
    sortedArr = []
    while L < len(left) and R < len(right):
        if left[L] <= right[R]:
            sortedArr.append(left[L])
            L += 1
        else:
            sortedArr.append(right[R])
            R += 1
    for i in range(L, len(left)):
        sortedArr.append(left[i])
    for i in range(R, len(right)):
        sortedArr.append(right[i])
    return sortedArr

list = [3, 5, 2, 4, 1]
list = mergeSort(list)
print(list)
