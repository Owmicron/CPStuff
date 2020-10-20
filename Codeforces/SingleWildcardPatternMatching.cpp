#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str wild,w,s,t;ll n,a,b;
bool iswild;
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
    cin>>a>>b;
    cin>>wild;
    cin>>s;
    str w=wild;
        if(w.find("*") == w.size()-1){
            t = create(w);
            if(s.find(t)==0){iswild=true;}
        }
        else if(w.find("*") == 0){
            w=flip(w);s=flip(s);
            t = create(w);
            if(s.find(t)==0){s=flip(s);iswild=true;}
        }
        else{
            t = create(w);
            if(s.find(t)==0){
                w=flip(w);s=flip(s);
                t = create(w);
                if(s.find(t)==0){
                    s=flip(s);
                    if(w.size()-1<=s.size()){iswild=true;}
                }

            }
        }
    if (wild==s){iswild=true;}
    if(iswild){cout<<"YES";}
    else{cout<<"NO";}

}
