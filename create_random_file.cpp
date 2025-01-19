#include "create_random_file.h"
#include "random_string.h"
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

// Функция для создания файла с случайным содержимым
void create_random_file(const std::string& directory, size_t min_size, size_t max_size) {
    std::string filename = random_string(10) + ".txt";
    std::string file_path = directory + "/" + filename;

    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<size_t> size_dist(min_size, max_size);
    size_t file_size = size_dist(rng);

    try {
        std::ofstream ofs(file_path, std::ios::binary);
        if (ofs) {
            std::vector<char> buffer(file_size);

            // Генератор случайных байт от 0 до 255
            std::uniform_int_distribution<int> byte_dist(0, 255);

            // Заполнение буфера случайными байтами
            for (size_t i = 0; i < file_size; ++i) {
                buffer[i] = static_cast<char>(byte_dist(rng));
            }

            ofs.write(buffer.data(), file_size);
            ofs.close();
            std::cout << "Файл создан: " << file_path << " (" << file_size << " байт)\n";
        }
        else {
            throw std::ios_base::failure("Не удалось открыть файл для записи.");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при создании файла: " << file_path << " - " << e.what() << std::endl;
    }
}
