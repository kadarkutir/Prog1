#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>

struct Item{
    std::string name;
    int iid;
    double value;
};

template <typename T>
void print_values(T v)
{
    for( auto row : v)
        std::cout<<row.name << " " << row.iid<< " " << row.value<<std::endl;
}

bool byname(const Item a, const Item b)
{
    return a.name < b.name;
}

bool byiid (const Item a, const Item b)
{
    return a.iid < b.iid;
}

bool byvalue (const Item a, const Item b)
{
    return a.value > b.value;
}

class erase_name{
    std::string name;
    public:
    erase_name(std::string nn): name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};

class erase_iid {
    int iid;
public:
    erase_iid(int ii) : iid{ii} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};



int main()
{
    //File
    std::vector<Item> vi;
    std::ifstream f;
    f.open("input1.txt");
    Item temp;
    std::string val;
    while(!f.eof())
    {
        getline(f, temp.name, ';');
        getline (f, val, ';');
        temp.iid = stoi(val);
        getline(f, val);
        temp.value = stod(val);
        vi.push_back(temp);
    }

    //Sorts
    std::cout<<"The file:"<<std::endl;
    print_values(vi);
    std::cout<<std::endl;

    std::cout<<"By name:"<<std::endl;
    sort(vi.begin(), vi.end(), byname);
    print_values(vi);
    std::cout<<std::endl;

    std::cout<<"By iid:"<<std::endl;
    sort(vi.begin(), vi.end(), byiid);
    print_values(vi);
    std::cout<<std::endl;

    std::cout<<"By value:"<<std::endl;
    sort(vi.begin(),vi.end(),byvalue);
    print_values(vi);
    std::cout<<std::endl;

    //Inserts
    std::cout<<"Inserts:"<<std::endl;
    Item insert1 = {"Horse shoe", 99, 12.34};
    Item insert2 = {"Canon S400", 9988, 499.95};

    vi.insert(vi.begin(), insert1);
    vi.insert(vi.begin(), insert2);

    print_values(vi);
    std::cout<<std::endl;

    //Erase
    //Name
    std::cout<<"Erase by name:"<<std::endl;
    vi.erase(std::find_if(vi.begin(), vi.end(), erase_name("Apple")));
    vi.erase(std::find_if(vi.begin(), vi.end(), erase_name("Plum")));
    print_values(vi);
    std::cout<<std::endl;

    //Iid
    std::cout<<"Erase by iid:"<<std::endl;
    vi.erase(std::find_if(vi.begin(), vi.end(), erase_iid(5)));
    vi.erase(std::find_if(vi.begin(), vi.end(), erase_iid(2)));
    print_values(vi);



    return 0;
}