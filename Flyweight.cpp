#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class WebSite
{
public:
    virtual void Use(){}
};

class ConcreteWebSite : public WebSite
{
private:
    string name;
public:
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
    void Use(){
        cout << "网站分类：" << name << endl;
    }
};

class WebSiteFactory
{
public:
    WebSite* getWebSiteCategory(string key){
        if(!m.count(key)){
            WebSite* w = new ConcreteWebSite();
            m[key] = w;
        }
        return m[key];
    }

    int getWebStieCount(){
        return m.size();
    }
private:
    unordered_map<string, WebSite*> m;
};

int main(){
    WebSiteFactory* f = new WebSiteFactory();

    WebSite* fx = f->getWebSiteCategory("主页1");
    ((ConcreteWebSite*)fx)->setName("李特风");
    fx->Use();

    WebSite* fy = f->getWebSiteCategory("主页2");
    ((ConcreteWebSite*)fy)->setName("王轩火");
    fy->Use();

    WebSite* fz = f->getWebSiteCategory("主页1");
    fz->Use();

    cout << f->getWebStieCount() << endl;
}