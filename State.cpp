#include <iostream>
using namespace std;

class State;

class Work
{
public:
    void setState(State*& s);

    void writePrograme();

    void setHour(int hour){
        this->hour = hour;
    }

    int getHour(){
        return hour;
    }

    void setStatus(bool status){
        this->hasFinished = status;
    }

    bool getStatus(){
        return this->hasFinished;
    }
private:
    State* currentState = nullptr;
    int hour;
    bool hasFinished;
};

class State{
public:
    virtual void writeProgram(Work* w)=0;
};

class Beforenoon;

class Rest : public State{
public:
    void writeProgram(Work* w);
};

class Evening : public State{
public:
    void writeProgram(Work* w){
        if(!w->getStatus()){
            cout << "正在加班" << endl;
        }else{
            State* s = new Rest();
            w->setState(s);
            w->writePrograme();
        }
    }
};

class Afternoon : public State{
public:
    void writeProgram(Work* w){
        if(w->getHour() < 18){
            cout << "这是下午" << endl;
        }else{
            State* s = new Evening();
            w->setState(s);
            w->writePrograme();
        }
    }
};

class Beforenoon : public State{
public:
    void writeProgram(Work* w){
        if(w->getHour() < 12){
            cout << "这是早上" << endl;
        }else{
            State* s = new Afternoon();
            w->setState(s);
            w->writePrograme();
        }
    }
};

inline void Work::setState(State*& s){
        if(currentState){
            delete currentState;
            currentState = nullptr;
        }        
        currentState = s;
    }

inline void Work::writePrograme(){
       currentState->writeProgram(this);
    }

inline void Rest::writeProgram(Work* w){
        if(w->getHour() < 12 && w->getHour() > 8){
            State* s = new Beforenoon();
            w->setState(s);
            w->writePrograme();
        }else{
            cout << "休息中" << endl;
        }
    }    
int main(){
    Work* w = new Work();
    w->setStatus(false);
    w->setHour(9);
    State* s = new Beforenoon();
    w->setState(s);
    w->writePrograme();

    w->setHour(13);
    w->writePrograme();

    w->setHour(18);
    w->writePrograme();

    w->setHour(20);
    w->writePrograme();

    w->setStatus(true);
    w->writePrograme();

    w->setStatus(7);
    w->setStatus(false);
    w->writePrograme();

    w->setHour(9);
    w->writePrograme();
}