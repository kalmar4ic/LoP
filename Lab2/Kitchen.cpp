#include "Kitchen.h"

Kitchen::Kitchen()
{
	arr = nullptr;
	size = 0;
}

Kitchen::Kitchen(Appliance** arr, int size)
{
	this->size = size;
	Appliance** create = new Appliance* [size];
	for (int i = 0; i < size; i++)
	{
		create[i] = arr[i]->clone();
	}
	this->arr = create;
}

Kitchen::Kitchen(const Kitchen &K)
{
	size = K.size;
	arr = new Appliance * [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = K.arr[i]->clone();
	}
}

Kitchen::~Kitchen()
{
	clean();
}

void Kitchen::In()
{
	clean();
	cout << "size: ";
	cin >> size;
	cin.ignore();
	arr = new Appliance * [size];
	for (int i = 0; i < size; i++)
	{
		int type = 0;
		cout << "Type of object: " << endl;
		cout << "1 - Refrigerator" << endl;
		cout << "2 - Microwave" << endl;
		cout << "Select your type: ";
		cin >> type;
		cin.ignore();

		if (type == 1)
		{
			arr[i] = new Refrigerator();
			cout << "Brand Price Year Temperature"<< endl;
			cin >> arr[i];
		}
		else if (type == 2)
		{
			arr[i] = new Microwave();
			cout << "Brand Price Year Timer"<< endl;
			cin >> arr[i];
		}
	}
}

ostream& Kitchen::Out(ostream& stream)
{
	for (int i = 0; i < size; i++)
	{
		stream << arr[i];
	}
	return stream;
}

void Kitchen::fromFile(istream& stream)
{
	clean();
	stream >> size;
	string type;
	arr = new Appliance * [size];
	stream >> type;
	for (int i = 0; i < size; i++)
	{
		if (type == "Refrigerator")
		{
			arr[i] = new Refrigerator();
			stream >> arr[i];
		}
		else if (type == "Microwave")
		{
			arr[i] = new Microwave();
			stream >> arr[i];
		}
		stream >> type;
	}
}

void Kitchen::toFile(ostream& stream)
{
	stream << size << endl;
	Out(stream);
}

void Kitchen::clean()
{
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

void Kitchen::outByYear(int year)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getYear() == year)
		{
			arr[i]->Out(cout);
		}
	}
}

void Kitchen::outByPrice(int price)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getPrice() > price)
		{
			arr[i]->Out(cout);
		}
	}
}

void Kitchen::outByCharacteristics()
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->MyName() == "Refrigerator")
		{
			cout << "Brand Price Year Temperature"<< endl;
		}
		else if (arr[i]->MyName() == "Microwave")
		{
			cout << "Brand Price Year Timer"<< endl;
		}
		cout << arr[i];
		cout << endl;
	}
}
