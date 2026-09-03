#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");

    int a, b;

    std::cout << "Введите первую переменную: ";
    std::cin >> a;
    std::cout << "Введите вторую переменную: ";
    std::cin >> b;
    std::cout << "Результат сложения: " << a + b;

    return 0;
}