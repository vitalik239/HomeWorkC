#include <cstdlib>
#include <iostream>

using namespace std;

struct a 
{
	/*void foo()
	{
		cerr << "A" << endl;
	}*/
};

struct b 
{
	void foo()
	{
		cerr << "B" << endl;
	}
};

struct c 
{
	void foo()
	{
		cerr << "C" << endl;
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
	typedef typename list::Head This;
	typedef Inherit<typename list::Tail> Next;

	template <void (This::*)()>
	struct Try {};

	template <typename T>
	void Call(Try<&T::foo>*)
	{
		This::foo();
	}

	template <typename T>
	void Call(...) {
	}

	void foo() {
	    Call <This> (nullptr);
	    ((Next *)this)->foo();
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


