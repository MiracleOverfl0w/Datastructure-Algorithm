#include<iostream>
using namespace std;
class Animal {
private:
    int age,exp,day;
    float health,max_health;
    float hungly;
    string status;

    void sethungly(float n) {
        (hungly+n > 100.0)? hungly = 100.0 : hungly+=n;
    }
    void setage() {
        ++age;
    }
    void sethealth(float n) {
        (health+n > max_health) ? hungly = max_health : health+=n;
    }
    void updateStatus() {
        ++exp;
        if ( exp >= (10*age )) max_health+=10.0;
        exp = 0;
        if (day%20 == 0) ++age;
        if (hungly<-10)
        {
            status = "dead";
            age = -1;
            health = 0;
            hungly = -1;
        }
    }
    void incressday() {
        ++day;
    }
public:
    Animal() {
        age = 1;
        health = 50.0;
        hungly = 50.0;
        max_health=50.0;
        exp=0;
        day=0;
        status = "alive";
    }
    void getall() {
        cout << "age: " << age << endl;
        cout << "health: " << health / max_health * 100 << "%" << endl;
        cout << "hungly: " << hungly << endl;
    }
    int getage() {
        return age;
    }
    float gethungly() {
        return hungly;
    }
    float gethealth() {
        return health;
    }


    void perform(string act)
    {
        if(act== "eat") sethungly(20.0);
        else if(act== "walk") sethungly(-2.0);
        else if(act == "rest") sethealth(5.0) ;
        updateStatus();
    }
    void sleep() {
        sethealth(70.0);
        sethungly(-20.0);
        incressday();
        updateStatus();
    }
};

int main() {

    Animal cat;

    cat.getall();
    return 0;
}
