#include <iostream>
#include <string>
#include "TableSee.h"

using namespace std;

void main()
{
	table<int,std::string> v(15);

	setlocale(NULL, "Russian");

	v.fillTable();


	cout << v;

	
		
	cin.get();
}