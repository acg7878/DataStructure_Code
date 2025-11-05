#include <algorithm>
#include <iostream>
#include <random>
#include <utility>
#include <vector>
std::vector<int> generateRandomData(int count) {
    std::vector<int> data(count);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-1000000000, 1000000000);
    for (int i = 0; i < count; ++i) {
        data[i] = dis(gen);
    }
    return data;
}

void heapify(std::vector<int>& arr, int start, int end) {
    int smallest = start;
    int left = start * 2 + 1;
    int right = start * 2 + 2;

    if (left < end && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < end && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != start) {
        std::swap(arr[smallest], arr[start]);
        heapify(arr, smallest, end);
    }
}

void build_heap(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }
}

std::vector<int> topK(const std::vector<int>& arr, int K) {
    if (arr.empty() || K <= 0 || K > arr.size()) {
        return {};
    }
    std::vector<int> min_heap(arr.begin(), arr.begin() + K);
    build_heap(min_heap);
    for (int i = K; i < arr.size(); ++i) {
        if (arr[i] > min_heap[0]) {
            min_heap[0] = arr[i];
            heapify(min_heap, 0, K);
        }
    }
    std::sort(min_heap.begin(), min_heap.end(), std::greater<int>());
    return min_heap;
}

int main() {
    const int DATA_SIZE = 100000000;
    const int K = 50;

    std::cout << "Using manual min-heap:" << std::endl;
    std::vector<int> topK_manual = topK(generateRandomData(DATA_SIZE), K);
    std::cout << "The top " << K << " elements are: ";
    for (int val : topK_manual) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}