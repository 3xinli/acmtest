#include<cstdio>

int main()
{
    int p;
    scanf("%d",&p);
    while(p--)
    {
        int k,n;
        scanf("%d%d",&k,&n);
        int s1=0,s2=0,s3=0,odd=1,even=2;
        for(int i=1;i<=n;i++,odd+=2,even+=2)
        {
            s1+=i;
            s2+=odd;
            s3+=even;
        }
        printf("%d %d %d %d\n",k,s1,s2,s3);
    }
}
