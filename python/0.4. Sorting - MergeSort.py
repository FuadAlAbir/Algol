def MergeSort(A):
    if len(A) > 1:
        mid = len(A)//2
        leftHalf = A[:mid]
        rightHalf = A[mid:]
        MergeSort(leftHalf)
        MergeSort(rightHalf)
        
        i = j = k = 0
        while i < len(leftHalf) and j < len(rightHalf):
            if leftHalf[i] < rightHalf[j]:
                A[k] = leftHalf[i]
                i = i+1
            else:
                A[k] = rightHalf[j]
                j = j + 1
            k = k + 1
            
        while i < len(leftHalf):
            A[k] = leftHalf[i]
            i = i + 1
            k = k + 1
            
        while j < len(rightHalf):
            A[k] = rightHalf[j]
            j = j + 1
            k = k + 1
                
A = [21, 34, 52, 11, 8, 51, 3]
MergeSort(A)
print A
