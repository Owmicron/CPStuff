#include<bits/stdc++.h>
using namespace std;
int cnt(string s){
    int sum=0;
    for(int i=0;i<s.size();i++){
        if (s[i]=='V'){
            if(s[i+1]=='K'){sum++;}
        }
    }

    return sum;

}
int main(){
    string s;
    cin>>s;

    int mx;
    mx=cnt(s);

    string x;
    for(int i=0;i<s.size();i++){
        x=s;
        if (x[i]=='V'){x[i]='K';}
        else{x[i]='V';}

        int t;
        t=cnt(x);
        if(t > mx){mx=t;}
    }
    cout<<mx;

}
