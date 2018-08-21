#include <iostream>
using namespace std;

struct stk {
    int val; 
    struct stk* next;
}; //stack node definition
void stack_push(stk **top,int val) {
    stk *temp = new stk();
    temp->val = val;
    temp->next = *top;
    *top = temp;
    return;
}
void stack_pop(stk **top) {
    stk *temp; 
    temp = *top;
    *top = (*top)->next;
    free(temp);
    return;
}
void Print(stk *top) {
    while(top!=NULL) {
        cout<<top->val<<" ";
        top = top->next;
    }
}
int main() {
	struct stk* top; 
	top = NULL;
	stack_push(&top,5);
	stack_push(&top,4);
	stack_push(&top,3);
	stack_push(&top,2);
	stack_push(&top,1);
	cout<<"\nThe stack printed in LIFO order: ";
	Print(top);
    cout<<"\nThe new stack after pop(in LIFO order): ";
	stack_pop(&top);
	Print(top);
	return 0;
}
