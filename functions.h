#ifndef FUNCTIONS_H 
#define FUNCTIONS_H 

std::tuple<int, int, int, int> createTuple(int n1, int n2, int n3, int n4); // Функция создания кортежа с отдельными числами ip адреса
std::vector<std::tuple<int, int, int, int>> readingFile(std::string fileName); // Функция считывания файла
void sortIPAdresses(std::vector<std::tuple<int, int, int, int>>& ipAddresses); // Функция сортировки ip адресов

#endif