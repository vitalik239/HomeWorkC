#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm> 
#include "deque.h"

using namespace std;

Deque <int> l, r;

int main()
{
	try {

		for (int i = 0; i < 2; i++)
		{
			l.push_back(i + 1);
		}
		Deque<int>::myiterator it = l.begin();
		it++;
		for (int i = 0; i < 1000; i++)
			l.insert(it, i);
		l.~Deque();
	}
	catch (char const * s)
	{
		printf("%s\n", s);
	}	

	
	


	return 0;
}	