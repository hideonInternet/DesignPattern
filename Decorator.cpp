#include <iostream>
#include <string>
using namespace std;

class Component{
public:
     virtual void operation(){};
     Component(){
         cout << "Component 构造" << endl;
     }
     ~Component(){
        cout << "Component 析构" << endl;
    }
};

class ConcreteComponent:public Component{
public:
    ConcreteComponent(string name){
        cout << "ConcreteComponent 构造" << endl;
        this->name = name;
    }
    ~ConcreteComponent(){
        cout << "ConcreteComponent 析构" << endl;
    }
    void operation(){
        cout << name << endl;
    }
private:
    string name;
};

class Decorate : public Component{
public:
    void setComponent(Component* component){
        this->component = component;
    }
    virtual void operation(){
        if(component != nullptr){
            component->operation();
        }
    }
    Decorate(){
        cout << "Decorate 构造" << endl;
    }
    ~Decorate(){
        cout << "Decorate 析构" << endl;
    }
private:
    Component* component = nullptr;
};

class DecorateA : public Decorate{
public:
    void operation(){
        Decorate::operation();
        cout << "DecorateA Operation" << endl;
    }
    ~DecorateA(){
        cout << "DecorateA 析构" << endl;
    }
    DecorateA(){
        cout << "DecorateA 构造" << endl;
    }
};

class DecorateB : public Decorate{
public:
    void operation(){
        Decorate::operation();
        cout << "DecorateB Operation" << endl;
    }
    ~DecorateB(){
        cout << "DecorateB 析构" << endl;
    }
    DecorateB(){
        cout << "DecorateB 构造" << endl;
    }
};



int main(){
    ConcreteComponent* person = new ConcreteComponent("student1");
    DecorateA* chinese = new DecorateA();
    DecorateB* english = new DecorateB();

    chinese->setComponent(person);
    english->setComponent(chinese);
    english->operation();


    delete english;
    delete chinese;
    delete person;
}