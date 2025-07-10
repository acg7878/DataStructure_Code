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

void selectSort(std::vector<int>& arr) {
    int size = arr.size();
    int count = 0;
    // count用来表示进行了几轮的计算，也用来充当当前轮次的第“一”个元素的index
    while (count < size - 1) {
        int min = arr[count];
        int min_index = count;
        for (int i = count; i < size; i++) {
            if (min > arr[i]) {
                min_index = i;
                min = arr[i];
            }
        }
        std::swap(arr[min_index], arr[count]);
        count++;
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
    selectSort(arr);
}