#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k;
str s;
stack <char> st,ans;
bool gj;
int main(){
    cin>>n;
    cin>>s;
    st.push(s[0]);
    for(int i=1;i<s.size();i++){
        int sz = st.size();
        if(sz % 2 == 0){st.push(s[i]);}
        else{
            char fr = st.top();
            if(fr==s[i]){k++;}
            else {st.push(s[i]);}
        }
    }
    if(st.size()%2==1){st.pop();k++;}
    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }
    cout<<k<<endl;
    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }
}
