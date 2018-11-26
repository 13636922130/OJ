#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int x[105], y[105];
int n;

int main()
{
    while(scanf("%d", &n))
    {
        if(n == 0) break;
        n *= 2;
        for(int i=0;i<n;i++)
            scanf("%d%d", &x[i],&y[i]);

        int findFlag = 0;
        for(int i=-500;i<=500;i++)
        {
            for(int j=-500;j<=500;j++)
            {
                int cutCherry = 0;
                int big=0, small=0;
                for(int k=0;k<n;k++)
                {
                    if(i*x[k]+j*y[k] > 0)
                        big++;
                    else if(i*x[k]+j*y[k] < 0)
                        small++;
                    else
                    {
                        cutCherry = 1;
                        break;
                    }
                }
                if(cutCherry==1) continue;
                if(big == small)
                {
                    printf("%d %d\n", i, j);
                    findFlag = 1;
                    break;
                }
            }
            if(findFlag)
                break;
        }

    }
}
