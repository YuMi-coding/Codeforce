#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#define USE_ONLINE_JUDGE
#define MAXN 40

std::map<std::string,int> nameSet;
std::string name;
std::string searchName;
char name_[50];

int main()
{
    #ifndef USE_ONLINE_JUDGE
        freopen("input.txt","rt",stdin);
        freopen("output.txt","wt",stdout);
    #endif

    int n;
    scanf("%d",&n);
    for(int i = 0; i<n;i++)
    {
        bool isOriginal = true;
        scanf("%s",name_);

        int j = nameSet[name_];
        if(nameSet[name_])
        {
            printf("%s%d\n",name_,j);
        }
        else
        {
            printf("OK\n");
        }
        nameSet[name_] ++;
    }
    return 0;
}