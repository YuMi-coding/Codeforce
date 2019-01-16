#include <cstdio>
#include <cstring>

//#define INPUT_REDIRECTION
#define MAXN 1010
#define MIN(a,b) (((a)>(b))?(b):(a))

int track_five[MAXN][MAXN];
int track_two[MAXN][MAXN];
int dp_table[MAXN][MAXN];
int dp_five[MAXN][MAXN];
int dp_two[MAXN][MAXN];
int dp_direction[MAXN][MAXN];
int numbers[MAXN][MAXN];
int N;
char route[2*MAXN];
int route_pos;

void initialize()
{
    memset(track_five, 0,sizeof(track_five[0][0])*MAXN*MAXN);
    memset(track_two,  0,sizeof(track_two[0][0]) *MAXN*MAXN);
    memset(dp_table,   0,sizeof(dp_table[0][0])  *MAXN*MAXN);
    memset(numbers,    0,sizeof(numbers[0][0])   *MAXN*MAXN);
    memset(dp_five,    0,sizeof(dp_five[0][0])   *MAXN*MAXN);
    memset(dp_two,     0,sizeof(dp_two[0][0])    *MAXN*MAXN);
    
    memset(dp_direction,0,sizeof(dp_direction[0][0])*MAXN*MAXN);
    memset(route,0,sizeof(route[0])*MAXN);

    N = 0;// size of the square
    route_pos = 0;// the length of this route
    fscanf(stdin,"%d", &N);
}

void input()
{
    for(int i = 1;i<=N;i++)
    {
        for(int j = 1;j<=N;j++)
        {
            fscanf(stdin,"%d",&numbers[i][j]);
        }
    }
}

void fill_five_and_two()
{
    for(int i = 1;i<=N;i++)
    {
        for(int j = 1;j<=N;j++)
        {
            int zeros = 0;
            int this_num = numbers[i][j];
            while(!(this_num %10))
            {
                zeros ++;
                this_num /= 10;
            }

            int twos = 0;
            int this_two = this_num;
            while(!(this_two %2))
            {
                twos ++;
                this_two /= 2;
            }

            int fives = 0;
            int this_five = this_num;
            while(!(this_five %5))
            {
                fives ++;
                this_five /= 5;
            }

            track_five[i][j] = fives + zeros;
            track_two[i][j]  = twos  + zeros;
        }
    }
}

void fill_dp_table()
{
    for(int i = N;i>0;i--)
    {
        for(int j = N; j>0;j--)
        {
            int from_down  = MIN(dp_five[i+1][j]+track_five[i][j],dp_two[i+1][j]+track_two[i][j]);

            int from_right = MIN(dp_five[i][j+1]+track_five[i][j],dp_two[i][j+1]+track_two[i][j]);
            if(i+1>N)
            {
                // has to go right
                dp_direction[i][j] = 2;
                dp_five[i][j]  = dp_five[i][j+1] + track_five[i][j];
                dp_two[i][j]   = dp_two[i][j+1]  + track_two[i][j] ;
                dp_table[i][j] = from_right;
                continue;
            }
            else if(j+1>N)
            {
                //has to go down
                dp_direction[i][j] = 1;
                dp_five[i][j]  = dp_five[i+1][j] + track_five[i][j];
                dp_two[i][j]   = dp_two[i+1][j]  + track_two[i][j] ;
                dp_table[i][j] = from_down;
                continue;
            }


            if(from_down<from_right)
            {
                //select down route
                dp_direction[i][j] = 1;
                dp_five[i][j]  = dp_five[i+1][j] + track_five[i][j];
                dp_two[i][j]   = dp_two[i+1][j]  + track_two[i][j] ;
                dp_table[i][j] = from_down;
            }
            else
            {
                //select right route
                dp_direction[i][j] = 2;
                dp_five[i][j]  = dp_five[i][j+1] + track_five[i][j];
                dp_two[i][j]   = dp_two[i][j+1]  + track_two[i][j] ;
                dp_table[i][j] = from_right;
            }
        }
    }
}

void backtrack(int x,int y)
{
    if(x>=N && y>=N)
        return;
    if(dp_direction[x][y] == 1)// going down
    {
        route[route_pos] = 'D';
        route_pos ++;
        backtrack(x+1,y);
    }
    else if(dp_direction[x][y] == 2)
    {
        route[route_pos] = 'R';
        route_pos ++;
        backtrack(x,y+1);
    }
    return;
}

int main()
{
#ifdef INPUT_REDIRECTION
	freopen("in.in","r",stdin);
#endif

    initialize();
    input();
    fill_five_and_two();
    fill_dp_table();
    backtrack(1,1);
    
    fprintf(stdout,"%d\n",dp_table[1][1]);
    fprintf(stdout,"%s\n",route);

    return 0;
}