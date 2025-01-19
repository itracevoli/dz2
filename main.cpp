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

    // ���� ������ � ����������
    std::cout << "������� ���� � ���������� ��� �������� ������: ";
    std::getline(std::cin, start_directory);

    // �������� ������������� ����������
    std::string test_file = start_directory + "/test.tmp";
    std::ofstream test_ofs(test_file);
    if (!test_ofs) {
        std::cerr << "������: ���������� �� ���������� ��� ����������." << std::endl;
        return 1;
    }
    test_ofs.close();
    std::remove(test_file.c_str()); // �������� ��������� �����

    std::cout << "������� ���������� ������ ��� ��������: ";
    std::cin >> num_files;
    std::cout << "������� ����������� ������ ����� (� ������): ";
    std::cin >> min_size;
    std::cout << "������� ������������ ������ ����� (� ������): ";
    std::cin >> max_size;

    if (min_size > max_size) {
        std::cerr << "������: ����������� ������ �� ����� ���� ������ �������������." << std::endl;
        return 1;
    }

    // �������� ������
    for (size_t i = 0; i < num_files; ++i) {
        create_random_file(start_directory, min_size, max_size);
    }

    return 0;
}
