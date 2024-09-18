#ifndef PersonalData_h
#define PersonalData_h


class PersonalData
{
private:
	string secondName;
	string firstName;
	string surName;
	string sex;
	string education;
	int YoB;

public:

	PersonalData();
	PersonalData(string secN, string firN, string surN, string s, string edu, int year);
	PersonalData(const PersonalData& P);
	~PersonalData();

	void In();
	void Out();
	int get_age();
	void set_age(int age);
	void age_choice(int age);
	void high_edu_human(int minAge, int maxAge);
	void sort_sex(string gender);
	

	friend istream& operator>> (istream& stream, PersonalData& P);
	friend ostream& operator<< (ostream& stream, const PersonalData& P);

	bool operator> (const PersonalData& P);
	bool operator< (const PersonalData& P);

	static PersonalData* fromFile(istream& file, int& count);
	static void sort_data(PersonalData* P, int count);
	static void ToFile(PersonalData* P, ostream& file, int count);
};
#endif
