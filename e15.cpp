#include<cstdio>

long long findroot(int,int);
int main()
{
    int P;
    scanf("%d",&P);
    while(P--)
    {
        int k,p,q;
        scanf("%d%d/%d",&k,&p,&q);
        long long result=0;
        result=findroot(p,q);
        printf("%d %lld\n",k,result);
    }
}

long long findroot(int p,int q)
{
    if(p==q)
        return 1;
    else if(p>q)
        return findroot(p-q,q)*2+1;
    else
        return findroot(p,q-p)*2;
}
