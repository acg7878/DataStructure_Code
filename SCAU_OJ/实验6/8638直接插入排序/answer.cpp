#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        int temp = i;
        while (temp > 0 && arr[temp] < arr[temp - 1]) {
            std::swap(arr[temp], arr[temp - 1]);
            temp--;
        }
        // 排序一趟打印一次
        for (int i : arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}