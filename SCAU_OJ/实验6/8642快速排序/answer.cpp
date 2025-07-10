//
// Created by EDY on 25-6-27.
//
#include <iostream>
#include <vector>

void print_arr(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && arr[j] >= pivot)
            j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot)
            i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    return i;
}

void quick_sort(std::vector<int>& arr, int left, int right) {
    if (left >= right)
        return;
    int index = partition(arr, left, right);
    print_arr(arr);
    quick_sort(arr, left, index - 1);
    quick_sort(arr, index + 1, right);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);  // n-1 而不是 n
}