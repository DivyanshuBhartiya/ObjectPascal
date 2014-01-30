#include "Definitions.h"
//#include "IR.h"

int Club(Type* a) 
{
	switch(a->dataType) {
		case DT_VOID:   return DT_VOID;
		case DT_INT:    return DT_INT;	
		case DT_CHAR:   return DT_INT;	
		case DT_BOOL:return DT_VOID;	
		case DT_REAL:   return DT_INT;	
		case DT_SUBR:   return DT_VOID;
		case DT_STRING: return DT_STRING;
		case DT_SINGLE: return DT_INT;
		case DT_DOUBLE: return DT_INT;
		}
	return DT_VOID;
}

int ClubTypeCheck(Type* a, Type* b) 
{
	if(Club(a) == Club(b) && Club(a) != DT_VOID && Club(a)!=DT_STRING )
		return 1;
	else	
		return 0;		
}

List* merge(List *list1, List *list2) {
	List *temp = list1;
	if(list1==NULL)
		return list2;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}	
	temp->next=list2;
	return list1;
}

List* create_new_list(int i) {
	List* temp = (List *)malloc(sizeof(List));
	temp->addr = i;
	temp->next =NULL;
	return temp;
}

void BackPatch(List*L, int k ){
	//printf("\n Backpatch : %d\n",k);
	List *temp = L;
	/*
	while(temp != NULL)
	{
		printf("\n%d\n", temp->addr);
		temp = temp->next;
	}*/
	char *s;
	s = (char *)malloc(5*sizeof(char));
	sprintf(s,"%d",k);
	while(L!= NULL) {
		codelist[L->addr]->arg1 = strdup(s); // is it always arg1??
		L = L->next;
	}
// 	for( ; L != NULL; L = L->next )
// 		codelist[L->addr]->arg1 = strdup(s); // is it always arg1??
}

Type* setBasicType(int inType)
{
	Type* x;
	x = (Type *)malloc(sizeof(Type));
        switch(inType)
	  	{
		case DT_VOID:   {x->dataType = DT_VOID;x->width = SIZE_VOID;break;}
		case DT_INT:    {x->dataType = DT_INT; x->width = SIZE_INT; break;}	
		case DT_CHAR:   {x->dataType = DT_CHAR; x->width = SIZE_CHAR; break;}	
		case DT_BOOL:{x->dataType = DT_BOOL; x->width = SIZE_BOOL; break;}	
		case DT_REAL:   {x->dataType = DT_REAL; x->width = SIZE_REAL; break;}	
		case DT_SUBR:   {x->dataType = DT_SUBR; x->width = SIZE_VOID;break;}	// CHECK IF ITS REQUIRED
		case DT_STRING: {x->dataType = DT_STRING; break;}
		case DT_SINGLE: {x->dataType = DT_SINGLE; x->width = SIZE_SINGLE;break;}
		case DT_DOUBLE: {x->dataType = DT_DOUBLE; x->width = SIZE_DOUBLE; break;}
		case DT_REC:	{x->dataType = DT_REC; break;} // WAHIN PAR
		case DT_ERROR:   {x->dataType = DT_ERROR; break;}	// WAHIN PAR
		case DT_OBJ: {x->dataType = DT_OBJ;break;}
		case DT_CLASS:	{x->dataType = DT_CLASS;break;}
		case DT_PROC:	{x->dataType = DT_PROC; x->width = SIZE_PTR; break;}
		case DT_FUNCTION : {x->dataType = DT_FUNCTION; x->width = SIZE_PTR; break;}
		
		}		 	  
		x->leftEnd = TYPE_SIZE_IN_BITS;
		return x;
}

int strictClub(Type* a) {
	switch(a->dataType) {
		case DT_VOID:   return DT_VOID;
		case DT_INT:    return DT_INT;	
		case DT_CHAR:   return DT_INT;	
		case DT_BOOL:	return DT_BOOL;	
		case DT_REAL:   return DT_REAL;	
		case DT_SUBR:   return DT_VOID;
		case DT_STRING: return DT_STRING;
		case DT_SINGLE: return DT_REAL;
		case DT_DOUBLE: return DT_REAL;
		}
	return DT_VOID;	
}

int typeCheck(Type* a, Type* b)
{
	if(a == NULL || b == NULL) return 0;
	if ( a->dataType == b->dataType)
		return 1;
	else
		return 0;
}

int conversionTypeCheck(Type* a, Type* b) 
{
	if(a == NULL || b == NULL) return 0;
	if((a->dataType == DT_INT || a->dataType == DT_REAL) && (b->dataType == DT_INT || b->dataType == DT_REAL))
		return 1;
	else
		return 0;
}

int assignTypeCheck(Type* a, Type* b) 
{
	if(a == NULL || b == NULL) return 0;
	if(strictClub(a) == DT_REAL && Club(b) == DT_INT)
		return 1;
	else if(strictClub(a) == strictClub(b))
		return 1;
	else
		return 0;
}

Type* getArithType( Type* t1, Type* t2)
{
	if(t1 == NULL || t2 == NULL) return setBasicType(DT_VOID);
	if (t1->dataType == DT_INT && t2->dataType == DT_INT)
		return t1;
	else if (t1->dataType == DT_REAL)
			return t1;
	else	return t2; 
}

Type* CopyType(Type *a)
{
	Type* temp = (Type*)malloc(sizeof(Type));
	if(a!=NULL) 
	{
		temp->dataType = a->dataType;
		temp->leftEnd = a-> leftEnd;
		temp->entry = a->entry;
		temp->attScope = a->attScope;
	}
	else
		temp = NULL;
	return temp;	 
}

Type* CopyType2(Type *a)
{
	Type* temp = (Type*)malloc(sizeof(Type));
	if(a!=NULL) 
	{
		temp->dataType = a->dataType;
		temp->leftEnd = a-> leftEnd;
		temp->entry = a->entry;
		temp->attScope = a->attScope;
		temp->truelist = a->truelist;
		temp->falselist = a->falselist;
		temp->next = a->next; // use it
		temp->counter = a->counter;
		temp->width = a->width; // size of this dataType
		temp->flag = a->flag;
		temp->maxIndex = a->maxIndex;
		temp->low = a->low;
		temp->place = (char *)malloc(100); // for place in 3 address code
		if(a->place != NULL) 
			sprintf(temp->place,"%s",a->place);
		//temp->place = a->place;
		temp->code = a->code; // for 3 address code
		temp->funcAttScope = a->funcAttScope;
		temp->nextlist = a->nextlist;	
	}
	else
	temp = NULL;
	return temp;	 
}

void initialize_type(Type* x) 
{
 x->leftEnd = 0;
 x->dataType = 0;
}
	
Type* setType(Type* inType) 
{
	Type *x;
	x = (Type *)malloc(sizeof(Type));
		x->leftEnd = inType->leftEnd;
		x->dataType = inType->dataType;
		x->width = inType->width;
	return x;
}

void updateLeftEnd(Type* x)
{
	x->leftEnd += TYPE_SIZE_IN_BITS;
}

void augmentType(Type** t,int inType)
{
	Type *x;
	x = *t;
        switch(inType)
	  	{
		case DT_REC:	{x->dataType |= (DT_REC << x->leftEnd);;break;}
		case DT_CONST:	{x->dataType |= (DT_CONST << x->leftEnd);;break;}
		case DT_ARR:     {x->dataType |= (DT_ARR << x->leftEnd);;break;}	
		case DT_PTR:     {x->dataType |= (DT_PTR << x->leftEnd);break;}	
		case DT_FUNCTION:{x->dataType |= (DT_FUNCTION << x->leftEnd);break;}
		}		 	  
		//updateLeftEnd(x);
		x->leftEnd =  x->leftEnd + TYPE_SIZE_IN_BITS;	
		
}

Type* getSubType(Type* t)
{
	if(t == NULL) 
		return 0;
	Type* tp;
	tp = (Type *)malloc(sizeof(Type));
	tp->leftEnd = t->leftEnd - TYPE_SIZE_IN_BITS;
	tp->dataType = t->dataType & ~((long)(-1)<< tp->leftEnd); 
	return tp;
}

void append_to_list(Type *a,Type **head) 
{
	Type *temp;
	temp = *head;
	while(temp->next!=NULL) 
	{
		temp = temp->next;
	}
	temp->next = a;
}

void make_new_list(Type *a,Type **head)
{
	Type *temp,*r;
	temp = *head;
	//printf("Inside make list \n");
	if(*head == NULL) {	
		//printf("empty in record");
		temp = (Type *)malloc(sizeof(Type));
		temp->dataType=a->dataType;
		temp->leftEnd = a->leftEnd;
		temp->next = NULL;
		*head = temp;
	}
	else 
	{
		//printf("multiple args in record");
		while(temp->next != NULL) 
		{
			temp = temp->next;
		}
		r = (Type *)malloc(sizeof(Type));
		r->dataType=a->dataType;
		r->leftEnd = a->leftEnd;
		r->next = NULL;
		temp->next = r;	
	}
}

void printType( Type* t)
{
 	if(t != NULL)
	{
		int left = t->leftEnd;
		unsigned long dType = t->dataType;
		int tp;
		int mask = ~( (long)(-1) << TYPE_SIZE_IN_BITS );	
		// printf( "Type(hex : %x)::",dType);
		while(left>0)
		{
			tp = dType & mask; 
			switch (tp)
			{
				case DT_VOID : { printf("Void "); break; }
				case DT_INT:    {printf("int ");break;}	
				case DT_CHAR:   {printf("char ");break;}	
				case DT_BOOL: {printf("bool ");break;}	
				case DT_REAL:   {printf("REAL ");break;}	
				case DT_SUBR:   {printf("SUBR ");break;}	
				case DT_STRING: { printf("STRING ");break;}
				case DT_SINGLE: { printf("SINGLE ");break;}
				case DT_DOUBLE: {printf("DOUBLE ");break;}
				case DT_ERROR:   {printf("ERROR ");break;}	
				case DT_OBJ: {printf("OBJECT, ");printf("Attribute Scope : %d",t->attScope);break;}
				case DT_CLASS:	{printf("CLASS, "); printf("Attribute Scope : %d",t->attScope);break;}
				case DT_ARR:	{printf("Array "); break;}
				case DT_REC:	{printf("Record, "); printf("Attribute Scope : %d",t->attScope); break;}
				case DT_PTR:	{printf("Pointer "); break;}
				case DT_CONST:	{printf("Const "); break;}	
				case DT_FUNCTION:	{printf("Function, ");printf("Attribute Scope : %d",t->attScope); break;}
				case DT_PROC:	{printf("Procedure, "); printf("Attribute Scope : %d",t->attScope); break;}
				default : {printf("VOID ");}
			}
			dType >>= TYPE_SIZE_IN_BITS;
			left -= TYPE_SIZE_IN_BITS;
		}
	}
}
