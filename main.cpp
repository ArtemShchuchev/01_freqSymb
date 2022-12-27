#include <iostream>
#include <map>
#include <functional>

void printHeader();

int main()
{
	printHeader();

	const std::string inStr("Hello world!!");
	std::cout << "[IN]: " << inStr << std::endl;
	std::cout << "[OUT]:" << std::endl;

	// не сортированный словарь
	std::unordered_map<char, int> unordMap;
	for (const char& ch : inStr)
	{
		if (auto search = unordMap.find(ch); search != unordMap.end())
			++search->second;	// если словарь содержит "char", то увеличим данные
		else
			unordMap[ch] = 1;	// если "char" нет -> добавим с единичкой в данных
		
	}

	// словарь с поддержкой дубликатов и сортировкой по убыванию
	std::multimap<int, char, std::greater<int>> multiMap;
	for (const auto& [key, elem] : unordMap)
	{
		// теперь словарь отсортирован и ключом будут элементы
		multiMap.insert({ elem, key });
	}

	unordMap.clear();	// этот словарь больше не нужен

	// вывожу словарь в консоль (данные : ключи)
	for (const auto& elem : multiMap)
	{
		std::cout << elem.second << ": " << elem.first << std::endl;
	}


	return 0;
}

// функции
// заголовок 
void printHeader()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");   // задаём русский текст
	system("chcp 1251");            // настраиваем кодировку консоли
	std::system("cls");
	cout << "Задача 1. Частота символов\n"
		 << "--------------------------\n" << endl;
}