#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
using namespace std;

class Observer{
protected:
    string name;
    string sub;
public:
    virtual void update(){}
};

class Subject{
public:
    virtual void attach(Observer* observer)=0;
    virtual void detach(Observer* observer)=0;
    virtual void notify()=0;
    void setName(string name){
        this->name = name;
    }
    string getName(string name){
        return name;
    }
private:
    string name;
};

class Secretary : public Subject{
public:
    void attach(Observer* obs){
        wait4Notify.push_front(obs);
        m[obs] = wait4Notify.begin();
    }
    void detach(Observer* obs){
        wait4Notify.erase(m[obs]);
        m.erase(obs);
    }
    void notify(){
        list<Observer*>::iterator itr;
        for(itr=wait4Notify.begin(); itr!=wait4Notify.end(); itr++){
            cout << "Secreatry Notify: ";
            (*itr)->update();
        }
    }
private:
    unordered_map<Observer*, list<Observer*>::iterator> m;
    list<Observer*> wait4Notify;
};

class Employee:public Observer{
public:
    Employee(string name, string sub){
        this->name = name;
        this->sub = sub;
    }
    void update(){
        cout << "员工：" << name << " 部门：" << sub << endl;
    }
};

class Guard : public Observer{
public:
    Guard(string name, string power){
        this->name = name;
        this->power = power;
    }
    void update(){
        cout << "保安：" << name << " 武力值：" << power << endl;
    }
private:
    string power;
};


int main(){
    Subject* sec = new Secretary();
    Observer* emp1 = new Employee("孙世辰", "BRL实验室");
    Observer* emp2 = new Employee("孙志明", "冶金学院");
    Observer* emp3 = new Employee("胡渊", "新钢");


    Observer* guard1 = new Guard("李连杰", "10");
    Observer* guard2 = new Guard("成龙", "9");
    Observer* guard3 = new Guard("吴京", "11");

    sec->attach(emp1);
    sec->attach(emp2);
    sec->attach(emp3);
    sec->attach(guard1);
    sec->attach(guard2);
    sec->attach(guard3);

    sec->notify();

    sec->detach(emp3);
    sec->detach(guard2);
    sec->notify();

}