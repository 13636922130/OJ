
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

string s;
int n;

int main()
{
    cin>>n;
    while(n--)
    {
        cin>>s;
        sort(s.begin(), s.end());
        cout<<s<<endl;
        while(next_permutation(s.begin(), s.end()))
              cout<<s<<endl;
        cout<<endl;
    }
}
