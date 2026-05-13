// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class shape{
    public:
        virtual void size()=0;
        virtual ~shape() {}
};

class circle: public shape{
    public:
        void size() override{
            cout<<"This is circle class\n";
        }
};
class square: public shape{
    public:
        void size() override{
            cout<<"This is square class\n";
        }
};
class rectangle: public shape{
    public:
        void size() override{
            cout<<"This is rectangle class\n";
        }
};
class triangle: public shape{
    public:
        void size() override{
            cout<<"This is triangle class\n";
        }
};

class shapeFactory{
  public:
    shape* getShape(string s){
        if(s=="circle"){
            return new circle();
        }
        else if(s=="rectangle"){
            return new rectangle();
        }
        else if(s=="triangle"){
            return new triangle();
        }
        return new square();
    }
};

int main() {
    shapeFactory* sf = new shapeFactory();
    shape* s1 = sf->getShape("circle");
    s1->size();
    delete s1;
    s1=sf->getShape("rectangle");
    s1->size();
}