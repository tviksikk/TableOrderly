#include <iostream>
#include <string>
#include "TableSee.h"

using namespace std;

void main()
{
	table<int,std::string> v(15);

	setlocale(NULL, "Russian");

	v.add(12, std::string("����������� ������1"));
	v.add(31, std::string("����������� ������2"));
	v.add(15, std::string("������ �������� �3"));

	cout << v[15] << endl;
	cout << v[12] << endl;
	cout << v[31] << endl;

	
		
	cin.get();
}