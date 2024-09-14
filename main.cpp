#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Структура для хранения IP-адреса
struct IPAddress {
    int n1, n2, n3, n4;
};

int main() {
    std::vector<IPAddress> ipAddresses;

    // Открываем файл для чтения
    std::ifstream file("C:/programming/lab02/ip_filter.tsv");
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string text1, text2, text3;
        std::getline(iss, text1, '\t');
        std::getline(iss, text2, '\t');
        std::getline(iss, text3, '\t');

        // Разделение IP-адреса на отдельные числа
        std::istringstream ipStream(text1);
        IPAddress ip;
        std::getline(ipStream, text1, '.');
        ip.n1 = std::stoi(text1);
        std::getline(ipStream, text1, '.');
        ip.n2 = std::stoi(text1);
        std::getline(ipStream, text1, '.');
        ip.n3 = std::stoi(text1);
        std::getline(ipStream, text1, '.');
        ip.n4 = std::stoi(text1);

        ipAddresses.push_back(ip);
    }

    // Закрываем файл
    file.close();

    // Сортировка в обратном лексикографическом порядке с помощью лямбда-функции
    std::sort(ipAddresses.begin(), ipAddresses.end(), [&](IPAddress ip1, IPAddress ip2){
        if (ip1.n1 != ip2.n1) {
            return ip1.n1 > ip2.n1;
        } else if (ip1.n2 != ip2.n2) {
            return ip1.n2 > ip2.n2;
        } else if (ip1.n3 != ip2.n3) {
            return ip1.n3 > ip2.n3;
        } else {
            return ip1.n4 >= ip2.n4;
        }
    });

    // Вывод отсортированного списка
    std::cout << "Вывод отсортированного списка: " << std::endl;
    for (const auto& ip : ipAddresses) {
        std::cout << ip.n1 << "." << ip.n2 << "." << ip.n3 << "." << ip.n4 << std::endl;
    }
    // Вывод отсортированного списка адресов, первый байт которых равен 1
    std::cout << "Вывод отсортированного списка адресов, первый байт которых равен 1: " << std::endl;
    for (const auto& ip : ipAddresses) {
        if (ip.n1 == 1) {
            std::cout << ip.n1 << "." << ip.n2 << "." << ip.n3 << "." << ip.n4 << std::endl;
        }
    }
    // Вывод отсортированного списка адресов, первый байт которых равен 46, а второй – 70
    std::cout << "Вывод отсортированного списка адресов, первый байт которых равен 46, а второй - 70: " << std::endl;
    for (const auto& ip : ipAddresses) {
        if ((ip.n1 == 46) && (ip.n2 == 70)) {
            std::cout << ip.n1 << "." << ip.n2 << "." << ip.n3 << "." << ip.n4 << std::endl;
        }
    }
    // Вывод отсортированного списка адресов, любой байт которых равен 46
    std::cout << "Вывод отсортированного списка адресов, любой байт которых равен 46: " << std::endl;
    for (const auto& ip : ipAddresses) {
        if ((ip.n1 == 46) || (ip.n2 == 46) || (ip.n3 == 46) || (ip.n4 == 46)) {
            std::cout << ip.n1 << "." << ip.n2 << "." << ip.n3 << "." << ip.n4 << std::endl;
        }
    }
    return 0;
}