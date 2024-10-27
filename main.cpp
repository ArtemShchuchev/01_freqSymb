#include <iostream>
#include <map>
#include <unordered_map>
#include <functional>

void printHeader();

int main()
{
	printHeader();

	const std::string inStr("Hello world!!");
	std::cout << "[IN]: " << inStr << std::endl;

	// словарь с поддержкой дубликатов и сортировкой по убыванию
	std::multimap<int, char, std::greater<int>> multiMap;
	if (!inStr.empty()) {
		// не сортированный словарь
		std::unordered_map<char, int> unordMap;
		for (const char& ch : inStr) {
			++unordMap[ch];
			/*
			if (auto search = unordMap.find(ch); search != unordMap.end())
				++search->second;	// если словарь содержит "char", то увеличим данные
			else
				unordMap[ch] = 1;	// если "char" нет -> добавим с единичкой в данных
			*/
		}

		for (const auto& [ch, count] : unordMap) {
			// теперь словарь отсортирован и ключом будут повторы
			multiMap.insert({ count, ch });
		}
	}


	std::cout << "[OUT]:\n";
	// вывожу словарь в консоль (данные : ключи)
	for (const auto& [count, ch] : multiMap) {
		std::cout << ch << ": " << count << std::endl;
	}


	return 0;
}

// функции
// заголовок 
void printHeader() {
	using namespace std;
	setlocale(LC_ALL, "Russian");   // задаём русский текст
	system("chcp 1251");            // настраиваем кодировку консоли
	std::system("cls");
	cout << "Задача 1. Частота символов\n"
		 << "--------------------------\n" << endl;
}