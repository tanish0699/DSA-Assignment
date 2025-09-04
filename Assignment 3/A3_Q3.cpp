//program that checks if an expression has balanced parentheses

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

bool isValid(string str){
    stack s;
    int length = str.length();
    for(int i=0;i<length;i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            s.push(str[i]);
        }
         else {
            if(s.empty()) {
                return false; 
            }
         
       if(str[i]==')'&&s.top()=='('||str[i]=='}'&&s.top()=='{'||str[i]==']'&&s.top()=='['){
s.pop();
        }
        else{
            return false;
        }
         
    }
    }
   return s.empty(); 
}
int main(){
    
   string str;
   cout<<"enter the expression ";
   cin>>str;
    if(isValid(str)){
        cout<<"expression is valid ";
    }
    else {
        cout<<"expression is not valid ";
    }
    
    return 0;
}
