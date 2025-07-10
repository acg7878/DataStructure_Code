//
// Created by EDY on 25-6-27.
//

#include <iostream>
#include <vector>

void print_arr(const std::vector<int>& arr) {
    for (const int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void shell_sort(std::vector<int>& arr) {
    const int size = static_cast<int>(arr.size());
    int gap = size / 2;
    while (gap >= 1) {
        for (int i = gap; i < size; i++) {
            const int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {  // j >= gap 注意取等
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
        print_arr(arr);  // 每轮排序后打印一次
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    shell_sort(arr);
}