#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] > key)
            right = mid - 1;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int key;
    std::cin >> key;
    int pos = binary_search(arr, key);
    if (pos == -1)
        std::cout << "The element is not exist.\n";
    else
        std::cout << "The element position is " << pos << ".\n";
    return 0;
}