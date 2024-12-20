#include<stdio.h>
#include<stdbool.h>

#define inf 999

//function to find minimum of the dist array, except the ones which are already visited
int min(int dist[4],bool visited[4]){
  int j=0;
  int newdist[4];
  for(int i=0;i<4;i++){
    if(!visited[i]){
      newdist[j]=dist[i];
      j++;
    }
    else{
      newdist[j]=inf;
      j++;
    }
  }
  j=j-1;
  int mindist=newdist[j];
  int index=j;
  for(int i=j;i>=0;i--){
    if(newdist[i]<newdist[j]){
       mindist=newdist[i];
      index=i;
    }
  }
  return index;
}

int spa(int graph[4][4],int source){
  int dist[4];
  bool visited[4]={false};
  int curr;
//all dist infinite except source node
  for(int i=0;i<4;i++){
    if(i==source){
      dist[i]=0;
    }
    else{
      dist[i]=inf;
    }
  }
 for(int j=0;j<4;j++){
//current node is the node with minimum distance from source node(except the visited ones)
   curr=min(dist,visited);
   for(int i=0;i<4;i++){
//new distance from curr + dist of curr from source< older min dist, update the dist
     if(!visited[i] && dist[j]+graph[curr][i]<dist[i] && graph[curr][i]>0 ){
       dist[i]=dist[j]+graph[curr][i];
     }
   }
//mark the curr as visited, since it was already min, so best possible dist is found
   visited[curr]=true;
 }
//printf the min distances from source node
 for(int k=0;k<4;k++){
   printf("%d\n",dist[k]);
 }
}

int main(){
//adjacency matrix for the graph
  int graph[4][4]={{0,2,4,0},{2,0,0,3},{4,0,0,2},{0,4,2,0}};
  int source=0;
  spa(graph,0);

//by Harsh Shah
}