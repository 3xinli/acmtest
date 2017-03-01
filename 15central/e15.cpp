#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    while(1)
    {
        long long a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a==-1 && b==-1 && c==-1 && d==-1)
            break;
        long long addc,mulc,result=-1;
        int flag=0;
        if(a==-1)
        {
            addc=c-b;
            if(flag==0 && addc==d-c)
            {
                result=b-addc;
                flag=1;
            }
            if(flag==0 && c%b==0 && d%c==0 && c/b==d/c)
            {
                mulc=c/b;
                if(b%mulc==0)
                    result=b/mulc;
                flag=1;
            }
        }
        if(d==-1)
        {
            addc=c-b;
            if(flag==0 && addc==b-a)
            {
                result=c+addc;
                flag=1;
            }
            if(flag==0 && c%b==0 && b%a==0 && c/b==b/a)
            {
                mulc=c/b;
                result=c*mulc;
                flag=1;
            }
        }
        if(b==-1)
        {
            addc=d-c;
            if(flag==0 && (c-a)%2==0 && addc==(c-a)/2)
            {
                result=a+addc;
                flag=1;
            }
            if(flag==0 && d%c==0)
            {
                mulc=d/c;
                if(a*mulc*mulc==c)
                    result=a*mulc;
                flag=1;
            }
        }
        if(c==-1)
        {
            addc=b-a;
            if(flag==0 && (d-b)%2==0 && addc==(d-b)/2)
            {
                result=b+addc;
                flag=1;
            }
            if(flag==0 && b%a==0)
            {
                mulc=b/a;
                if(b*mulc*mulc==d)
                {
                    result=b*mulc;
                    flag=1;
                }
            }
        }
        if(result>=1 && result<=1000000)
            printf("%lld\n",result);
        else
            printf("-1\n");
    }
}
