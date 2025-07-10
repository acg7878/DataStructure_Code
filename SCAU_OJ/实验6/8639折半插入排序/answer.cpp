#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& arr, int start, int end,
                  const int key) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}

void print_arr(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void binary_sort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int pos = binary_search(arr, 0, i - 1, key);
        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
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
    binary_sort(arr);
}
