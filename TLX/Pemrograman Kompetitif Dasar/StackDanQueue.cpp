#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
deque<ll> q;
ll n,x;
str command;
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>command;
        if(command=="pop_front"){q.pop_front();}
        else if(command=="pop_back"){q.pop_back();}
        else{cin>>x;
            if(command=="push_front"){q.push_front(x);}
            else if(command=="push_back"){q.push_back(x);}
        }
    }
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop_front();
    }
}
