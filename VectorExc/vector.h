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
        try
        {
            T* p = Temp;
            for (int i = 0; i < size; i++)
            {
                new(p) T(Data[i]); 
                p++;
            }
        }
        catch (...)
        {
            free(Temp);
            Temp = NULL;
            throw("Something went wrong");
        }
        if (Temp)
        {
            free(Data);
            Data = Temp;
        }
    }
    void push_back(T a)
    {
        if (cap == size)
            resize();
        try
        {
            new(&Data[size]) T(a);
        }
        catch (...)
        {
            throw("Placement New fail");
        }
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
