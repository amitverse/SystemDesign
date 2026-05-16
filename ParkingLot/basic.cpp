#include <bits/stdc++.h>
using namespace std;

class parking{
  public:
    int t;
    int n;
    vector<int> v;
    parking(){
        t=0;
        n=20;
        v.resize(n,-1);
    }
    parking(int n){
        this->n=n;
        v.resize(n,-1);
    }
    int getNextToken(){
        return ++t;
    }
    void assignLot(int t){
        for(int i=0; i<n; i++){
            if(v[i]==-1){
                v[i]=t;
                cout<<"Lot No "<<(i+1)<<" is assigned to the vehicle: "<<t<<endl;
                return;
            }
        }
        cout<<"Parking full\n";
    }
    void releaseLot(int t){
        for(int i=0; i<n; i++){
            if(v[i]==t){
                v[i]=-1;
                cout<<"Lot No "<<(i+1)<<" is release from the vehicle: "<<t<<endl;
                return;
            }
        }
        cout<<"Vehicle not found\n";
    }
};

class vehicle {
  public:
    int t;
    parking* p;
    vehicle(parking* p){
        this->p=p;
        this->t=p->getNextToken();
    }
    virtual int getToken()=0;
    virtual void getlot(int s)=0;
    virtual void getexit(int s)=0;
};

class twow: public vehicle {
  public:
    twow(parking* p): vehicle(p) {}
    int getToken(){
        return this->t;
    }
    void getlot(int t){
        p->assignLot(t);
    }
    void getexit(int t){
        p->releaseLot(t);
    }
};

class fourw: public vehicle{
  public:
    fourw(parking* p): vehicle(p) {}
    int getToken(){
        return this->t;
    }
    void getlot(int t){
        p->assignLot(t);
    }
    void getexit(int t){
        p->releaseLot(t);
    }
};

int main(){
    parking p(10);
    vehicle* t1= new twow(&p);
    int token1=t1->getToken();
    cout<<token1<<endl;
    t1->getlot(token1);
    vehicle* t2=new twow(&p);
    int token2=t2->getToken();
    cout<<token2<<endl;
    t2->getlot(token2);
    t1->getexit(token1);
    vehicle* f1=new fourw(&p);
    int token3=f1->getToken();
    cout<<token3<<endl;
    f1->getlot(token3);
}