#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");

    int a;

    std::cout << "Введите сторону квадрата: ";
    std::cin >> a;
    std::cout << "\nПериметр квадрата: " << a * 4 << "\n\n" << "Площадь квадрата: " << a * a;
}