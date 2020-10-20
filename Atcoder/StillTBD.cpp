#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str s;
int y,m,d;
int main(){
    cin>>s;
    y = int(s[0]-48)*1000+int(s[1]-48)*100+int(s[2]-48)*10+int(s[3]-48);
    m = int(s[5]-48)*10+int(s[6]-48);
    d = int(s[8]-48)*10+int(s[9]-48);
    if(y>2019){cout<<"TBD\n";}
    if(y==2019 && m > 4){cout<<"TBD\n";}
    else cout<<"Heisei\n";
}
