def counting_sort(arr):
    max_arr = max(arr)
    numbers = [0] * (max_arr + 1)
    for i in arr:
        numbers[i] += 1
    x = 0
    for i in range(max_arr + 1):
        for j in range(numbers[i]):
            arr[x] = i
            x += 1


arr = [0]
counting_sort(arr)
print(arr)
