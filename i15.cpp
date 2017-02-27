#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

string addrevorder(string);

int main()
{
    int P;
    cin>>P;
    while(P--)
    {
        string s,t;
        int k,m;
        cin>>k>>m>>s;
        int accum[10];
        for(int i=1;i<=9;i++)
        {
            accum[i]=0;
        }
        for(int i=0;i<s.size();i++)
        {
            accum[s[i]-'0']++;
        }
        if(accum[1]==1&&accum[2]==1&&accum[3]>=2&&accum[4]==4&&accum[5]==0&&accum[6]==0&&accum[7]==0&&accum[8]==0&&accum[9]==0)
        {
            cout<<k<<" C "<<1<<endl;
            continue;
        }
        if(accum[1]==0&&accum[2]==0&&accum[3]==0&&accum[4]==0&&accum[5]==2&&accum[6]>=2&&accum[7]==4&&accum[8]==0&&accum[9]==0)
        {
            cout<<k<<" C "<<1<<endl;
            continue;
        }
        t=s;
        map<string,int> check;
        check[s]=1;
        int i=2;
        for(i=2;i<=m;i++)
        {
           s=addrevorder(s);
//           cout<<"("<<s<<")"<<endl;
           if(s=="alert")
           {
               cout<<k<<" C "<<i<<endl;
               break;
           }
           if(check[s]==0)
               check[s]=1;
           else
           {
               cout<<k<<" R "<<i<<endl;
               break;
           }
        }
        if(i==m+1)
            cout<<k<<" "<<s<<endl;
    }
}

string addrevorder(string s)
{
    string output="";
    int carry=0;
    int size=s.size();
    int accum[11]={0};
    for(int i=0;i<=9;i++)
        accum[i]=0;
    for(int i=0;i<size;i++)
    {
        int a=s[i]-'0';
        int b=s[size-1-i]-'0';
        accum[(a+b+carry)%10]++;
        carry=(a+b+carry)/10;    
    }
    if(carry==1)
        accum[1]++;
    if(accum[1]==1&&accum[2]==1&&accum[3]>=2&&accum[4]==4&&accum[5]==0&&accum[6]==0&&accum[7]==0&&accum[8]==0&&accum[9]==0)
        return "alert";
    if(accum[1]==0&&accum[2]==0&&accum[3]==0&&accum[4]==0&&accum[5]==2&&accum[6]>=2&&accum[7]==4&&accum[8]==0&&accum[9]==0)
        return "alert";

    for(int i=1;i<=9;i++)
    {
        for(int j=0;j<accum[i];j++)
            output=output+(char)(i+'0');
    }
    return output;
}
