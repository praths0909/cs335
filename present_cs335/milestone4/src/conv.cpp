#include<bits/stdc++.h>
using namespace std;
int flag=0;
vector<string>saved;
string vec_to_str(vector<string>p,int i,int j){
    string y="";
    for(int k=i;k<j;k++)
    y=y+p[k]+"  ";
    return y;
}
string removemain(string x){
    if(x.size()<=4)
    return x;
    else
    {
        string y;
        if(x[0]=='.'&&x[1]=='m'&&x[2]=='a'&&x[3]=='i'&&x[4]=='n'){
        y="main";
        for(int i=5;i<x.length();i++)
        y+=x[i];
        }
        else{
            y=x;
        }
        return y;
    }
}

bool is_number(string p){
    if(p[0]=='-'){
        for(int i=1;i<p.length();i++)
        if(!(isdigit(p[i])))
        return false;
        return true;
    }
    else{
    for(int i=0;i<p.length();i++)
    if(!(isdigit(p[i])))
    return false;
    return true;
    }
}
bool contain_offset(string x){
    int flag1=0,flag2=0;
    for(int i=0;i<x.length();i++)
    if(x[i]=='{')
    flag1=1;
    else if(x[i]=='}')
    flag2=1;
    if(flag1&&flag2)
    return true;
    return false;
}
bool isarray(string x){
    int flag1=0,flag2=0;
    for(int i=0;i<x.length();i++)
    if(x[i]=='[')
    flag1=1;
    else if(x[i]==']')
    flag2=1;
    if(flag1&&flag2)
    return true;
    return false;
}
pair<string,string>extractarr1(string x){
    pair<string,string>p;
    int i=0,n=x.length();
    string curr1="",curr2="";
    while(i<n&&x[i]!='[')
    {
        curr1+=x[i];
        i++;
    }
    i++;
    while(i<n&&x[i]!=']')
    {
        curr2+=x[i];
        i++;
    }
    p.first=curr1;
    p.second=curr2;
    return p;
}
int findoffset(string x){
    string ans="";
    int i=0;
    while(i<x.length()&&x[i]!='{'){
        i++;
    }
    i++;
    while(i<x.length()&&x[i]!='}')
    {
        ans+=x[i];
        i++;
    }
    return stoi(ans);
}
vector<string> partition(string x){
    vector<string>s;
    int i=0;
    int n=x.length();
    string curr="";
    while(i<n){
        while(i<n&&x[i]==' ')
        i++;
        curr="";
        while(i<n&&x[i]!=' '){
            curr+=x[i];
            i++;
        }
        if(curr!=""){
            s.push_back(removemain(curr));
        }
    }
    return s;
}

string memorylocation(string identifier){
    int p;
    if(contain_offset(identifier)){
        p=findoffset(identifier);
    }
    else{
            string y;
            getline(cin,y);
            vector<string>z=partition(y);
            if(z[0]=="pushlocal")
            {
                p=findoffset(z[1]);
            }
            else{
                p=-8;
            }
        }
    string x = to_string(p)+"(%rbp)";
    return x;
}

vector<string>concate(vector<string>a,vector<string>b){
    vector<string>ans;
    ans=a;
    for(auto z:b){
        ans.push_back(z);
    }
    return ans;
}
string getconstant(string x){
    return "$"+x;
}
string actuallocation(string x){
    if(x=="%rax")
    return x;
    else if(is_number(x))
    return getconstant(x);
    else
    return memorylocation(x);
}

string moveq(string a,string b){
    return "movq\t"+a+", "+b;
}
string addq(string a,string b){
    return "addq\t"+a+", "+b;
}
string subq(string a,string b){
    return "subq\t"+a+", "+b;
}
string imulq(string a){
    return "imulq\t"+a;
}
string idivq(string x){
    return "idivq\t"+x;
}
string compq(string a,string b){
    return "cmpq\t"+a+", "+b;
}
string setg(){
    string p="%al";
    return "setg\t"+p;
}
string setl(){
    string p="%al";
    return "setl\t"+p;
}
string setge(){
    string p="%al";
    return "setge\t"+p;
}
string setle(){
    string p="%al";
    return "setle\t"+p;
}
string sete(){
    string p="%al";
    return "sete\t"+p;
}
string setne(){
    string p="%al";
    return "setne\t"+p;
}
string movezbq(string a,string b){
    return "movzbq\t"+a+", "+b;
}
string  sal(string a,string b){
    string s = "";
    return s;
}
string imulq2(string a,string b){
    return "imulq\t"+a+", "+b;
}
string orq(string a,string b){
    return "orq\t"+a+", "+b;
}
string xorq(string a,string b){
    return "xorq\t"+a+", "+b;
}
string andq(string a,string b){
    return "andq\t"+a+", "+b;
}
string jmp(string x){
    string z=".";
    return "jmp\t"+z+x;
}
string call(string x){
     string z="";
    return "call\t"+z+x;
    // return "."+x;
}


vector<string> printarray(string p,string q){\
    vector<string>ans;
    string x = p+"(%rbp)";
    ans.push_back(moveq(x,"%r13"));
    // cout<<moveq(x,"%r13");
    string nq="";
    for(int i=1;i<q.length();i++)
    nq+=q[i];
    ans.push_back(addq("$"+nq,"%r13"));
    ans.push_back(imulq2("$-1","%r13"));
    // cout<<addq("$"+q,"%r13");
    // cout<<moveq("0(%r12)","%r13");
    // return x;
    return ans;
}
pair<string,string> findarray(string x){
    string a="";
    string b="";
    int i=0;
    int n=x.length();
    while(x[i]==' '||x[i]=='\t')
    i++;
    while(x[i]!='{')
    i++;
    i++;
    while(x[i]!='}'){
    a+=x[i];
    i++;
    }
    while(x[i]!='{')
    i++;
    i++;
     while(x[i]!='}'){
    b+=x[i];
    i++;
    }
    // cout<<a<<"\n"<<b<<"\n";
    return make_pair(a,b);
}
string extractidentifiername(string x){
    string y="";
    int i=0,n=x.length();
    while(i<n&&x[i]==' '||x[i]=='\t')
    i++;
    while(i<n&&x[i]!='{'&&x[i]!=' '&&x[i]!='\t'){
        y+=x[i];
        i++;
    }
    return y;
}
vector<string>getarray (string x){
    pair<string,string> p=findarray(x);
    vector<string>ans=printarray(p.second,p.first);
    return ans;
}

vector<string> generatearray(string a,string b){
    vector<string>ans;
    ans.push_back(moveq(a,"%r12"));
    ans.push_back(addq(b,"%r12"));
    ans.push_back(addq("%rbp","%r12"));
    return ans;
}
vector<string>print(){
    vector<string>t;
    t.push_back(moveq("%rax","%rsi"));
    t.push_back("leaq\t.LC0(%rip), %rax");
    t.push_back(moveq("%rax","%rdi"));
    t.push_back(moveq("$0","%rax"));
    t.push_back("call printf@PLT");
    return t;
}
vector<string> tac_to_x86(string x){
    vector<string>p=partition(x);
    vector<string>ans;
    vector<string>ans2;
    if(p[0]=="_xv86"){
        if(p[1]!="subq"){
        vector<string>t;
        for(int i=1;i<p.size();i++){
            t.push_back(removemain(p[i]));
        }
        ans.push_back(vec_to_str(t,0,t.size()));
        return ans;
        }
    }
    if(p.size()==1){
        string y="."+p[0]+":";
        ans.push_back(y);
    }
     else if(p.size()==2){
        if(p[0]=="print"){
            string y=moveq(actuallocation(p[1]),"%rax");
            ans.push_back(y);
            vector<string>l=print();
            ans=concate(ans,l);
        }
        else if(p[0]=="pushparam"){
            string y="pushq\t"+memorylocation(p[1]);
            ans.push_back(y);
        }
    }
    else if(p.size()==3){
        if(p[0]=="go"&&p[1]=="to"){
            string y=jmp(p[2]);
            ans.push_back(y);
        }
        else if(p[0]=="pushlocal"&&p[1]=="FIELD"){
            string idname=extractidentifiername(p[2]);
            string ptrname="ptr_"+idname;
            saved.push_back(ptrname);
            ans.push_back(moveq("$8","%rdi"));
            ans.push_back("call malloc");
            ans.push_back(moveq("%rax",ptrname));
        }
        if(p[1]=="="){
            // if(isarray(p[0])){
            //     pair<string,string>s=extractarr1(p[0]);
            //     int arraybaseoffset=findoffset(s.first);
            //     int indexoffset;

            // }
            // else{

            // }
            if(p[0]=="%rax"){
                string y=moveq(actuallocation(p[2]),"%rax");
                ans.push_back(y);

            }
            else if(p[2]=="%rax"){
                string y=moveq("%rax",actuallocation(p[0]));
                ans.push_back(y);
            }
            else if(isarray(p[0])){
                ans.push_back(moveq(actuallocation(p[2]),"%r12"));
                vector<string>t=getarray(p[0]);
                for(auto str:t)
                ans.push_back(str);
                ans.push_back(moveq("%rbp","%r15"));
                ans.push_back(addq("%r13","%rbp"));
                ans.push_back(moveq("%r12","0(%rbp)"));
                ans.push_back(moveq("%r15","%rbp"));
            }
            else if(isarray(p[2])){
                vector<string>t=getarray(p[2]);
                for(auto str:t)
                ans.push_back(str);
                ans.push_back(moveq("%rbp","%r15"));
                ans.push_back(addq("%r13","%rbp"));
                ans.push_back(moveq("0(%rbp)","%r12"));
                ans.push_back(moveq("%r15","%rbp"));
                // ans.push_back(moveq("%r12",actuallocation(p[0])));
                if(contain_offset(p[0]))
                ans.push_back(moveq("%r12",actuallocation(p[0])));
                else{
                    string y;
                    getline(cin,y);
                    vector<string>z=partition(y);
                    int num;
                    if(z[0]=="pushlocal")
                    {
                        num=findoffset(z[1]);
                    }
                    else{
                        num=-8;
                    }
                    string yy = to_string(num)+"(%rbp)";
                    ans.push_back(moveq("%r12",yy));
                }
            }
            else{
                if(is_number(p[2])){
                string y="movq\t"+getconstant(p[2])+", "+memorylocation(p[0]);
                ans.push_back(y);
                 }
                else{
                    if(contain_offset(p[0])){
                        string y= "movq\t"+memorylocation(p[2])+", %r12";
                        ans.push_back(y);
                        y="movq\t%r12, "+memorylocation(p[0]);
                        ans.push_back(y);   
                    }
                    else{
                        
                        //                     string y;
                        //         getline(cin,y);
                        //         vector<string>z=partition(y);
                        //         if(z[0]=="pushlocal")
                        //         {
                        //             p=findoffset(z[1]);
                        //         }
                        //         else{
                        //             p=-8;
                        //         }
                        //     }
                        // string x = to_string(p)+"(%rbp)";
                        // return x;

                        string y;
                        getline(cin,y);
                        vector<string>par=partition(y);
                        int rm;
                        if(par[0]!="pushlocal"){
                            rm=-8;
                        }
                        else{
                            if(par.size()==2){
                                rm=findoffset(par[1]);
                                string ads=to_string(rm)+"(%rbp)";
                                string ys= "movq\t"+memorylocation(p[2])+", %r12";
                                ans.push_back(ys);
                                // ys="movq\t%r12, "+memorylocation(p[0]);
                                ys="movq\t%r12, "+ads;
                                ans.push_back(ys); 

                            }
                            else if(par.size()==3){
                                string idname=p[0];
                                string ptrname="ptr_"+idname;
                                saved.push_back(ptrname);
                                 ans.push_back(moveq("$8","%rdi"));
                                ans.push_back("call malloc");
                                ans.push_back(moveq("%rax",ptrname));
                                ans.push_back(moveq("$0","%rax"));
                                ans.push_back(moveq(ptrname,"%rdi"));
                                ans.push_back(moveq(memorylocation(p[2]),"%r14"));
                                ans.push_back(moveq("%r14","(%rdi,%rax)"));
                                
                            }
                        }
                    }
               
                }
            }
            
        }
    }
    else if(p.size()==4){
         if(p[0]=="methodgo"&&p[1]=="to"){
            // cout<<"ssssssssssssssssssssssssssssssssssssssssss";
            string y=call(p[2]);
            ans.push_back(y);
            int q=stoi(p[3]);
            q*=8;
            ans.push_back(addq(getconstant(to_string(q)),"%rsp"));
        }
        else if(p[0]=="FIELD"&&p[2]=="="){
            string idname=extractidentifiername(p[1]);
            string ptrname="ptr_"+idname;
            ans.push_back(moveq("$0","%rax"));
            ans.push_back(moveq(ptrname,"%rdi"));
            ans.push_back(moveq(actuallocation(p[3]),"%r14"));
            ans.push_back(moveq("%r14","(%rdi,%rax)"));

        }
        else if(p[2]=="FIELD"&&p[1]=="="){
            string idname=extractidentifiername(p[3]);
            string ptrname="ptr_"+idname;
             ans.push_back(moveq("$0","%rax"));
            ans.push_back(moveq(ptrname,"%rdi"));
            ans.push_back(moveq("(%rdi,%rax)","%r14"));
            ans.push_back(moveq("%r14",actuallocation(p[0])));

        }
    }
    else if(p.size()==5){

        if(p[1]=="="&&p[3]=="+"){
            // ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            // ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            // ans.push_back(addq("%r12","%r13"));
            // ans.push_back(moveq("%r13",actuallocation(p[0])));
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq("%r12",actuallocation(p[0])));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(addq("%r13",actuallocation(p[0])));
        }
        else if(p[1]=="="&&p[3]=="-"){
            // ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            
            // ans.push_back(subq("%r12","%r13"));
            // ans.push_back(moveq("%r13",actuallocation(p[0])));
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq("%r12",actuallocation(p[0])));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(subq("%r13",actuallocation(p[0])));
        }
        else if(p[1]=="="&&p[3]=="*"){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(imulq2("%r12","%r13"));
            ans.push_back(moveq("%r13",actuallocation(p[0])));
        }
        else if(p[1]=="="&&p[3]=="/"){
            ans.push_back(moveq(actuallocation(p[2]),"%rax"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back("cqto");
            ans.push_back(idivq("%r13"));
            ans.push_back(moveq("%rax",actuallocation(p[0])));
        }
        else if(p[1]=="="&&p[3]=="%"){
            ans.push_back(moveq(actuallocation(p[2]),"%rax"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back("cqto");
            ans.push_back(idivq("%r13"));
            ans.push_back(moveq("%rdx",actuallocation(p[0])));
        }
        else if(p[1]=="="&&p[3]=="<"){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(compq("%r12","%r13"));
            ans.push_back(setg());
            ans.push_back(movezbq("%al","%r12"));
            ans.push_back(moveq("%r12",actuallocation(p[0])));
        }
        else if(p[1]=="="&&p[3]==">"){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(compq("%r12","%r13"));
            ans.push_back(setl());
            ans.push_back(movezbq("%al","%r12"));
            ans.push_back(moveq("%r12",actuallocation(p[0])));
        }
        else if(p[1]=="="&&p[3]=="=="){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(compq("%r12","%r13"));
            ans.push_back(sete());
            ans.push_back(movezbq("%al","%r12"));
            ans.push_back(moveq("%r12",actuallocation(p[0])));
        }
        else if(p[1]=="="&&p[3]=="<="){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(compq("%r12","%r13"));
            ans.push_back(setle());
            ans.push_back(movezbq("%al","%r12"));
            ans.push_back(moveq("%r12",actuallocation(p[0])));
        }
        else if(p[1]=="="&&p[3]==">="){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(compq("%r12","%r13"));
            ans.push_back(setge());
            ans.push_back(movezbq("%al","%r12"));
            ans.push_back(moveq("%r12",actuallocation(p[0])));
        }
        if(p[1]=="="&&p[3]=="&"){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(andq("%r12","%r13"));
            ans.push_back(moveq("%r13",actuallocation(p[0])));
        }
        if(p[1]=="="&&p[3]=="|"){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(orq("%r12","%r13"));
            ans.push_back(moveq("%r13",actuallocation(p[0])));
        }
        if(p[1]=="="&&p[3]=="^"){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(moveq(actuallocation(p[4]),"%r13"));
            ans.push_back(xorq("%r12","%r13"));
            ans.push_back(moveq("%r13",actuallocation(p[0])));
        }
        
    }
    else if(p.size()==6){
        if(p[0]=="if"&&p[1]=="zero"&&p[3]=="go"&&p[4]=="to"){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(compq(actuallocation("0"),"%r12"));
            ans.push_back("je\t."+p[5]);
        }
        if(p[0]=="if"&&p[1]=="nonzero"&&p[3]=="go"&&p[4]=="to"){
            ans.push_back(moveq(actuallocation(p[2]),"%r12"));
            ans.push_back(compq(actuallocation("0"),"%r12"));
            ans.push_back("jne\t."+p[5]);
        }
    }
    return ans;
}

vector<string>tacvector_to_x86(vector<string>s){
    vector<string>ans;
    for(auto z:s)
    ans=concate(ans,tac_to_x86(z));
    return ans;
}
void printstring(vector<string>s){
    for(auto z:s){
        cout<<z<<"";
    }
    cout<<"\n";
}

int main(){

    // string a="  ebfuerbf furbvufr vurbv  a ";
    // printstring(partition(a));
    // for(int i=0;i<5;i++)
    // {
    //     string x;
    //     cin>>x;
    //     cout<<is_number(x)<<"\n";
    // }
    // cout<<memorylocation("awde");
    // vector<string>t={" a = 2"," b = 4 ", " a = b "," a = c + d"," a = 2 * 2"};
    // vector<string>t={"t1 = 2","a = t1","t2 = 3","b = t2","t3 = 0","c = t3","t4 = a","t5 = b","t6 = t4 < t5","if zero t6 go to LABEL1","t7 = 4","c = t7","t8 = 5","c = t8"};
    // vector<string>ans=tac_to_x86(t[0]);
    // for(int i=1;i<t.size();i++){
    //     ans=concate(ans,tac_to_x86(t[i]));
    // }
//     cout<<".globl _start\n";
// cout<<"_start:\n";
// cout<<"jmp .main\n";
   vector<string>ans;
    vector<string>ans2;
    string x;
    while(getline(cin,x))
    {   if(x=="enter required subq")
        ans.push_back(subq("$1600","%rsp"));
        else if(x==""){
            continue;
        }
        else if(x==".type	.main,  @function  ")
        ans.push_back(".type	main,  @function  ");
        else if(x==".globl	.main  ")
        ans.push_back(".globl	main");
        else if(x=="function is starting"){
            flag=1;
        }
        else if(x=="function end"){
            flag=0;
        }
        else if(x[0]=='_'&&x[1]=='x'&&x[2]=='v'&&x[3]=='8'&&x[4]=='6'){
            ans=concate(ans,tac_to_x86(x));
        }
        else
        {
            if(flag){
                ans=concate(ans,tac_to_x86(x));
            }
            else{
                ans2=concate(ans2,tac_to_x86(x));
            }
        }

      
        // ans.push_back(x);
    }
    cout<<".data\n";
    for(auto z:saved)
    {
        cout<<z+": .quad 0\n";
    }
    cout<<".LC0:\n";
    string y=".string \"%ld \"";
    cout<<y<<"\n";
    cout<<" .text\n";
    int count=0;
    int done=1;
    for(auto c:ans){
        if(done&&count==6){
            for(auto r:ans2)
            cout<<r<<"\n";
            done=0;
        }
        if(done&&count){
            count++;
        }

        if(done&&count==0&&c.length()>=5){
            if(c[0]=='m'&&c[1]=='a'&&c[2]=='i'&&c[3]=='n'&&c[4]==':'){
                count=1;
            }
        }
        
    cout<<c<<"\n";
    }
    // for(auto c:ans)
    // cout<<c<<"\n";
    // for(auto c:ans2)
    // cout<<c<<"\n";
    
    return 0;
}