#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXN 200000+20

std::vector<int> hp(MAXN);
std::vector<int> dmg(MAXN);
std::vector<int> compare(MAXN);
int n=0;
int a=0;
int b=0;

void initialize()
{
	// memset(hp,0,sizeof(hp));
	// memset(dmg,0,sizeof(dmg));
	// memset(compare,0,sizeof(compare));
}

void readinput()
{
	fscanf(stdin,"%d%d%d",&n,&a,&b);
	for(int i = 0;i<n;i++)
	{
		fscanf(stdin,"%d%d",&hp[i],&dmg[i]);
		compare[i] = hp[i]-dmg[i];
	}
}

void process()
{
	while(a+b>0)
	{
		if(a>0&&b>0)// both spell still available
		{
			int maxhp = 0; int maxpos1 = -1;
			for(int i = 0;i<n;i++)
			{
				if(hp[i]<dmg[i])
					continue;
				if(hp[i]>maxhp)
				{
					maxhp = hp[i];
					maxpos1 = i;
				}
			}
			// maxsub = 0; int maxpos2 = -1;
			// for(int i = 0;i<n;i++)
			// {
			// 	if((hp[i]-dmg[i])>maxsub)
			// 	{
			// 		maxsub = hp[i]-dmg[i];
			// 		maxpos2 = i;
			// 	}
			// }
			std::iterator<int> maxsub_i = (std::max_element(compare.begin(),compare.end()));
			int maxpos2 = *(std::distance(compare.begin(),maxsub_i));
			int maxsub = *(maxsub_i);
			if(maxhp > maxsub)// spell 1
			{
				hp[maxpos1] *=2; a--; continue;
			}
			else //spell2
			{
				dmg[maxpos2] = hp[maxpos2]; b--;continue;
			}
		}
		else if(b>0)// spell 1 not available, spell 2 available
		{
			//int maxsub = 0; int maxpos2 = -1;
			auto maxsub = (std::max_element(compare.begin(),compare.end()));
			auto maxpos = *(std::distance(compare.begin(),maxsub));
			int maxpos2 = maxpos;
			// for(int i = 0;i<n;i++)
			// {
			// 	if((hp[i]-dmg[i])>maxsub)
			// 	{
			// 		maxsub = hp[i]-dmg[i];
			// 		maxpos2 = i;
			// 	}
			// }
			dmg[maxpos2] = hp[maxpos2]; b--;continue;
		}
		else
			break;
	}
	
	int total_damage = 0;
	for(int i = 0;i<n;i++)
	{
		total_damage += dmg[i];
	}

	fprintf(stdout,"%d",total_damage);


	
}

int main()
{
	initialize();
	readinput();
	process();

	return 0;
}