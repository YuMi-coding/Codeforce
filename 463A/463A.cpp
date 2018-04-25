#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int n,s;
int candies[105];
int cnt = 0;

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&s);
    for(int i = 0; i<n;i++)
    {
        int dollar,cents;
        scanf("%d%d",&dollar,&cents);
        if(dollar < s)
            candies[cnt++] =  cents;
        if(dollar == s&&cents ==0)
            candies[cnt++] = 0;
    }
    sort(candies,candies+cnt);
    if(cnt == 0)
        {
            printf("-1\n");
            return 0;
        }
    int max_ = 0;
    for(int i = 0; i<cnt;i++)
        if(candies[i]!=0)
            {
                int change = 100-candies[i];
                if(change !=100&&change >max_)
                    max_ = change;
                break;
            }
        printf("%d\n",max_);

    return 0;
}