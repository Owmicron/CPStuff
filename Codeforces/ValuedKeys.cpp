#include<bits/stdc++.h>
using namespace std;
bool valid(string a,string b){
    bool v=true;
    for(int i=0;i<a.size();i++){
        if (b[i]>a[i]){
            v=false;
            break;
        }
    }
    return v;
}


int main(){
    string x,y;

    cin>>x;
    cin>>y;

    if (valid(x,y)){
        cout<<y;
    }
    else{cout<<-1;}

}
