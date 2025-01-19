#include "random_string.h"
#include <random>

// Функция для генерации случайной строки заданной длины
std::string random_string(size_t length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string result;
    std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);
    std::default_random_engine rng(std::random_device{}());

    for (size_t i = 0; i < length; ++i) {
        result += charset[dist(rng)];
    }
    return result;
}
