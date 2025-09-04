// Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD"

#include<iostream>
#include<vector>
using namespace std;
class stack{
   private:
       
       vector<char> v;
   
    public:
    
    void push(char c){
        v.push_back(c);
    }
    void pop(){
        v.pop_back();
    }
    char top(){
        return v.back();
    }
    bool empty(){
        return v.empty();
    }
};
int main(){
    string str;
    cout<<"enter the string = ";
   getline(cin,str);
    int length = str.length();
    stack s;
    for(int i=0;i<length;i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}
