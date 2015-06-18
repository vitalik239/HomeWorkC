#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

char q[1000000];
int cur, m, c_op, c_n, nw;
stack <int> n;
stack <char> op;

int main()
{
	//freopen("evalhard.in", "r", stdin);
	//freopen("evalhard.out", "w", stdout);
    cin >> q;
    int l = (int)strlen(q);
    q[l] = '+';
    q[l + 1] = '0';
    for (int i = 0; i < l + 2; i++)
    {
		if (q[i] >= '0' && q[i] <= '9')
            cur = cur * 10 + (q[i] - '0');
        else
        {
            if (q[i] == '+' || q[i] == '-')
            {
                while (!op.empty() && op.top() != '(')
                {
                    c_op = op.top(), op.pop();
                    c_n = n.top(), n.pop();
                    if (c_op == '*')
                        cur *= c_n;
                    if (c_op == '/')
                         cur = c_n / cur;
                    if (c_op == '+')
                        cur += c_n;
                    if (c_op == '-')
                        cur = c_n - cur;
                }
                n.push(cur);
                cur = 0;
                op.push(q[i]);
            }
            if (q[i] == '*' || q[i] == '/')
            {
                while (!op.empty() && !n.empty() && (op.top() == '*' || op.top() == '/'))
                {
                    c_op = op.top(), op.pop();
                    c_n = n.top(), n.pop();
                    if (c_op == '*')
                        cur *= c_n;
                    else
                        cur = c_n / cur;
                }
                n.push(cur);
                cur = 0;
                op.push(q[i]);
            }
            if (q[i] == ')')
            {
                while (op.top() != '(')
                {
                    c_op = op.top(), op.pop();
                    c_n = n.top(), n.pop();
                    if (c_op == '*')
                        cur *= c_n;
                    if (c_op == '/')
                        cur = c_n / cur;
                    if (c_op == '+')
                        cur += c_n;
                    if (c_op == '-')
                        cur = c_n - cur;
                }
                op.pop();
            }
            if (q[i] == '(')
                op.push(q[i]);
        }
    }
    if (!n.empty() && op.empty())
        cur = n.top();
	while (!op.empty())
    {
        c_op = op.top(), op.pop();
        c_n = n.top(), n.pop();
        if (c_op == '*')
            cur *= c_n;
        if (c_op == '/')
            cur = c_n / cur;
        if (c_op == '+')
            cur += c_n;
        if (c_op == '-')
            cur = c_n - cur;
    }
    cout << cur;
    
    return 0;
}