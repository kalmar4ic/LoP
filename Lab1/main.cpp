#include <iostream>
#include <string>
#include <istream>
#include <fstream>
using namespace std;
#include "PersonalData.h"

int main()
{
	int ch = 0;
	int check = 0;
	int count = 0;
	int maxAge = 0;
	int minAge = 0;
	ifstream fromFile;
	ofstream toFile;
	fromFile.open("1.txt");
	toFile.open("2.txt");
	string gender = "";
	PersonalData* PDHumans = new PersonalData;

	while (ch != 10)
	{
		cout << "Select 1 to create a class array manually" << endl;
		cout << "Select 2 to create a class array from a file" << endl;
		cout << "Select 3 to show a class array" << endl;
		cout << "Select 4 to change the year of birth" << endl;
		cout << "Select 5 to show data for people older than..." << endl;
		cout << "Select 6 to show data for people with a college degree whose age is in the range" << endl;
		cout << "Select 7 to show a list of people with a specific gender" << endl;
		cout << "Select 8 to sort the array in ascending order" << endl;
		cout << "Select 9 to append the array to the file" << endl;
		cout << "Select 10 to exit" << endl;
		cin >> ch;
		cin.ignore();

		switch (ch)
		{
		case 1:
			if (check != 0)
			{
				cout << "Error, array already created" << endl;
			}
			else
			{
				cout << "Array length: ";
				cin >> count;
				cin.ignore();

				delete[] PDHumans;
				PDHumans = new PersonalData[count];

				for (int i = 0; i < count; i++)
				{
					PDHumans[i].In();
				}

				check = 1;
			}
			break;

		case 2:
			if (check != 0)
			{
				cout << "Error, array already created" << endl;
			}
			else
			{
				delete PDHumans;
				PDHumans = PersonalData::fromFile(fromFile, count);
				fromFile.close();

				check = 1;
			}
			break;

		case 3:
			if (check == 0)
			{
				cout << "Error, create a class array" << endl;
			}
			else
			{
				for (int j = 0; j < count; j++)
				{
					PDHumans[j].Out();
					cout << endl;
				}
			}
			break;

		case 4:
			if (check == 0)
			{
				cout << "Error, create a class array" << endl;
			}
			else
			{
				int line = 0;
				cout << "Select which column the birth year change will occur in: ";
				cin >> line;

				if (line > count || line == 0)
				{
					cout << "Error" << endl;
				}
				else
				{				
					int data;
					cout << "Write your year of birth: ";
					cin >> data;

					PDHumans[line - 1].set_age(data);
				}
			}
			break;

		case 5:
			if (check == 0)
			{
				cout << "Error, create a class array" << endl;
			}
			else
			{
				cout << "Age for list: ";
				cin >> maxAge;
				cin.ignore();

				for (int i = 0; i < count; i++)
				{
					PDHumans[i].age_choice(maxAge);
					cout << endl;
					
				}
			}
			maxAge = 0;
			break;

		case 6:
			if (check == 0)
			{
				cout << "Error, create a class array" << endl << endl;
			}
			else
			{
				cout << "Max age for list: ";
				cin >> maxAge;
				cin.ignore();

				cout << "Min age for list: ";
				cin >> minAge;
				cin.ignore();

				for (int i = 0; i < count; i++)
				{
					PDHumans[i].high_edu_human(minAge, maxAge);
					cout << endl;
				}
				
			}
			maxAge = 0;
			minAge = 0;
			break;

		case 7:
			if (check == 0)
			{
				cout << "Error, create a class array" << endl << endl;
			}
			else
			{
				cout << "Enter gender: ";
				cin >> gender;
				cin.ignore();

				for (int i = 0; i < count; i++)
				{
					PDHumans[i].sort_sex(gender);
					cout << endl;
				}
			}
			gender = "";
			break;

		case 8:
			if (check == 0)
			{
				cout << "Error, create a class array" << endl << endl;
			}
			else
			{
				PersonalData::sort_data(PDHumans, count);
			}
			break;

		case 9:
			if (check == 0)
			{
				cout << "Error, create a class array" << endl << endl;
			}
			else
			{
				PersonalData::ToFile(PDHumans, toFile, count);
			}
			break;
		default:
			break;
		}
	}
	delete[] PDHumans;
}