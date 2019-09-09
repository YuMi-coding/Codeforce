#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<iostream>
#include<string>

#define MAXN (120)
int main()
{
    char input[MAXN];
    int countTraffic = 0;
    int countPeople = 0;
    while(std::cin.getline(input,120))
    {
        if(input[0] == '+')
        {
            countPeople ++;
        }
        else if(input[0] == '-')
        {
            countPeople --;
        }
        else
        {
            int lenCommand = strlen(input);
            int lenMessage = 0;
            for (int i = 0; i<lenCommand; i++)
                if(input[i] == ':')
                {
                    lenMessage = strlen(input+i)-1;
                }
            countTraffic += countPeople * lenMessage;
        }
    }
    printf("%d\n", countTraffic);

    return 0;
}