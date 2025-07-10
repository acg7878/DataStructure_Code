#include <iostream>
#include <vector>

void print_arr(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void merge(std::vector<int>& arr, int left, int mid, int right,
           std::vector<int>& temp) {

    int i = left;     // 左半起点 [left, mid]
    int j = mid + 1;  // 右半起点 [mid + 1, right]
    int k = left;     // 临时数组的起点

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int index = left; index <= right; index++) {
        arr[index] = temp[index];
    }
}

void mergeSort(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> temp(n);
    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;  // 左半部分子数组的最后一个元素的下标
            int right = std::min(left + 2 * size - 1,
                                 n - 1);  // 当前合并区间的右边界下标
            merge(arr, left, mid, right, temp);
        }
        print_arr(arr);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    mergeSort(arr);
}