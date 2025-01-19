#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "create_random_file.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::string start_directory;
    size_t num_files;
    size_t min_size;
    size_t max_size;

    // Ввод данных с клавиатуры
    std::cout << "Введите путь к директории для создания файлов: ";
    std::getline(std::cin, start_directory);

    // Проверка существования директории
    std::string test_file = start_directory + "/test.tmp";
    std::ofstream test_ofs(test_file);
    if (!test_ofs) {
        std::cerr << "Ошибка: директория не существует или недоступна." << std::endl;
        return 1;
    }
    test_ofs.close();
    std::remove(test_file.c_str()); // Удаление тестового файла

    std::cout << "Введите количество файлов для создания: ";
    std::cin >> num_files;
    std::cout << "Введите минимальный размер файла (в байтах): ";
    std::cin >> min_size;
    std::cout << "Введите максимальный размер файла (в байтах): ";
    std::cin >> max_size;

    if (min_size > max_size) {
        std::cerr << "Ошибка: минимальный размер не может быть больше максимального." << std::endl;
        return 1;
    }

    // Создание файлов
    for (size_t i = 0; i < num_files; ++i) {
        create_random_file(start_directory, min_size, max_size);
    }

    return 0;
}
