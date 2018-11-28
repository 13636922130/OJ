#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
bool isPrime[16005];
void run()
{
    for(int i=0;i<n;i++)
        isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;

    for(int i=2;i<n;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<n;j+=i)
                isPrime[j] = false;
        }
    }
    isPrime[2] = false;
}

int main()
{
    n = 16001;
    run();
    int num, index = 1;
    while(scanf("%d", &num))
    {
        if(num <= 0) break;
        printf("%d: ", index++);
        if(isPrime[num])
            printf("yes\n");
        else
            printf("no\n");
    }
}

