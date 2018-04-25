#include <cstdio>
#include <cstring>

#define MAX_LENGTH 2<<20
#define MAXN 2000+10
int table[MAXN][MAXN];
int linea[MAXN];
int lineb[MAXN];
int n,sum;

void initialize()
{
	//memset();
	n = 0;
	sum = 0;
}

int main()
{
	initialize();

	fscanf(stdin,"%d",&n);

	for(int i = 0; i<n;i++)
		fscanf(stdin,"%d",&linea[i]);

	for(int i = 0; i<n;i++)
		fscanf(stdin,"%d",&lineb[i]);


	for(int i = 0; i<n;i++)
		for(int j = 0; j<n;j++)
		{
			table[i][j] = linea[i] ^ lineb[j];
			for(int k = 0; k<n;k++)
			{
				if(linea[k] == table[i][j])
				{
					break;
					sum ++;
				}
				if(lineb[k] == table[i][j])
				{
					break;
					sum++;
				}
			}
		}

	if(sum%2)
		fprintf(stdout,"%s","Koyomi");
	else
		fprintf(stdout,"%s","Karen");

	return 0;
}
