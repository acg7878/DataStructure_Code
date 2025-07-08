#include <iostream>
#include <vector>
#include "../template.hpp"

// -------------算法 begin---------------
int partion(std::vector<int>& arr, int left, int right) {
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
    int pos = partion(arr, left, right);
    quick_sort(arr, left, pos - 1);
    quick_sort(arr, pos + 1, right);
}

void partition_arr(std::vector<int> a,
                   std::vector<int>& a1,
                   std::vector<int>& a2) {
    // 排序 + 划分
    quick_sort(a, 0, a.size() - 1);
    int n = a.size();
    int n1 = n / 2;
    a1.clear();
    a2.clear();
    a1.reserve(n1);
    a2.reserve(n - n1);
    for (int i = 0; i < n1; i++) {
        a1.push_back(a[i]);
    }
    for (int i = n1; i < n; i++) {
        a2.push_back(a[i]);
    }
}
// -------------算法 end---------------

int main() {
    std::vector<int> arr = createArr();
    std::vector<int> a1, a2;
    partition_arr(arr, a1, a2);
    std::cout << "Partition Result:" << std::endl;
    print_vector_info("a1", a1);
    print_vector_info("a2", a2);
}
