/*
    Factory Method - Defines an interface for creating objects but
    allows subclasses to decide which class to instantiate
*/

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
            cout<<"Prepare premium burger ...";
        }
};

class BasicWheatBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Preparing Wheat basic burger ...";
        }
};

class StandardWheatBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Preparing Wheat standard burger ...";
        }
};

class PremiumWheatBurger : public Burger {
    public:
        void prepare() override {
            cout<<"Preparing Wheat premium burger ...";
        }
};


class BurgerFactory {
    public:
        virtual Burger* createBurger(string &type) = 0;
        ~BurgerFactory() {}
};

class NormalBurgerFactory : public BurgerFactory {
    public:
        Burger* createBurger(string &type) override {
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
                cout<<"Invalid burger ...";
                return nullptr;
            }
        }
};

class WheatBurgerFactory : public BurgerFactory {
    public:
        Burger* createBurger(string &type) override {
            if(type == "BASIC") {
                return new BasicWheatBurger();
            }
            else if(type == "STANDARD") {
                return new StandardWheatBurger();
            }
            else if(type == "PREMIUM") {
                return new PremiumWheatBurger();
            }
            else {
                cout<<"Invalid burger ...";
                return nullptr;
            }
        }
};


int main() {
    
    string type = "STANDARD";
    
    BurgerFactory* burgerFactory = new NormalBurgerFactory();
    
    Burger* burger = burgerFactory->createBurger(type);
    
    burger->prepare();
    
    return 0;
}
