def missingnumber(arr, low, high):
    if low == high:
        return arr[low]
    mid = (low + high)//2
    if mid == low:
        return (arr[low] + arr[high])//2
    dist1 = (arr[mid] - arr[low]) / (mid - low)
    dist2 = (arr[high] - arr[mid]) / (high - mid)
    if dist1 > dist2:
        return missingnumber(arr, low, mid)
    elif dist2 > dist1:
        return missingnumber(arr, mid, high)
    else:
        return arr[mid]

arr = [4, 10, 13, 16, 19, 22, 25, 28]
print(missingnumber(arr, 0, len(arr) - 1))
