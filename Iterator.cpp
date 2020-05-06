#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Container;

template <typename T>
class Iterator
{
public:
    virtual T& first()=0;
    virtual T& next()=0;
    virtual bool end()=0;
    virtual T& currentItem()=0;
    virtual void setContainer(Container<T>* c)=0;

};

template <typename T>
class Container
{
public:
    virtual Iterator<T>* createIterator()=0;
};

template <typename T>
class MyList;

template <typename T>
class ConcreteIterator : public Iterator<T>
{
public:
    void setContainer(Container<T>* c){
        this->con = c;
    }

    T& first(){
        return (*(MyList<T>*)con)[0];
    }

    T& next(){
        ret = nullptr;
        if(++idx < ((MyList<T>*)con)->size()){
            ret = &(*(MyList<T>*)con)[idx];
        }
        return *ret;
    }

    T& currentItem(){
        if(ret) return *ret;

        if(idx < ((MyList<T>*)con)->size()){
            ret = &(*((MyList<T>*)con))[idx];
        }
        return *ret;
    }

    bool end(){
        return idx >= ((MyList<T>*)con)->size() ? true : false;
    }

private:
    T* ret = nullptr;
    int idx = 0;
    Container<T>* con;
};

template <typename T>
class MyList : public Container<T>
{
public:
    Iterator<T>* createIterator(){
        Iterator<T>* ret = new ConcreteIterator<T>();
        ret->setContainer(this);
        return ret;
    }

    T& operator[](T t){
        return l[t];
    }

    int size(){
        return l.size();
    }

    void push_back(T t){
        l.push_back(t);
    }
private:
    vector<T> l;
};


int main(){
    MyList<int> ml = MyList<int>();
    ml.push_back(1);
    ml.push_back(2);
    ml.push_back(3);
    ml.push_back(4);
    ml.push_back(5);

    Iterator<int>* it = ml.createIterator();

    int ele = it->first();

    cout << ele << endl;

    int& curEle = it->currentItem();
    cout << curEle << endl;

    curEle = 10;

    int testEle = it->first();
    cout << testEle << endl;

    int nextEle = it->next();
    cout << nextEle << endl;

    ml[2] = 11;
    int test2Ele = it->next();
    cout << test2Ele << endl;
    
    delete it;

    return 0;
}