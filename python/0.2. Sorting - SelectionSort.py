def SelectionSort(A):
    for i in range (len(A) - 1):
        k = i
        for j in range (i+1, len(A)):
            if(A[j] < A[k]):
                k = j
        A[i], A[k] = A[k], A[i]
        print(A)
                
A = [2, 7, 4, 1, 5, 3]
print(A)
SelectionSort(A)
