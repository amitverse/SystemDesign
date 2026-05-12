#include <bits/stdc++.h>
using namespace std;

class pizza{
    public:
        virtual int cost()=0;
};

class magerita: public pizza{
    public:
        int cost() override{
            return 200;
        }
};

class pasto: public pizza{
    public:
        int cost() override{
            return 150;
        }
};

class topple: public pizza{
    public:
        pizza* pz;
        topple(pizza* p){
            pz=p;
        }
};

class cheese: public topple{
    public:
        cheese(pizza* p): topple(p) {}
        int cost() override {
            return pz->cost()+10;
        }
};

class olive: public topple{
    public:
        olive(pizza* p): topple(p) {}
        int cost() override {
            return pz->cost()+20;
        }
};

int main() {
    pizza* mg=new magerita();
    cout<<mg->cost()<<endl;
    pizza* mgc=new cheese(mg);
    cout<<mgc->cost()<<endl;
    pizza* mgco=new olive(mgc);
    cout<<mgco->cost()<<endl;
}