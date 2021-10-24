typedef char EleType;
typedef struct node{
	EleType data;
	struct node* next;
}ChainNode;
typedef struct{
	ChainNode* head;
}List;

List* CreateList(void);
void DestoryList(List*);
void ClearList(List*);
int ListAppend(List*,EleType);
int ListInsert(List*,int,EleType);
int ListDelete(List*,int);
int GetElemet(List*,int,EleType*);
ChainNode* GetAddr(List*,int);
int TraverseList(List*,int(*)(EleType*));
ChainNode* NewChainNode(EleType);
