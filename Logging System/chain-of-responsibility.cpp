#include <bits/stdc++.h>
using namespace std;

enum priority{
    INFO,
    WARN,
    DEBUG,
    ERROR
};

class req{
  public:
    priority p;
    req(){
        p=DEBUG;
    }
    req(priority p){
        p=p;
    }
    void setPriority(priority p){
        this->p=p;
    }
    priority getPriority(){
        return p;
    }
};

class logger {
  public:
    logger* nextlog;
    logger(){
        nextlog=nullptr;
    }
    virtual void handleReq(req r)=0;
    virtual void passReq(logger* h)=0;
};

class info: public logger {
  public:
    void handleReq(req r) override {
        if(r.getPriority()==INFO){
            cout<<"Reqest handled by INFO handler\n";
        }
        else if(nextlog!=nullptr){
            nextlog->handleReq(r);
        }
        else{
            cout<<"Request can't be processed with available log level\n";
        }
    }
    void passReq(logger* h) override {
        this->nextlog = h;
    }
};

class warn: public logger {
  public:
    void handleReq(req r) override {
        if(r.getPriority()==WARN){
            cout<<"Reqest handled by WARN handler\n";
        }
        else if(nextlog!=nullptr){
            nextlog->handleReq(r);
        }
        else{
            cout<<"Request can't be processed with available log level\n";
        }
    }
    void passReq(logger* h) override {
        this->nextlog = h;
    }
};

class debug: public logger {
  public:
    void handleReq(req r) override {
        if(r.getPriority()==DEBUG){
            cout<<"Reqest handled by DEBUG handler\n";
        }
        else if(nextlog!=nullptr){
            nextlog->handleReq(r);
        }
        else{
            cout<<"Request can't be processed with available log level\n";
        }
    }
    void passReq(logger* h) override {
        this->nextlog = h;
    }
};

class error: public logger {
  public:
    void handleReq(req r) override {
        if(r.getPriority()==ERROR){
            cout<<"Reqest handled by ERROR handler\n";
        }
        else if(nextlog!=nullptr){
            nextlog->handleReq(r);
        }
        else{
            cout<<"Request can't be processed with available log level\n";
        }
    }
    void passReq(logger* h) override {
        this->nextlog = h;
    }
};

int main() {
    logger* i=new info();
    logger* d=new debug();
    logger* w=new warn();
    logger* e=new error();
    req r;
    d->passReq(i);
    i->passReq(w);
    w->passReq(e);
    d->handleReq(r);
    r.setPriority(INFO);
    d->handleReq(r);
    r.setPriority(WARN);
    d->handleReq(r);
    r.setPriority(ERROR);
    d->handleReq(r);
}










