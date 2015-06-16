#pragma once
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Deque {
private:    
    T** Show;
    size_t size, num;
    int first_show, first_T, last_show, last_T;
public:
    class myiterator : public std::iterator<std::random_access_iterator_tag, T> {
    protected:
    	int pos;
    	Deque<T> *Deq;
    public:
    	myiterator(int, Deque<T>*);
    	myiterator& operator=(const myiterator&);
    	myiterator& operator++();
    	myiterator operator++(int);
    	myiterator& operator--();
     	myiterator operator--(int);
     	myiterator operator+(int);       
     	myiterator operator-(int);
 		myiterator& operator+=(int);
     	myiterator& operator-=(int);
     	T& operator*();
    	T& operator[](int);
    	int operator-(myiterator);
    	bool operator<(myiterator);
    	bool operator>(myiterator);
    	bool operator==(myiterator);
    	bool operator!=(myiterator);
    };
    class reverse_myiterator: public myiterator {
    public:
        reverse_myiterator(int, Deque<T>*);
        reverse_myiterator& operator=(const reverse_myiterator&);
        myiterator base();
        reverse_myiterator& operator++();
        reverse_myiterator operator++(int);
        reverse_myiterator& operator--();
        reverse_myiterator operator--(int);
        reverse_myiterator operator+(int);       
        reverse_myiterator operator-(int);
        reverse_myiterator& operator+=(int);
        reverse_myiterator& operator-=(int);
        T& operator*();
        bool operator<(reverse_myiterator);
        bool operator>(reverse_myiterator);
    };
   	Deque();
    myiterator begin();
    myiterator end();
	reverse_myiterator rbegin();
    reverse_myiterator rend();
    void new_Data(size_t);
    void insert(myiterator, T);
    void Show_Realloc();
    size_t Size();
	void push_back(T);
	void push_front(T);
	void pop_back();
	void pop_front();
	T& front();
	T& back();
	T& operator[](int);
    Deque& operator=(const Deque&);
	~Deque();
};

template <typename T> 
Deque<T>::reverse_myiterator::reverse_myiterator(int a, Deque<T>* c) : myiterator(a, c) {}

template <typename T> 
typename Deque<T>::reverse_myiterator& Deque<T>::reverse_myiterator::operator=(const reverse_myiterator& a)
{
    if (this == &a)
        return *this;
    this->pos = a.pos;
    this->Deq = a.Deq;
    return *this;
}

template <typename T> 
typename Deque<T>::myiterator Deque<T>::reverse_myiterator::base()
{
    myiterator it((*this->Deq).Size() - this->pos - 1, this->Deq);
    return it;
}

template <typename T> 
typename Deque<T>::reverse_myiterator& Deque<T>::reverse_myiterator::operator++()
{
    --this->pos;
    return *this;
}

template <typename T> 
typename Deque<T>::reverse_myiterator& Deque<T>::reverse_myiterator::operator--()
{
    ++this->pos;
    return *this;
}

template <typename T> 
typename Deque<T>::reverse_myiterator Deque<T>::reverse_myiterator::operator++(int a)
{
    reverse_myiterator tmp = *this;
    --this->pos;
    return tmp;
}

template <typename T> 
typename Deque<T>::reverse_myiterator Deque<T>::reverse_myiterator::operator--(int a)
{
    reverse_myiterator tmp = *this;
    ++this->pos;
    return tmp;
}

template <typename T> 
typename Deque<T>::reverse_myiterator Deque<T>::reverse_myiterator::operator+(int a)
{
    reverse_myiterator it(this->pos - a, this->Deq);
    return it;
}

template <typename T> 
typename Deque<T>::reverse_myiterator Deque<T>::reverse_myiterator::operator-(int a)
{
    reverse_myiterator it(this->pos + a, this->Deq);
    return it;
}

template <typename T> 
typename Deque<T>::reverse_myiterator& Deque<T>::reverse_myiterator::operator+=(int a)
{
    this->pos -= a;
    return *this;
}

template <typename T> 
typename Deque<T>::reverse_myiterator& Deque<T>::reverse_myiterator::operator-=(int a)
{
    this->pos += a;
    return *this;
}

template <typename T> 
T& Deque<T>::reverse_myiterator::operator*()
{
    return (*this->Deq)[this->pos];
}

template <typename T> 
typename Deque<T>::myiterator& Deque<T>::myiterator::operator=(const myiterator& a)
{
    if (this == &a)
        return *this;
    pos = a.pos;
    Deq = a.Deq;
    return *this;
}

template <typename T> 
typename Deque<T>::myiterator& Deque<T>::myiterator::operator++()
{
    ++pos;
    return *this;
}


template <typename T> 
typename Deque<T>::myiterator& Deque<T>::myiterator::operator--()
{
    --pos;
    return *this;
}

template <typename T> 
typename Deque<T>::myiterator Deque<T>::myiterator::operator++(int a)
{
    myiterator tmp = *this;
    ++pos;
    return tmp;
}

template <typename T> 
typename Deque<T>::myiterator Deque<T>::myiterator::operator--(int a)
{
    myiterator tmp = *this;
    --pos;
    return tmp;
}

template <typename T> 
typename Deque<T>::myiterator Deque<T>::myiterator::operator+(int a)
{
    myiterator it(pos + a, Deq);
    return it;
}

template <typename T> 
typename Deque<T>::myiterator Deque<T>::myiterator::operator-(int a)
{
    myiterator it(pos - a, Deq);
    return it;
}

template <typename T> 
typename Deque<T>::myiterator& Deque<T>::myiterator::operator+=(int a)
{
    pos += a;
    return *this;
}

template <typename T> 
typename Deque<T>::myiterator& Deque<T>::myiterator::operator-=(int a)
{
    pos -= a;
    return *this;
}

template <typename T> 
T& Deque<T>::myiterator::operator*()
{
    return (*Deq)[pos];
}

template <typename T> 
T& Deque<T>::myiterator::operator[](int a)
{
    return *(*this + a);
}

template <typename T> 
int Deque<T>::myiterator::operator-(myiterator a)
{
    return pos - a.pos;
}

template <typename T> 
bool Deque<T>::myiterator::operator<(myiterator a)
{
    return (pos < a.pos); 
}

template <typename T> 
bool Deque<T>::myiterator::operator>(myiterator a)
{
    return (pos > a.pos);
}

template <typename T> 
bool Deque<T>::myiterator::operator==(myiterator a)
{
    return (pos == a.pos && Deq == a.Deq);
}

template <typename T> 
bool Deque<T>::myiterator::operator!=(myiterator a)
{
    return (!(*this == a));
}

template <typename T> 
void Deque<T>::insert(myiterator iter, T a)
{
    (*this).push_back(a);
    copy_backward(iter, (*this).end() - 1, (*this).end()); 
    *iter = a;
 }

template <typename T> 
Deque<T>::myiterator::myiterator(int a, Deque<T>* c)
{
	pos = a;
	Deq = c;
}

template <typename T> 
Deque<T>::Deque()
{
	size = 6;
	num = 300;
	Show = new T*[size]();
    first_show = size / 2 - 1;
    last_show = first_show + 1;
    new_Data(first_show);
}

template <typename T> 
typename Deque<T>::myiterator Deque<T>::begin()
{
	myiterator it(0, this);
	return it;
}

template <typename T> 
typename Deque<T>::myiterator Deque<T>::end()
{
	myiterator it(Size(), this);
	return it;
}


template <typename T> 
typename Deque<T>::reverse_myiterator Deque<T>::rbegin()
{
    reverse_myiterator it(Size() - 1, this);
    return it;
}

template <typename T> 
typename Deque<T>::reverse_myiterator Deque<T>::rend()
{
    reverse_myiterator it(-1, this);
    return it;
}


template <typename T> 
void Deque<T>::new_Data(size_t k)
{
	if (!Show[k])
		Show[k] = (T*)malloc(num * sizeof(T));
}

template <typename T> 
void Deque<T>::Show_Realloc()
{
	int t = last_show - first_show;
	T** Temp = new T*[3 * t]();
    for (int i = 0; i < first_show; i++)
        free(Show[i]);
    for (int i = last_show; i < size; i++)
        free(Show[i]);
    for (int i = first_show; i < last_show; i++)
		Temp[t + i - first_show] = Show[i];
	first_show = t;
	last_show = first_show + t;
	size = 3 * t;
	delete [] Show;
	Show = Temp;
}

template <typename T> 
size_t Deque<T>::Size()
{
    if (first_show == last_show - 1)
    	return (last_T - first_T);
    else return (last_show - first_show - 2) * num + last_T + (num - first_T);
}

template <typename T> 
void Deque<T>::push_back(T a)
{
	new (&Show[last_show - 1][last_T++]) T(a);
	if (last_T == num)
	{
		new_Data(last_show++);
		last_T = 0;
	}
	if (last_show == size - 1)
		Show_Realloc();
}

template <typename T> 
void Deque<T>::push_front(T a)
{
	if (first_show == 0 && first_T == 0)
		Show_Realloc();
	if (first_T == 0)
	{
		new_Data(--first_show);
		first_T = num;
	}
	new (&Show[first_show][--first_T]) T(a);	
}

template <typename T> 
void Deque<T>::pop_back()
{
	if (last_T == first_T && last_show - 1 == first_show)
		throw("The stack is empty");
	if (last_T == 0)
	{
		last_T = num - 1;
		last_show--;
	}
	last_T--;
    Show[last_show][last_T].~T();	
}

template <typename T> 
void Deque<T>::pop_front()
{
	if (last_T == first_T && last_show - 1 == first_show)
		throw("The stack is empty");
	Show[first_show][first_T].~T();
    first_T++;
	if (first_T == num)
		first_show++, first_T = 0;
}


template <typename T> 
T& Deque<T>::front()
{
	return Show[first_show][first_T];
}

template <typename T> 
T& Deque<T>::back()
{
	int prev = last_T - 1;
	if (prev < 0)
	{
		prev += num - 1;
		return Show[last_show - 2][prev];
	}
	else
		return Show[last_show - 1][prev];		
}	

template <typename T> 
T& Deque<T>::operator[](int a)
{
	myiterator it(a, this);
	if (it > end() || it < begin())
		throw("Out of bounds");
	return Show[first_show + a / num + (first_T + a % num) / num][(first_T + a % num) % num];
}

template <typename T> 
Deque<T>& Deque<T>::operator=(const Deque& a)
{
    if (this == &a)
        return *this;
    Show = a.Show;
    size = a.size, num = a.num;
    first_show = a.first_show, first_T = a.first_T, last_show = a.last_show, last_T = a.last_T;
    return *this;
}

template <typename T> 
Deque<T>::~Deque()
{
    if (Show)
    {
        while (Size())
            pop_back();
        for (int i = 0; i < size; i++)
        	if (Show[i])
                free(Show[i]);
	    delete [] Show;
        Show = NULL;
    }
}