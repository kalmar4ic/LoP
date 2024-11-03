#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab2/src/lib/Kitchen.h"

int main()
{
	int ch = 0;
	int size = 0;
	int yearch = 0;
	int pricech = 0;
	string fileNameOut;
	string fileNameIn;
	ifstream outFile;
	ofstream inFile;
	Kitchen kitchen;

	while (ch != 7)
	{
		cout << "Select 1 to create a class array manually" << endl;
		cout << "Select 2 to create a class array from a file" << endl;
		cout << "Select 3 to display characteristics" << endl;
		cout << "Select 4 to display devices with the specified year of manufacture;" << endl;
		cout << "Select 5 to display a list of devices with a price greater than the user specified price." << endl;
		cout << "Select 6 to append the array to the file" << endl;
		cout << "Select 7 to exit" << endl;
		cin >> ch;
		cin.ignore();

		switch (ch)
		{
		case 1:
			kitchen.In();
			break;

		case 2:
			cout << "Enter file name: ";
			cin >> fileNameOut;
			outFile.open(fileNameOut);

			kitchen.fromFile(outFile);

			outFile.close();
			break;

		case 3:
			kitchen.outByCharacteristics();
			break;

		case 4:
			cout << "Enter year: ";
			cin >> yearch;
			cin.ignore();

			kitchen.outByYear(yearch);
			break;

		case 5:
			cout << "Enter price: ";
			cin >> pricech;
			cin.ignore();

			kitchen.outByPrice(pricech);
			break;

		case 6:
			cout << "Enter file name: ";
			cin >> fileNameIn;
			inFile.open(fileNameIn);

			kitchen.toFile(inFile);

			inFile.close();
			break;

		default:
			break;
		}
	}
	return 0;
}