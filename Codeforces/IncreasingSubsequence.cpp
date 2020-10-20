#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
deque<int> q;
int n,last,ans;
str s;
int main(){
    last=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        q.push_back(temp);
    }

    while(!q.empty()){
        if(q.front() < last && q.back()<last){break;}

        int a,b;
        a = q.front();
        b = q.back();

        //cout<<a<<" "<<b<<endl;
        if(a<=b){
            if(a>last){s+="L";last=a;q.pop_front();ans++;}
            else {s+="R";last=b;q.pop_back();ans++;}
        }
        else if(b<=a){
            if(b>last){s+="R";last=b;q.pop_back();ans++;}
            else{s+="L";last=a;q.pop_front();ans++;}
        }
    }
    cout<<ans<<endl;
    cout<<s;
}
