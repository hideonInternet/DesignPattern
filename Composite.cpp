/*
客户端可以一致地使用一个组合结构或其中单个对象，不必关心处理的是单个对象还是整个组合结构，简化了客户端代码。
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Component{
public:
    virtual void print(int depth) = 0;
    virtual void add(Component* c) = 0;
};

class Folder : public Component{
public:
    void add(Component* c){
        entry.push_front(c);
    }
    void print(int depth){
        string prefix = ">";
        prefix.append(depth, '-');
        cout << prefix << "这是一个文件夹：" << endl;
        for(list<Component*>::iterator it = entry.begin(); it!=entry.end(); ++it){
            (*it)->print(depth+2);
        }
    }
private:
    list<Component*> entry;
};

class File : public Component{
public:
    void print(int depth){
        string prefix = ">";
        prefix.append(depth, '-');
        cout << prefix << "这只是一个文件" << endl;
    }
    void add(Component* c){
        cout << "错误使用！" << endl;
    }
};


int main(){
    Component* root = new  Folder();
    Component* file = new File();
    Component* folder1 = new Folder();
    Component* file11 = new File();
    Component* file12 = new File();

    Component* folder2 = new Folder();
    Component* file21 = new File();
    Component* file22 = new File();

    Component* folder22 = new Folder();
    Component* file212 = new File();
    Component* file222 = new File();

    folder1->add(file11);
    folder1->add(file12);
    root->add(folder1);
    folder2->add(file21);
    folder2->add(file22);
    root->add(folder2);

    folder2->add(folder22);
    folder22->add(file212);
    folder22->add(file222);

    root->add(file);

    root->print(1);
}