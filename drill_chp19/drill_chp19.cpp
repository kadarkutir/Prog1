#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct S {
    explicit S(T ss = 0) : val{ss} { }

    S& operator=(const T& new_val);

    T& get();
    const T& get() const;
    //void set(T tt) { val = tt; }

private:
    T val;
};

template<typename T>
T& S<T>::get()
{
    return val;
}

template<typename T>
const T& S<T>::get() const
{
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
    val = s;
    return *this;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}";

    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    char ch;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

template<typename T> void read_val(T& v)
{
    std::cin >> v;
}

int main()
{
    S<int> sint (21);
    S<char> schar ('K');
    S<double> sdouble (69.42);
    S<string> sstring ("Uf");
    S<vector<int>> svector (vector<int> {0, 1, 2, 3, 4});

    cout<<"int: "<<sint.get()<<endl;
    cout<<"char: "<<schar.get()<<endl;
    cout<<"double: "<<sdouble.get()<<endl;
    cout<<"string: "<<sstring.get()<<endl;
    std::cout << "S<vector<int>> : ";
    for (auto& a : svector.get())
        cout << a << ',';
    cout << endl;

    int i;
    cout<<"Add an int: "<<endl;
    read_val(i);
    sint=i;

    char c;
    cout<<"Add a char: "<<endl;
    read_val(c);
    schar=c;
//    schar.set('O');

    double d;
    cout<<"Add a double: "<<endl;
    read_val(d);
    sdouble=d;

    string s;
    cout<<"Add a string: "<<endl;
    read_val(s);
    sstring=s;

    cout<<"int: "<<sint.get()<<endl;
    cout<<"char: "<<schar.get()<<endl;
    cout<<"double: "<<sdouble.get()<<endl;
    cout<<"string: "<<sstring.get()<<endl;

    cout<<"Vector<int> {val, val, val}"<<endl;
    vector<int> vektor;
    read_val(vektor);
    cout<<vektor<<endl;

    return 0;
}