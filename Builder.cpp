#include <iostream>
using namespace std;

class Process{
public:
    virtual void processA()=0;
    virtual void processB()=0;
    virtual void processC()=0;
    virtual void processD()=0;
};

class ProductI : public Process{
public:
    void processA(){
        cout << "ProcudtI A" << endl;
    }
    void processB(){
        cout << "ProcudtI B" << endl;
    }
    void processC(){
        cout << "ProcudtI C" << endl;
    }
    void processD(){
        cout << "ProcudtI D" << endl;
    }
};

class ProductII : public Process{
public:
    void processA(){
        cout << "ProcudtII A" << endl;
    }
    void processB(){
        cout << "ProcudtII B" << endl;
    }
    void processC(){
        cout << "ProcudtII C" << endl;
    }
    void processD(){
        cout << "ProcudtII D" << endl;
    }
};

class Director{
public:
    Director(Process* p){
        this->p = p;
    }
    void createProduct(){
        p->processA();
        p->processB();
        p->processC();
        p->processD();
    }
private:
    Process* p = nullptr;;
};

int main(){
    Process* p = new ProductII();
    Director d(p);

    d.createProduct();
}