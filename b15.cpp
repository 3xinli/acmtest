#include<cstdio>

using namespace std;

long long comp(long long,long long);
int main()
{
    int p;
    scanf("%d",&p);
    while(p--)
    {
        int k,s;
        scanf("%d%d",&k,&s);
        long long x=0,y=0,cnt=0;
        long long tmp;
        for(y=0;y<=s/2;y++)
        {
            if((s-2*y)%4==0)
            {
                x=(s-2*y)/4;
                if(x>=y)
                {
                    tmp=comp(y,x+y);
                    cnt+=tmp*tmp;
                }
            }
        }
        printf("%d %lld\n",k,cnt);
    }
}
long long comp(long long x,long long y)
{
    long long result=1;
    for(long long i=1;i<=x;i++)
    {
        result*=i+(y-x);
        result/=i;
    }
    return result;
}

