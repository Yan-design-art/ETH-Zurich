// ИСХОДНЫЙ КОД:

//include iostream
//void main() {
//    cout >> "Введите число: "
//        int number;
//    std::cin << number;
//    std::cout << "Вы ввели: " << number \n;
//}

#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");

	std::cout << "Введите число: ";
	int number;
	std::cin >> number;
    std::cout << "Вы ввели: " << number << "\n";

	return 0;
}