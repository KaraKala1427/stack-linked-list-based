#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* create_stack(){
	stack *st = malloc(sizeof(stack));
	if(st == NULL){
		printf("Memory not allocated for stack");
		exit(1);
	}
	st->top = NULL;
	st->stack_size = 0;

	return st;

}

void destroy_stack(stack *stk){
	free(stk->top);
	free(stk);
}

void push(stack *stk, int val){
	node *myNode = malloc(sizeof(node));

	if(myNode == NULL){
		printf("Memory not allocated for node");
		exit(1);
	}

	myNode->value = val;
	myNode->link = stk->top;

	stk->stack_size++;
	stk->top  = myNode;
}

int pop(stack *stk){

	if(stk->stack_size == 0){
		printf("stack Underflow\n");
		return 0;
	}
	node *tempNode = stk->top;

	// I honestly didn’t understand why tempNode->link, because it’s a link to the next node
	//and I thought we should assign like (tempNode->prev) to the previous node,
	//which I don't have in my node struct
	// So I just in order to go on put it here tempNode->link, so it worked , but I did't understand it why
	stk->top = tempNode->link;
	stk->stack_size--;
	free(tempNode);

	return tempNode->value;
}

int peek_top(stack *stk){
	if (stk->stack_size != 0) {
		return stk->top->value;
	}

	return 0;
}

size_t stack_size(stack *stk){
	return stk->stack_size;
}

void clear_stack(stack *stk){
	stk->stack_size = 0;
	stk->top = NULL;
}

void print_stack(stack *stk){
	if(stk->stack_size == 0)
	{
		printf("Stack is empty\n");
	}
	else if(stk->stack_size > 0)
	{
		while(stk->top != NULL){
			printf("%d\n",stk->top->value);
			stk->top = stk->top->link;
		}
	}
}





