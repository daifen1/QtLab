#include <iostream>
#include <stdio.h>
using namespace std;

class Base
{
private:
	 void display()
	{
		cout << "Base display()" << endl;
	}
	void say()
	{
		cout << "Base say()" << endl;
	}
public:
	void exec()
	{
		display();
		say();
	}
	void f1(string a)
	{
		cout << "Base f1(string)" << endl;
	}
	void f1(int a)
	{
		cout << "Base f1(int)" << endl;
	} //overload������f1������Base����ڲ�������
};

class DeriveA: public Base
{
public:
	void display()
	{
		cout << "DeriveA display()" << endl;
	} //override��������displayΪ�麯�����ʴ˴�Ϊ��д
	void f1(int a, int b)
	{
		cout << "DeriveA f1(int,int)" << endl;
	} //redefining��f1������Base���в�Ϊ�麯�����ʴ˴�Ϊ�ض���
	void say()
	{
		cout << "DeriveA say()" << endl;
	} //redefining��ͬ��
};

class DeriveB: public Base
{
public:
	void f1(int a)
	{
		cout << "DeriveB f1(int)" << endl;
	} //redefining���ض���
};

int main()
{
	DeriveA a;
	Base *base = &a;
	base->exec();
    //)b��ߵĺ���display��A�า�ǣ�����say�����Լ��ġ�
	a.exec(); //same result as last statement

	a.say();

	DeriveB b;
	b.f1(1); //version of DeriveB called
}
