#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>

// Функция создания кортежа с отдельными числами ip адреса
auto createTuple(int n1, int n2, int n3, int n4) {
    return std::make_tuple(n1, n2, n3, n4);
}

// Функция считывания файла
std::vector<std::tuple<int, int, int, int>> readingFile(std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
    }
    
    std::vector<std::tuple<int, int, int, int>> ipAddresses; // Вектор с ip адресами

    // Считывание строк из файла
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string text1, text2, text3;
        std::getline(iss, text1, '\t');
        std::getline(iss, text2, '\t');
        std::getline(iss, text3, '\t');

        // Разделение ip адреса на отдельные числа
        std::istringstream ipStream(text1);
        std::getline(ipStream, text1, '.');
        auto n1 = std::stoi(text1);
        std::getline(ipStream, text1, '.');
        auto n2 = std::stoi(text1);
        std::getline(ipStream, text1, '.');
        auto n3 = std::stoi(text1);
        std::getline(ipStream, text1, '.');
        auto n4 = std::stoi(text1);

        auto IPAdress = createTuple(n1, n2, n3, n4); // Кортеж IPAdress с отдельными числами ip адреса
        
        ipAddresses.push_back(IPAdress); // Добавление кортежа в вектор с ip адресами
    }

    // Закрываем файл
    file.close();

    return ipAddresses;
}

// Функция сортировки ip адресов
void sortIPAdresses(std::vector<std::tuple<int, int, int, int>>& ipAddresses) {
    std::sort(ipAddresses.begin(), ipAddresses.end(), [](const auto& ip1, decltype(ip1) ip2){
        if (std::get<0>(ip1) != std::get<0>(ip2)) {
            return std::get<0>(ip1) > std::get<0>(ip2);
        } else if (std::get<1>(ip1) != std::get<1>(ip2)) {
            return std::get<1>(ip1) > std::get<1>(ip2);
        } else if (std::get<2>(ip1) != std::get<2>(ip2)) {
            return std::get<2>(ip1) > std::get<2>(ip2);
        } else {
            return std::get<3>(ip1) > std::get<3>(ip2);
        }
    });
}