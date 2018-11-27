
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

string s;

int main()
{
    while(cin>>s)
    {
        if(s[0] == '#') break;
        if(next_permutation(s.begin(), s.end()))
            cout<<s<<endl;
        else
            cout<<"No Successor"<<endl;
    }
}
