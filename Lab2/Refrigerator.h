#pragma once
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab2/src/lib/Appliance.h"
class Refrigerator:
	public Appliance
{
private:
	int temperature;

public:
	Refrigerator();
	Refrigerator(const Refrigerator& R);
	~Refrigerator();

	string MyName() override;
	istream& In(istream& stream) override;
	ostream& Out(ostream& stream) override;
	Appliance* clone() override;
};