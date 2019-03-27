def BubbleSort(A):
    for i in range(len(A)):
        for j in range(len(A) - 1, i, -1):
            if(A[j] < A[j - 1]):
                #swap(A, j, j - 1)
                A[j], A[j - 1] = A[j - 1], A[j]
                print(A)
                
A = [21, 34, 52, 11, 8, 51, 3]
#A = [3, 8, 11, 21, 34, 51, 52]
print(A)
BubbleSort(A)
