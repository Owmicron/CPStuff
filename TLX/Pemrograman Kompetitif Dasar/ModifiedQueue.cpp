#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
deque <ll> q;
str s;
ll n,x,y;
bool r;
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>s;
        if(s=="add"){
            cin>>x>>y;
            for(ll i=1;i<=y;i++){
                if(!r){q.push_back(x);}
                else{q.push_front(x);}
            }
            cout<<q.size()<<endl;
        }
        else if(s=="del"){
            cin>>y;
            for(ll i=1;i<=y;i++){
                if(q.empty()){break;}
                if(!r){
                    if(i==1)cout<<q.front()<<endl;
                    q.pop_front();
                }
                else{
                    if(i==1)cout<<q.back()<<endl;
                    q.pop_back();
                }
            }
        }
        else{
            r=not r;
        }
    }
}
