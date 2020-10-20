#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s[51],x[51];
char c[51];

string mark(string a){
    int pos=0;
    for(int i=0;i<s[1].size();i++){
        if(a[0] == c[i]){pos=i;break;}
    }
    cout<<pos;
}
int main(){
    //cin>>n;
    cin>>s[1];

    for(int i=0;i<s[1].size();i++){
        x[1][i]=i;
        c[i]=s[1][i];
    }

    cin>>s[2];
    cout<<mark(s[2]);


}
