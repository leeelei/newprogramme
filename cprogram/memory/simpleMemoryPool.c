#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MEMORY_POOL_SIZE 2048

//the node of memory
typedef struct node{
	int data;
}memoryNode_t;

struct memoryPool{
	int current;
	int used_count;
	int used[MEMORY_POOL_SIZE];
	memoryNode_t memPool[MEMORY_POOL_SIZE];

};

struct memoryPool *G_memPool =NULL;
int memoryPool_init(){
	G_memPool = (struct memoryPool *) malloc(sizeof(struct memoryPool));
	if(NULL == G_memPool){
		printf("[ ]%s:%d ]: malloc error\n",__func__,__LINE__);
		return -1;
	}
	memset(G_memPool,0,sizeof(struct memoryPool));
	return 0;
}

void memoryPool_show(){
	int i=0;
	int used=0;
	for(;i<MEMORY_POOL_SIZE;i++){
		if(G_memPool->used[i])
			used++;
	}
	return ;
}
memoryNode_t* memoryPool_malloc(){
	int i=G_memPool->current;
	for(;i<MEMORY_POOL_SIZE;i++){
		if(G_memPool->used[i])
			continue;
		G_memPool->used[i]=1;
		G_memPool->current +=1;
		G_memPool->used_count+=1;
		if(G_memPool->current == MEMORY_POOL_SIZE)
			G_memPool->current=0;
		return &(G_memPool->memPool[i]);
	}

	for(i=0;i<G_memPool;i++){
		if(G_memPool->used[i])
			continue;
		G_memPool->used[i]=1;
		G_memPool->current +=1;
		G_memPool->used_count+=1;
		return &(G_memPool->memPool[i]);
	}

	printf("[%s:%d ] : FULL memory Pool!!!\n");
	return NULL;

}
int memoryPool_free(memoryNode_t* node){
	if(!node)
		return 0;
	int index=node-G_memPool->memPool;
	if(index<0||index>=MEMORY_POOL_SIZE)
		return -1;
	if(G_memPool->used[index] == 0){
		return -2;
	}	
	G_memPool->used[index]=0;
	G_memPool->used_count -= 1;
	return 0;
}
int memoryPool_destroy(){
	if(!G_memPool){
		free(G_memPool);
	}
	return 0;
}



int memPool_demo(){
	int i=0;
	memoryNode_t* node[2048]={NULL};
	for(i=0;i<2048;i++){
		node[i]=memoryPool_malloc();
		if(NULL == node[i]){
			printf("[%s:%d ]: i=%d malloc error\n",__func__,__LINE__,i);
			return -1;

		}
		node[i]->data=i;
	}
	for(i=0;i<2048;i++){
		if(node[i]){
			int ret=memoryPool_free(node[i]);
			if(ret !=0){
				printf("MemoryPool free error\n");
				return -1;
			}
		}
	}
	return 0;
}

int commonProc(){
	int i=0;
	memoryNode_t* node[2048]={NULL};
	for(i=0;i<2048;i++){
		node[i]=(memoryNode_t*)malloc(sizeof(memoryNode_t));
		if(NULL == node[i]){
			printf("[ %s:%d ] : i = %d malloc error\n",__func__,__LINE__,i);
			return -1;
		}
		node[i]->data = i;
	}
	for(i=0;i<2048;i++){
		if(node[i])
			free(node[i]);
	
	}
	return 0;
}	


int main(int argc,char* argv[]){
	int cnt=500000;
	clock_t start,end;
	start=end=0;
	start=clock();

	memoryPool_init();
	while(cnt--)
		memPool_demo();
	memoryPool_destroy();
	end=clock();
	printf("Memory Pool duration : %f\n",(double)(end-start)/CLOCKS_PER_SEC);


	cnt=500000;
	start=end=0;
	start=clock();

	memoryPool_init();
	while(cnt--)
		commonProc();

	end=clock();
	printf("Common Process duration : %f\n",(double)(end-start)/CLOCKS_PER_SEC);

}
