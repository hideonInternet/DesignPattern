#include <iostream>
using namespace std;

class Implementor
{
public:
    virtual void Operation(){}
};

class ImplementorA : public Implementor
{
public:
    void Operation(){
        cout << "ImplementorA" << endl;
    }
};

class ImplementorB : public Implementor
{
public:
    void Operation(){
        cout << "ImplementorB" << endl;
    }
};

class Phone
{
public:
    virtual void Operation(){}
    void setImplementor(Implementor* impl){
        this->impl = impl;
    }
protected:
    Implementor* impl = nullptr;
};

class Iphone : public Phone
{
public:
    void Operation(){
        cout << "Iphone: ";
        impl->Operation();
    }
};

class Samsung : public Phone
{
public:
    void Operation(){
        cout << "Samsung: ";
        impl->Operation();
    }
};

int main(){
    Implementor* impla = new ImplementorA();
    Implementor* implb = new ImplementorB();

    Phone* firstPhone = new Samsung();
    firstPhone->setImplementor(impla);
    firstPhone->Operation();

    firstPhone->setImplementor(implb);
    firstPhone->Operation();
}