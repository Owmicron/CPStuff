#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str a,b,c,d;
bool isupper(char c){
    if((c>96)&&(c<123)){return false;}
    else{return true;}
}
char change(char c){
    if(isupper(c)){return char(int(char(c)+32));}
    else{return char(int(char(c)-32));}
}
bool us(str x){
    if(x.find("_")>x.size()){return false;}
    else{return true;}
}
int main(){
    str s;
    cin>>s;
    if(us(s)){
        while(us(s)){
            char t = change(s[s.find("_")+1]);
            str tt;tt="";tt+=t;
            s.replace(s.find("_") ,2, tt);
        }
    }
    else{
        str temp="";temp+=s[0];
        for(ll i=1;i<s.size();i++){
            if(isupper(s[i])){
                temp+="_";
                temp+=change(s[i]);
            }
            else{temp+=s[i];}
        }
        s=temp;
    }
    cout<<s<<endl;
}






