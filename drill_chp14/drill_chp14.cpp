#include <iostream>

class pvfB1{
public:
	virtual void pvf() const = 0;
};

class B1: public pvfB1{
public:
	virtual void vf() const { std::cout << "B1::vf()"<<std::endl;}
	void f() const { std::cout << "B1::f()"<<std::endl; }
	void pvf() const override {std::cout<<"B1::pvf()"<<std::endl;}
};

class D1: public B1 {
public:
    void vf() const override {std::cout<<"D1::vf()"<<std::endl;}
	void f() const {std::cout<<"D1::f()"<<std::endl;}
};

class D2: public D1{
public:
	void pvf() const override {std::cout<<"D2::pvf()"<<std::endl;}
};

class B2{
public:
	virtual void pvf() const =0;
};

class D21: public B2{
public:
	std::string iras="valami";
	void pvf() const override {std::cout<<iras<<std::endl;}
};

class D22: public B2{
public:
	int szam=2121;
	void pvf() const override {std::cout<<szam<<std::endl;}
};

void f(const B2& b)
{
	b.pvf();
}


int main()
{
	std::cout << "B1:" << std::endl;
	B1 b1;
	b1.vf();
	b1.f();
	b1.pvf();

	std::cout << "D1:" << std::endl;
	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();

	std::cout << "B1 Reference:" << std::endl;
	B1& rb1 = d1;
	rb1.vf();
	rb1.f();
	rb1.pvf();

	std::cout<< "D2:" << std::endl;
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	std::cout<< "D21,D22:" << std::endl;
	D21 d21;
	D22 d22;

	f(d21);
	f(d22);
}