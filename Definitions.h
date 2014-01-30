#define TYPE_SIZE_IN_BITS	5
#define MAX_TEMP_SIZE	1000
#define DT_VOID	 	0x0
#define DT_INT 	 	0x1
#define DT_CHAR 	0x2
#define DT_REAL 	0x3	
#define	DT_SINGLE	0x4
#define	DT_DOUBLE	0x5
#define DT_BOOL 	0x6
#define DT_SUBR 	0x7
#define DT_STRING	0x8
#define DT_ERROR	0x9
#define DT_OBJ		0xA
#define DT_CLASS	0xB
#define DT_REC		0xC
#define DT_CONST	0xD
#define DT_ARR 	 	0xE
#define DT_PTR 	  	0xF
#define DT_FUNCTION 	0x10
#define DT_PROC    	0x11

#define SIZE_VOID	0
#define SIZE_INT 	4
#define SIZE_CHAR 	4
#define SIZE_REAL 	8	
#define SIZE_BOOL 	4
#define SIZE_SUBR 	1
#define SIZE_STRING	1
#define	SIZE_SINGLE	4
#define	SIZE_DOUBLE	8
#define SIZE_PTR 	4

#define MAX_SYMBOLS 256

#define MAX_SCOPES 100

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct code
{
	char* op;
	char* res;
	char* arg1;
	char* arg2;
}code;

code* codelist[2400]; // will be an array containing the entired intermediate code

typedef struct node
{
	int val;
	struct node* next;
}stack; // current stack of scopes

stack* scopeStack;

typedef struct Header{
	unsigned int size;
}header;

header *scopeHeader[MAX_SCOPES];

typedef struct list
{
	int addr;
	struct list *next;
}List;

typedef struct Type
{
	int leftEnd;                  // the bit number uptill where the type has been calculated  
	unsigned long dataType;       // type of the node 	
	struct Type* next; // use it
	char *entry; // iski sym table entry ka lexeme
	unsigned int attScope;
	int counter;
	int width; // size of this dataType
	int flag;
	int maxIndex;
	int low;
	char* place; // for place in 3 address code
	char* code; // for 3 address code
	int funcAttScope;
	List* truelist;
 	List* falselist;	
	List* nextlist;
}Type;

typedef struct symbolTable{
	char *lexeme;
	int token;
	Type* type;
	int line;
	int offset;
	//int access;
	unsigned int myScope;
	struct symbolTable *next;
}sym;

sym *table[MAX_SYMBOLS];
void make_new_list(Type *a,Type **head);
void printType( Type* t);
void append_to_list(Type *a,Type **head); 
Type* getArithType( Type* t1, Type* t2);
Type* getSubType(Type* t);
void Push(stack** x, int y);
stack* Pop(stack ** given );
void initialize_type(Type* x);
Type *setType(Type* inType);
Type* setBasicType(int inType); 
void augmentType(Type** x,int inType);
char* get_new_temp(int);
char* create_new_label();
Type* CopyType(Type*);
Type* CopyType2(Type*);

void emitcode(char *operation, char * operand1, char * operand2, char * operand3 ); 
List* merge(List *list1, List *list2);/*Return a new list in which list2 has been added to the end of list1*/
void BackPatch(List*L, int k ); 
List* create_new_list(int k);
void printCode(); // prints intermediate code into terminal (later change it to a file)
//void Codegen(); // prints final code into a file
//void load_argument(char *,char *); // load into string char* , the value in register $(t)int
//void store_argument(char *,char *);
//void load_argumentR(char *,char *); // load into string char* , the value in register $(f)int
//void store_argumentR(char *,char *);
//void move_argument(char *,char *);
void ChangeLabel(char*,int);
//void store_argumentReturnVal(char*,int);
//void restore_argumentState();
//void saveState();

void Add(int, unsigned int);
unsigned int SizeMap(Type *);
unsigned int SizeOf(int);
void PrintHeader();
int hashKey(char *);
int NewEntry(char *,int, int,sym **,stack *, Type *);
void Print();
sym *getEntry(char *,stack *);
int matchScope(unsigned int,stack *);
