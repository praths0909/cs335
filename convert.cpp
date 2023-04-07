#include<bits/stdc++.h>
using namespace std;
char c;
// FILEPTR* fptr;
FILE* fptr;
int flag=0;
void typestr(string x,string nonterminal)
{
    vector<string>words;
    for(int i=0;i<x.length();i++)
    {
        while(i<x.length()&&(x[i]==' '||x[i]=='\t'))
        i++;
        string curr="";
        while(i<x.length()&&x[i]!=' '&&x[i]!='\t')
        curr+=x[i++];
        if(curr!="")
        words.push_back(curr);
    }
    // for(int i=0;i<words.size();i++)
    // cout<<words[i]<<" ";
    // cout<<"{\n";
    // cout<<"\t\t\t\t$$ = ++nodeCount;";
    // cout<<"cout << $$ << \"[label=\\\""<<nonterminal<<"\\\"]\\n\";";
    for(int i=0;i<words.size();i++)
    {
        // cout<<"cout << $$ << \" -> \" << $"<<i+1<<" << \"\\n\";";
    }
    // cout<<"\t\t\t}\n";
    words.clear();
}
void call(){
    string non="";
    non+=c;
    c=getc(fptr);
    while(c!=':')
    {
        non+=c;
        c=getc(fptr);
    }
    cout<<non<<" ";
    c=getc(fptr);
    string prod="";
    while(c!='\n')
    {
        prod+=c;
        c=getc(fptr);
    }
    // cout<<prod;
    c=getc(fptr);
    while(1)
    {
        while(c==' '||c=='\t')
        {
            c=getc(fptr);
        }
        // cout<<"hi";
        if(c=='|')
        {
            // cout<<prod<<"\n";
            typestr(prod,non);
            prod="";
            c=getc(fptr);
            while(c!='\n')
            {
                prod+=c;
                c=getc(fptr);
            }
            // cout<<"\t\t|\t"<<prod;
            c=getc(fptr);
            continue;
        }
        else if(c==';')
        {
            // cout<<"xd";
            typestr(prod,non);
            prod="";
            c=getc(fptr);
            while(c==' '||c=='\t')
            c=getc(fptr);
            // cout<<"\t\t;\n";
            if(c==EOF)
            {
                flag=1;
                break;
            }
            break;
        }
    }
}
int main(){
    fptr=fopen("input.txt","r");
    while(1){
    // cout<<"hi";
    if(flag==1||c==EOF)
    break;
     c=getc(fptr);
        while(c==' '||c=='\t'||c=='\n')
        {
            c=getc(fptr);
        }
        // cout<<"hi";
        if(c==EOF)
        return 0;
        call();
    }
    return 0;
}