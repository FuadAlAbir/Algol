def QuickSort(A, low, high):
    if low < high:
        pivot = Partition(A, low, high)
        QuickSort(A, low, pivot - 1)
        QuickSort(A, pivot + 1, high)
        
def Partition(A, low, high):
    pivot = low
    A[pivot], A[high] = A[high], A[pivot]
    for i in range(low, high):
        if A[i] <= A[high]:
            A[i], A[low] = A[low], A[i]
            low += 1
    A[low], A[high] = A[high], A[low]
    return low
                
A = [21, 34, 52, 11, 8, 51, 3]
print A
QuickSort(A, 0, len(A) - 1)
print A
