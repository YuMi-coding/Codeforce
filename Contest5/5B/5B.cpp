#include<cstdio>
#include<iostream>
#include<cstring>

#define MAXN (1010)

int main()
{
    char data[MAXN][MAXN];
    int lineLength[MAXN];
    int maxLength = 0;
    int countLines = 0;

    // #ifndef USE_ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    memset(data,0,size_t(MAXN*MAXN));
    memset(lineLength,0,sizeof(lineLength));

// INPUT
    while(std::cin.getline(data[countLines],MAXN))
    {
        int thisLength = strlen(data[countLines]);
        if(thisLength > maxLength)
            maxLength = thisLength;
        
        lineLength[countLines] = thisLength;

        countLines ++;
    }
    // printf("MAXN%d\n",maxLength);
// OUTPUT
    for(int i = 0; i<(maxLength+2);i++)
        putchar('*');
    putchar('\n');

    int unevenLines = 0;
    for(int i = 0; i<countLines;i++)
    {
        putchar('*');
        int leftSpace, rightSpace;
        int totalSpace = maxLength - lineLength[i];

        if(totalSpace % 2)
        {
            if(unevenLines % 2)
            {
                leftSpace = totalSpace >> 1;
                rightSpace = leftSpace;
                leftSpace ++;
            }
            else
            {
                leftSpace = totalSpace >> 1;
                rightSpace = leftSpace + 1;
            }
            unevenLines ++;
        }
        else
        {
            leftSpace = totalSpace >> 1;
            rightSpace = leftSpace;
        }
        for(int j = 0; j< leftSpace; j++)
            putchar(' ');
        
        printf("%s",data[i]);
        for(int j = 0; j< rightSpace; j++)
            putchar(' ');
        putchar('*');
        // printf("%d", lineLength[i]);
        putchar('\n');
    }


    for(int i = 0; i<(maxLength+2);i++)
        putchar('*');
    putchar('\n');

    return 0;
}


