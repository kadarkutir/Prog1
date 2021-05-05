#include<iostream>
#include<vector>
#include<array>
#include<list>
#include<algorithm>

template<typename T>
void print_values(T tp)
{
    for(auto elem:tp)
        std::cout<<elem<<" ";
        std::cout<<std::endl;
}

template<typename T, typename A>
void increment(T& tp, A inc)
{
    for(auto& elem : tp)
        elem+=inc;
}

template<typename Iter1, typename Iter2>
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for(Iter1 i= f1; i!=e1;++i)
    {
        *f2= *i;
        f2++;
    }

    return f2;
}

int main()
{
    //first array,vector,list
    std::array<int,10> myarray = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> myvector = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::list<int> mylist = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    //second array,vector,list
    std::array<int,10> myarray2 = myarray;
    std::vector<int> myvector2 = myvector;
    std::list<int> mylist2 = mylist;

    //first print
    std::cout<<"Array: ";
    print_values(myarray);
    std::cout<<"Vector: ";
    print_values(myvector);
    std::cout<<"List: ";
    print_values(mylist);
    std::cout<<std::endl;

    //second print
    std::cout<<"Array2: ";
    print_values(myarray2);
    std::cout<<"Vector2: ";
    print_values(myvector2);
    std::cout<<"List2: ";
    print_values(mylist2);
    std::cout<<std::endl;

    //increment
    std::cout<<"Increment:"<<std::endl;

    std::cout<<"Array: ";
    increment(myarray,2);
    print_values(myarray);

    std::cout<<"Vector: ";
    increment(myvector,3);
    print_values(myvector);

    std::cout<<"List: ";
    increment(mylist,5);
    print_values(mylist);

    std::cout<<std::endl;

    //copy
    std::cout<<"Copy:"<<std::endl;

    //array>>vector
    mycopy(myarray.begin(),myarray.end(),myvector.begin());
    std::cout<<"Copy vector: ";
    print_values(myvector);

    //list>>array
    mycopy(mylist.begin(),mylist.end(),myarray.begin());
    std::cout<<"Copy array: ";
    print_values(myarray);

    std::cout<<std::endl;

    //find
    std::cout<<"Find:"<<std::endl;

    //vector
    std::cout<<"Vector: ";
    print_values(myvector);
    std::vector<int>::iterator vfind;

    vfind = std::find (myvector.begin(), myvector.end(), 3);
    if (vfind != myvector.end())
        std::cout << "Element found in position: " <<distance(myvector.begin(), vfind) << std::endl;
    else
        std::cout << "Element not found in the vector"<<std::endl;

    //list
    std::cout<<"List: ";
    print_values(mylist);
    std::list<int>::iterator lfind;

    lfind = std::find (mylist.begin(), mylist.end(), 27);
    if (lfind != mylist.end())
        std::cout << "Element found in position: " <<distance(mylist.begin(), lfind) << std::endl;
    else
        std::cout << "Element not found in the list"<<std::endl;

    return 0;
}