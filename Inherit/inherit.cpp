#include <cstdlib>
#include <iostream>

using namespace std;

struct a 
{
	void foo()
	{
		cout << "A" << endl;
	}
};

struct b 
{
	void foo()
	{
		cout << "B" << endl;
	}
};

struct c 
{
	void foo()
	{
		cout << "C" << endl;
	}
};

struct listend {};

template <typename T1, typename T2>
struct list {
	typedef T1 Head;
	typedef T2 Tail;
};

template <typename list>
struct Inherit : list::Head, Inherit<typename list::Tail>
{
	typedef typename list::Head P1;
	typedef Inherit<typename list::Tail> P2;
	void foo() {
	    ((P1 *)this)->foo();
	    ((P2 *)this)->foo();
	}
};

template <>
struct Inherit <listend> {
	void foo() {};
};

int main()
{
	Inherit <list <a, list <b, list <c, listend> > > > s;
	s.foo();
	return 0;
}