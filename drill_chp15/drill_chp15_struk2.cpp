#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

struct Person {
    public:
    Person() {}
    Person(string f,string s, int a);

    string first_name() const { return first; }
    string second_name() const { return second; }
    int getage() const { return age; }

    private:
    string first;
    string second;
    int age;
};

Person::Person(string f,string s , int a)
    : first{f},second{s},age{a}
{
    if (a < 0 || 150 < a) throw invalid_argument("Not an existing age");

    string n = f + s; 

    size_t found = n.find_first_of(";:'[]*&^%$#@!");

        if (found != string::npos) {
            throw invalid_argument("Not an existing name");
        }
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << p.first_name() << ' ' << p.second_name() << ' ' << p.getage();
}

istream& operator>>(istream& is, Person& p)
{
    string f;
    string s;
    int a;

    is >> f >> s >> a;
    p = Person(f,s,a);

    return is;
}

int main()
{
    try{
        
    vector<Person> vp;

    cout << "Write names and ages end it with end" << endl;

    for (Person p; cin >> p; ) {
        if (p.first_name() == "end") break;
        vp.push_back(p);
    }
    
    getchar();

    for (Person p : vp)
        cout << p << endl;

    }
    catch (invalid_argument& e)
    {
        cerr<< e.what() << endl;
        return -1;
    }

    return 0;
}