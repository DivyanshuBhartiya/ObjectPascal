#include "Definitions.h"
//#include "Type.h"
//#include "Scope.h"
#include "y.tab.h"
//extern int INT;
//extern double REAL,FLOAT;
//extern char CHAR_STRING[256];
extern unsigned int tempId;
extern int tempArray[1000];

int hashKey(char *s)
{
	char *p;
	unsigned h=0,g=0;
	if(s == NULL)
		return -1;
	for(p=s;*p!='\0';p=p+1)
	{
		h=(h<<4)+(*p);
		if(g=h&0xf0000000)
		{
			h=h^(g>>24);
			h=h^g;
		}
	}
	return (h%256);
}

int NewEntry(char* s, int type,int line_no, sym **head,stack *inScopeStack, Type* t)
{
	
	//unsigned int mask = ~((int)(-1) << SCOPE_ID_SIZE);

	int flag = 0;
	sym *temp,*r;
	temp = *head;
	if(*head == NULL) {
		temp = (sym *)malloc(sizeof(sym));
		temp->lexeme=malloc(strlen(s)+1);
		strcpy(temp->lexeme,s);
		temp->token = type;
		temp->line = line_no;
		temp->myScope = inScopeStack->val ;
		temp->offset  = SizeOf(inScopeStack->val);
		temp->type = (Type *)malloc(sizeof(Type));  
		if(t !=NULL) {
			temp->type = t;
		}
		if(type == INT ) { temp->type->dataType = DT_INT; temp->type->leftEnd = TYPE_SIZE_IN_BITS;}
		else if (type == REAL || type == FLOAT) { temp->type->dataType = DT_REAL; temp->type->leftEnd = TYPE_SIZE_IN_BITS; }
		else if(type == CHAR_STRING) {temp->type->dataType = DT_STRING; temp->type->leftEnd = TYPE_SIZE_IN_BITS;}
		
		temp->next = NULL;
		*head = temp;
	}
	else {
		  while(temp->next != NULL) {
			  if(strcasecmp(temp->lexeme,s) == 0 && temp->myScope == inScopeStack->val ) {
				  flag = 1; return 0;
				  break;
			  }
			  temp = temp->next;
		  }
		  if(strcasecmp(temp->lexeme,s) == 0 && temp->myScope == inScopeStack->val ) {
				flag = 1; return 0;
		}
		
		if(flag == 0) {	
			r = (sym *)malloc(sizeof(sym));
			r->lexeme=malloc(strlen(s)+1);
			strcpy(r->lexeme,s);
			r->line = line_no;
			r->next = NULL;
			r->token = type;
			r->offset = SizeOf(inScopeStack->val);
			r->type = (Type *)malloc(sizeof(Type));  
			r->myScope = inScopeStack->val;
			if(t !=NULL) {
				r->type = t;
			}
			if(type == INT ) { r->type->dataType = DT_INT; r->type->leftEnd = TYPE_SIZE_IN_BITS;}
			else if (type == REAL || type == FLOAT) { r->type->dataType = DT_REAL; r->type->leftEnd = TYPE_SIZE_IN_BITS; }
			else if(type == CHAR_STRING) {temp->type->dataType = DT_STRING; temp->type->leftEnd = TYPE_SIZE_IN_BITS;}
		
			temp->next = r;
			
		}
		
	}
	return 1;
}

sym* getEntry(char* text, stack *inScopeStack){
	int hash = hashKey(text);
	if(hash == -1 || inScopeStack == NULL)
		return NULL;
	sym* temp = table[hash];
	sym *r ;
	r = (sym *)malloc(sizeof(sym));
	r = NULL;
	while(temp != NULL) {
		if(strcasecmp(text,temp->lexeme)==0  && matchScope(temp->myScope,inScopeStack)!=0 ) {
			if(r == NULL || r->myScope < temp->myScope)
			{
				r = temp;
			}
		}
		temp = temp->next;
	}
	return r;
}

void Print() {
	printf(" \n *** Printing symbol table *** \n\n");
	sym *temp;
	int key;
	for(key = 0;key<256;key++) {
		temp = table[key];
		while(temp!= NULL && strcmp(temp->lexeme,"")!=0) {
			printf("Lexeme : %s ,Scope : %d, Line : %d , offset : %d",temp->lexeme,temp->myScope,temp->line,temp->offset);
			printf(" Type : "); printType(temp->type);
			printf("\n");
			temp = temp->next;
		}	
	}
	printf(" \n *** End of symbol table *** \n\n");
}

char* get_new_temp(int scopeId){
	char* temp = malloc(5);
	sprintf(temp,"_t_%d",tempId);
	tempArray[tempId] =  SizeOf(scopeId);
	tempId++;
	return temp;	
}

