#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str wild,w,s,t;ll n;
str create(str z){
    str temp="";
    for(ll i=0;i<=z.size();i++){
        if(z[i]=='*'){break;}
        else{temp+=z[i];}
    }
    return temp;

}
str flip(str z){
    str temp="";
    for(ll i=z.size()-1;i>=0;i--){
        temp+=z[i];
    }
    return temp;
}
int main(){
    cin>>wild;
    cin>>n;
    for(ll i=1;i<=n;i++){
        w=wild;
        cin>>s;
        if(w.find("*") == w.size()-1){
            t = create(w);
            if(s.find(t)==0){cout<<s<<endl;}
        }
        else if(w.find("*") == 0){
            w=flip(w);s=flip(s);
            t = create(w);
            if(s.find(t)==0){s=flip(s);cout<<s<<endl;}
        }
        else{
            t = create(w);
            if(s.find(t)==0){
                w=flip(w);s=flip(s);
                t = create(w);
                if(s.find(t)==0){
                    s=flip(s);
                    if(w.size()-1<=s.size()){cout<<s<<endl;}
                }

            }
        }
    }
}
