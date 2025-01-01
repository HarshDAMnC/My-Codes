#include <iostream>
#include<stdbool.h>
using namespace std;
//concepts:recursion, BFS, pallindrome check, c++

struct node{
  int k;
  struct node *l;
  struct node *r;
};

struct node *createnode(int val){
//dynamic memory allocation using new keyword
//syntax - datatype of ptr* ptr variable= new datatype(size)
  struct node *n=new node;
  n->k=val;
  n->l=NULL;
  n->r=NULL;
  return n;
}

//recursion to get the height of the tree
int getheight(struct node *n){
  if(n==NULL){
    return 0;
  }
  else{
    int a=getheight(n->l);
    int b=getheight(n->r);
    if(a>b){
      return a+1;
    }
    else{
      return b+1;
    }
  }
}

//in the for loop, each level gets traversed
void levelorder(struct node *n,int level,int arr[100],int j){
  if(level==1){
    arr[j]=n->k;
    cout<<arr[j]<<" ";
    j+=1;
  }
  else{
    levelorder(n->l,level-1,arr,j);
    levelorder(n->r,level-1,arr,j);
  }
}
//checking if tree is symmetric or not using pallindrome check
bool checkpallindrome(int arr[100],int size){
   if(size%2==0){
      for(int i=0;i<size/2;i++){
        if(arr[i]!=arr[size-i-1]){
         return false;
        }
      }
      return true;
    }
    else if (size==1){
      return true;
    }
}

int main(){
  struct node* n1=createnode(1);
  struct node *n2=createnode(2);
  struct node *n3=createnode(2);
  n1->l=n2;
  n1->r=n3;
  int h=getheight(n1);
  cout << "height of tree : " << h << "\n";
  cout << "levelorder traversal";
  for(int i=1;i<=h;i++){
    int j=0;
    int arr[100];
    cout << "\n";
    levelorder(n1,i,arr,j);
    int k=0;
//getting the sizeof array
    while(arr[k]!='\0'){
      k+=1;
    }
    int size=k;
    if(checkpallindrome(arr,size)==false){
      cout<<"\nnot a symmetric tree\n";
      return 0;
    }
  }
  cout<<"\nsymmetric tree!\n";

}