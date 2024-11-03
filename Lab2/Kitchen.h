#pragma once
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab2/src/lib/Appliance.h"
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab2/src/lib/Microwave.h"
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab2/src/lib/Refrigerator.h"

class Kitchen
{
private:
	Appliance** arr;
	int size;
public:
	Kitchen();
	Kitchen(Appliance** arr, int size);
	Kitchen(const Kitchen& K);
	~Kitchen();

	void In();
	ostream& Out(ostream& stream);
	void fromFile(istream& stream);
	void toFile(ostream& stream);
	void clean();

	void outByYear(int year);
	void outByPrice(int price);
	void outByCharacteristics();
};

