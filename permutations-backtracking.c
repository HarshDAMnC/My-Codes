#include<stdio.h>
#include<string.h>

//use pointers while swapping so that change is made at that memory location
void swap(char *a,char *b){
  char t=*a;
  *a=*b;
  *b=t;
  return;
}

void permute(int n,char str[5],int index){
  if(index==n-1){
    printf("%s\n",str);
    return;
  }
//first loop makes 5 strings abcde,bacde,bcade,dbcae,ebcda. All 5 are sent to next loop which
//makes 4 strings, with first char fixed, each of the 20 int 3, each 60 *2=120 total str
  for(int i=index;i<n;i++){
    swap(&str[i],&str[index]);
    permute(n,str,index+1);
    swap(&str[i],&str[index]);
  }
}

int main(){
  char str[5]="abcde";
  int n=strlen(str);
  permute(n,str,0);
}