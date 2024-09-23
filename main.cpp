#include <iostream>
#include <vector>
#include <tuple>
#include "functions.h"

int main() {
    std::vector<std::tuple<int, int, int, int>> ipAddresses = readingFile("C:/programming/lab02/ip_filter.tsv");
    sortIPAdresses(ipAddresses);
    // Вывод отсортированного списка
    for (const auto& ip : ipAddresses) {
        std::cout << std::get<0>(ip) << "." 
        << std::get<1>(ip) << "." 
        << std::get<2>(ip) << "." 
        << std::get<3>(ip) << std::endl;
    }
    // Вывод отсортированного списка адресов, первый байт которых равен 1
    for (const auto& ip : ipAddresses) {
        if (std::get<0>(ip) == 1) {
            std::cout << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip) << std::endl;
        }
    }
    // Вывод отсортированного списка адресов, первый байт которых равен 46, а второй – 70
    for (const auto& ip : ipAddresses) {
        if ((std::get<0>(ip) == 46) && (std::get<1>(ip) == 70)) {
            std::cout << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip) << std::endl;
        }
    }
    // Вывод отсортированного списка адресов, любой байт которых равен 46
    for (const auto& ip : ipAddresses) {
        if ((std::get<0>(ip) == 46) || (std::get<1>(ip) == 46) || (std::get<2>(ip) == 46) || (std::get<3>(ip) == 46)) {
            std::cout << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip) << std::endl;
        }
    }
    return 0;
}