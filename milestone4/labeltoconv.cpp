#include<bits/stdc++.h>
using namespace std;
ifstream myfile;
bool islabel(string x){
    if(x.length()>5&&x[0]=='L'&&x[1]=='A'&&x[2]=='B'&&x[3]=='E'&&x[4]=='L'){
            for(int i=5;i<x.length();i++){
                if(x[i]<'0'||x[i]>'9')
                {
                    if(x[i]!=' ')
                    return false;
                }
            }
            return true;
        }
        return false;
}
vector<string> piece(string x){
    int n=x.length();
    int i=0;
    vector<string>ans;
    string curr="";
    while(i<n){
        while(i<n&&x[i]==' '){i++;
        }
        while(i<n&&x[i]!=' '){
            curr+=x[i];
            i++;
        }
        if(curr!="")
        ans.push_back(curr);
        curr="";

    }
    return ans;
}
int main(){
    myfile.open("output.3ac");
    string x;
    int lineno=1;
    map<string,int>m;
    vector<string>p;
    while(getline(myfile,x)){
        
        if(islabel(x))
        {
            m[x]=lineno;
        }
        else{
            p.push_back(x);
            lineno++;
        }
    }
    lineno=1;
    for(int i=0;i<p.size();i++){
            vector<string>temp=piece(p[i]);
            cout<<lineno<<":"<<"\t";
            for(int j=0;j<temp.size();j++){
                if(islabel(temp[j])){
                    cout<<m[temp[j]]<<" ";
                }
                else{
                    cout<<temp[j]<<" ";
                }
            }
            cout<<"\n";
            lineno++;
    }
    return 0;
}