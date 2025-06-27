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

void bubble_sort(std::vector<int> &arr) {
  int size = arr.size();
  while (size >= 1) {
    bool is_sort = true;
    for (int i = 1; i < size; i++) {
      if (arr[i] < arr[i - 1]) {
        std::swap(arr[i], arr[i - 1]);
        is_sort = false;
      }
    }
    size--;
    print_arr(arr);
    if (is_sort) break;
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  bubble_sort(arr);
}