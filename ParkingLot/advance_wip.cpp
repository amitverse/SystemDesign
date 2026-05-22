#include <bits/stdc++.h>
using namespace std;

class vehicle;
class parkingSpot{
  public:
    int type;
    int price;
    bool isempty;
    vehicle v;
    virtual int getprice()=0;
    virtual string gettype()=0;
};
class twops: public parkingSpot{
  public:
    twops(){
        this->type=2;
        this->price=10;
    }
    twops(int n){
        this->price=n;
    }
    int getprice(){
        return this->price;
    }
    string gettype(){
        return this->type;
    }
};
class fourps: public parkingSpot{
  public:
    fourps(){
        this->type=4;
        this->price=20;
    }
    fourps(int n){
        this->price=n;
    }
    int getprice(){
        return this->price;
    }
    string gettype(){
        return this->type;
    }
};

class vehicle{
  public:
    int type;
    int number;
    vehicle(int t, int n){
        this->type=t;
        this->number=n;
    }
};
class twov: public vehicle{
  public:
    twov(int n):type(2), number(n) {}
};
class fourv: public vehicle{
  public:
    twov(int n):type(4), number(n) {}
};

class token{
  public:
    int number;
    vehicle v;
    int type;
};

class entry{
  public:
    pamanager* psm;
    token* generatetoken(vehicle* v){
        token* t=new token();
        t->number=v->number;
        t->type=v->type;
        t->vehicle=v;
        return t;
    }
    
};
