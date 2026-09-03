#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");

    unsigned short a;

    std::cout << "Введите ваш возраст: ";
    std::cin >> a;
    std::cout << "Ваш возраст: " << a;

    return 0;
}