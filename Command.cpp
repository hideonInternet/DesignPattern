/**
 * 将命令类抽象出来，使得命令内容，命令执行方法，发出命令者三者隔离开来。
*/
#include <iostream>
#include <string>
using namespace std;

class Operator
{
public:
    Operator(string name="default"):name(name){}
    void makeBeef(){
        cout << name << "开始" << "制作牛肉" << endl;
    }

    void makeChicken(){
        cout << name << "开始" << "制作鸡肉" << endl;
    }
private:
    string name;
};

class Command
{
public:
    void setOperator(Operator* opt){
        this->opt = opt;
    }
    virtual void process()=0;
protected:
    Operator* opt;
};

class MakeChicken : public Command
{
    void process(){
        cout << "发送制作鸡肉命令！" << endl;
        opt->makeChicken();
    }
};

class MakeBeef : public Command
{
    void process(){
        cout << "发送制作牛肉命令！" << endl;
        opt->makeBeef();
    }
};

class Waiter
{
private:
    Command* cmd;
public:
    void setCommand(Command* cmd){
        this->cmd = cmd;
    }

    void Notify(){
        cmd->process();
    }
};

int main(){
    Waiter* w = new Waiter();
    Operator* opt = new Operator("张天明");
    Operator* opt2 = new Operator("李纯风");
    Command* cmdChicken = new MakeChicken();
    Command* cmdBeef = new MakeBeef();

    cmdBeef->setOperator(opt);
    cmdChicken->setOperator(opt2);

    w->setCommand(cmdBeef);
    w->Notify();

    w->setCommand(cmdChicken);
    w->Notify();
}