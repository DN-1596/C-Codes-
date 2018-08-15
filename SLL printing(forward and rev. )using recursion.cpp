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

void Print(struct node *head) {
    struct node *temp;
    temp = head; 
    cout<<"\n Printing list using iterative method :- ";
    while (temp !=NULL) {
        cout<<temp->data<<"_";
        temp= temp->next;
    }
}
void printrecur(struct node *p) { // les efficient than iterative method since extra memory is used
    if (p == NULL) return; 
    cout<<p->data<< " ";
    printrecur(p->next); //using print funx after cout makes it simple recursion
}
void revprintrecur(struct node*p) {
    if(p==NULL) return;
    revprintrecur(p->next); //using print fnx before cout makes it backtracking and hence prints it in reverse
    cout<<p->data<<" "; 
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
	cout<<"\nPrinting list using recursive method:- ";
	printrecur(head);
	cout<<"\nReverse Printing list using recursive method:- ";
	revprintrecur(head);
    return 0;
}
