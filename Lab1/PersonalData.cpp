#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "PersonalData.h"


PersonalData::PersonalData()
{
	secondName = "Cherkahin";
	firstName = "Sergey";
	surName = "Antonovich";
	sex = "Male";
	education = "School";
	YoB = 2005;
}

PersonalData::PersonalData(string secN, string firN, string surN, string s, string edu, int year)
{
	secondName = secN;
	firstName = firN;
	surName = surN;
	sex = s;
	education = edu;
	YoB = year;
}

PersonalData::PersonalData(const PersonalData& P)
{
	secondName = P.secondName;
	firstName = P.firstName;
	surName = P.surName;
	sex = P.sex;
	education = P.education;
	YoB = P.YoB;
}

PersonalData::~PersonalData()
{

}

void PersonalData::In()
{
	cin >> secondName >> firstName >> surName >> sex >> education >> YoB;
}

void PersonalData::Out()
{
	cout << "secondName: " << secondName << "\n" << "firstName: " << firstName << "\n" << "surName: " << surName << "\n" << "sex: " << sex << "\n" 
		<< "education: " << education << "\n" << "Year of Birth: " << YoB << endl;
}

int PersonalData::get_age()
{
	int ageReturn;
	
	ageReturn = YoB;

	return ageReturn;
}

void PersonalData::set_age(int age)
{
	YoB = age;
}

void PersonalData::age_choice(int age)
{

	if (YoB < age)
	{
		Out();
	}
}

void PersonalData::high_edu_human(int minAge, int maxAge)
{
	if (education == "High" && YoB > minAge && YoB < maxAge)
	{
		Out();
	}
}

void PersonalData::sort_sex(string gender)
{
	if (sex == gender)
	{
		Out();
	}
}

void PersonalData::sort_data(PersonalData* P, int count)
{
	PersonalData x;
	for (int i = 0; i < count; i++)
	{
		for (int j = count - 1; j > i; j--)
		{
			if (P[j - 1] > P[j])
			{
				x = P[j - 1];
				P[j - 1] = P[j];
				P[j] = x;
			}
		}
	}
}

istream& operator>> (istream& stream, PersonalData& P)
{	
	stream >> P.secondName >> P.firstName >> P.surName >> P.sex >> P.education >> P.YoB;
	return stream;
}

ostream& operator<< (ostream& stream, const PersonalData& P)
{
	stream << "secondName: " << P.secondName << "\n" << "firstName: " << P.firstName << "\n" << "surName: " 
		<< P.surName << "\n" << "sex: " << P.sex << "\n" << "education: " << P.education << "\n" << "Year of Birth: " << P.YoB << endl;
	return stream;
}

bool PersonalData::operator>(const PersonalData& P)
{
	return (YoB > P.YoB);
	
}

bool PersonalData::operator<(const PersonalData& P)
{
	return (YoB < P.YoB);
}

PersonalData* PersonalData::fromFile(istream& file, int& count)
{
	int size;
	file >> size;
	count = size;
	PersonalData* Data = new PersonalData[size];
	for (int i = 0; i < size; i++)
	{
		file >> Data[i];
	}
	return Data;
}

void PersonalData::ToFile(PersonalData* P, ostream& file, int count)
{
	file << count << endl;
	for (int i = 0; i < count; i++)
	{
		file << P[i].secondName << " " << P[i].firstName << " " << P[i].surName << " " << P[i].sex << " " << P[i].education << " " << P[i].YoB << endl;
	}

}