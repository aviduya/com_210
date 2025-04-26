#include <iostream>

int SumToN(int n) {
    if (n == 0) return 0;
    // std::cout << n << std::endl;
    return n + SumToN(n - 1);

}

int main() {
    std::cout << "Answer: " << SumToN(4) << std::endl;
    return 0;
}
