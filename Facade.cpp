#include <iostream>
using namespace std;

class MethodA{
public:
    void func1(){
        cout << "MethodA func1" << endl;
    }
    void func2(){
        cout << "MethodA func2" << endl;
    }
};

class MethodB{
public:
    void func1(){
        cout << "MethodB func1" << endl;
    }
    void func2(){
        cout << "MethodB func2" << endl;
    }
};

class MethodC{
public:
    void func1(){
        cout << "MethodC func1" << endl;
    }
    void func2(){
        cout << "MethodC func2" << endl;
    }
};

class Box{
private:
    MethodA ma;
    MethodB mb;
    MethodC mc;
public:
    Box(){
        ma = MethodA();
        mb = MethodB();
        mc = MethodC();
    }

    void allFunc1(){
        ma.func1();
        mb.func1();
        mc.func1();
    }

    void allFunc2(){
        ma.func2();
        mb.func2();
        mc.func2();
    }
};

int main(){
    Box box = Box();
    box.allFunc1();
    box.allFunc2();
}