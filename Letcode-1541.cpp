#include <iostream>
#include <string.h>
using namespace std;

struct stack{
  int top;
  char arr[50];
};

int main() 
{
    char str[50]="))())(";
    int x=strlen(str);
    struct stack s;
    s.top=-1;
    s.arr[50];
    int count=0;
    for(int i=0;i<x;i++){
      if(str[i]=='('){
        s.top+=1;
        s.arr[s.top]='(';
        continue;
      }
      if(str[i]==')'){
       
          if(str[i+1]==')'){
            if(s.top!=-1){
          i+=1;
          s.arr[s.top]='\0';
          s.top-=1;
          }
          else{
            i++;
            count+=1;
          }
        }
          else{
            if(s.top!=-1){
          s.top--;
          count+=1;
            }
            else{
              count+=2;
            }
        }
      }
    }
    int ans=(s.top+1)*2 + count;
    cout << ans ;
}