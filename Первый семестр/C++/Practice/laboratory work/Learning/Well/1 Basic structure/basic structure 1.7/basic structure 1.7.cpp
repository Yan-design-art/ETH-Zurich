#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    
    int a, b, c;

    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;
    std::cout << "Введите третье число: ";
    std::cin >> c;
    std::cout << "\nТри числа в обратном порядке:\n";

    std::cout << c << "\t" << b << "\t" << a;
}