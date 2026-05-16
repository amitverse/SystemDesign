#include <bits/stdc++.h>
using namespace std;


class player{
  public:
    string name,sym;
    player(string s, string sy){
        this->name=s;
        this->sym=sy;
    }
};

class board{
  public:
    int n;
    vector<vector<int>> b;
    board(int n){
        this->n=n;
        b.resize(n, vector<int> (n, -1));
    }
    bool addMove(int row, int col, int p){
        if(row<0 || row>=n || col<0 || col>=n){
            cout<<"Invalid move"<<endl;
            return 0;
        }
        if(b[row][col]!=-1){
            cout<<"Cell already occupied"<<endl;
            return 0;
        }
        b[row][col]=p;
        return 1;
    }
    bool checkWinner(int row, int col, int p){

        bool win=true;

        for(int j=0;j<n;j++){
            if(b[row][j]!=p){
                win=false;
                break;
            }
        }
        if(win) return true;


        win=true;
        for(int i=0;i<n;i++){
            if(b[i][col]!=p){
                win=false;
                break;
            }
        }
        if(win) return true;


        if(row==col){
            win=true;
            for(int i=0;i<n;i++){
                if(b[i][i]!=p){
                    win=false;
                    break;
                }
            }
            if(win) return true;
        }


        if(row+col==n-1){
            win=true;
            for(int i=0;i<n;i++){
                if(b[i][n-1-i]!=p){
                    win=false;
                    break;
                }
            }
            if(win) return true;
        }

        return false;
    }
    void play(player p, player q){
        int k=0,c=n*n,row,col,w=0;
        while(c>0){
            if(k%2==0){
                cout<<p.name<<" : ";
                cin>>row;
                if(row==-10){
                    cout<<"Player exit the game"<<endl;
                    return;
                }
                cin>>col;
                if(col==-10){
                    cout<<"Player exit the game"<<endl;
                    return;
                }
                if(!addMove(row,col,1)){
                    continue;
                }
                w=checkWinner(row,col,1);
                if(w){
                    cout<<"Winner- "<<p.name<<endl;
                    return;
                }
            }
            else{
                cout<<q.name<<" : ";
                cin>>row;
                if(row==-10){
                    cout<<"Player exit the game"<<endl;
                    return;
                }
                cin>>col;
                if(col==-10){
                    cout<<"Player exit the game"<<endl;
                    return;
                }
                if(!addMove(row,col,2)){
                    continue;
                }
                w=checkWinner(row,col,2);
                if(w){
                    cout<<"Winner- "<<q.name<<endl;
                    return;
                }
            }
            c--,k++;
        }
        cout<<"Game Over. No winner"<<endl;
    }
};

int main(){
    int n;
    cout<<"Enter Board size:- ";
    cin>>n;
    board b(n);
    string s,sy;
    cout<<"Enter player-1 name and symbol:- ";
    cin>>s>>sy;
    player p1(s,sy);
    cout<<"Enter player-2 name and symbol:- ";
    cin>>s>>sy;
    while(s==p1.name || sy==p1.sym){
        cout<<"Name and Symbol for each player must be unique. Please re-enter the details:- ";
        cin>>s>>sy;
    }
    player p2(s,sy);
    b.play(p1,p2);
}