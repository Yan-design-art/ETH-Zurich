#include <iostream>
#include <print>
#include <string>
#include <charconv>
#include <concepts>

template <typename T>
	requires std::integral<T> || std::floating_point<T>
T read_number(const std::string & text) {
	std::string text_buffer;
	T out_val{};

	while (true) {
		std::print("{}", text);

		if (!std::getline(std::cin, text_buffer)) {
			std::println("\nОшибка ввода. Окончание программы");
			exit(1);
		}

		auto [stop_character, error_status] = std::from_chars(text_buffer.data(), text_buffer.data() + text_buffer.size(), out_val);

		if (error_status == std::errc{} && stop_character == text_buffer.data() + text_buffer.size()) {
			return out_val;
		}

		std::println("Ошибка: введено неверное число. Попробуйте еще раз.");
	}
}

int main() {
	setlocale(LC_ALL, "RU");

	double price = read_number<double>("Введите цену товара: ");
	int discount = read_number<int>("Введите скидку: ");
	double result_discount = (price * discount) / 100;

	std::print("Цена со скидкой: {:.2f}", price - result_discount);

	return 0;
}