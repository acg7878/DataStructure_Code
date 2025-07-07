#include <iostream>
#include <random>
#include <vector>

std::vector<int> createArr() {
    std::vector<int> arr;
    const int size = 10;
    const int min_val = 1;
    const int max_val = 100;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min_val, max_val);

    arr.reserve(size);
    for (int i = 0; i < size; ++i) {
        arr.push_back(distrib(gen));
    }
    return arr;
}
// 打印 vector 信息的辅助函数
void print_vector_info(const std::string& name, const std::vector<int>& vec) {
    long long sum = 0;
    std::cout << name << " (size=" << vec.size() << "): ";
    for (int x : vec) {
        std::cout << x << " ";
        sum += x;
    }
    std::cout << "| Sum = " << sum << std::endl;
}

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
