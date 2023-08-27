import random
def quicksort(arr, L, R):
    if R <= L:
        return
    pivot = random.randint(L, R)
    swap(arr, L, pivot)
    newIndex = partition(arr, L, R)
    quicksort(arr, L, newIndex - 1)
    quicksort(arr, newIndex + 1, R)
def swap(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp
def partition(arr, L, R):
    pivot = arr[L]
    i = L + 1
    for j in range(L+1, R+1):
        if arr[j] < pivot:
            swap(arr, i, j)
            i += 1
    swap(arr, L, i - 1)
    return i - 1

list = [10, 8, 2, 3, 4, 1, 5, 7, 9]
quicksort(list, 0, len(list) - 1)
print(list)
