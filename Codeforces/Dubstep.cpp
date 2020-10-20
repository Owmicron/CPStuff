#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s,sep;
bool found(str x){
    if(x.find("WUB")<1000000){
        return true;
    }
    else{return false;}
}
int main(){
    sep="";
    cin>>s;
    while(found(s)){
        if (s.find("WUB") != 0){sep=" ";}
        s.replace(s.find("WUB"),3,sep);
    }
    cout<<s;

}
