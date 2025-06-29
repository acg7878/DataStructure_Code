//
// Created by EDY on 25-6-27.
//

#include <iostream>
#include <utility>
#include <vector>

void print_arr(const std::vector<int>& arr) {
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}
void heapify(std::vector<int>& arr, int n, int i) {
  // n为堆大小，i为需要调整的结点下标
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heap_sort(std::vector<int>& arr) {
  int size = arr.size();
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(arr, size, i);
  }
  print_arr(arr);
  for (int i = size - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]);
    heapify(arr, i, 0);
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
  heap_sort(arr);
}