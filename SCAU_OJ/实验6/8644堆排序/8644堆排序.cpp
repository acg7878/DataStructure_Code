//
// Created by EDY on 25-6-27.
//

#include <iostream>
#include <vector>

void print_arr(const std::vector<int> &arr) {
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}
void heapify(std::vector<int> &arr, int start, int end) {}
void heap_sort(std::vector<int> &arr) {
  int size = arr.size();
  for (int i = (size - 2) / 2; i >= 0; i--) {
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  heap_sort(arr);
}