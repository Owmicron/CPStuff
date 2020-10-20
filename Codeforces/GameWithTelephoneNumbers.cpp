#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
str s;
bool w[200000];
int a,b,t;
vector<int>p,v;
vector<int> eight,neight;
int iv,ip;
bool win;
bool vasya;
int main(){
    cin>>n;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='8'){p.push_back(i);}
        else{v.push_back(i);}
    }
    for(int i=0;i<v.size();i++)
        eight.push_back(v[i]);
    for(int i=0;i<p.size();i++)
        eight.push_back(p[i]);

    for(int i=0;i<p.size();i++)
        neight.push_back(p[i]);
    for(int i=0;i<v.size();i++)
        neight.push_back(v[i]);

    iv=0;
    ip=0;

    for(int i=n;i>11;i--){
        if(i%2==1){
            w[neight[ip]]=true;
            ip++;
        }
        else{
            w[eight[iv]]=true;
            iv++;
        }
    }
    for(int i=0;i<s.size();i++){
        if(!w[i]){
            if(s[i]=='8')win=true;
            else{win=false;}
            break;
        }
    }

    if(win)cout<<"YES\n";
    else cout<<"NO\n";
}

