#include <iostream>
using namespace std;

class Ours{
public:
    virtual void func1(){
        cout << "Ours func1" << endl;
    }
};

class ModuleA : public Ours{
public:
    void func1(){
        cout << "ModuleA func1" << endl;
    }
};

class ModuleB : public Ours{
public:
    void func1(){
        cout << "ModuleB func1" << endl;
    }
};

class Others{
public:
    void hanshu(){
        cout << "Others hanshu" << endl;
    }
};

class OthersModuleC: public Ours{
public:
    void func1(){
        obj = Others();
        obj.hanshu();
    }
private:
    Others obj;
};

int main()
{
    Ours* a = new ModuleA();
    Ours* b = new ModuleB();
    Ours* c = new OthersModuleC();

    a->func1();
    b->func1();
    c->func1();
}
