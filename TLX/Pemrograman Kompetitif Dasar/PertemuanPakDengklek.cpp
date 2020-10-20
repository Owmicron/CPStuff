#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n;str t;
deque<str>s [11];
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>t;
        s[t.size()].push_back(t);
    }
    for(ll i=1;i<=10;i++){
        if(!s[i].empty()){
            sort(s[i].begin(),s[i].end());
            while(!s[i].empty()){
                cout<<s[i].front()<<endl;s[i].pop_front();
            }
        }
    }
}
