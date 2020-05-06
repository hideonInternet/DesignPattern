#include <iostream>
#include <string>
using namespace std;

class Cloneable{
public:
    virtual ~Cloneable(){}
    virtual Cloneable* clone()=0;
    virtual void show();
};

class Resume : public Cloneable{
public:
    Resume(string name){
        this->name = name;
    }

    void setExperience(string sex, string age){
        this->sex = sex;
        this->age = age;
    }

    Cloneable* clone(){
        Resume* obj = new Resume(this->name);
        obj->setExperience(sex, age);
        return obj;
    }

    void show(){
        cout << "My name is " << name << endl;
        cout << "Age: " << age << " Sex: " << sex << endl;
    }
private:
    string name;
    string sex;
    string age;
};

int main(){
    Resume p1("孙世辰");
    p1.setExperience("男","24");

    /*
    向下类型转换十分危险，可能出现地址越界的问题
    Resume* p2 = static_cast<Resume*>(p1.clone());
    Resume* p3 = static_cast<Resume*>(p1.clone());
    */

    Cloneable* p2 = p1.clone();
    Cloneable* p3 = p1.clone();
    
    p1.show();
    cout << "============" << endl;
    p2->show();
    cout << "============" << endl;
    p3->show();

}