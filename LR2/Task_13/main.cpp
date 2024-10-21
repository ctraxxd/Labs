#include <iostream>

int main() {
    int x, y, cnt;
    std::cin >> x >> y >> cnt;
    std::cout << x << " " << y << "\n";
    while (cnt--) {
        if (x < y)
            x += y;
        else y += x;
        std::cout << x << " " << y << "\n";
    }
    return 0;
}