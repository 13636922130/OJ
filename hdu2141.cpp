#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[505], b[505], c[505];
int value[505*505];
int l, m, n, s, index;
int cnt=0;

bool c_binary_search(int v)
{
    int l=0, r=index-1;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(value[m]<v)
            l = m + 1;
        else if(value[m]>v)
            r = m - 1;
        else
            return true;
    }
    return false;
}

int main()
{
    while(scanf("%d%d%d", &l,&m,&n)!=EOF)
    {
        cnt++;
        for(int i=0;i<l;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);

        index = 0;
        for(int i=0;i<l;i++)
            for(int j=0;j<m;j++)
                value[index++] = a[i]+b[j];
        sort(value, value+index);

        scanf("%d", &s);
        printf("Case %d:\n", cnt);
        while(s--)
        {
            int sum;
            scanf("%d", &sum);
            bool findFlag = false;
            for(int i=0;i<n;i++)
            {
                if(c_binary_search(sum-c[i])) //用二分查找数组长度更长的value
                {                                 //时间复杂度更低
                    findFlag = true;
                    break;
                }
            }
            if(!findFlag)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
}
