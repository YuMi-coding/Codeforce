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
int dp_direction_two[MAXN][MAXN];
int dp_direction_five[MAXN][MAXN];
int numbers[MAXN][MAXN];
int N;
char route[2*MAXN];
int route_pos;
int zero_flag;
int zero_pos_x,zero_pos_y;

void initialize()
{
    memset(track_five, 0,sizeof(track_five[0][0])*MAXN*MAXN);
    memset(track_two,  0,sizeof(track_two[0][0]) *MAXN*MAXN);
    memset(dp_table,   0,sizeof(dp_table[0][0])  *MAXN*MAXN);
    memset(numbers,    0,sizeof(numbers[0][0])   *MAXN*MAXN);
    memset(dp_five,    0,sizeof(dp_five[0][0])   *MAXN*MAXN);
    memset(dp_two,     0,sizeof(dp_two[0][0])    *MAXN*MAXN);
    
    memset(dp_direction_two, 0,sizeof(dp_direction_two[0][0]) *MAXN*MAXN);
    memset(dp_direction_five,0,sizeof(dp_direction_five[0][0])*MAXN*MAXN);
    
    memset(route,0,sizeof(route[0])*MAXN);

    N = 0;// size of the square
    route_pos = 0;// the length of this route
    zero_flag = 0;
    fscanf(stdin,"%d", &N);
}

void input()
{
    for(int i = 1;i<=N;i++)
    {
        for(int j = 1;j<=N;j++)
        {
            fscanf(stdin,"%d",&numbers[i][j]);
            if(!numbers[i][j])// There is zero
            {
                zero_pos_x = i;
                zero_pos_y = j;
                zero_flag ++;
            }
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
            while(!(this_num %10)&& this_num)
            {
                zeros ++;
                this_num /= 10;
            }

            int twos = 0;
            int this_two = this_num;
            while(!(this_two %2)&& this_two)
            {
                twos ++;
                this_two /= 2;
            }

            int fives = 0;
            int this_five = this_num;
            while(!(this_five %5)&& this_two)
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
            int two_from_down   = dp_two[i+1][j] + track_two[i][j]; 
            //MIN(dp_five[i+1][j]+track_five[i][j],dp_two[i+1][j]+track_two[i][j]);
            int two_from_right  = dp_two[i][j+1] + track_two[i][j];
            int five_from_down  = dp_five[i+1][j] + track_five[i][j];
            int five_from_right = dp_five[i][j+1] + track_five[i][j];
            //MIN(dp_five[i][j+1]+track_five[i][j],dp_two[i][j+1]+track_two[i][j]);
            if(i+1>N)
            {
                // has to go right
                dp_direction_two[i][j]  = 2;
                dp_direction_five[i][j] = 2;
                dp_five[i][j]  = five_from_right;
                dp_two[i][j]   = two_from_right;
                continue;
            }
            else if(j+1>N)
            {
                //has to go down
                dp_direction_two[i][j]  = 1;
                dp_direction_five[i][j] = 1;
                dp_five[i][j]  = five_from_down;
                dp_two[i][j]   = two_from_down;
                continue;
            }


            if(two_from_down<two_from_right)
            {
                //select down route
                dp_direction_two[i][j] = 1;
                dp_two[i][j]   = two_from_down;
            }
            else
            {
                //select right route
                dp_direction_two[i][j] = 2;
                dp_two[i][j]  = two_from_right;
            }

            if(five_from_down<five_from_right)
            {
                //select down route
                dp_direction_five[i][j] = 1;
                dp_five[i][j]   = five_from_down;
            }
            else
            {
                //select right route
                dp_direction_five[i][j] = 2;
                dp_five[i][j]  = five_from_right;
            }
        }
    }
}

void backtrack(int follow,int x,int y)
{
    if(x>=N && y>=N)
        return;
    if(follow == 2)
    {
         if(dp_direction_two[x][y] == 1)// going down
        {
            route[route_pos] = 'D';
            route_pos ++;
            backtrack(2,x+1,y);
        }
        else if(dp_direction_two[x][y] == 2)
        {
            route[route_pos] = 'R';
            route_pos ++;
            backtrack(2,x,y+1);
        }
    }
    else if(follow == 5)
    {
         if(dp_direction_five[x][y] == 1)// going down
        {
            route[route_pos] = 'D';
            route_pos ++;
            backtrack(5,x+1,y);
        }
        else if(dp_direction_five[x][y] == 2)
        {
            route[route_pos] = 'R';
            route_pos ++;
            backtrack(5,x,y+1);
        }
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

    int ans = MIN(dp_two[1][1],dp_five[1][1]);
    if(ans >=1 && zero_flag)
    {
        fprintf(stdout,"1\n");
        for(int i = 1;i<zero_pos_x;i++)
            fprintf(stdout,"D");
        for(int j = 1;j<zero_pos_y;j++)
            fprintf(stdout,"R");
        for(int i = zero_pos_x;i<N;i++)
            fprintf(stdout,"D");
        for(int j = zero_pos_y;j<N;j++)
            fprintf(stdout,"R");
        fprintf(stdout,"\n");
        return 0;
    }
    if(dp_two[1][1]<dp_five[1][1])
    {
        //follow two
        backtrack(2,1,1);
    }
    else{
        //follow five
        backtrack(5,1,1);
    }

    fprintf(stdout,"%d\n",ans);
    fprintf(stdout,"%s\n",route);
    return 0;
}