#include<bits/stdc++.h>
#include<stack>
#include<utility>
#include<vector>

using namespace std;

class voter{
    private:
    string Identity;
    int Age;  
    string Name;
    protected:
    stack<tuple<string,string,int>>st;
public: 
    // voter(string name,string identity,int age):Name(name), Identity(identity), Age(age) {}
    void registration(){
        
        cout<<"Enter Your Name :"<<endl;
        cin>>Name;

        cout<<"Enter Your Identity :"<<endl;
        cin>>Identity;

        cout<<"Enter Your age :"<<endl;
        cin>>Age;

        st.push(make_tuple(Name,Identity,Age));
    }
    int Totalregistration(){
        return st.size();
    }
};

class candidate:public voter{
private:
    string Name;
    int age;
     vector<pair<int,string>>vt;
    stack<tuple<string,string,int>>cde;
public:
    // candidate(string name,int Age):voter("", "", 0),Name(name),age(Age){}
    void Infocandit(){
       
        cout<<"Enter Age Of Candidate"<<endl;

        cin>>age;

        cout<<"Enter Name Of Candidate "<<endl;

        cin>>Name;

        vt.push_back(make_pair(age,Name));
    }
    void insertvote(){
         while(!st.empty()){
            auto voterinfo=st.top();
            cde.push(make_tuple(get<0>(voterinfo),get<1>(voterinfo),get<2>(voterinfo)));
            st.pop();
         }
    }
    int votercount(){
        return cde.size();
    }
    
};
// class check_winner:public candidate{
//     public:
//     :candidate("",0)
//     void
//     stack<int>cw;
//     cw.push_back(int votercount());
// }

int main(){
    voter vt1;
    voter vt2;
    candidate cd1;
    candidate cd2;

    cd1.Infocandit();
    vt1.registration();
    cd1.insertvote();
    cd2.Infocandit();
    vt1.registration();
    vt1.registration();
    cd2.insertvote();

    int a=cd1.votercount();
    int b=cd2.votercount();
    if(a>=b){
        cout<<"The Winner Of this _____Election is A";
    }
     else if(a==b){
        cout<<"tie";
    }
    else{
        cout<<"The Winner Of this_____Election is candidate B";
    }

    return 0;
}
