#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Person {
    public:
    Person() {}
    Person(string n, int a);

    string getname() const { return name; }
    int getage() const { return age; }

    private:
    string name;
    int age;
};

Person::Person(string n, int a)
    : name{n},age{a}
{
    if (a < 0 || 150 < a) throw invalid_argument("Not a existing age");
    
    size_t found = n.find_first_of(";:'[]*&^%$#@!");

        if (found != string::npos) {
            throw invalid_argument("Not an existing name");
        }

}

ostream& operator<<(ostream& os, const Person& p)
{
    //return os << p.name << ' ' << p.age<<endl;
    return os << p.getname() << ' ' << p.getage();
}

istream& operator>>(istream& is, Person& p)
{
    string n;
    int a;

    is >> n >> a;
    //p.name=n;
    //p.age=a;
    p = Person(n,a);

    return is;
}

int main()
{
    try{
    //Person p;
    //p.name="Goofy";
    //p.age=63;
    //cout << p.name << " " << p.age << endl;

    vector<Person> vp;

    cout << "Write names and ages end it with end" << endl;

    for (Person p; cin >> p; ) {
        if (p.getname() == "end") break;
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