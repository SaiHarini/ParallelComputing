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
void FW_BW(int * V,int num);

void main(){
printf("----------1");
//int n = sizeof(vertices) / sizeof(vertices[0]),i;
int n=11,i;
int *V;
for(i=0;i<n;i++){
V[i]=i;
}
printf("----------1");
FW_BW(V,n);
printf("----------1");
}



void FW_BW(int * V,int num){
if(num=0){
return;
}
printf("----------1");

            int v=V[0];
            static int d=0;
            int i=0,d_count=0,p_count=0,r_count=0,j=0,k=0,ds_count=0,ps_count=0,s_count=0;
            int *D,*P,*R,*S,*D_S,*P_S;
            //struct vertices_s* inGraph,outGraph;
           /* for(i=0;i<n;i++){
                visited[i]=false;
            }*/
           /* for(i=0;i<Vertices[v].deg;i++){
            	if(Vertices[v].adj[i]<0){
            		inGraph[k]=Vertices[v].adj[i];
            	}
            	else{
            		outGraph[k]=Vertices[v].adj[i];
            	}
            }*/
            D=bfs(V,num,vertices,v,&d_count,1);
printf("----------1");
            P=bfs(V,num,vertices,v,&p_count,0);
printf("----------1");            
            for(i=0;i<num;i++){
            
            for(k=0;k<d_count;k++){
            	if(D[k]==V[i])
            		break;
            }
            for(j=0;j<p_count;k++){
            	if(P[j]==V[i])
            		break;
            }
            if(k==d_count && j==p_count){
            	R[r_count]=V[i];
            	r_count++;
            }
            
            
            }
            
            
printf("----------1");            
            for(i=0;i<d_count;i++){
            	for(j=0;j<p_count;j++){
            		/*if(j==i){
            			for(k=0;k<s_count;k++){
            				if(S[k]==i)
            				break;	
            			}
            			if(k==s_count){
            			S[s_count]=i;
            			s_count++;
            			}
            		}*/
            		if(D[i]==P[j])
            			break;	
            	}
            	if(j!=p_count){
            		S[s_count]=D[i];
            		s_count++;
            	}
            }
            
            printf("scc %d: ", ++d);
            for(i=0;i<s_count;i++){
            	printf("%d  ",S[i]);
            }
            
            for(i=0;i<d_count;i++){
            for(k=0;k<s_count;k++){
            	if(D[i]==S[k])
            		break;
            }
            if(k==s_count){
            	D_S[ds_count]=i;
            	ds_count++;
            }
            }
            
            for(i=0;i<p_count;i++){
            for(k=0;k<s_count;k++){
            	if(P[i]==S[k])
            		break;
            }
            if(k==s_count){
            	P_S[ps_count]=i;
            	ps_count++;
            }
            }
            FW_BW(D_S,ds_count);
            FW_BW(P_S,ps_count);
            FW_BW(R,r_count);
            
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

