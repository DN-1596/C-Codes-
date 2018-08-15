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
void Delete(struct node**head , int position) {
    node *temp;
    temp = *head;
    int k=0;
    if (position == 0) {
        *head = temp->next; // address skipping;
        free(temp);
        return;
    }
    while ((temp!= NULL) && (k<position-1) ) {
        k++;
        temp= temp->next;
    }
    node *temp2;
    temp2 = temp->next; // position ot be deleted
    temp->next = temp2->next; //address skipping 
    free(temp2); //de;ete temp2;
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
	insert(&head,5,0); // inserting 5 at initial position
	insert(&head,6,0);
	insert(&head,7,1);
	Print(head);
	insert(&head,8,2); //insertion at random position
	Print(head);
	// deletion from random position
	Delete(&head,0);
	Delete(&head,2);
	Print(head);
	insert(&head,9,2);
	Print(head);
    return 0;
}
