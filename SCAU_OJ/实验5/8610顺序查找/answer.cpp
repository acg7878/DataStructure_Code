#include <iostream>
#include <vector>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
    }
    int key, pos = 0;
    std::cin >> key;
    for (int i = 1; i <= n; i++) {
        if (key == arr[i]) {
            pos = i;
            break;
        }
    }
    if (pos == 0) {
        std::cout << "The element is not exist.\n";

    } else {
        std::cout << "The element position is " << pos << "." << std::endl;
    }
    return 0;
}