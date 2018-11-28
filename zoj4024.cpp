#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[100005];
int n, t;
int l;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &l);
        int num, lastNum;
        int flag = 0;
        int i;
        int err = 0;
        for(i=0;i<l;i++)
        {
            scanf("%d", &num);
            if(err) continue;
            if(i == 0)
                lastNum = num;
            else if(i == 1)
            {
                if(num>lastNum)
                {
                    flag = 1;
                    lastNum = num;
                }
                else
                    err = 1;
            }
            else
            {
                if(num>lastNum)
                {
                    if(flag == 0)
                        err = 1;
                    lastNum = num;
                }
                else if(num<lastNum)
                {
                    if(flag == 1)
                        flag = 0;
                    lastNum = num;
                }
                else err = 1;
            }
        }

        if(!err)
        {
            if(flag)
                printf("No\n");
            else
                printf("Yes\n");
        }
        else printf("No\n");
    }
}
