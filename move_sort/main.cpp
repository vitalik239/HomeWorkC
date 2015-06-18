#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "C.h"

using namespace std;

template<class T> 
void myswap(T& a,T& b)
{
    T tmp (move (a));
    a = move (b);
	b = move (tmp);
}

template <typename T>
void qsort(T* q, int l, int r)
{
	int i = l, j = r, m = (l + r) / 2;
	while (i <= j)
	{
		while (q[m] > q[i])
			i++;
		while (q[m] < q[j])
			j--;
		if (i <= j)
		{
			myswap(q[i], q[j]);
			i++, j--;
		}
	}
	if (j > l)
		qsort(q, l, j);
	if (i < r)
		qsort(q, i, r);
}

int main()
{
	C* V = new C[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		V[i] = 1 + rand();
	for (int i = 0; i < n; i++)
		cerr << V[i].X() << " ";
	cerr << endl;
	qsort(V, 0, n - 1);
	for (int i = 0; i < n; i++)
		cerr << V[i].X() << " ";
	
	return 0;
}