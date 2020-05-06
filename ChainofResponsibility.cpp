/**
 * 职责链模式跟状态模式很像，但是状态模式的状态转换方向是写死在逻辑当中的。
*/
#include <iostream>
#include <string>
using namespace std;

class Request
{
private:
    string name;
    string content;
    int numb;
public:
    Request(string name, string content, int numb):name(name), content(content), numb(numb){}
    int getNumb(){
        return numb;
    }

    string getContent(){
        return content;
    }

    string getName(){
        return name;
    }
};

class Handler
{
protected:
    Handler* successor;
public:
    void setSuccessor(Handler* h){
        this->successor = h ;
    }
    virtual void processRequeset(Request* req){}
};

class Manager: public Handler
{
public:
    void processRequeset(Request* req){
        if(req->getNumb() < 10){
            cout << "经理同意请求：" << endl;
            cout << "请求名：" << (req->getName()) << endl;
            cout << "请求内容：" << (req->getContent()) << endl;
        }else{
            successor->processRequeset(req);
        }
    }
};

class Majordomo: public Handler
{
public:
    void processRequeset(Request* req){
        if(req->getNumb() < 20){
            cout << "总监同意请求：" << endl;
            cout << "请求名：" << (req->getName()) << endl;
            cout << "请求内容：" << (req->getContent()) << endl;
        }else{
            successor->processRequeset(req);
        }
    }
};

class GeneralManager: public Handler
{
public:
    void processRequeset(Request* req){
        cout << "总经理同意请求：" << endl;
        cout << "请求名：" << (req->getName()) << endl;
        cout << "请求内容：" << (req->getContent()) << endl;
    }
};




int main(){
    Handler* a = new Manager();
    Handler* b = new Majordomo();
    Handler* c = new GeneralManager();
    Request* r = new Request("秦子夜", "学习九绝", 14);

    a->setSuccessor(b);
    b->setSuccessor(c);


    a->processRequeset(r);


}