#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int rowFlag[10], colFlag[10];
typedef pair<int, int> P;
P pos[100];
P p;
int n, k, len, ans;
char chess[100][100];

void solve(int start, int depth)
{
    if(depth == k)
    {
        ans++;
        return;
    }

    int x = pos[start].first;
    int y = pos[start].second;

    rowFlag[x] = 1;
    colFlag[y] = 1;

    for(int i=start+1; i<len; i++)
    {

        if(rowFlag[pos[i].first] != 0 || colFlag[pos[i].second] != 0)
            continue;
        solve(i, depth+1);
    }

    rowFlag[x] = 0;
    colFlag[y] = 0;
}

int main()
{
    while(cin>>n>>k)
    {
        getchar();

        memset(rowFlag, 0, 10);
        len = 0;
        ans = 0;

        if(n==-1 && k==-1) break;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%c", &chess[i][j]);
                if(chess[i][j] == '#')
                {
                    p.first=i;
                    p.second=j;
                    pos[len++] = p;
                }
            }
            getchar();
        }

        for(int i=0; i<len; i++)
            solve(i, 1);
        cout<<ans<<endl;

    }
}
