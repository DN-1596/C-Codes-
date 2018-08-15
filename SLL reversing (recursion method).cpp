#include <iostream>
using namespace std;

struct node {
   int data;
   struct node *next; 
};
void insert(struct node **head,int data,int position) {
    struct node *temp;
    int k=0;
    temp = new node(); 
    temp->data = data;
    temp->next = NULL;
    if (position == 0) {
         temp->next= *head;
        *head = temp;
        return;
    }
    struct node *temp2;
    temp2 = *head; 
    while ( k < position-1) {
        k++;
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;

}
struct node *globalhead;
void revrecur(struct node *p) {
    if (p->next==NULL) {
        globalhead = p;
        return;
    }
    revrecur(p->next) ; 
    p->next->next = p; 
    p->next = NULL;
}

void Print(struct node *head) {
    struct node *temp;
    temp = head; 
    cout<<"\n Printing list using iterative method :- ";
    while (temp !=NULL) {
        cout<<temp->data<<"_";
        temp= temp->next;
    }
}

// insertion at nth position
int main() {
	// Building a linked list
	struct node *head;
	head = NULL;
	insert(&head,2,0);
	insert(&head,3,1);
	insert(&head,5,2);
	insert(&head,4,2);
	Print(head);
	globalhead = head;
    revrecur(head);
    Print(globalhead);
    return 0;
}
