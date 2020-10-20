#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
stack<char> st;
str s;int f;
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(st.empty())st.push(s[i]);
        else{
            if(s[i]!=st.top()){st.pop();f+=2;}
            else{st.push(s[i]);}
        }
    }
    cout<<f<<endl;
}
