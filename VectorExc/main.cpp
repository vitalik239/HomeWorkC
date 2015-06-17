#include <iostream>
#include <fstream>
#include "vector.h"


class BrokenOne {
public:
    int a, b, c;
    BrokenOne(int x, int y, int z) : a(x), b(y), c(z) {}
    BrokenOne& operator=(const BrokenOne& x)
    {
        if (this == &x)
            return *this;
        a = x.a, b = x.b, c = x.c;
        if (a + b + c == 27)
            throw("NOOOOOOOO");
        return *this;
    }
};

int main()
{
	try
	{
		Vector <BrokenOne> q(2);
		for (int i = 0; i < 20; i++)
			q.push_back(BrokenOne(i, i, i));
	}
	catch (const char * s)
	{
		cerr << s << endl;
	}
	return 0;
}