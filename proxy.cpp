#include<bits/stdc++.h>
using namespace std;

class action{
  public:
    string s;
    action(){
        s="user";
    }
    action(string s){
        this->s=s;
    }
    virtual ~action() {}
    virtual void access()=0;
    virtual void performActivity()=0;
};
class performAction: public action{
  public:
    string pas;
    performAction(): action(){}
    performAction(string s): action(s){
        pas=s;
    }
    void access() override{
        pas = pas!=""? pas:"user";
        cout<<pas<<": ";
        if(pas=="admin"){
            cout<<"User has access\n";
            return;
        }
        cout<<"Access denied\n";
    }
    void performActivity() override{
        pas = pas!=""? pas:"user";
        cout<<pas<<": ";
        if(pas=="admin"){
            cout<<"Action performed\n";
            return;
        }
        cout<<"Action can't perform\n";
    }
};
class proxy: public action{
  public:
    performAction pa;
    proxy(): action(){}
    proxy(string s): action(s), pa(s){}
    void access() override {
        pa.access();
    }
    void performActivity() override {
        pa.performActivity();
    }
};

int main()
{
    action* ps1 = new proxy();
    ps1->access();
    ps1->performActivity();
    delete ps1;
    action* ps2 = new proxy("admin");
    ps2->access();
    ps2->performActivity();
    delete ps2;
}