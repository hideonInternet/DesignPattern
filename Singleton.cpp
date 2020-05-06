#include <iostream>
#include <mutex>
using namespace std;


/**
class Singleton
{
public:
    static Singleton* getInstance(){
        return obj;
    }
    void print(){
        cout << "饿汉模式" << endl;
    }
private:
    Singleton(){}
    static Singleton* obj;
};

Singleton* Singleton::obj = new Singleton();
**/

class Singleton
{
private:
    Singleton(){};
    static Singleton* obj;
public:
    static Singleton* getInstance();
    static mutex m;
    void print(){
        cout << "双重检测" << endl;
    }
};

Singleton* Singleton::obj = nullptr;

Singleton* Singleton::getInstance(){
    if(obj == nullptr){
        m.lock();
        if(obj == nullptr){
            obj = new Singleton();
        }
        m.unlock();
    }
    return obj;
}



int main(){
    Singleton* p = Singleton::getInstance();
    p->print();
}