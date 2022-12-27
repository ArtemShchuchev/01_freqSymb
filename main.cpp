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

	// �� ������������� �������
	std::unordered_map<char, int> unordMap;
	for (const char& ch : inStr)
	{
		if (auto search = unordMap.find(ch); search != unordMap.end())
			++search->second;	// ���� ������� �������� "char", �� �������� ������
		else
			unordMap[ch] = 1;	// ���� "char" ��� -> ������� � ��������� � ������
		
	}

	// ������� � ���������� ���������� � ����������� �� ��������
	std::multimap<int, char, std::greater<int>> multiMap;
	for (const auto& [key, elem] : unordMap)
	{
		// ������ ������� ������������ � ������ ����� ��������
		multiMap.insert({ elem, key });
	}

	unordMap.clear();	// ���� ������� ������ �� �����

	// ������ ������� � ������� (������ : �����)
	for (const auto& elem : multiMap)
	{
		std::cout << elem.second << ": " << elem.first << std::endl;
	}


	return 0;
}

// �������
// ��������� 
void printHeader()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");   // ����� ������� �����
	system("chcp 1251");            // ����������� ��������� �������
	std::system("cls");
	cout << "������ 1. ������� ��������\n"
		 << "--------------------------\n" << endl;
}