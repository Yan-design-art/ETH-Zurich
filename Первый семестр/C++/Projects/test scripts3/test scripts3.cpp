#include <iostream>
#include <print>
#include <string>
#include <locale>

#ifdef _WIN32
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

char getch_crossplatform() {
#ifdef _WIN32
    return static_cast<char>(_getch());
#else
    char buf = 0;
    struct termios old = { 0 };
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
    return buf;
#endif
}

void clearScreen() {
    std::print("\033[H\033[2J");
    std::flush(std::cout);
}

void waitForReturnKey() {
    std::print("\nНажмите [0] для возврата в главное меню...");
    while (true) {
        char key = getch_crossplatform();
        if (key == '0') {
            break;
        }
    }
}

void showMenu() {
    std::print("=== ГЛАВНОЕ МЕНЮ ===\n");
    std::print("1. Первая задача\n");
    std::print("2. Вторая задача\n");
    std::print("3. Третья задача\n");
    std::print("Esc. Выход из программы\n");
    std::print("====================\n");
    std::print("Нажмите цифру для выбора пункта...\n");
}

int main() {
    std::locale::global(std::locale(""));
    bool isRunning = true;

    while (isRunning) {
        clearScreen();
        showMenu();

        char choice = getch_crossplatform();

        switch (choice) {
        case '1':
            clearScreen();
            std::print("-> Вы открыли Задачу 1\n");
            std::print("Здесь выполняется полезный код задачи...\n");

            waitForReturnKey();
            break;

        case '2':
            clearScreen();
            std::print("-> Вы открыли Задачу 2\n");
            std::print("Здесь выполняется код второй задачи...\n");

            waitForReturnKey();
            break;

        case '3':
            clearScreen();
            std::print("-> Вы открыли Задачу 3\n");

            waitForReturnKey();
            break;

        case 27:
            clearScreen();
            std::print("Выход из программы. До свидания!\n");
            isRunning = false;
            break;

        default:
            break;
        }
    }

    return 0;
}