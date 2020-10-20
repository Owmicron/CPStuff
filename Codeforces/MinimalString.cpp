#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
stack <char> t;
queue <char> u,y;
queue <ll> z;
pair <char,ll> in[100001];
ll find(ll a){
    ll m=a;;
    for(ll i=a; i<=s.size()-1; i++){
        if (s[i] < s[m]){m=i;}
    }
    return m;
}

ll mini=0,p;
int main(){
    cin>>s;
    for(ll i=0;i<s.size();i++){
        in[i].first=s[i];
        in[i].second=i;
    }

    sort(in,in+s.size());

    for(ll i=0;i<s.size();i++){
        y.push(in[i].first);
        z.push(in[i].second);
    }


    mini=z.front();
    while(p<s.size() || !t.empty()){
        //mini=find(p);
        if(!t.empty()){
            if (p >= s.size()){
                while(!t.empty()){
                    u.push(t.top());
                    t.pop();
                }
                break;
            }
            if(t.top() < s[mini]){
                u.push(t.top());
                t.pop();
            }
            else{
                for(ll i=p;i<mini;i++){
                    t.push(s[i]);
                }
                u.push(s[mini]);
                p=mini+1;
                y.pop();z.pop();
                //mini=find(p);
                bool get=false;
                while(!get){
                    if (z.front()>=p){
                        get=true;
                        mini=z.front();
                    }
                    else{y.pop();z.pop();}

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
                    if (z.front()>=p){
                        mini=z.front();
                        get=true;
                    }
                    else{y.pop();z.pop();}

                }
            //mini=find(p);
        }
    }
    while(!u.empty()){
        cout<<u.front();
        u.pop();

    }
}
