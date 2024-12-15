#pragma once
#include <iostream>
#include <string>
using namespace std;
class Tournament
{
private:
    struct Participant
    {
        string name;
        double points;
    };

    vector<Participant> participants;
    vector< vector<char> > results;
public:
    Tournament();
    ~Tournament();
    void readFromFile(istream& stream);
    void writeResultsTo(ostream& stream) const;
    void calculatePoints();
    void sorting();
};