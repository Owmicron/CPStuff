#include <bits/stdc++.h>
using namespace std;

string s="";
int binary_conversion(int n)
{
    cout<<n<<" ";
    if(n == 1){s+="1";return 0;}
    else if(n%2 != 0){s+="1"; cout<<"a"<<endl;binary_conversion(n/2);}
    else if(n%2 == 0){s+="0"; cout<<"b"<<endl;binary_conversion(n/2);}
}

int main()
{
    int n;
    cin >> n;
    binary_conversion(n);
    cout << s << endl;
}
