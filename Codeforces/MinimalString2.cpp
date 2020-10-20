#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
stack <char> t;
queue <char> u;
pair <char,ll> in[1000000];

ll mini=0,p,x;
int main(){
    cin>>s;
    for(ll i=0;i<s.size();i++){
        in[i].first=s[i];
        in[i].second=i;
    }

    sort(in,in+s.size());

    mini=in[x].second;
    x++;
    while(p<s.size() || !t.empty()){

        if(!t.empty()){
            if (p >= s.size()){
                while(!t.empty()){
                    u.push(t.top());
                    t.pop();
                }
                break;
            }
            if(t.top() <= s[mini]){
                u.push(t.top());
                t.pop();
            }
            else{
                for(ll i=p;i<mini;i++){
                    t.push(s[i]);
                }
                u.push(s[mini]);
                p=mini+1;

                bool get=false;
                while(!get){
                    if (in[x].second>=p){
                        get=true;
                        mini=in[x].second;
                    }
                    else{x++;}

                }

            }

        }
        else{
            for(ll i=p;i<mini;i++){
                t.push(s[i]);
            }
            u.push(s[mini]);
            p=mini+1;
                bool get=false;
                while(!get){
                    if (in[x].second>=p){
                        get=true;
                        mini=in[x].second;
                    }
                    else{x++;}

                }

        }
    }
    while(!u.empty()){
        cout<<u.front();
        u.pop();

    }
}

