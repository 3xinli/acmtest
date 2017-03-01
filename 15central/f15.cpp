#include<cstdio>
#include<iostream>
#include<string> 
#include<map>

using namespace std;

int main()
{
    map<char,string> code;
    char al;
    for(int i=0;i<=25;i++)
    {
        cin>>al;
        cin>>code[al];
    }
    int numword;
    cin>>numword;
    string word;
    map<string,string> dic;
    for(int i=0;i<numword;i++)
    {
        cin>>word;
        string tmp2="";
        for(int j=0;j<word.size();j++)
            tmp2+=code[word[j]];
        dic[tmp2]=word;
        //cout<<"dic:"<<tmp2<<"=>"<<word<<endl;
    }
    int test;
    while(cin>>test,test)
    {
        int flag=0;
        string cur;
        string output="";
        string wrong;
        for(int i=0;i<test;i++)
        {
            cin>>cur;
            if(flag==0 && dic[cur]=="")
            {
                wrong=cur;
                flag=1;
            }
            output+=dic[cur];
            if(i<(test-1))
                output+=" ";
        }
        if(flag==0)
            cout<<output<<endl;
        else
            cout<<wrong<<" not in dictionary."<<endl;
    }
}
