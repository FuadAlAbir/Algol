def SelectionSort(A):
    for i in range (len(A)):
        for j in range (i+1, len(A)):
            if(A[j] < A[i]):
                A[j], A[i] = A[i], A[j]
                
A = [21, 34, 52, 11, 8, 51, 3]
#A = [3, 8, 11, 21, 34, 51, 52]
print(A)
SelectionSort(A)
print(A)
