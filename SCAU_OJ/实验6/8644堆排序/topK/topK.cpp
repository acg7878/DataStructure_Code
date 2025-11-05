#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <algorithm>

using namespace std;

vector<int> generateRandomData(int count) {
    vector<int> data(count);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-1000000000, 1000000000);
    for (int i = 0; i < count; ++i) {
        data[i] = dis(gen);
    }
    return data;
}

vector<int> topKWithMinHeap(const vector<int>& data, int K) {
    if (data.empty() || K <= 0 || K > data.size()) {
        return {};
    }
    // 小顶堆
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < K; ++i) {
        minHeap.push(data[i]);
    }
    // 遍历剩余元素，比堆顶大则替换堆顶
    for (int i = K; i < data.size(); ++i) {
        if (data[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(data[i]);
        }
    }
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    // 从大到小排序
    sort(result.rbegin(), result.rend());

    return result;
}


void siftDown(vector<int>& heap, int start, int end) {
    int parent = start;
    int child = 2 * parent + 1; // 左子节点
    while (child <= end) {
        // 找出左右子节点中较小的那个
        if (child + 1 <= end && heap[child + 1] < heap[child]) {
            child++; // 如果右子节点更小，则指向右子节点
        }
        
        // 如果父节点已经比它最小的子节点还要小或相等，则堆性质已满足
        if (heap[parent] <= heap[child]) {
            break;
        }

        // 否则，交换父节点和最小的子节点，并继续向下调整
        swap(heap[parent], heap[child]);
        parent = child;
        child = 2 * parent + 1;
    }
}

void buildMinHeap(vector<int>& arr) {
    int n = arr.size();
    // 从最后一个非叶子节点开始，自下而上对每个节点进行siftDown操作
    for (int i = (n / 2) - 1; i >= 0; i--) {
        siftDown(arr, i, n - 1);
    }
}

vector<int> topKWithManualMinHeap(const vector<int>& data, int K) {
    if (data.empty() || K <= 0 || K > data.size()) {
        return {};
    }

    // 1. 取前K个元素作为初始堆
    vector<int> minHeap(data.begin(), data.begin() + K);

    // 2. 将这K个元素构建成一个最小堆
    buildMinHeap(minHeap);

    // 3. 遍历数组的剩余部分
    for (size_t i = K; i < data.size(); ++i) {
        // 如果当前元素比堆顶(当前K个最大值中的最小值)大
        if (data[i] > minHeap[0]) {
            // 替换堆顶元素
            minHeap[0] = data[i];
            // 向下调整，维持最小堆的性质
            siftDown(minHeap, 0, K - 1);
        }
    }

    // 4. 此时堆中的K个元素就是最大的K个，但不是有序的
    //    为了得到从大到小的顺序，我们先排序（从小到大），再翻转
    sort(minHeap.begin(), minHeap.end());
    reverse(minHeap.begin(), minHeap.end());

    return minHeap;
}


int main() {
    const int DATA_SIZE = 100000000;
    const int K = 50;
    cout << "Generating 1M random integers..." << endl;
    vector<int> data = generateRandomData(DATA_SIZE);
    cout << "Finding top " << K << " largest numbers..." << endl;
    
    cout << "Using std::priority_queue:" << endl;
    vector<int> topK_pq = topKWithMinHeap(data, K);
    cout << "The top " << K << " elements are: ";
    for (int val : topK_pq) {
        cout << val << " ";
    }
    cout << endl << endl;

    cout << "Using manual min-heap:" << endl;
    vector<int> topK_manual = topKWithManualMinHeap(data, K);
    cout << "The top " << K << " elements are: ";
    for (int val : topK_manual) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}