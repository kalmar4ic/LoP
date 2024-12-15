#include </Users/kalmar4ic/Documents/VSCodeC++/Lab4/src/lib/Tournament.h>
#include <algorithm>
using namespace std;

Tournament::Tournament()
{
}

Tournament::~Tournament()
{
    participants.clear();
    results.clear();
}

void Tournament::readFromFile(istream &stream)
{
    int size;
    stream >> size;
    stream.ignore();
    participants.resize(size);
    for (int i = 0; i < participants.size(); i++)
    {
        if (i == participants.size() - 1)
        {
            getline(stream, participants[i].name, '\n');
        }
        else
        {
            getline(stream, participants[i].name, '|');
        }        
        participants[i].points = 0;
    }

    results.resize(size, vector<char>(size));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            stream >> results[i][j];
        }
    }
}

void Tournament::writeResultsTo(ostream &stream) const
{
    for (int i = 0; i < participants.size(); i++)
    {
        stream << participants[i].name << " " << participants[i].points << endl;
    }
}

void Tournament::calculatePoints()
{
    for (int i = 0; i < results.size(); i++)
    {
        for (int j = 0; j < results[i].size(); j++)
        {
            if (results[i][j] == 'W')
            {
                participants[i].points += 1;
            }
            else if (results[i][j] == 'D')
            {
                participants[i].points += 0.5;
            }
        }
    }
}

void Tournament::sorting()
{
    sort(participants.begin(), participants.end(), 
         [](const Participant& a, const Participant &b) { return a.points > b.points; });
}