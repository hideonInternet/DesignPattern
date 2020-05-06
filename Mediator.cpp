#include <string>
#include <iostream>
using namespace std;

class Mediator;

class Colleague
{
private:
    Mediator* m;
public:
    void setMediator(Mediator* m){
        this->m = m;
    }
    void send(string msg);
    virtual void getMessage(string msg){}
};

class Mediator{
public:
    virtual void setColleague(Colleague* c1, Colleague* c2){}
    virtual void send(string message, Colleague* colleague){}
};

class ConcreteMediator : public Mediator
{
private:
    Colleague* c1;
    Colleague* c2;
public:
    void setColleague(Colleague* c1, Colleague* c2){
        this->c1 = c1;
        this->c2 = c2;
    }

    void send(string message, Colleague* colleague){
        if(c1!=nullptr && c1 == colleague){
            c2->getMessage(message);
        }else if(c2 != nullptr){
            c1->getMessage(message);
        }else{
            cout << "你要发送给谁？" << endl;
        }
    }
};

void Colleague::send(string msg){
        m->send(msg, this);
    }

class Manager : public Colleague
{
public:
    void getMessage(string msg){
        cout << "经理接受到：" << msg << endl;
    }
};

class Guard : public Colleague
{
public:
    void getMessage(string msg){
        cout << "保安接受到：" << msg << endl;
    }
};

int main(){
    Colleague* c1 = new Manager();
    Colleague* c2 = new Guard();
    Mediator* m = new ConcreteMediator();

    m->setColleague(c1, c2);

    c1->setMediator(m);
    c2->setMediator(m);

    c1->send("吃了吗");
    c2->send("没呢");

}