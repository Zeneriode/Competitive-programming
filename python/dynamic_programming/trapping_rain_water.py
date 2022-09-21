"""Given an array arr[] of N non-negative integers representing the height of blocks.
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. """


def trapping_water(arr, n):
    left = [0] * n
    right = [0] * n
    water = 0

    left[0] = arr[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], arr[i])

    right[n - 1] = arr[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], arr[i])

    for i in range(0, n):
        water += min(left[i], right[i]) - arr[i]

    return water
