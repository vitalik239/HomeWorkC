#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>

using namespace std;


class Func
{
private:
	map <string, int> &m;
public:
	Func(map <string, int> &m) : m(m) {}
	void operator()(string s)
	{
		m[s]++;
	}
};
	
class FuncPr
{
public:
	void operator()(const pair <string, int>& p)
	{
		cout << p.first << ' ' << p.second << endl;
	}
};
	
int main()
{
	freopen("text.txt", "r", stdin);
	map <string, int> m;
	for_each(istream_iterator <string> (cin), istream_iterator <string> (), Func(m));
	for_each(m.rbegin(), m.rend(), FuncPr());
	return 0;
}