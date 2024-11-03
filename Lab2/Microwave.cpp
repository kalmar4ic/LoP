#include "Microwave.h"
Microwave::Microwave()
{
	timer = 60;
}

Microwave::Microwave(Microwave& M)
{
	timer = M.timer;
}

Microwave::~Microwave()
{

}

string Microwave::MyName()
{
	return "Microwave";
}

istream& Microwave::In(istream& stream)
{
	Appliance::In(stream);
	stream >> timer;
	return stream;
}

ostream& Microwave::Out(ostream& stream)
{
	Appliance::Out(stream);
	stream << " " << timer << endl;
	return stream;
}

Appliance *Microwave::clone()
{
	return new Microwave(*this);
}