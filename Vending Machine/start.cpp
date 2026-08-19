#include<bits/stdc++.h>
using namespace std;

class item{
  public:
    string name;
    int price,curr_count,max_count;

};
class chips:public item{
  public:
    chips(){
        name="CHIPS";
        price=10,curr_count=10,max_count=10;
    }
};
class kurkure:public item{
  public:
    kurkure(){
        name="KURKURE";
        price=10,curr_count=10,max_count=10;
    }
};
class coke:public item{
  public:
    coke(){
        name="COKE";
        price=20,curr_count=10,max_count=10;
    }
};
class order{
  public:
    unordered_map<string,int> cart;
    order(unordered_map<string,int> c){
        cart=c;
    }
    void processPayment(){
        cart.clear();
        cout<<"Payment Done\n";
    }
};
class display{
  public:
    unordered_map<string,item> store;
    int total_amount=0;
    unordered_map<string,int> cart;
    display() {
        store["CHIPS"] = chips();
        store["KURKURE"] = kurkure();
        store["COKE"] = coke();
    }
    void addToCart(string t){
        item it=store[t];
        if(it.curr_count<=0){
            cout<<t<<" is out of stock.\n";
            return;
        }
        cout<<t<<" added to cart\n";
        cart[t]++;
        total_amount+=it.price;
        int tc=it.curr_count;
        store[t].curr_count=(tc-1);
    }
    void removeFromCart(string t){
        item it=store[t];
        if(it.curr_count>=it.max_count){
            cout<<"Item "<<t<<" not present in cart list\n";
            return;
        }
        cout<<t<<" removed from cart\n";
        cart[t]--;
        if(cart[t]==0){
            cart.erase(t);
        }
        total_amount-=it.price;
        int tc=it.curr_count;
        store[t].curr_count=(tc+1);
    }
    void makePayment(){
        order ord(cart);
        ord.processPayment();
        cart.clear();
        total_amount=0;
    }
};


int main() {
    display vendingMachine;

    vendingMachine.addToCart("CHIPS");
    vendingMachine.addToCart("CHIPS");
    vendingMachine.addToCart("COKE");

    vendingMachine.removeFromCart("CHIPS");

    vendingMachine.makePayment();

    return 0;
}

