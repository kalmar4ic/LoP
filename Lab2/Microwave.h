#pragma once
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab2/src/lib/Appliance.h"
class Microwave :
	public Appliance
{
private:
	int timer;

public:
	Microwave();
	Microwave(Microwave& M);
	~Microwave();

	string MyName() override;
	istream& In(istream& stream) override;
	ostream& Out(ostream& stream) override;
	Appliance* clone() override;
};