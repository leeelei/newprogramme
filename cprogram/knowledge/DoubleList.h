typedef struct Node{
	struct Node* prior;
	int data;
	struct Node* next;
}Node;
//Create double list node
Node* initNode(Node* head);
//show double list element
void display(Node* head);
