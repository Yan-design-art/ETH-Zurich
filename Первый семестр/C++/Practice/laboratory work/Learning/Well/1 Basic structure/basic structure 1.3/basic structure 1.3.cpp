#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "RU");

    unsigned short a;
    std::string b;

    std::cout << "Введите ваше имя: ";
    std::cin >> b;
    std::cout << "Введите ваш возраст: ";
    std::cin >> a;
    std::cout << "Привет, " << b << "! Тебе уже " << a << " лет";

    return 0;
}