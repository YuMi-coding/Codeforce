#include <cstdio>
#include <cstring>

int n,m,a;

int main()
{
	n = 0, m = 0, a = 0;
	fscanf(stdin,"%d%d%d",&n,&m,&a);

	long long linea = ((n/a) + bool(n%a));
	long long lineb = ((m/a) + bool(m%a));
	fprintf(stdout,"%I64d",linea*lineb);
}