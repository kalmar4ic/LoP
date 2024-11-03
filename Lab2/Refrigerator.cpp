#include "Refrigerator.h"
Refrigerator::Refrigerator()
{
	temperature = 4;
}

Refrigerator::Refrigerator(const Refrigerator& R)
{
	temperature = R.temperature;
}

Refrigerator::~Refrigerator()
{

}

string Refrigerator::MyName()
{
	return "Refrigerator";
}

istream& Refrigerator::In(istream& stream)
{
	Appliance::In(stream);
	stream >> temperature;
	return stream;
}

ostream& Refrigerator::Out(ostream& stream)
{
	Appliance::Out(stream);
	stream << " " << temperature << endl;
	return stream;
}

Appliance *Refrigerator::clone()
{
	return new Refrigerator(*this);
}