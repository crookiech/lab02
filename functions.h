#ifndef FUNCTIONS_H 
#define FUNCTIONS_H 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>

std::tuple<int, int, int, int> createTuple(int n1, int n2, int n3, int n4); // Функция создания кортежа с отдельными числами ip адреса
std::vector<std::tuple<int, int, int, int>> readingFile(std::string fileName); // Функция считывания файла
void sortIPAdresses(std::vector<std::tuple<int, int, int, int>>& ipAddresses); // Функция сортировки ip адресов

#endif