#include <iostream>
#include <string>
using namespace std;

class Memo{
public:
    Memo(int a, int d, int v):attack(a),defense(d),vitality(v){}
    int getAttack(){
        return attack;
    }
    int getVitality(){
        return vitality;
    }
    int getDefense(){
        return defense;
    }
    void setAttack(int a){
        this->attack = a;
    }
    void setDefense(int d){
        this->defense = d;
    }
    void setVitality(int v){
        this->vitality = v;
    }
private:
    int attack;
    int defense;
    int vitality;
};

class Player{
public:
    Player(string name, int a, int d, int v):name(name),attack(a),defense(d),vitality(v){}
    
    Memo* setMemo(){
        return new Memo(attack, defense, vitality);
    }

    void recover(Memo&  memo){
        this->attack = memo.getAttack();
        this->defense = memo.getDefense();
        this->vitality = memo.getVitality();
    }

    void show(){
        cout << "攻击力：" << attack << endl;
        cout << "防御力：" << defense << endl;
        cout << "生命值：" << vitality << endl;
    }

    int getAttack(){
        return attack;
    }
    int getVitality(){
        return vitality;
    }
    int getDefense(){
        return defense;
    }
    void setAttack(int a){
        this->attack = a;
    }
    void setDefense(int d){
        this->defense = d;
    }
    void setVitality(int v){
        this->vitality = v;
    }
private:
    string name;
    int attack;
    int defense;
    int vitality;
};

class MemoManager{
public:
    void saveMemo(Memo* m){
        if(this->m){
            delete m;
            m = nullptr;
        }
        this->m = m;
    }
    Memo* getMemo(){
        return m;
    }
private:
    Memo* m=nullptr;
};

int main(){
    Player p1 = Player("孙世辰", 100, 100, 100);
    p1.show();

    MemoManager mm = MemoManager();
    mm.saveMemo(p1.setMemo());

    p1.setAttack(200);
    p1.show();

    Memo* m = mm.getMemo();

    p1.recover(*(mm.getMemo()));
    p1.show();

}