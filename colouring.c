#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 10
#define MAX_NUM_VERTICES 30

struct vertices_s {
    int visited;
    int deg;
    int adj[MAX_DEGREE]; /* < 0 if incoming edge */
} vertices[] = {
    {0, 3, {2, -3, 4}},//incoming negative,outgoing positive
    {0, 2, {-1, 3}},
    {0, 3, {1, -2, 7}},
    {0, 3, {-1, -5, 6}},
    {0, 2, {4, -7}},
    {0, 3, {-4, 7, -8}},
    {0, 4, {-3, 5, -6, -12}},
    {0, 3, {6, -9, 11}},
    {0, 2, {8, -10}},
    {0, 3, {9, -11, -12}},
    {0, 3, {-8, 10, 12}},
    {0, 3, {7, 10, -11}}
};


int* bfs(int *V,int num,struct vertices_s* graph,int v,int *count,int in_out);
void ColourSCC(struct vertices_s *graph);

void main(){
printf("----------1");
int n = sizeof(vertices) / sizeof(vertices[0]),i;
//int n=11,i;
int *V;
for(i=0;i<n;i++){
V[i]=i;
}
printf("----------1");
ColourSCC(vertices);
printf("----------1");
}



int* bfs(int *V,int num,struct vertices_s* graph,int v,int *count,int in_out)
{
    int* bfs_graph;int k=0;
    int i,front,rear,u;
    int que[20];
    front=rear= -1;
    v=V[0];	
    printf("%d ",v);
    graph[v].visited=1;
    rear++;
    front++;
    que[rear]=v;

    while(front<=rear)
    {
        v=que[front];     
        front++;
        for(i=0;i<graph[v].deg;i++)
        {
            
            /*if( adj[v][i]==1 && visited[i]==false)
            {
                printf("%d ",i);
                bfs_graph[k]=i;
                k++;
                visited[i]=true;
                rear++;
                que[rear]=i;
             }*/
             
             u=graph[v].adj[i];
             for(i=0;i<num;i++){
             	if(u==i){
             		break;
             	}
             }
          if(i!=num) {
            
             if(graph[u].visited==0)
            {
               if(in_out==1 && u>0 || in_out==0 && u<0){
                printf("%d ",u);
                bfs_graph[k]=u;
                k++;
                
                graph[u].visited=1;
                rear++;
                que[rear]=u;
               }
             }
           }
        }
    }

   
    return bfs_graph;
}



void ColourSCC(struct vertices_s *graph){

int c,v,u,i,j,flag=1,count=0,num=0,scv_count=0,temp=0;
int *colours,*visited,*VC,*V,*SCV;
int n=sizeof(graph) / sizeof(graph[0]);
if(n==0)
return;

while(n!=0){

	for(i=0;i<n;i++){
	
		colours[i]=i;
		visited[i]=0;
		V[i]=i;
	
	}
	
	while(flag==1){
		flag=0;
		for(u=0;u<n;u++){
			for(j=0;j<graph[u].deg;j++){
				v=graph[u].adj[j];
				if(colours[u]>colours[v]){
					colours[v]=colours[u];
					flag=1;
				}
			}
		}
	}
}
num=n;
for(c=0;c<n;c++){
	
	if(visited[c]==0){
	
	visited[c]=1;
	graph[c].visited=1;
	
	for(i=0;i<num;i++){
		u=V[i];//Since u should belong to V
		if(visited[u]==0 && colours[u]==c){
			visited[u]=1;
			graph[u].visited=1;
			VC[count]=u;
			count++;	
		}
	}
	
	SCV=bfs(VC,num,graph,VC[0],&scv_count,0);//incoming=>0
	printf("SCC :\n");
	for(i=0;i<scv_count;i++){
		printf("%d\t",SCV[i]);
	}
	
	temp=0;
	for(i=0;i<num;i++){
		for(j=0;j<scv_count;j++){
			if(V[i]==SCV[j]){
				break;
			}
		}
		if(j==scv_count){
			V[temp]=i;
			temp++;
		}
	}
	num=temp;
	
	
	}
}

}
