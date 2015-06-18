class C
{
private:
	int x;
	C(const C&);
	C& operator=(const C&);
public:
	C(int x = 0) : x(x) {}
	C(C&& a)
    {
    	x = std::move(a.x);
    }
    C& operator=(C&& a)
    {
    	x = std::move(a.x);
    	return *this;
    }
	bool operator>(const C& a)
	{
		return x > a.x;
	}
	bool operator<(const C& a)
	{
		return x < a.x;
	}
	int X() 
	{
		return x;
	}
};