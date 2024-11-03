#include "Appliance.h"

Appliance::Appliance()
{
	brand = "Samsung";
	price = 1000;
	year = 2020;
}

Appliance::Appliance(const Appliance& A)
{
	brand = A.brand;
	price = A.price;
	year = A.year;
}


Appliance::~Appliance()
{

}

istream& Appliance::In(istream& stream)
{
	stream >> brand >> price >> year;
	return stream;
}

ostream& Appliance::Out(ostream& stream)
{
	stream << MyName() << endl;
	stream << brand << " " << price << " " << year;
	return stream;
}

int Appliance::getYear()
{
	return year;
}

int Appliance::getPrice()
{
	return price;
}

istream& operator>>(istream& stream, Appliance* A)
{
	A->In(stream);
	return stream;
}

ostream& operator<<(ostream& stream, Appliance* A)
{
	A->Out(stream);
	return stream;
}
