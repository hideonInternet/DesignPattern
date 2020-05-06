/**
 *  工厂方法（FactoryMethod)模式与简单工厂模式相比，好处是实现了开发扩展，封闭修改原则。比方说，
 *  如果我们要新增一种运算规则，如果采用简单工厂模式，就势必要修改原有工厂类中的方法（增加新增规则的判断分支），
 *  如果我们采用工厂方法模式，就只需要新增两个继承公共接口的类，然后修改客户端代码即可。
 * **/
#include <iostream>
using namespace std;

class Operation{
public:
    /*
        基类必须要有一个可以为无参的构造函数，这样子类的构造函数才可以默认调用
    */
    Operation(int a=0, int b=0):numberA(a), numberB(b){
        cout << "Operation Constructor" << endl;
    }
    /*
        基类的析构函数必须写成虚函数，这样在调用delete 子类对象时，就可以顺利析构子类对象。
    */
    virtual ~Operation(){
        cout << "Operation Deconstructor" << endl;
    }
    void setA(int a){
        numberA = a;
    }
    void setB(int b){
        numberB = b;
    }
    int getA(){
        return numberA;
    }
    int getB(){
        return numberB;
    }
    virtual int getResult(){
        return result;
    }
private:
    int result = 0;
    int numberA = 0;
    int numberB = 0;
};

class Plus: public Operation{
public:
    Plus(){
        cout << "Plus Constructor" << endl;
    }
    Plus(Plus& p1){
        cout << "Plus Copy Constructor" << endl;
    }
    Plus(Plus&& p1){
        cout << "Plus Move Constructor" << endl;
    }
    ~Plus(){
        cout << "Plus Deconstructor" << endl;
    }
    int getResult(){
        int a = getA();
        int b = getB();
        return a + b; 
    }

};

class Minus: public Operation{
public:
    
    int getResult(){
        int a = getA();
        int b = getB();
        return a - b; 
    }
};

class Mul: public Operation{
public:
    int getResult(){
        int a = getA();
        int b = getB();
        return a * b;  
    }
};

class IFactory{
public:
    virtual Operation* getOperation(){};
    virtual ~IFactory(){
        cout << "IFactory Deconstructor" << endl;
    }
};

class PlusFactory : public IFactory{
public:
    Operation* getOperation(){
        return new Plus();
    }
    ~PlusFactory(){
        cout << "PlusFactory Deconstructor" << endl;
    }
};

class MinusFactory : public IFactory{
public:
    Operation* getOperation(){
        return new Minus();
    }
};

class MulFactory : public IFactory{
public:
    Operation* getOperation(){
        return new Mul();
    }
};


int main(){
    IFactory* fac = new PlusFactory();
    Operation* op = fac->getOperation();
    op->setA(10);
    op->setB(20);

    int res = op->getResult();
    cout << res << endl;

    delete fac;
    delete op;

    return 0;
}