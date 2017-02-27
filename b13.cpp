#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int P;
    scanf("%d",&P);
    while(P--)
    {
        int n;
        double d,a,b,f;
        scanf("%d%lf%lf%lf%lf",&n,&d,&a,&b,&f);
        printf("%d %.2f\n",n,d/(a+b)*f);
    }
}
