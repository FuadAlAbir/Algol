def InsertionSort(A):
    for i in range(len(A)):
        temp = A[i]
        k = i;
        while k > 0 and temp < A[k - 1]:
            A[k] = A[k - 1]
            k -= 1
        A[k] = temp
        print(A)
                
A = [21, 34, 52, 11, 8, 51, 3]
InsertionSort(A)
