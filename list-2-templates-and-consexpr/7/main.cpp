#include <iostream>

template <typename T, typename ... Rest>
auto add(T a, Rest... rest) {
    if constexpr (sizeof...(rest) > 0) {
        return a + add(rest...);
    }
    else {
        return a;
    }
}

int main() {
    int a = 1;
    float b = 2.2;
    double c = 3.3;

    std::cout << add(a, b, c) << "\n";

    return 0;
}