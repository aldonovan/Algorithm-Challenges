#include <vector>
#include <iostream>
template <class T> T median(std::vector<T> v) {
    sort(v.begin(), v.end());
    if (v.size() % 2 == 0) {
        return (v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2;
    }
    return v[v.size() / 2];
}

int main() {
    std::vector<double> floats = {1.0, 2.0, 1.4, 1.23};
    std::vector<int> integers = {1, 0, 12};
    std::cout << median(floats) << std::endl;
    std::cout << median(integers) << std::endl;
    return 0;
}