#include <iostream>
using namespace std;

class Subject{
public:
    virtual void request(){}
};

class RealSubject: public Subject{
public:
    void request(){
        cout << "RealSubject: 真实请求" << endl;
    }
};

class Proxy : public Subject{
public:
    void request(){
        if(realSubject == nullptr){
            realSubject = new RealSubject();
        }
        realSubject->request();
    }
private:
    RealSubject* realSubject = nullptr;
};

int main(){
    Proxy* proxy = new Proxy();
    proxy->request();
}