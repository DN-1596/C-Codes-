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

void reverse (struct node **head) {
    struct node * current, *prev,*step; 
    current = *head ; 
    prev = NULL;
    while (current!=0) {
        step = current->next; 
        current->next = prev; 
        prev= current; 
        current =step;
    }
    *head = prev;
}
void Print(struct node *head) {
    struct node *temp;
    temp = head; 
    cout<<"\n The list is :- ";
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
	reverse(&head);
	cout<<"\nReversed List (iteration method):- "; 
	Print(head);
    return 0;
}
