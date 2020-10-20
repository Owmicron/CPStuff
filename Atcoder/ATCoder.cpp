#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool ACGT(char c){
    if (c=='A'||c=='C'||c=='G'||c=='T') return true;
    else return false;
}
int mx,f;
str s;
int main(){
    cin>>s;
    f=0;
    for(int i=0;i<s.size();i++){
        if(ACGT(s[i])){f++;mx=max(mx,f);}
        else{f=0;}
    }
    cout<<mx<<endl;
}
