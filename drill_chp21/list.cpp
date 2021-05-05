#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include<string>

struct Item 
{
    std::string name;
    int iid;
    double value;
};

template <typename T>
void print_values(T v)
{
    for( auto val : v)
            std::cout<<val.name << " " << val.iid<< " " << val.value<<std::endl;
}

bool byname(const Item a, const Item b)
{
    return a.name < b.name;
}

bool byiid (const Item a, const Item b)
{
    return a.iid < b.iid;
}

bool byvalue (const Item a, Item b)
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
    std::list<Item> li;
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
        li.push_back(temp);
    }
    
    //Sorts
    std::cout<<"The file:"<<std::endl;
    print_values(li);
    std::cout<<std::endl;

    std::cout<<"By name:"<<std::endl;
    li.sort(byname);
    print_values(li);
    std::cout<<std::endl;

    std::cout<<"By iid:"<<std::endl;
    li.sort(byiid);
    print_values(li);
    std::cout<<std::endl;

    std::cout<<"By value:"<<std::endl;
    li.sort(byvalue);
    print_values(li);
    std::cout<<std::endl;

    //Inserts
    Item insert1 = {"Horse shoe", 99, 12.34};
    Item insert2 = {"Canon S400", 9988, 499.95};

    li.insert(li.begin(), insert1);
    li.insert(li.begin(), insert2);

    std::cout<<"Inserts:"<<std::endl;
    print_values(li);
    std::cout<<std::endl;

    //Erase
    li.erase(find_if(li.begin(), li.end(), erase_name("Apple")));
    li.erase(find_if(li.begin(), li.end(), erase_name("Peach")));

    li.erase(find_if(li.begin(), li.end(), erase_iid(4)));
    li.erase(find_if(li.begin(), li.end(), erase_iid(9)));

    std::cout<<"Erase:"<<std::endl;
    print_values(li);
    std::cout<<std::endl;


    return 0;
}