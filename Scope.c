#include "Definitions.h"
extern int line_number;

void Add(int index, unsigned int inSize)
{
	if(scopeHeader[index] == NULL)
	{
		scopeHeader[index] = (header*)malloc(sizeof(header));
		scopeHeader[index]->size = scopeHeader[index]->size + 20; // for scopeId,RA,RV,old_SP,t0--t9,s0--s7
	}
	scopeHeader[index]->size = scopeHeader[index]->size + inSize;
}

unsigned int SizeOf(int index)
{
	//printf("called SizeOf for scope = %d",index);
	if(scopeHeader[index] == NULL)
		return 20;
	return (scopeHeader[index]->size);
}
	
void PrintHeader()
{
	int i;
	for(i=0;i<MAX_SCOPES;i++)
	{
		if(scopeHeader[i] != NULL)
			printf("Scope %d : Size = %d\n",i,scopeHeader[i]->size);
	}
	printf("\n");
}

void Push(stack ** given , int y)
{
	//printf("** Scope pushed =  %d at line = %d **\n",y,line_number);
	stack* x=*given;
	stack* temp=(stack*)malloc(sizeof(stack));
	temp->val=y;
	temp->next=x;
	*given=temp;
	
}

stack* Pop(stack ** given )
{
	stack* x;
	x=*given;
	if(x == NULL) 
	{
		return NULL;	
	}
	else 
	{
		//printf("---------Popped = %d  ---------\n",x->val);
		*given = x->next;
		return x;
	}	
}


int matchScope(unsigned int scopeId,stack* inScopeStack)
{
	//unsigned int mask = ~((int)(-1) << SCOPE_ID_SIZE);
	stack *temp = inScopeStack;
	while(temp!=NULL)
	{
		if(scopeId == temp->val)
			return 1;
		/*inScopeStack >>= SCOPE_ID_SIZE;*/// Pop(&inScopeStack);
		temp = temp->next;
	}
	return 0;
}
