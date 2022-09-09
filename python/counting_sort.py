def counting_sort(arr):
    max_num = max(arr)
    nums = [0] * (max_num + 1)
    for num in arr:
        nums[num] += 1

    index = 0
    for i in range(max_num + 1):
        for j in range(nums[i]):
            arr[index] = i
            index += 1


arr = [1, 2, 3, 4, 5, 5, 6, 3, 7, 5]
counting_sort(arr)
print(arr)