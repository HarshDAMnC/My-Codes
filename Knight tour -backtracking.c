x#include<stdio.h>
#include<stdbool.h>
//knight tour problem using recursion- leetcode : 2596

bool safespot(int chessboard[8][8],int row,int col,int count){
  if(row<0 || col <0 || row>7 || col>7 || chessboard[row][col]!=0){
    return false;
  }
  return true;
}

int playgame(int chessboard[8][8],int row,int col,int count){
  int i,j;
  if(count==65){
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
        printf("%d ",chessboard[i][j]);
      }
      printf("\n");
    }
    return true;
  }
  int dx[]={2,1,-1,-2,-2,-1,1,2};
  int dy[]={1,2,2,1,-1,-2,-2,-1};
  for(i=0;i<8;i++){
    row=row+dx[i];
    col=col+dy[i];
    if(safespot(chessboard,row,col,count)==true){
   
      chessboard[row][col]=count;
      count++;
      if(playgame(chessboard,row,col,count)){
        return true;
      }
       chessboard[row][col]=0;
      count--;
    }
    row=row-dx[i];
    col=col-dy[i];
  }
 
  return false;
}

int main(){
  int chessboard[8][8]={0};
  int row=0,col=3;
  int count=0;
  playgame(chessboard,row,col,count);
}