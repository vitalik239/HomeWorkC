#pragma once
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Vector {
private:    
    T* Data;
    size_t size, cap;
public:
    Vector(size_t cp = 10) : cap(cp)
    {
        size = 0;
        Data = (T*)malloc(sizeof(T) * cap);
    }
    void resize()
    {
        cap *= 2;
        T* Temp = (T*)malloc(sizeof(T) * cap);
        T* p = Temp;
        for (int i = 0; i < size; i++)
        {
            new(p) T(Data[i]); 
            p++;
        }
        free(Data);
        Data = Temp;
    }
	void push_back(T a)
	{
		if (cap == size)
            resize();
        new(&Data[size]) T(a);
        size++;
	}
	void pop_back()
	{
		if (size == 0)
            throw("Vector is empty");
        size--;
        Data[size].~T();
	}
    T& operator[](int a)
    {
        if (a < 0 || a >= size)
            throw("Out of bounds");
        return Data[a];
    }
    ~Vector()
    {
        for (int i = 0; i < size; i++)
            Data[size].~T();
    	delete [] Data;
    }
};

template <>
class Vector <bool>
{
private:
    class Boolean 
    {
    private:
        Vector &V;
        size_t pos;
        bool is;
    public:
        Boolean(Vector &V, size_t pos, bool is) : V(V), pos(pos), is(is) {}
        Boolean& operator=(bool nw)
        {
            V.set_bit(pos, nw);
            is = nw;
            return *this;
        }
        Boolean& operator=(const Boolean& s)
        {   
            if (this == &s)
                return *this;
            V.set_bit(pos, s.is);
            is = s.is;
            return *this;
        }
        bool Boo()
        {
            return is; 
        }
    };   
    int* Data;
    size_t size, cap;
public:
    Vector(size_t cp = 10) : cap(cp)
    {
        size = 0;
        Data = (int*)malloc(cap);
    }
    void resize()
    {
        cap *= 2;
        int* Temp = (int*)malloc(cap);
        int* p = Temp;
        for (int i = 0; i < size; i++)
        {
            new(p) int(Data[i]); 
            p++;
        }
        free(Data);
        Data = Temp;
    }
    void set_bit(int pos, bool a)
    {
        if (a)
            Data[pos / 8] |= (1 << (pos % 8));
        else 
            Data[pos / 8] &= ~(1 << (pos % 8));         
    }
    bool get_bit(int pos)
    {
        if (pos > size || pos < 0)
            throw("Out of bounds");
        return (Data[pos / 8] >> (pos % 8) & 1);
    }
    void push_back(bool a)
    {
        if (cap == 8 * size)
            resize();
        set_bit(size, a);
        size++;
    }
    void pop_back()
    {
        if (size == 0)
            throw("Vector is empty");
        size--;
    }
    Boolean operator[](int a)
    {
        if (a < 0 || a >= size)
            throw("Out of bounds");
        return Boolean(*this, a, get_bit(a));
    }
    ~Vector()
    {
        delete [] Data;
    }

};
