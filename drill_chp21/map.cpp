#include <iostream>
#include <map>
#include <string>
#include <numeric>

void get(std::map<std::string,int>& m)
{
    std::string s;
    int i;

    while (m.size() < 10) {
        std::cin >> s >> i;
        m.insert(std::make_pair(s, i));
    }
}

template<typename S, typename I>
void print(const std::map<S,I>& m)
{
    for (auto e : m)
        std::cout << e.first << ' ' << e.second << std::endl;
}

void rcopy(std::map<std::string,int>& msi, std::map<int,std::string>& mis)
{
    for(auto e : msi)
        mis.insert(std::make_pair(e.second, e.first));
}

int main(){

    std::map<std::string, int> msi;

    msi["Apple"] = 12;
    msi["Pear"] = 11;
    msi["Peach"] = 3;
    msi["Watermelon"] = 44;
    msi["Plum"] = 2;
    msi["Greap"] = 1;
    msi["Blueberries"] = 4;
    msi["Grapefruit"] = 7;
    msi["Orange"] = 9;
    msi["Guava"] = 15;

    print(msi);
    std::cout<<std::endl;

    //Erase
    msi.erase(msi.begin(), msi.end());

    print(msi);

    //Cin
    get(msi);
    std::cout<<std::endl;

    print(msi);
    std::cout<<std::endl;

    //Sum
    int total = std::accumulate(msi.begin(), msi.end(), 0,
            [](int sumofm, const std::pair<std::string,int>& m)
            { return sumofm += m.second; });

    std::cout<<"The sum of msi: " << total << std::endl;

    //Map mis
    std::map<int,std::string> mis;

    //Copy
    rcopy(msi,mis);
    std::cout<<"mis after copy:"<<std::endl;
    print(mis);

    return 0;
}