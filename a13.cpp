#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int p;
    scanf("%d",&p);
    while(p--)
    {
        int k,a[16];
        scanf("%d",&k);
        for(int i=0;i<15;i++)
            scanf("%d",&a[i]);
        int cnt=0;
        for(int i=0;i<14;i++)
        {
            int pre=i,cur=pre+1,flag=0;
            while(cur<15)
            {
                if(a[cur]>a[pre])
                    flag=1;
                else if(flag==1 && a[cur]==a[pre])
                {
                    cnt++;       
                    break;
                }
                else if(a[cur]==a[pre])
                    break;
                cur++;
            }
        }
        printf("%d %d\n",k,cnt);
    }
}
