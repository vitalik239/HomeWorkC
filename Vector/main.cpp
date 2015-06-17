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
        return *this;
    }
    void print()
    {
     	if (a + b + c == 30)
            throw("NOOOOOOOO");
       	else printf("%d %d %d\n", a, b, c);
    }
};

int main()
{
	try
	{
		Vector <BrokenOne> q(2);
		for (int i = 0; i < 100; i++)
			q.push_back(BrokenOne(i, i, i));
		Vector <bool> s(1);
        for (int i = 0; i < 10; i++)
            s.push_back(i == 3);
        for (int i = 4; i < 10; i++)
            s[i] = s[i - 1];
        for (int i = 0; i < 10; i++)
            cout << s[i].Boo() << " ";
                    
    }
	catch (const char * s)
	{
		cerr << s << endl;
	}



	return 0;
}