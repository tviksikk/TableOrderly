#pragma once
#include <iostream>

template<class KEY, class VALUE>
class table
{
private:
	KEY* masskye;
	VALUE* massdata;
	size_t datamaxcount, countUsed;

public:
	table(size_t size);
	~table();

	void add(KEY k, VALUE v);

	void remove(KEY k);

	VALUE& operator[](KEY k);

	table& operator = (table& vt);


	void resize(size_t newsized);


	friend std::ostream& operator<<(std::ostream& os, table<KEY, VALUE>& t)
	{
		for (size_t i = 0; i < t.countUsed; i++)
		{
			os << t.masskye[i] << " | " << t.massdata[i] << std::endl;
		}

		return os;
	}


	void fillTable()
	{
		int random;
		std::string tmp;
		for (int i = 0;i<datamaxcount; i++)
		{
			random = rand() % 7 + 3;
			tmp.clear();
			for (int i = 0; i < random; i++)
				tmp += rand()%255;
			add(random, tmp);
		}
	}


	int Search_Binary(int left, int right, int key)
	{
		int midd = 0;
		while (1)
		{
			midd = (left + right) / 2;

			if (key < masskye[midd])       
				right = midd - 1;      
			else if (key > masskye[midd])  
				left = midd + 1;	   
			else                       
				return midd;           

			if (left > right)          
				throw 9;
		}
	}

};

template<class KEY, class VALUE>
table<KEY, VALUE>::table(size_t size)
{
	datamaxcount = size;
	masskye = new KEY[size];
	for (size_t i = 0; i < datamaxcount; i++)
	{
		masskye[i] = NULL;
	}
	massdata = new VALUE[size];
	countUsed = 0;
}

template<class KEY, class VALUE>
table<KEY, VALUE>::~table()
{
	delete[]masskye;
	delete[]massdata;
}

template<class KEY, class VALUE>
void table<KEY, VALUE>::add(KEY k, VALUE v)
{
	for (size_t i = 0; i < datamaxcount; i++)
	{
		if (masskye[i] == NULL || masskye[i] >= k)
		{
			masskye[countUsed] = k;
			massdata[countUsed++] = v;

			for (size_t x = i; x < countUsed - 1; x++)
			{
				KEY tk = masskye[x];
				VALUE tv = massdata[x];

				masskye[x] = masskye[countUsed - 1];
				massdata[x] = massdata[countUsed - 1];
				masskye[countUsed - 1] = tk;
				massdata[countUsed - 1] = tv;
			}
			return;

		}
	}

	throw 1;

}

template<class KEY, class VALUE>
void table<KEY, VALUE>::remove(KEY k)
{

	try
	{
		int index = Search_Binary(0, s, k);
		for (size_t x = index; i < countUsed; i++)
		{
			masskye[x] = masskye[used - 1];
			massdata[x] = massdata[used - 1];
		}
		masskye[countUsed--] = KEY();
	}
	catch (int e)
	{
	}
}

template<class KEY, class VALUE>
VALUE & table<KEY, VALUE>::operator[](KEY k)
{

	try
	{
		return massdata[Search_Binary(0, countUsed, k)];
	}
	catch (int e)
	{
	}
	throw 1;
	
}

template<class KEY, class VALUE>
table<KEY, VALUE> & table<KEY, VALUE>::operator=(table & vt)
{
	datamaxcount = vt.datamaxcount;
	masskye = new KEY[datamaxcount];
	massdata = new VALUE[datamaxcount];
	countUsed = vt.countUsed;
	for (size_t i = 0; i < datamaxcount; i++)
	{
		masskye[i] = vt.masskye[i];
		massdata[i] = vt.massdata[i];
	}

	return *this;
}

template<class KEY, class VALUE>
void table<KEY, VALUE>::resize(size_t newsized)
{

	if (newsized < countUsed)
		throw 111;

	KEY* Tkey = new KEY[newsized];
	VALUE* Tval = new VALUE[newsized];
	size_t insertindex = 0;
	for (int i = 0; i < datamaxcount; i++)
	{
		Tkey[insertindex] = masskye[i];
		Tval[insertindex] = massdata[i];
		++insertindex;
		if (masskye[i] == NULL)
			break;
	}
	delete[]masskye, massdata;
	masskye = Tkey;
	massdata = Tval;
	datamaxcount = newsized;
}
