#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int pre[1005];
int n, m;

int find(int x)
{
    int r = x;
    while(pre[r] != r)
        r = pre[r];

    int i = x, j;
    while(i != r)
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);

    if(fx != fy)
        pre[fx] = fy;
}

void init()
{
    for(int i=1;i<=n;i++)
        pre[i] = i;
}

int main()
{
    while(scanf("%d%d",&n, &m))
    {
        int ans = 0;
        if(n == 0) break;
        init();
        for(int i=0;i<m;i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            join(x, y);
        }

        int head = find(1);
        for(int i=1;i<=n;i++)
        {
            if(find(i) != head)
            {
                ans++;
                join(i, head);
            }
        }
        printf("%d\n", ans);

    }
}
