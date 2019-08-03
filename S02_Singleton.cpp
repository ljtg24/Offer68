#include<iostream>
//using System;
using namespace std;

class Lock
{
private:      
    mutex mtex;
public:
    Lock(mutex m) : mtex(m)
    {
        mtex.Lock();
    }
    ~Lock()
    {
        mtex.Unlock();
    }
};

class Singleton
{
private:
    Singleton();
    Singleton(const Singleton&){};
    ~Singleton();
    Singleton& operator=(const Singleton& s1){};

    static Singleton* instance;

public:
    static Singleton* get_instance();
};
Singleton *Singleton::instance = NULL;
Singleton::Singleton()
{}

Singleton::~Singleton()
{}


Singleton* Singleton::get_instance()
{
   if(_instance == NULL ) {
        Lock lock(m);
        if( instance == NULL) {
            instance = new Singleton();
        }
    }
    return _instance; 
}

int main()
{
    cout << 123 << endl;
}