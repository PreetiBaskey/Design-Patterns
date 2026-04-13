#include<iostream>

using namespace std;

class Burger {
    public:
        virtual void prepare() = 0;
        ~Burger() {}
};

class BasicBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Preparing basic burger ...";
        }
};

class StandardBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Preparing standard burger ...";
        }
};

class PremiumBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Preparing premium burder ...";
        }
};

class BurgerFactory {
    public:
        Burger* createBurger(string &type) {
            if(type == "BASIC") {
                return new BasicBurger();
            }
            else if(type == "STANDARD") {
                return new StandardBurger();
            }
            else if(type == "PREMIUM") {
                return new PremiumBurger();
            }
            else {
                cout<<"Invalid burger type ...";
                return nullptr;
            }
        }
};


int main() {
    
    string type = "STANDARD";
    
    BurgerFactory* burgerFactory = new BurgerFactory();
    Burger* burger = burgerFactory->createBurger(type);
    
    burger->prepare();
    
    return 0;
}
