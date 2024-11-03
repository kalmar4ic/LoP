#pragma once
#include <iostream>
#include <string>
using namespace std;
class Appliance
{
protected:
	string brand;
	int price;
	int year;

public:
	Appliance();
	Appliance(const Appliance& A);
	~Appliance();

	virtual istream& In(istream& stream);
	virtual ostream& Out(ostream& stream);
	virtual string MyName() = 0;
	virtual Appliance* clone() = 0;
	int getYear();
	int getPrice();
};

istream& operator>> (istream& stream, Appliance* A);
ostream& operator<< (ostream& stream, Appliance* A);