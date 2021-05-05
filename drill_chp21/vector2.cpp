#include<fstream>
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>

template<typename T>
void print_values(T& v)
{
    for(auto e : v)
        std::cout<< e <<std::endl;
}

template<typename D,typename I>
void print_pairs(D& vd,I& vi)
{
    for(int i=0;i<vd.size();++i)
    {
        std::cout<< vd[i] << ' ' << vi[i] << std::endl;
    }
}

class Less_than {
    double v;
public:
    Less_than(double vv) : v{vv} { }

    bool operator()(const double val) { return val < v; }
};


int main()
{
    std::vector<double> vd;

    //File
    std::fstream f;
    f.open("input2.txt");
    double temp;
    while(!f.eof())
    {
        f >> temp;
        vd.push_back(temp);
    }

    //Cout
    std::cout<<"vd vector:"<<std::endl;
    print_values(vd);
    std::cout<<std::endl;

    //int vector
    std::vector<int> vi(16);

    //copy
    std::copy ( vd.begin(), vd.end(), vi.begin() );

    //cout pairs
    std::cout<<"vd and vi pairs:" << std::endl;
    print_pairs(vd,vi);
    std::cout<<std::endl;

    //sum of vd
    double dtotal = std::accumulate(vd.begin(),vd.end(),0.0);
    std::cout<<"The sum of vd: " << dtotal << std::endl;
    std::cout<<std::endl;

    //sum of difference vd and vi
    int itotal = std::accumulate(vi.begin(),vi.end(),0);
    std::cout<<"The difference of vd and vi: " << dtotal-itotal << std::endl;
    std::cout<<std::endl;

    //reverse vd
    std::reverse(vd.begin(),vd.end());
    print_values(vd);
    std::cout<<std::endl;

    //vd average
    double daverage = dtotal / vd.size();
    std::cout << "The average of vd: " << daverage << std::endl;
    std::cout<<std::endl;

    //copy vd2
    std::vector<double> vd2(16);
    auto vd2s = std::copy_if(vd.begin(),vd.end(),vd2.begin(),Less_than(daverage));
    vd2.resize(std::distance(vd2.begin(), vd2s));
    std::cout << "vd2 vector:" << std::endl;
    print_values(vd2);
    std::cout<<std::endl;

    //vd sort
    std::sort(vd.begin(),vd.end());
    std::cout << "Sorted vd:" <<std::endl;
    print_values(vd);

    return 0;
}