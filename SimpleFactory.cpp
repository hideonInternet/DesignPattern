#include <iostream>
using namespace std;

class Operation{
public:
    Operation(double a=0, double b=0):numberA(a), numberB(b){}
    void setA(double a){
        numberA = a;
    }
    void setB(double b){
        numberB = b;
    }
    double getA(){
        return numberA;
    }
    double getB(){
        return numberB;
    }
    virtual double getResult(){
        return result;
    }
private:
    double result = 0;
    double numberA = 0;
    double numberB = 0;
};

class Plus: public Operation{
public:
    double getResult(){
        double a = getA();
        double b = getB();
        return a + b; 
    }
};

class Minus: public Operation{
public:
    double getResult(){
        double a = getA();
        double b = getB();
        return a - b; 
    }
};

class Mul: public Operation{
public:
    double getResult(){
        double a = getA();
        double b = getB();
        return a * b;  
    }
};

int main(){
    Operation* op = new Minus();
    op->setA(10);
    op->setB(20);

    double res = op->getResult();
    
    printf("%d", res);

    return 0;
}