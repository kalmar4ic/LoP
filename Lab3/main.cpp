#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab3/src/lib/TMatrix.h"
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab3/src/lib/Fraction.h"

int main()
{
	srand(time(0));
	ifstream Fromfile;
	ofstream Tofile;
	string filename;
	int choice;
	int choice2;
	int max, min;
	cout << "Нажмите 1 - чтобы использовать значения int" << endl;
	cout << "Нажмите 2 - чтобы использовать значения Fraction" << endl;
	cin >> choice;
	cin.ignore();
	if (choice == 1)
	{
		TMatrix<int> matr;
		cout << "Нажмите 1 - чтобы ввести значения с клавиатуры" << endl;
		cout << "Нажмите 2 - чтобы ввести значения из файла" << endl;
		cin >> choice2;
		if (choice2 == 1)
		{
			matr.In(cin);
		}
		else if (choice2 == 2)
		{
			cout << "Введите название файла: ";
			cin >> filename;
			Fromfile.open(filename);
			matr.In(Fromfile);
			Fromfile.close();
		}
		matr.Out(cout);
		cout << "Главная диагональ: " << matr.mainDiagonal() << endl;
		cout << "Минимальное число: " << matr.findMinNumber() << endl;

		cout << "Если вы хотите задать значения рандомно - нажмите 3" << endl;
		cout << "Если вы хотите записать значения в файл - нажмите 4" << endl;
		cout << "Если вы хотите задать значения закончить программу - нажмите 5" << endl;
		cin >> choice2;
		cin.ignore();
		if (choice2 == 3)
		{
			cout << "Введите максимальное и минимальное значение: ";
			cin >> max >> min;
			matr.generateRandomValues(min, max);
			matr.Out(cout);
		}
		else if(choice2 == 4)
		{
			cout << "Введите название файла: ";
			cin >> filename;
			Tofile.open(filename);
			matr.Out(Tofile);
			Tofile.close();
		}

	}
	else if (choice == 2)
	{
		TMatrix<Fraction> matr;
		cout << "Нажмите 1 - чтобы ввести значения с клавиатуры" << endl;
		cout << "Нажмите 2 - чтобы ввести значения из файла" << endl;
		cin >> choice2;
		if (choice2 == 1)
		{
			matr.In(cin);
		}
		else if (choice2 == 2)
		{
			cout << "Введите название файла: ";
			cin >> filename;
			Fromfile.open(filename);
			matr.In(Fromfile);
			Fromfile.close();
		}
		matr.Out(cout);
		cout << "Главная диагональ: " << matr.mainDiagonal() << endl;
		cout << "Минимальное число: " << matr.findMinNumber() << endl;
		cout << "Если вы хотите задать значения рандомно - нажмите 3" << endl;
		cout << "Если вы хотите записать значения в файл - нажмите 4" << endl;
		cout << "Если вы хотите задать значения закончить программу - нажмите 5" << endl;
		cin >> choice2;
		cin.ignore();
		if (choice2 == 3)
		{
			cout << "Введите максимальное и минимальное значение: ";
			cin >> max >> min;
			matr.generateRandomValues(min, max);
			matr.Out(cout);
		}
		else if(choice2 == 4)
		{
			cout << "Введите название файла: ";
			cin >> filename;
			Tofile.open(filename);
			matr.Out(Tofile);
			Tofile.close();
		}
		}
	return 0;
}