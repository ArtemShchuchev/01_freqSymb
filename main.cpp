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

	// ������� � ���������� ���������� � ����������� �� ��������
	std::multimap<int, char, std::greater<int>> multiMap;
	if (!inStr.empty()) {
		// �� ������������� �������
		std::unordered_map<char, int> unordMap;
		for (const char& ch : inStr) {
			++unordMap[ch];
			/*
			if (auto search = unordMap.find(ch); search != unordMap.end())
				++search->second;	// ���� ������� �������� "char", �� �������� ������
			else
				unordMap[ch] = 1;	// ���� "char" ��� -> ������� � ��������� � ������
			*/
		}

		for (const auto& [ch, count] : unordMap) {
			// ������ ������� ������������ � ������ ����� �������
			multiMap.insert({ count, ch });
		}
	}


	std::cout << "[OUT]:\n";
	// ������ ������� � ������� (������ : �����)
	for (const auto& [count, ch] : multiMap) {
		std::cout << ch << ": " << count << std::endl;
	}


	return 0;
}

// �������
// ��������� 
void printHeader() {
	using namespace std;
	setlocale(LC_ALL, "Russian");   // ����� ������� �����
	system("chcp 1251");            // ����������� ��������� �������
	std::system("cls");
	cout << "������ 1. ������� ��������\n"
		 << "--------------------------\n" << endl;
}