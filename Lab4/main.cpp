#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
#include "/Users/kalmar4ic/Documents/VSCodeC++/Lab4/src/lib/Tournament.h"

int main()
{
    Tournament tournament;
    ifstream file;
    ofstream file2;
    file.open("1.txt");
    file2.open("2.txt");
    int choice;
    while (choice != 5)
    {
        cout << "Выберите 1, чтобы создать турнир из файла" << endl;
        cout << "Выберите 2, чтобы вывести результаты" << endl;
        cout << "Выберите 3, чтобы отсортировать результаты по порядку убывания" << endl;
        cout << "Выберите 4, чтобы записать результаты в файл" << endl;
        cout << "Выберите 5, чтобы выйти из программы" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            tournament.readFromFile(file);
            tournament.calculatePoints();
        }
        else if (choice == 2)
        {
            tournament.writeResultsTo(cout);
        }
        else if (choice == 3)
        {
            tournament.sorting();
        }
        else if (choice == 4)
        {
            tournament.writeResultsTo(file2);
        }
    }
    file.close();
    file2.close();
    return 0;
}