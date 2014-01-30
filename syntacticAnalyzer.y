%{
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Definitions.h"

extern char *yytext;
extern int yyleng;
extern int line_number;
extern unsigned int curScopeId;
extern unsigned int quadId;
extern int ifFlag;
extern FILE *data,*text;

void yyerror(char * error);

int errorFree = 1;
int errorFreeType = 1;
int flag = 1,counter = 0;
int numError = 0;
int numTypeError=0;
int i;
char tempName[256];
void errorLog();
%}

%union {     // UNION DEFINITION FOR YYLVAL
  int ival; 
  double dval;
  char name[256];
  Type* type;
}

%token ABSOLUTE CONSTRUCT DESTRUCT INHERITED IMPLEMENT INLINE INTERFACE OBJ ON OP REINTRO SELF
%token SHL SHR STRING UNIT USES XOR CLASS EXCEPT EXPORTS FINALIZATION FINALLY OUT PROPERTY
%token RAISE THREADVAR TRY DISPOSE EXIT FALS NEW TRU AND ARRAY CASE CONST DIV DO DOWNTO ELSE END EXTERN 
%token FOR FORWARD FUNC GOTO IF LABEL MOD NOT NIL OF OR OTHERWISE PACKED PBEGIN PROCEDURE PFILE PROGRAM RECORD
%token SET REPEAT THEN TO TYPE UNTIL VAR WHILE WITH ABSTRACT ALIAS ASSEMBLER CDECL CPPDECL DEFAULT EXPORT FAR FAR16
%token INDEX LOCAL NAME NEAR NOSTACKFRAME OLDFPCCALL PASCAL PRIVATE PROTECTED PUBLIC PUBLISHED READ REGISTER
%token SAFECALL SOFTFLOAT STDCALL VIRTUAL WRITE WRITELN ASSIGN COLON COMMA DOT DOTDOT PTRUE PFALSE
%token EQUAL GE GT LE LT LSQBRACK RSQBRACK LPAREN RPAREN MINUS NOTEQUAL PLUS SEMICOLON SLASH STAR  
%token STARSTAR UPARROW EXCLA BITNOT BITAND BITOR DOLLAR PERCENT HASH ATTHERATE OVERRIDE
%token IMPLEMENTATION RESOURCESTRING LIBRARY RESIDENT INITIALIZATION PACKAGE REQUIRES CONTAINS ADDROF
%token DISPINTERFACE READONLY WRITEONLY NODEFAULT store_argumentD IMPLEMENTS MESSAGE EXTERNAL ASMBODY AT ASCIICHAR REAL48
%token SINGLE DOUBLE REALS EXTENDED CURRENCY COMP SHORTINT SMALLINT QWORD BYTE LONGINT INT64 WORD BOOLEAN CHAR
%token WIDECHAR LONGWORD PCHAR CARDINAL OLEVARIANT ANSISTR WIDESTR AUTOMATED DYNAMIC OVERLOAD VARIANT INTEGER
%token <name> IDENT OCTAL BINARY HEXA CHAR_STRING
%token <ival> INT
%token <dval> FLOAT REAL
%nonassoc IFX
%nonassoc ELSE

%type <type> const_expr const_simple_expr const_term const_factor const_variable const_variable_2 unsigned_number type_decl type_decl_type type_ref simple_type range_expr range_term range_factor simple_type_identifier sign arr_simple_type pointer_type structured_type unpacked_structured_type array_type  record_type  string_type literal real_type_name ord_type_name  string_type_name  visibility_specifier typed_const object_type procedural_type stmt unlabelled_stmt assignment proc_call  compound_stmt stmt_list if_stmt then_branch else_branch case_stmt case_list case_item case_label_list case_label  else_case repeat_stmt while_stmt for_stmt asm_stmt expr_list expr simple_expr addop const_addop term factor  var_reference variable var_specifiers elem field_list fixed_part fixed_part_2 record_section procedural_type_kind procedural_type_decl fp_list fptype var_name_list var_init_value var_name identifier property_specifier_directives other non_reserved record_section_id record_section_id_list fp_sect_list fp_sect param_name_list fptype_new  param_name proc_name proc_heading func_heading func_name old_object_type oot_successor oot_typeidentifier oot_field_list oot_field oot_id_list oot_field_identifier oot_method_list oot_method oot_method_head oot_constructor_head oot_destructor_head oot_component_list oot_privat_list 

%type <type> const_relop const_mulop relop mulop Marker2 for_special 
%type <ival> Marker Marker3 proc_block func_block proc_block_decl asm_block block
%type <ival> var_address arr_factor 


%%
Goal : program_file { if(errorFree == 1 && errorFreeType==1) printf(" **** compiled  %d lines successfully\n",line_number); else errorLog();	}
  ; 
  
error_recovery_token : INTERFACE 
  | IMPLEMENTATION 
  | VAR 
  | CONST 
  | TYPE 
  | RESOURCESTRING 
  | OBJ 
  | FUNC 
  | PROCEDURE 
  | PBEGIN 
  | SEMICOLON 
  | END 
  ; 
  
program_file : program_heading program_block DOT 
  ; 
  
program_heading :  
  | PROGRAM program_name program_heading_2 
  ; 
  
program_heading_2 : SEMICOLON 
  | LPAREN program_param_list RPAREN SEMICOLON 
  ; 
  
// adding program name to symbol  table with basic type as void
program_name : IDENT 
	{
		NewEntry($1, IDENT, line_number, &table[hashKey($1)], scopeStack, setBasicType(DT_VOID));
	}
  ; 
  
program_param_list : program_param 
  | program_param_list COMMA program_param 
  ; 
  
//adding program parameters to symbol table with type void and adding the size of scope by size of void since the parametrs are useful and to be store_argumentd 
program_param : IDENT 
	{
		NewEntry($1,IDENT,line_number,&table[hashKey($1)],scopeStack,setBasicType(DT_VOID));Add(scopeStack->val,SIZE_VOID);
	}
  ; 
  
program_block : program_decl_sect_list Marker3 compound_stmt
	{
		ChangeLabel("main",$2);
	}
 ; 
  
program_decl_sect_list : impl_decl_sect_list 
  ; 
  

impl_decl_sect_list :  
  | impl_decl_sect_list impl_decl_sect 
  ; 
  
impl_decl_sect :  const_decl_sect 
  | type_decl_sect 
  | var_decl_sect 
  | proc_decl 
  | func_decl 
  ; 
  
const_decl_sect : CONST const_decl 
  | const_decl_sect const_decl 
  ; 
  

type_decl_sect : TYPE type_decl 
  | type_decl_sect type_decl 
  ; 
  
var_decl_sect : VAR var_decl {}
  | var_decl_sect var_decl 
  ; 
  
const_decl : IDENT EQUAL const_expr SEMICOLON 
	{
		if($3->dataType == DT_ERROR )   // if error then make errorfreetype flag to zero 
		{ 
			NewEntry($1,CONST,line_number,&table[hashKey($1)],scopeStack,$3); 
			errorFreeType = 0;
		}
		else  // adding entry to sym table , making token to const if variable found again, adding size of scope
		{ 
			NewEntry($1,CONST,line_number,&table[hashKey($1)],scopeStack,$3);
		 	getEntry($1,scopeStack)->token = CONST; 
			Add(scopeStack->val,$3->width);
		} 
	}
 | IDENT COLON type_ref EQUAL typed_const SEMICOLON 
	{
		NewEntry($1,CONST,line_number,&table[hashKey($1)],scopeStack,NULL); 	//adding entry to sym table
		if (typeCheck(getEntry($1,scopeStack)->type,$3) == 0) {		//if type check fails
			if(conversionTypeCheck(getEntry($1,scopeStack)->type,$3) == 0)		//if type conversion fails
				{ getEntry($1,scopeStack)->type = setBasicType(DT_ERROR); errorFreeType = 0; }	///Error
			else
				{ getEntry($1,scopeStack)->type = $3; augmentType(&(getEntry($1,scopeStack)->type),DT_CONST); Add(scopeStack->val,$3->width);  }	//changing type to const
		} 
		else {	//changing type to const
			 getEntry($1,scopeStack)->type = $3; 
			augmentType(&(getEntry($1,scopeStack)->type),DT_CONST); 		
			Add(scopeStack->val,$3->width);
   		}
	}
 | error error_recovery_token	
  ; 
  
const_expr : const_simple_expr
	{
		$$ = $1;
	}
  | const_simple_expr const_relop const_simple_expr 
	{
		 flag = 1; 
		if ($1->dataType == DT_ERROR || $1->dataType == DT_ERROR) { flag =0;  }		//erroroneous data types
		else 
		{	
				if( Club($1) != Club($3) || Club($1) == DT_VOID )			//if not comparable
				 {
					flag = 0; printf("(Line %d) Incompatible types in relop const_expr\n",line_number);
				 	printType($1); printType($3); 
				}
	 	}
		if(flag == 0)		//if error found
		{
			$$ = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
		}
		else 		//making bool type and calculating the boolean value
		{
			$$ = setBasicType(DT_BOOL);
			$$->truelist = create_new_list(quadId);
			$$->falselist = create_new_list(quadId+1);
			sprintf(tempName,"if %s %s %s",$1->place,$2->entry,$3->place);
			emitcode("Cgoto",NULL,"---",tempName); // special case for emit
			emitcode("goto",NULL,"---",NULL);
		}
}
  ; 
  
const_relop : EQUAL {$$ = setBasicType(DT_VOID);	$$->entry = "=";}
  | NOTEQUAL {$$ = setBasicType(DT_VOID);	$$->entry = "<>";}
  | LT {$$ = setBasicType(DT_VOID);	$$->entry = "<";}
  | GT {$$ = setBasicType(DT_VOID);	$$->entry = ">";}
  | LE {$$ = setBasicType(DT_VOID);	$$->entry = "<=";}
  | GE {$$ = setBasicType(DT_VOID);	$$->entry = ">=";}
  ; 
  
const_simple_expr : const_term 
	{
		$$=$1;
	}
  | const_simple_expr const_addop Marker const_term 
	{
		if(strcmp($2->entry,"OR")==0 && $1->dataType == DT_BOOL && $4->dataType == DT_BOOL) 	//if operator is OR then set type to bool
		{
			$$ = setBasicType(DT_BOOL);
			BackPatch($1->falselist,$3);
			$$->truelist = merge($1->truelist,$4->truelist);
			$$->falselist = $4->falselist;
		}
		else if(ClubTypeCheck($1,$4) == 0)			//if types incomparable then error
		{
			$$ = setBasicType(DT_ERROR); 
			numTypeError++;errorFreeType = 0;
			printf("(Line %d) Type Error in constant expression\n",line_number);
		}
		else
		{
			$$ =setType(getArithType($1,$4)); 		//find type of resulting expression
			$$->place = get_new_temp(scopeStack->val);		//setting a temporary variable to store_argument the value of expression
			Add(scopeStack->val,$$->width);  // for $$->place 's get_new_temp
			if($1->dataType == DT_INT && $4->dataType == DT_INT) 
			{
				sprintf(tempName,"%s%s","int",$2->entry);
				emitcode(tempName,$$->place,$1->place,$4->place);
			}
			else if($1->dataType == DT_REAL && $4->dataType == DT_REAL) 
			{
				sprintf(tempName,"%s%s","real",$2->entry);
				emitcode(tempName,$$->place,$1->place,$4->place);
			}
			if($1->dataType == DT_INT && $4->dataType == DT_REAL) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);		//creating a temporary variable for type conversion
				emitcode("<IntToReal>",u,$1->place,NULL);
				sprintf(tempName,"%s%s","real",$2->entry);
				emitcode(tempName,$$->place,u,$4->place);
			}
			if($1->dataType == DT_REAL && $4->dataType == DT_INT) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
				emitcode("<IntToReal>",u,$4->place,NULL);
				sprintf(tempName,"%s%s","real",$2->entry);
				emitcode(tempName,$$->place,$1->place,u);
			}	
		}
	}
  ; 
  
const_addop : PLUS  { $$ = setBasicType(DT_VOID);	$$->entry = "+";}
  | MINUS { $$ = setBasicType(DT_VOID);	$$->entry = "-";}
  | OR { $$ = setBasicType(DT_VOID);	$$->entry = "OR";}
  | XOR { $$ = setBasicType(DT_VOID);	$$->entry = "XOR";}
  ; 
  
const_term : const_factor 
	{
		$$=$1;
	}
  | const_term const_mulop Marker const_factor 
	{
		flag=1;
		if(strcmp($2->entry,"AND")==0 && $1->dataType == DT_BOOL && $4->dataType == DT_BOOL)		//if boolean
		 {
			$$ = setBasicType(DT_BOOL);
			BackPatch($1->truelist,$3);
			$$->truelist = $4->truelist;
			$$->falselist = merge($1->falselist,$4->falselist);
		}
		else if(ClubTypeCheck($1,$4)== 0)		//if error
		{
			printf("(Line %d) Type Error in constant expression\n",line_number); flag =0 ;
		}
		else 
		{
			if($2->counter ==STAR ||  $2->counter == SLASH || $2->counter == DIV) 		//if arithmetic operator
			{ 
				$$ = setType(getArithType($1,$4)); 
				$$->place = get_new_temp(scopeStack->val);			//create temp variable for storing result of expression
				Add(scopeStack->val,$$->width); 					// for get_new_temp of $$
				if($1->dataType == DT_INT && $4->dataType == DT_INT) 
				{
					sprintf(tempName,"%s%s","int",$2->entry);
					emitcode(tempName,$$->place,$1->place,$4->place);
				}
				else if($1->dataType == DT_REAL && $4->dataType == DT_REAL) {
					sprintf(tempName,"%s%s","real",$2->entry);
					emitcode(tempName,$$->place,$1->place,$4->place);
				}
				if($1->dataType == DT_INT && $4->dataType == DT_REAL) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);		//temporary variable for type casting
					emitcode("<IntToReal>",u,$1->place,NULL);
					sprintf(tempName,"%s%s","real",$2->entry);
					emitcode(tempName,$$->place,u,$4->place);
				}
				if($1->dataType == DT_REAL && $4->dataType == DT_INT) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);		//temporary variable for type casting
					emitcode("<IntToReal>",u,$4->place,NULL);
					sprintf(tempName,"%s%s","real",$2->entry);
					emitcode(tempName,$$->place,$1->place,u);
				}			
			} 
			else if($2->counter == MOD || $2->counter== SHR || $2->counter == SHL) 		//if bit operators
			{
				if(strictClub($1) == DT_INT && strictClub($4) == DT_INT ) 		//if type checked strictly
				{
					$$ = setBasicType(DT_INT);
					$$->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,$$->width); // for get_new_temp of $$
					emitcode($2->entry,$$->place,$1->place,$4->place);
				}
				 else 
				{ 
					flag =0; printf("(Line %d) Type Error in constant expression\n",line_number);
				}
			} 
			else if($2->counter == AND)
			 { 
				if($1->dataType == DT_INT && (typeCheck($1,$4) ==1)) 
				{
					$$ = setBasicType(DT_INT);
					$$->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,$$->width); // for get_new_temp of $$
					emitcode("AND",$$->place,$1->place,$4->place);
				}
				else
				{
					printf("(Line %d) Type Error in constant expression\n",line_number); flag = 0; 
				} 
			}
			if (flag == 0) { $$ = setBasicType(DT_ERROR);  numTypeError++;errorFreeType = 0; }
		} 	
	}
  ; 
  
const_mulop : STAR   {$$ = setBasicType(DT_VOID);	$$->entry = "*"; $$->counter = STAR;} 
  | SLASH {$$ = setBasicType(DT_VOID);	$$->entry = "/"; $$->counter = SLASH;}
  | DIV {$$ = setBasicType(DT_VOID);	$$->entry = "/"; $$->counter = DIV;}
  | MOD {$$ = setBasicType(DT_VOID);	$$->entry = "MOD"; $$->counter = MOD;}
  | SHL {$$ = setBasicType(DT_VOID);	$$->entry = "SHL"; $$->counter = SHL;}
  | SHR {$$ = setBasicType(DT_VOID);	$$->entry = "SHR"; $$->counter = SHR;}
  | AND {$$ = setBasicType(DT_VOID);	$$->entry = "AND"; $$->counter = AND;}
 ; 
  
const_factor : const_variable {$$=$1;}
  | unsigned_number {$$=$1;}
  | literal {$$=$1;}
  | NIL  {$$ = setBasicType(DT_VOID);}
  | ADDROF const_factor  {$$ = $2; augmentType(&$$,DT_PTR);}
  | LPAREN const_expr RPAREN {$$ = $2;}
  | NOT const_factor 
	{
		$$ = setType($2);
		$$->truelist = $2->falselist;
		$$->falselist = $2->truelist; 
		sprintf(tempName,"%s %s","NOT",$2->place);
		$$->place = tempName;
	}
  | sign const_factor  {$$ = $2;}
  | UPARROW const_factor  {$$ = $2; augmentType(&$$,DT_PTR); }
  | PTRUE 
	{
		$$ = setBasicType(DT_BOOL); 
		$$->place = "TRUE";
		if(ifFlag == 1) 
		{
			$$->truelist = create_new_list(quadId); 
			emitcode("goto",NULL,"---",NULL); 
		}
	}
  | PFALSE 
	{
		$$ = setBasicType(DT_BOOL); 
		$$->place = "FALSE";
		if(ifFlag == 1) 
		{
			$$->truelist = create_new_list(quadId); 
			emitcode("goto",NULL,"---",NULL); 
		}
	}
  ; 
  
sign : PLUS {$$ = setBasicType(DT_VOID); $$->code= "+";}
  | MINUS {$$ = setBasicType(DT_VOID); $$->code = "-"; }
  ; 
  
const_variable : identifier {$$=$1;}
  | const_variable const_variable_2
	{
		if($2->dataType == DT_VOID) $$ = getSubType($1);		//find the sub type if dereferenced or parameter 
 		else $$ = $2; 		//find the type of field
	} 
  ; 
  
const_variable_2 : DOT identifier {$$ = $2;}
  | UPARROW {$$ = setBasicType(DT_VOID);}
  | LPAREN const_func_expr_list RPAREN  {$$ = setBasicType(DT_VOID);}
  ; 
  
const_func_expr_list : const_expr 
  | const_expr COMMA const_expr 
  ; 
  
unsigned_number : INT 
	{
		$$ = setBasicType(DT_INT); 
		$$->code = ""; 
		$$->place = (char *)malloc(10*sizeof(char)); 
		sprintf($$->place,"%d",$1); 		//saving value of number in place
	}
  | FLOAT 
	{
		$$ = setBasicType(DT_INT); 
		$$->place = (char *)malloc(10); 
		sprintf($$->place,"%f",$1); 
	}
  ; 
  
typed_const : const_expr {$$ = $1;}
  ; 

type_decl : IDENT EQUAL type_decl_type SEMICOLON 	//adding entry to sym table and setting basic type of statement to void
	{
		NewEntry($1,TYPE,line_number,&table[hashKey($1)],scopeStack,$3); /*Add(scopeStack->val,$3->width);*/
		$$ = setBasicType(DT_VOID);  
	}
  | error error_recovery_token {$$ = setBasicType(DT_VOID);}
  ; 
  
type_decl_type : type_ref {$$=$1;}
  | TYPE type_ref  {$$=$2;}
  | object_type {$$=$1;}
  ; 
  
type_ref : simple_type {$$=$1;}
  | string_type {$$=$1;}
  | pointer_type {$$=$1;}
  | structured_type {$$=$1;}
  | procedural_type {$$=$1;}
  ; 
  
simple_type : ord_type_name  {$$=$1;}
  | real_type_name {$$=$1;}
  | simple_type_identifier {$$=$1;}
  | range_expr DOTDOT range_expr 
	{
		if(strictClub($1) == strictClub($3)) 
			$$ = $1; 
		else 
		{ 
			$$ = setBasicType(DT_ERROR);  
			numTypeError++;errorFreeType = 0;  
		}
	}
  ; 
  
range_expr : range_term {$$ = $1;}
  | range_expr const_addop Marker range_term
	{
		if(strcmp($2->entry,"OR")==0 && $1->dataType == DT_BOOL && $4->dataType == DT_BOOL)
		 {
			$$ = setBasicType(DT_BOOL);
			BackPatch($1->falselist,$3);
			$$->truelist = merge($1->truelist,$4->truelist);
			$$->falselist = $4->falselist;
		}
		else if(ClubTypeCheck($1,$4) == 0)
		{ 
			 numTypeError++;errorFreeType = 0;  $$ = setBasicType(DT_ERROR); printf("(Line %d) Type Error in constant expression\n",line_number);
		}
		else
		{
			$$ =setType(getArithType($1,$4)); 
			$$->place = get_new_temp(scopeStack->val);
			Add(scopeStack->val,$$->width);  // for $$->place 's get_new_temp
			if($1->dataType == DT_INT && $4->dataType == DT_INT) 
			{
				sprintf(tempName,"%s%s","int",$2->entry);
				emitcode(tempName,$$->place,$1->place,$4->place);
			}
			else if($1->dataType == DT_REAL && $4->dataType == DT_REAL) 
			{
				sprintf(tempName,"%s%s","real",$2->entry);
				emitcode(tempName,$$->place,$1->place,$4->place);
			}
			if($1->dataType == DT_INT && $4->dataType == DT_REAL) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
				emitcode("<IntToReal>",u,$1->place,NULL);
				sprintf(tempName,"%s%s","real",$2->entry);
				emitcode(tempName,$$->place,u,$4->place);
			}
			if($1->dataType == DT_REAL && $4->dataType == DT_INT) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
				emitcode("<IntToReal>",u,$4->place,NULL);
				sprintf(tempName,"%s%s","real",$2->entry);
				emitcode(tempName,$$->place,$1->place,u);
			}			
		} 
	}  
  ; 
  
range_term : range_factor {$$ = $1;}
  | range_term const_mulop Marker range_factor 
	{
		flag=1;
		if(strcmp($2->entry,"AND")==0 && $1->dataType == DT_BOOL && $4->dataType == DT_BOOL) {
			$$ = setBasicType(DT_BOOL);
			BackPatch($1->truelist,$3);
			$$->truelist = $4->truelist;
			$$->falselist = merge($1->falselist,$4->falselist);
		}	
		else if(ClubTypeCheck($1,$4)== 0){
			printf("(Line %d) Type Error in constant expression\n",line_number); flag =0 ;
		}
		else 
		{
			if($2->counter ==STAR ||  $2->counter == SLASH || $2->counter == DIV) 
			{ 
				$$ = setType(getArithType($1,$4)); 
				$$->place = get_new_temp(scopeStack->val);
				Add(scopeStack->val,$$->width); // for get_new_temp of $$
				if($1->dataType == DT_INT && $4->dataType == DT_INT)
				{
					sprintf(tempName,"%s%s","int",$2->entry);
					emitcode(tempName,$$->place,$1->place,$4->place);
				}
				else if($1->dataType == DT_REAL && $4->dataType == DT_REAL) 
				{
					sprintf(tempName,"%s%s","real",$2->entry);
					emitcode(tempName,$$->place,$1->place,$4->place);				
				}
				if($1->dataType == DT_INT && $4->dataType == DT_REAL) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
					emitcode("<IntToReal>",u,$1->place,NULL);
					sprintf(tempName,"%s%s","real",$2->entry);
					emitcode(tempName,$$->place,u,$4->place);
				}
				if($1->dataType == DT_REAL && $4->dataType == DT_INT) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
					emitcode("<IntToReal>",u,$4->place,NULL);
					sprintf(tempName,"%s%s","real",$2->entry);
					emitcode(tempName,$$->place,$1->place,u);
				}		
			} 
			else if($2->counter == MOD || $2->counter== SHR || $2->counter == SHL) 
			{
				if(strictClub($1) == DT_INT && strictClub($4) == DT_INT ) 
				{
					$$ = setBasicType(DT_INT);
					$$->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,$$->width); // for get_new_temp of $$
					emitcode($2->entry,$$->place,$1->place,$4->place);
				}
				else 
				{ 
					flag =0; printf("(Line %d) Type Error in constant expression\n",line_number);
				}
			} 
			else if($2->counter == AND) 
			{ 
				if($1->dataType == DT_INT && (typeCheck($1,$4) ==1)) 
				{
					$$ = setBasicType(DT_INT);
					$$->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,$$->width); // for get_new_temp of $$
					emitcode("AND",$$->place,$1->place,$4->place);
				}
				else 	
				{
					printf("(Line %d) Type Error in constant expression\n",line_number); flag = 0; 
				} 
			}
			if (flag == 0) { $$ = setBasicType(DT_ERROR);  numTypeError++;errorFreeType = 0; }
		} 
	}
  ; 
  
range_factor : identifier {$$=$1;}
  | unsigned_number {$$=$1;}
  | sign range_factor {$$=$1;}
  | literal {$$=$1;}
  | identifier LPAREN const_expr RPAREN {$$=$1;}
  | LPAREN const_expr RPAREN {$$=$2;}
  ; 
  
simple_type_identifier : IDENT 
	{
		flag =0;
		sym* temp;
	 	temp = getEntry($1,scopeStack);
		if(temp == NULL)
		{
			$$ = setBasicType(DT_ERROR);  
			numTypeError++;errorFreeType = 0;  
			printf("(Line %d) Type Error : Not a type\n", line_number);
		}
		else	
		{
			if( temp->token == TYPE) 
			{ 
				$$ = temp->type; 
			}
			else 
			{ 
				printf("(Line %d) Type error : %s is not a type \n",line_number, temp->lexeme);
				$$ = setBasicType(DT_ERROR);  numTypeError++;errorFreeType = 0; 
			}
		}
	}
  ; 
  
pointer_type : UPARROW identifier {$$ = $2; augmentType(&$$,DT_PTR); }
  ; 
  
structured_type : unpacked_structured_type {$$ = $1;}
  | PACKED unpacked_structured_type  {$$ = $2;}
  ; 
  
unpacked_structured_type : array_type {$$ = $1;}
  | record_type {$$ = $1;}
  ; 
  
array_type  : ARRAY LSQBRACK arr_simple_type RSQBRACK OF type_ref 
	{
		$$ = CopyType($6); 
		augmentType(&$$,DT_ARR); 
		$$->width = $6->width * $3->maxIndex;	//type width times maximum index store_argumentd in width, width contains size
		$$->low = $3->low;		//low index
		$$->maxIndex = $3->maxIndex;		//max index
		$$->next = $6;		//mext type referrence
		Type* temp;
		temp = $$;
		while(temp!=NULL)
		{
			temp = temp->next;
		}
	}
  ; 
  
arr_simple_type : arr_factor DOTDOT arr_factor 
	{
		$$ = setBasicType(DT_VOID);
		$$->maxIndex = $3-$1 + 1;
		$$->low = $1;
	}
;

arr_factor : INT {$$=$1;}
;

record_type : RECORD field_list END 
	{
		$$ = setBasicType(DT_REC); 		//next store_arguments the field list in record
		$$->width = SizeOf(scopeStack->val);
		$$->next = $2;	
		$$->attScope = scopeStack->val;
		Pop(&scopeStack);		//popping scope to return out of record
	}
  ; 
  
field_list : fixed_part {$$=$1;}
  ; 
  
fixed_part : fixed_part_2 {$$=$1;}
  | fixed_part_2 SEMICOLON {$$=$1;}
  ; 
  
fixed_part_2 : record_section {$$=$1;}
  | fixed_part_2  SEMICOLON record_section { append_to_list($1,&$3); $$ = $3; }
  ; 
  
record_section : record_section_id_list COLON type_ref 
	{
		Type* head; 
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		sym* tempEntry;
		temp = $1; 
		for(i = 1; i<= $1->counter;i++) 	//adding record identifiers in next, counter holds the number of identifiers
		{
			tempEntry = getEntry((temp->entry),scopeStack);
 			tempEntry->type = $3;
			tempEntry->offset = SizeOf(scopeStack->val);		//size of returns the size of scope from scope headers and hence getting the offset
			Add(scopeStack->val,$3->width);					//adding width to size of scope
			make_new_list($3,&head);		//adding type to identifiers
			temp = temp->next;
		}
		$$ = head;
	}
  ; 
  
record_section_id_list : record_section_id { $$ = $1; $$->counter = 1;}
  | record_section_id COMMA record_section_id_list { $1-> next = $3; $$ = $1;   $$->counter = $3->counter + 1;  }
  ; 

record_section_id : IDENT
	{
		NewEntry($1,IDENT,line_number,&table[hashKey($1)],scopeStack,NULL); 
		$$ = setBasicType(DT_VOID);   
		$$->entry = getEntry($1,scopeStack)->lexeme; 
	} 
  ; 
 
string_type : string_type_name {$$ = $1;}
  | STRING LSQBRACK const_expr RSQBRACK {$$ = setBasicType(DT_STRING);}
  ; 
  
procedural_type : procedural_type_kind {$$=$1;}
  ; 
  
procedural_type_kind : procedural_type_decl {$$=$1;}
  | procedural_type_decl OF OBJ {$$=$1;}
  ; 
  
procedural_type_decl : PROCEDURE fp_list 
	{
		if($2->dataType == DT_ERROR) 
		{ 
			$$ = setBasicType(DT_ERROR);  
			numTypeError++;errorFreeType = 0;  
		}
		else 
		{ 
			$$ = setBasicType(DT_PROC);		
		}
	}
  | FUNC fp_list COLON fptype
	{
		 if($2->dataType == DT_ERROR) 
		{
			$$ = setBasicType(DT_ERROR);  
			numTypeError++;errorFreeType = 0;  
		}
		else 
		{ 
			$$ = setBasicType(DT_FUNCTION);
			$4->next = $2; 
			$$->next = $4;
		}
	}
  ; 
  
object_type : old_object_type {$$ = $1;}
  ; 
  
old_object_type : OBJ oot_successor oot_component_list oot_privat_list END 
	{
		$$ = setBasicType(DT_OBJ);  
		$$->width = SizeOf(scopeStack->val);
		$$->attScope = scopeStack->val ;
		if($2 != NULL) 		//appending next's info
		{ 
			append_to_list($3,&$2); 
			append_to_list($4,&$2); 
			$$->next = $2; 
		}
		else if($3 != NULL) 
		{
			append_to_list($4,&$3); $$->next = $3;
		}
		else $$->next = $4;
		Pop(&scopeStack);
	}
  ; 
  
oot_privat_list :  {$$=NULL;}
  | PRIVATE oot_component_list 
	{
		Type* temp;
		temp = $2;
		while(temp != NULL) 
		{
			if(getEntry(temp->entry,scopeStack) != NULL) 
				getEntry(temp->entry,scopeStack)->token = PRIVATE;
			temp=temp->next;
		}
		$$ = $2;
	}
  ; 
  
oot_component_list :  {$$ = NULL;}
  | oot_field_list  {$$ = $1;}
  | oot_field_list oot_method_list  { append_to_list($2,&$1); $$ = $1;}
  | oot_method_list {$$ = $1;}
  ; 
  
oot_successor : LPAREN oot_typeidentifier RPAREN 		//adding scope to a temporary stack, USE OF TEMPORARY STACK ??
	{
		Type* temp = $2->next;
		sym* symEntry;
		stack* tempStack;
		Push(&tempStack,$2->attScope);
		while(temp!= NULL) 
		{		
			symEntry = getEntry(temp->entry,tempStack);
			if(symEntry != NULL) 
			{
				NewEntry(symEntry->lexeme,symEntry->token,symEntry->line,&table[hashKey(symEntry->lexeme)],scopeStack,symEntry->type);
				Add(scopeStack->val,symEntry->type->width);
			}
			temp = temp->next;
		}
		$$ = $2->next;
	}
   | {$$=NULL;}
  ; 
  
oot_typeidentifier : identifier {$$ = $1; }
  ; 
  
oot_field_list : oot_field {$$ = $1; }
  | oot_field_list oot_field  { append_to_list($2,&$1); $$ = $1; }
  ; 
  
oot_field : oot_id_list COLON type_ref SEMICOLON 		//same as adding record id section above CHECK LAST LINE IN BOTH ,WHY NEXT NOW HERE ?
	{
		Type* head; 
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		sym* tempEntry;
		temp = $1; 
		for(i = 1; i<= $1->counter;i++) 
		{
			tempEntry = getEntry((temp->entry),scopeStack);
			tempEntry->type = setType($3);
			tempEntry->offset = SizeOf(scopeStack->val);
			Add(scopeStack->val,$3->width);
			make_new_list($3,&head);
			temp = temp->next;
		}
		$$ = head;
		$$ -> next = $1;
	}
  ; 
  
oot_id_list : oot_field_identifier 
	{
		$$ = setType($1); 
		$$->next = NULL; 
		$$ = $1; 
		$$->counter = 1; 
	}
  | oot_field_identifier COMMA oot_id_list 
	{
		$1->next = $3; 
		$$ = $1; 
		$$->counter = $3->counter + 1;  
	}
  ; 
  
oot_field_identifier : IDENT 
	{
		NewEntry($1,IDENT,line_number,&table[hashKey($1)],scopeStack,NULL); 
		$$ = setBasicType(DT_VOID); 
		$$->entry = getEntry($1,scopeStack)->lexeme; 
	}
  ; 
  
oot_method_list : oot_method 
	{
		$$ = setType($1); 
		$$->next = NULL; 
		$$ = $1; 
		$$->counter = 1;
	}
  | oot_method oot_method_list 
	{
		$1-> next = $2; 
		$$ = $1;   
		$$->counter = $2->counter + 1; 
	}
  ; 
  
oot_method : oot_method_head {$$ = $1;}
  ; 
  
oot_method_head : proc_heading { $$ = $1;Pop(&scopeStack);}
  | func_heading { $$ = $1; Pop(&scopeStack);}
  | oot_constructor_head { $$ = $1; Pop(&scopeStack);}
  | oot_destructor_head { $$ = $1; Pop(&scopeStack);}
  ; 
  
oot_constructor_head : CONSTRUCT proc_name fp_list fp_directives {$$=$2;}		// WHY NOT ADDING $3 AND $4 TO NEXT OF $2
  ; 
  
oot_destructor_head : DESTRUCT proc_name fp_list fp_directives {$$=$2;}			// WHY NOT ADDING $3 AND $4 TO NEXT OF $2
  ; 

var_decl : var_name_list COLON type_ref SEMICOLON 
	{
		Type *temp; temp = $1;
		while(temp !=NULL) 
		{
			temp->dataType = $3->dataType;
			temp->leftEnd = $3->leftEnd;
			temp->attScope = $3->attScope;
			if(temp->entry != NULL) 
			{
				getEntry(temp->entry,scopeStack)->type = $3;
				getEntry(temp->entry,scopeStack)->type->attScope = $3->attScope;
				getEntry(temp->entry,scopeStack)->offset = SizeOf(scopeStack->val);
				Add(scopeStack->val,$3->width);
			}
			temp = temp->next;
		}
	}
  | var_name_list COLON type_ref EQUAL var_init_value SEMICOLON 
	{
		sym* tempEntry;
		if(typeCheck($3,$5)== 0) 
		{ 
			Type *temp; temp = $1; 
		       printf("(Line %d) Type error in var_decl \n",line_number);
			if(conversionTypeCheck($3,$5) == 0 ) 
			{
			       while(temp !=NULL) 
				{
					temp->dataType = DT_ERROR; temp->leftEnd = TYPE_SIZE_IN_BITS;
					temp = temp->next;
					 numTypeError++;errorFreeType = 0; 
				}
  			}
			else 
			{
				while(temp !=NULL) 
				{
					if(temp->entry != NULL)
					 {
						tempEntry = getEntry(temp->entry,scopeStack);
						tempEntry->type = setType($3);
						tempEntry->type->attScope = $3->attScope;
						tempEntry->offset = SizeOf(scopeStack->val);
						Add(scopeStack->val,$3->width);
					}
					temp = temp->next; 
				}		
			}
 		} 
		else 
		{ 
			Type *temp; temp = $1; 
			while(temp !=NULL) 
			{
				if(temp->entry != NULL) 
				{
					tempEntry = getEntry(temp->entry,scopeStack);
					tempEntry->type = setType($3);
					tempEntry->type->attScope = $3->attScope;
					tempEntry->offset = SizeOf(scopeStack->val);
					Add(scopeStack->val,$3->width);
				}
				temp = temp->next; 
			}
 		}
	}
  | var_name_list error error_recovery_token 
	{
		Type* temp; temp = $1; 
		while(temp !=NULL) 
		{
			temp->dataType = DT_ERROR; 
			temp->leftEnd = TYPE_SIZE_IN_BITS ;
			temp = temp->next; 
			numTypeError++;errorFreeType = 0;
		} 
	}
  ; 
  
var_init_value : typed_const {$$=$1;}
  ; 
  
var_name_list : var_name {$1->next=NULL; $$=$1;}
  |  var_name COMMA var_name_list {$1->next=$3; $$=$1;}
  ; 
  
var_name : IDENT 
	{
		NewEntry($1,IDENT,line_number,&table[hashKey($1)],scopeStack,NULL); 
		$$ = setBasicType(DT_VOID);
  		$$->entry = getEntry($1,scopeStack)->lexeme; 
	}
  ; 
  
proc_decl : proc_heading proc_block  
	{
		Pop(&scopeStack);			//popping scope since out of procedure
		emitcode("RETURN",$1->place,NULL,NULL); 
		ChangeLabel($1->place,$2);		//making the label of procedure body to proc name
	}
   ; 
  
func_decl : func_heading func_block 
	{
		Pop(&scopeStack);
		emitcode("RETURN",$1->place,NULL,NULL); 
		ChangeLabel($1->place,$2);
	}
 ; 
  
Marker3 : 
	{
		$$ = quadId;	
		emitcode("START",NULL,NULL,NULL);		//starting code since matched at start of program
	}
;
proc_heading : PROCEDURE proc_name fp_list fp_directives 
	{
		if($2->counter == -1)			//error in heading
		 {
			$$ = setBasicType(DT_ERROR);  
			numTypeError++;errorFreeType = 0; 	
		}
		else if($2->counter == -2) 		//correct heading
		{ 
			getEntry($2->entry,scopeStack)->type->next = $3;
			$2->next = $3;			//making proc parameters append to name list
			getEntry($2->entry,scopeStack)->type->attScope = scopeStack->val;
			$2->attScope = scopeStack->val;		//scope of proc 
			Type* temp = $2;
			while(temp != NULL)
			{
				temp = temp->next;
			}
			$$ = setBasicType(DT_PROC);		//setting type to proc
		}
		else 		//forward declaration of object's function
		{
			stack *tempStack;
			Push(&tempStack,$2->counter);		//push temp stack to find the ident of object, counter store_arguments the scope of object's declaration
			getEntry($2->entry,tempStack)->type->next = $3;
			$2->attScope = getEntry($2->entry,tempStack)->type->attScope;	//adding scope of list to proc name
			$2->next = $3;			//appending proc parameters to name
			Type* temp = $2;	
			while(temp != NULL)
			{
				temp = temp->next;
			}
			$$ = setBasicType(DT_PROC);
		}
		$$->entry = $2->entry;			//storing lexeme of proc name to  proc heading
		$$->place = $2->place;			//storing address of proc name to proc heading
	}
  | PROCEDURE proc_name error error_recovery_token {} // check
  ; 
  
proc_name : IDENT 
	{
		sym *temp;	
		stack *tempStack;
		Push(&tempStack,scopeStack->val);
		if(getEntry($1,tempStack) == NULL)			//if function name not declared
		{
	  		NewEntry($1,IDENT,line_number,&table[hashKey($1)],scopeStack,setBasicType(DT_PROC));			//creating a entry of type procedure
			Add(scopeStack->val,SIZE_PTR);				//adding size of ptr to scope
	 		curScopeId++;
			Push(&scopeStack,curScopeId);		//pushing scope since moving in proc body
	 		 $$ = setBasicType(DT_PROC);
	  		$$->entry = getEntry($1,scopeStack)->lexeme; 
			$$-> counter = -2;		//flag to indicate correct proc declaration
			$$->place = (char*)malloc(strlen($$->entry)+5);
			sprintf($$->place,"%s@%d",$$->entry,getEntry($1,scopeStack)->myScope);			//putting proc name along with scope to place indicating address	
		}
		else
		{
			$$ = getEntry($1,tempStack)->type;		//func name already declared
			$$->entry = getEntry($1,scopeStack)->lexeme;		//lexeme copied
			$$->place = (char*)malloc(strlen($$->entry)+5);	
			sprintf($$->place,"%s@%d",$$->entry,tempStack->val);		//putting proc name with scope to place
		}
	}
  | visibility_specifier 
  | proc_name DOT identifier 
	{
		sym *temp;	
		stack *tempStack;
		Push(&tempStack,$1->attScope);		//creating a temporary stack
		temp = getEntry($3->entry,tempStack);			//finding field in temporary stack
		if(temp != NULL)
		{	
			$$ = temp->type;
			$$->counter = $1->attScope; 			//storing  sscope to counter to indicate function for object
			Push(&scopeStack,temp->type->attScope); 		// pushing filed's scope to scope stack
			$$->entry = temp->lexeme;						//name of procedure equals matched name in temp stack
			$$->place = (char*)malloc(strlen($1->place)+strlen($3->entry)+10);		
			sprintf($$->place,"%s.%s@%d",$1->place,$3->entry,tempStack->val);		//putting object's name , field's name along with scope value to proc's name place
		}
		else
		{		
			$$ = setBasicType(DT_ERROR);		//else error
			numTypeError++;errorFreeType = 0; 
			$$-> counter = -1;
			$$->entry = $3->entry;
		}
	}
  | proc_name DOT visibility_specifier 
  ; 
  
func_heading : FUNC func_name fp_list COLON fptype fp_directives 
	{
		if($2->counter == -1)
		 {
			$$ = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
		}
		else if($2->counter == -2)
		 { 
			NewEntry("Result",IDENT,line_number,&table[hashKey("Result")],scopeStack,$5);				// ?? RESULT  ??
			Add(scopeStack->val,$5->width);
			getEntry($2->entry,scopeStack)->type->next = $3;
			getEntry($2->entry,scopeStack)->type->attScope = scopeStack->val;
			$2->next = $3;
			$2->attScope = scopeStack->val;
			Type* temp = $2;
			while(temp != NULL)
			{
				temp = temp->next;
			}
			$$ = setBasicType(DT_FUNCTION);
		}
		else 
		{
			stack *tempStack;
			Push(&tempStack,$2->counter);
			getEntry($2->entry,tempStack)->type->next = $3;
			$2->next = $3;
			$2->attScope = getEntry($2->entry,tempStack)->type->attScope;
			Type* temp = $2;
			while(temp != NULL)
			{
				temp = temp->next;
			}
			$$ = setBasicType(DT_FUNCTION);
		}
		$$->entry = $2->entry;
		$$->place = $2->place;
	}
  | FUNC func_name fp_directives {}
  | FUNC func_name error error_recovery_token {} // check
  ; 
  
fp_directives : SEMICOLON ; 
  
func_name : IDENT 
	{
		sym *temp;	
		stack *tempStack;
		Push(&tempStack,scopeStack->val);
		if(getEntry($1,tempStack) == NULL)
		{
	  		NewEntry($1,IDENT,line_number,&table[hashKey($1)],scopeStack,setBasicType(DT_FUNCTION));
			Add(scopeStack->val,SIZE_PTR);
			curScopeId++; Push(&scopeStack,curScopeId);
			$$ = setBasicType(DT_FUNCTION);
			$$->entry = getEntry($1,scopeStack)->lexeme; 
			$$-> counter = -2;
			$$->place = (char*)malloc(strlen($$->entry)+5);
			sprintf($$->place,"%s@%d",$$->entry,getEntry($1,scopeStack)->myScope);
		}
		else
		{
			$$ = getEntry($1,tempStack)->type;
			$$->entry = getEntry($1,scopeStack)->lexeme;
			$$->place = (char*)malloc(strlen($$->entry)+5);
			sprintf($$->place,"%s@%d",$$->entry,tempStack->val);
		}
	}
  | visibility_specifier 
  | func_name DOT identifier 
	{
		sym *temp;	
		stack *tempStack;
		Push(&tempStack,$1->attScope);
		temp = getEntry($3->entry,tempStack);
		if(temp != NULL)
		{	
			$$ = temp->type;
			$$->counter = $1->attScope; // jugaad check
			Push(&scopeStack,temp->type->attScope); 
			$$->entry = temp->lexeme;
			$$->place = (char*)malloc(strlen($1->place)+strlen($3->entry)+10);
			sprintf($$->place,"%s.%s@%d",$1->place,$3->entry,tempStack->val);
		}
		else
		{
			$$ = setBasicType(DT_ERROR);	
			$$-> counter = -1;
			$$-> entry = $3->entry;
		}
	}
  | func_name DOT visibility_specifier 
  ; 
  
proc_block : proc_block_decl {$$=$1;}
  ; 
  
func_block : proc_block_decl {$$=$1;} 
  ; 
  
proc_block_decl : block   {$$=$1;}
  | asm_block {$$=$1;}
  ; 

asm_block : impl_decl_sect_list Marker3 ASMBODY SEMICOLON {$$=$2;}
  ; 
  
block :  impl_decl_sect_list Marker3  compound_stmt SEMICOLON {$$=$2;}
  ; 
  
fp_list :  {$$ = setBasicType(DT_VOID); $$->next = NULL; }
  | LPAREN fp_sect_list RPAREN {$$ = setBasicType(DT_VOID); $$-> next = $2; }
  ; 
  
fp_sect_list : {$$=NULL;}
  | fp_sect {$$ = $1;}
  | fp_sect_list SEMICOLON fp_sect 
	{
		 $$ = setType($1); 			//set type of $1 to $$
		 $$->next = $1->next; 		// ?? $$->NEXT=$1; ??  since one section will be missed
		 append_to_list($3,&$$);		//appendig $3 to result
	}
  ; 
  

fp_sect : param_name_list COLON fptype_new 
	{
		Type* head; 
		sym* tempEntry;
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		temp = $1;
		for(i = 1; i<= $1->counter;i++) 
		{
			if(temp->flag == 1) 		//if there is symbol entry in table
			{
				tempEntry = getEntry((temp->entry),scopeStack);	
				tempEntry->type = $3;		//setting type 
				tempEntry->offset = SizeOf(scopeStack->val);	
				Add(scopeStack->val,$3->width);
			}
			make_new_list($3,&head);	//adding parameters in a list pointed by head
			temp = temp->next;
		}
		$$ = head->next;
	}
  | param_name_list {$$=$1;}
  | VAR param_name_list COLON fptype_new 
	{
		Type* head; 
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		sym* tempEntry;
		temp = $2;
		for(i = 1; i<= $2->counter;i++) 
		{
			if(temp->flag == 1) 
			{
				tempEntry = getEntry((temp->entry),scopeStack);
				tempEntry->type = $4;
				tempEntry->offset = SizeOf(scopeStack->val);
				Add(scopeStack->val,$4->width);
			}
			make_new_list($4,&head);
			temp = temp->next;
		}
		$$ = head->next;
	}
  | VAR param_name_list {$$=$2;}
  | OUT param_name_list COLON fptype_new 
	{
		Type* head; 
		sym* tempEntry;
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		temp = $2; 
		for(i = 1; i<= $2->counter;i++) 
		{
			if(temp->flag == 1) 
			{
				tempEntry = getEntry((temp->entry),scopeStack);
				tempEntry->type = $4;
				tempEntry->offset = SizeOf(scopeStack->val);
				Add(scopeStack->val,$4->width);
			}
			make_new_list($4,&head);
			temp = temp->next;
		}
		$$ = head->next;
	}
  | OUT param_name_list {$$=$2;}
  | CONST param_name_list COLON fptype_new 
	{
		Type* head; 
		sym* tempEntry;
		head = (Type *)malloc(sizeof(Type));
		Type* temp;
		temp = $2; 
		for(i = 1; i<= $2->counter;i++) 
		{
			if(temp->flag == 1) 
			{
				tempEntry = getEntry((temp->entry),scopeStack);
				tempEntry->type = $4;
				tempEntry->offset = SizeOf(scopeStack->val);
				Add(scopeStack->val,$4->width);
				tempEntry->token  = CONST;
			}
			make_new_list($4,&head);
			temp = temp->next;
		}
		$$ = head->next;
	}
  | CONST param_name_list {$$=$2;}
  ; 
  
param_name_list : param_name 
	{
		$$ = setType($1); 
		$$->next = NULL;
		$$ = $1; 
		$$->counter = 1; 
	}
  |   param_name COMMA param_name_list 
	{
		$1->next = $3; 
		$$ = $1; 
		$$->counter = $3->counter + 1;
	}
  ; 
  
param_name : IDENT   
	{
		$$ = setBasicType(DT_VOID);   
  		$$->flag= NewEntry( $1,IDENT,line_number,&table[hashKey($1)],scopeStack,NULL);  
		$$->entry = getEntry($1,scopeStack)->lexeme; 
	}
   ; 
  
fptype : identifier  {$$=$1;}
  ; 
  
fptype_new : fptype {$$ = $1;}
  | fptype EQUAL const_expr 
	{
		$$ = $1; 
		if(typeCheck($1,$3)==0) 
			printf("(Line %d) Type error in parameter list\n",line_number);  
	}
  ; 
  
stmt : unlabelled_stmt 
  ; 
  
unlabelled_stmt :  { $$ = setBasicType(DT_VOID); $$->nextlist = malloc(sizeof(List)); $$->nextlist = NULL;}
  | assignment {$$=$1;}
  | proc_call {$$=$1;}
  | compound_stmt {$$=$1;}
  | if_stmt {$$=$1;}
  | case_stmt {$$=$1;}
  | repeat_stmt{$$=$1;}
  | while_stmt {$$=$1;}
  | for_stmt {$$=$1;}
  | asm_stmt {$$=$1;}
  ; 
  
assignment : var_reference ASSIGN expr 
	{
		if(typeCheck($1,$3) == 0) 
		{
			if(assignTypeCheck($1,$3) == 1) 
			{ 
				$$ = setBasicType(DT_VOID); 
			}
			else	
			{
				printf("(Line %d) Incompatible Types in Assignment. Found ",line_number); 
				printType($3); 
				printf(" required "); 
				printType($1); 
				printf("\n"); 
				$$ = setBasicType(DT_ERROR); 
				numTypeError++;errorFreeType = 0;
			}
		}
		else	
			$$ = setBasicType(DT_VOID);
		 emitcode(":=",$1->place,$3->place,NULL);
		 $$->nextlist = (List *)malloc(sizeof(List)); $$->nextlist = NULL;	
	}
| error {$$ = setBasicType(DT_VOID);}
  ; 
  
proc_call : var_reference 
	{
		sym* temp;
	 	flag = 0;
	  	if($1->next == NULL)
		 	$1->next = setBasicType(DT_VOID);
		temp = getEntry($1->entry,scopeStack);
		if(($1->entry!=NULL)&&(strcmp($1->entry,"WRITE")==0 || strcmp($1->entry,"READ")==0 || strcmp($1->entry,"WRITELN")==0 || strcmp($1->entry,"READLN")==0 ))
		{
			int isRead = 1;
			if(strcmp($1->entry,"WRITE")==0 || strcmp($1->entry,"WRITELN")==0)
			{
				isRead = 0;
			}
			counter = 0;
			Type *temp2 = $1;
			while(temp2!=NULL)
			{
				if(counter>=2) 
				{
					if(isRead == 1)
					{
						if(temp2->dataType == DT_INT)
							emitcode("paramRI",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_REAL)
							emitcode("paramRF",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_BOOL)
							emitcode("paramRB",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_STRING)
							emitcode("paramRS",temp2->place,NULL,NULL);
						else
							emitcode("paramRI",temp2->place,NULL,NULL);
					}
					else
					{
						if(temp2->dataType == DT_INT)
							emitcode("paramWI",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_REAL)
							emitcode("paramWF",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_BOOL)
							emitcode("paramWB",temp2->place,NULL,NULL);
						else if(temp2->dataType == DT_STRING)
							emitcode("paramWS",temp2->place,NULL,NULL);
						else
							emitcode("paramWI",temp2->place,NULL,NULL);
					}
				}
				counter++;
				temp2 = temp2->next;
			}
			char* cnt;
			cnt=(char*) malloc(50*sizeof(char));
			counter = counter-2;
			sprintf(cnt,"%d",counter);
			emitcode("call",NULL,$1->entry,cnt);
			
		}
		else if(temp == NULL || temp->type == NULL) 
		{
			$$ = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
		}
		else	
		{
				 
			if(temp->type->dataType == DT_PROC)
			{	
				flag = 0;
				counter = 0;
				Type	*tempCall,*tempDef;
				tempCall = $1;
				tempDef = temp->type;
				
				while(tempDef !=NULL && tempCall != NULL)
				{
					if(typeCheck(tempCall,tempDef) == 0/*strictClub($1)  != strictClub($3)*/) 
					{
						if(assignTypeCheck(tempDef,tempCall) == 1) 
						{ 
							if(counter>=2) 
							{
								if(tempCall->dataType == DT_INT)
									emitcode("paramI",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_REAL)
									emitcode("paramF",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_BOOL)
									emitcode("paramB",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_STRING)
									emitcode("paramS",tempCall->place,NULL,NULL);
								else
									emitcode("paramI",tempCall->place,NULL,NULL);
							}
						}
						else	
						{
							flag = 1;
							printf("\n(Line %d) Incompatible types in Procedure Call. Found ",line_number); 
							printType(tempCall); 
							printf(" required "); 
							printType(tempDef); 
							$$ = setBasicType(DT_ERROR); 
							numTypeError++;errorFreeType = 0;
							break;
						}
					}
					if(counter>=2) 
					{ 
						if(tempCall->dataType == DT_INT)
							emitcode("paramI",tempCall->place,NULL,NULL);
						else if(tempCall->dataType == DT_REAL)
							emitcode("paramF",tempCall->place,NULL,NULL);
						else if(tempCall->dataType == DT_BOOL)
							emitcode("paramB",tempCall->place,NULL,NULL);
						else if(tempCall->dataType == DT_STRING)
							emitcode("paramS",tempCall->place,NULL,NULL);
						else
							emitcode("paramI",tempCall->place,NULL,NULL);
					}
					tempCall = tempCall->next;
					tempDef = tempDef->next;
					counter++;
				}
				if((tempDef==NULL && tempCall != NULL) || (tempDef!=NULL && tempCall == NULL)) 
				{	
					flag =1;
					printf("\n(Line %d) Unexpected number of arguments\n",line_number);
				}
				char* cnt ;
				cnt = (char *)malloc(5*sizeof(char));
				counter = counter-2;
				sprintf(cnt,"%d",counter);
				sprintf(tempName,"%s@%d",$1->entry,getEntry($1->entry,scopeStack)->myScope);
				emitcode("call",NULL,tempName,cnt); 
			}
			else
			{	
				printf("\n(Line %d) Error in Procedure Call\n",line_number);
				$$ = setBasicType(DT_ERROR);
				numTypeError++;errorFreeType = 0;
			}		
			if(flag == 0)
			{
				$$ = setBasicType(DT_VOID);
			}	
			else
			{
				printf("\n(Line %d) Error in Procedure Call\n",line_number);
				$$ = setBasicType(DT_ERROR);
				numTypeError++;errorFreeType = 0;
			}
		}
	}
  ; 

compound_stmt : PBEGIN stmt_list END 
	{
		$$ = $2;  
	}
  ; 
  
stmt_list : stmt 
	{
		$$ = setBasicType(DT_VOID); 
		$$->nextlist = $1->nextlist; 
	}
  | stmt_list SEMICOLON Marker stmt 
	{
		if($1->dataType == DT_ERROR || $4->dataType == DT_ERROR)
		{
			$$ = setBasicType(DT_ERROR); 
			numTypeError++;errorFreeType = 0;
		}
		else 
			$$ = setBasicType(DT_VOID);
		BackPatch($1->nextlist,$3);
		$$->nextlist = $4->nextlist;
	}
  ; 
  
if_stmt : IF expr THEN Marker then_branch %prec IFX 
	{
		if($2->dataType != DT_BOOL) 
		{
			 printf("(Line %d) Error in test condition of IF \n ",line_number);
			 $$ = setBasicType(DT_ERROR); 
			numTypeError++;errorFreeType = 0;
		}  
	 	else 
		{
			$$ = setBasicType(DT_VOID);
			BackPatch($2->truelist,$4);
			$$->nextlist = merge($2->falselist,$5->nextlist);		
		}  
		ifFlag = 0;
	}
| IF expr THEN Marker then_branch ELSE Marker2  Marker else_branch 
	{
		if($2->dataType != DT_BOOL) 
		{ 
			printf("(Line %d) Error in test condition of IF \n ",line_number); 
			$$ = setBasicType(DT_ERROR); 
			numTypeError++;errorFreeType = 0;
		}  
 		else 
		{
			$$ = setBasicType(DT_VOID);
			BackPatch($2->truelist,$4);
			BackPatch($2->falselist,$8);
			List* temp = merge($5->nextlist,$7->nextlist);
			$$->nextlist = merge(temp,$9->nextlist);
		} 
		ifFlag = 0; 
	}
;
then_branch : stmt {$$ = $1;}
  ; 
  
else_branch : stmt {$$ = $1;}
  ; 
  
case_stmt : CASE expr OF case_list else_case END 
	{
		flag = 1;
		Type* temp; 
		temp = $4;
		 while(temp!=NULL) 
		{
			if($2->dataType != DT_VOID && typeCheck(temp,$2)==0) 
			{
				 flag = 0; 
				 break; 
			}
			temp = temp->next;
		}
		if(flag == 0)	
		{ 
			$$ = setBasicType(DT_ERROR); 
			printf("(Line %d) Type Error in case stmt\n",line_number);
			numTypeError++;errorFreeType = 0;
		}
		else
			$$ = setBasicType(DT_VOID);
	}
  ; 
  
case_list : case_item  { $1->next = NULL; $$ = $1;}
  |  case_item SEMICOLON case_list { $1->next = $3; $$ = $1; }
  ; 
  
case_item :  {$$ = setBasicType(DT_VOID);}
  | case_label_list COLON stmt {$$=$1;}
  ; 
  
case_label_list : case_label  { $$ = $1; }
  | case_label_list COMMA case_label 
	{
		if(typeCheck($1,$3)==1) 
			$$ = $1; 
		else 
		{ 
			$$ = setBasicType(DT_ERROR); 
			printf("(Line %d) Type Error in case label list \n",line_number); 
			numTypeError++;errorFreeType = 0;
		}
	}
  ; 
  
case_label : const_expr { $$ = $1; }
  | const_expr DOTDOT const_expr 
	{
		if($1->dataType == DT_INT && $3->dataType == DT_INT) 
			$$ = setBasicType(DT_INT); 
		else 
		{ 
			$$ = setBasicType(DT_ERROR); 
			printf("(Line %d) Error in case label subrange type\n",line_number);
			numTypeError++;errorFreeType = 0; 
		} 
	}
  ; 
  
else_case :  {$$=NULL;}
  | ELSE stmt_list {$$=NULL;} 
  ; 
  
repeat_stmt : REPEAT Marker stmt_list UNTIL Marker expr 
	{
		if($6->dataType != DT_BOOL) 
		{ 
			$$ = setBasicType(DT_ERROR); 
			printf("(Line %d) Error in test condition of REPEAT \n",line_number);
			numTypeError++;errorFreeType = 0;
		} 
		else 
		{
			$$ = setBasicType(DT_VOID);		
			BackPatch($3->nextlist,$5);
			BackPatch($6->falselist,$2);
			$$->nextlist = $6->truelist;
		} 
		ifFlag = 0;
	}
  ; 
  
while_stmt : WHILE Marker expr DO Marker stmt 
	{
		if($3->dataType != DT_BOOL) 
		{ 
			$$ = setBasicType(DT_ERROR); 
			printf("(Line %d) Error in test condition of WHILE loop \n",line_number); 
			numTypeError++;errorFreeType = 0;
		} 
		else 
		{ 
			$$ = setBasicType(DT_VOID);
			BackPatch($6->nextlist,$2);
			BackPatch($3->truelist,$5);
			$$->nextlist = $3->falselist;
			sprintf(tempName,"%d",$2);
			emitcode("goto",NULL,tempName,NULL); 
			ifFlag = 0;       
		}
	}
  ; 
  
for_stmt : FOR for_special DO stmt
	{
		if($2->dataType == DT_ERROR) 
		{
			$$ = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
			printf("(Line %d) Error in assign condition of FOR loop\n",line_number);
		}
		else 
		{ 
			$$ = setBasicType(DT_VOID); 		
			BackPatch($4->nextlist,quadId);
			if($2->flag == 1) 
			{
				if($2->dataType == DT_INT)
					emitcode("int+",$2->place,$2->place,"1");
				else
					emitcode("real+",$2->place,$2->place,"1");
			}
			else 
			{
				if($2->dataType == DT_INT)
					emitcode("int-",$2->place,$2->place,"1");
				else
					emitcode("real-",$2->place,$2->place,"1");
			}
			sprintf(tempName,"%d",$2->counter-1);
			emitcode("goto",NULL,tempName,NULL);
			sprintf(tempName,"%d",quadId);
			codelist[$2->counter]->arg1 = strdup(tempName);
			BackPatch($$->nextlist,quadId);		
		}
		ifFlag = 0;
	}
 ; 

for_special : identifier ASSIGN expr TO expr
	{
		if((typeCheck($1,$3) == 0 && conversionTypeCheck($1,$3) == 0)||(typeCheck($1,$5)==0 && conversionTypeCheck($1,$5)== 0)) 
		{
			$$ = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
			printf("(Line %d) Error in assign condition of FOR loop\n",line_number);
		}
		else 
		{
			emitcode(":=",$1->place,$3->place,NULL);
			sprintf(tempName,"if %s <= %s",$1->place,$5->place);
			char* temp = (char *)malloc(sizeof(char)*5);
			sprintf(temp,"%d",quadId+2);
			emitcode("Cgoto",NULL,temp,tempName);
			emitcode("goto",NULL,"---",NULL);
			$$ = $1;
			$$->counter = quadId-1;
			$$->flag = 1;		
		}
	}
| identifier ASSIGN expr DOWNTO expr 
	{
		if((typeCheck($1,$3) == 0 && conversionTypeCheck($1,$3) == 0)||(typeCheck($1,$5)==0 && conversionTypeCheck($1,$5)== 0)) 
		{
			$$ = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0;
			printf("(Line %d) Error in assign condition of FOR loop\n",line_number);
		}
		else 
		{
			emitcode(":=",$1->place,$3->place,NULL);
			sprintf(tempName,"if %s >= %s",$1->place,$5->place);
			char* temp = (char *)malloc(sizeof(char)*5);
			sprintf(temp,"%d",quadId+2);
			emitcode("Cgoto",NULL,temp,tempName);
			emitcode("goto",NULL,"---",NULL);
			$$ = $1;
			$$->counter = quadId-1;
			$$->flag = 0;
		}
	}
;
 
asm_stmt : ASMBODY {}
  ; 
  
expr_list : expr 
	{
		$$ = $1; 
		$$->next = NULL; 
		$$->counter = 1; 
	}
  | expr COMMA expr_list
	{
		$$ = $1; 
		$$->next = $3; 
		$$->counter = $3->counter + 1;
 		Type* temp;
	  	temp = $$;	
	}
  ;
  
expr : simple_expr 
	{
		$$ = setType($1); 
		$$->truelist = $1->truelist;
		$$->falselist = $1->falselist;
		$$->place = $1->place; 
		if($1 != NULL) 
			$$->next=NULL;
	}
  | simple_expr relop simple_expr 
	{
		flag = 1; 	
		if ($1->dataType == DT_ERROR || $3->dataType == DT_ERROR) 
		{ 
			flag =0; 
			numTypeError++;errorFreeType = 0;
		}
		else 
		{ 		
			if( Club($1) != Club($3) || Club($1) == DT_VOID ) 
			{
				flag = 0; 
				printf("(Line %d) Incompatible types in relop const_expr. \n",line_number); 
				printType($1); 
				printType($3);
			}	
		 }
		if(flag == 0) 
		{
			$$ = setBasicType(DT_ERROR);
			numTypeError++;errorFreeType = 0; 
		}
		else 
		{
			$$ = setBasicType(DT_BOOL);
			$$->truelist = create_new_list(quadId);
			$$->falselist = create_new_list(quadId+1);
			$$->place = "";
			sprintf(tempName,"if %s %s %s",$1->place,$2->entry,$3->place);
			emitcode("Cgoto",NULL,"---",tempName); 
			emitcode("goto",NULL,"---",NULL);
		}
	}
   ;
  
relop : EQUAL  {$$ = setBasicType(DT_VOID);	$$->entry = "=";}
  | NOTEQUAL {$$ = setBasicType(DT_VOID);	$$->entry = "<>";}
  | LT {$$ = setBasicType(DT_VOID);	$$->entry = "<";}
  | GT {$$ = setBasicType(DT_VOID);	$$->entry = ">";}
  | LE {$$ = setBasicType(DT_VOID);	$$->entry = "<=";}
  | GE {$$ = setBasicType(DT_VOID);	$$->entry = ">=";}
  ; 
  
simple_expr : term 
	{
		$$ = setType($1); 
		$$->truelist = $1->truelist;
		$$->falselist = $1->falselist;
		$$->place = $1->place; 
	}
  | simple_expr addop Marker term 
	{
		if(strcmp($2->entry,"OR")==0 && $1->dataType == DT_BOOL && $4->dataType == DT_BOOL) 
		{
			$$ = setBasicType(DT_BOOL);
			BackPatch($1->falselist,$3);
			$$->truelist = merge($1->truelist,$4->truelist);
			$$->falselist = $4->falselist;
		}
		else if(ClubTypeCheck($1,$4) == 0)
		{ 
			numTypeError++;errorFreeType = 0; 
			$$ = setBasicType(DT_ERROR); 
			printf("(Line %d) Type Error in constant expression\n",line_number);
		}
		else
		{
			$$ =setType(getArithType($1,$4)); 
			$$->place = get_new_temp(scopeStack->val);
			Add(scopeStack->val,$$->width);  // for $$->place 's get_new_temp
			if($1->dataType == DT_INT && $4->dataType == DT_INT) 
			{
				sprintf(tempName,"%s%s","int",$2->entry);
				emitcode(tempName,$$->place,$1->place,$4->place);
			}
			else if($1->dataType == DT_REAL && $4->dataType == DT_REAL) 
			{
				sprintf(tempName,"%s%s","real",$2->entry);
				emitcode(tempName,$$->place,$1->place,$4->place);
			}
			if($1->dataType == DT_INT && $4->dataType == DT_REAL) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
				emitcode("<IntToReal>",u,$1->place,NULL);
				sprintf(tempName,"%s%s","real",$2->entry);
				emitcode(tempName,$$->place,u,$4->place);
			}
			if($1->dataType == DT_REAL && $4->dataType == DT_INT) 
			{
				char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
				emitcode("<IntToReal>",u,$4->place,NULL);
				sprintf(tempName,"%s%s","real",$2->entry);
				emitcode(tempName,$$->place,$1->place,u);
			}		
		}
	}
  ; 
  
addop : PLUS { $$ = setBasicType(DT_VOID);	$$->entry = "+";}
  | MINUS { $$ = setBasicType(DT_VOID);	$$->entry = "-";}
  | OR { $$ = setBasicType(DT_VOID);	$$->entry = "OR";}
  | XOR { $$ = setBasicType(DT_VOID);	$$->entry = "XOR";}
  ; 
  
term : factor 
	{
		$$ = $1; 
		$$ = setType($1); 
		$$->truelist = $1->truelist;
		$$->falselist = $1->falselist;
		$$->place = $1->place; 
		//printf("\n...............$$->place in 2 = %s ........\n",$$->place);
	}
  | term mulop Marker factor  
	{
		flag=1;
		if(strcmp($2->entry,"AND")==0 && $1->dataType == DT_BOOL && $4->dataType == DT_BOOL) 
		{
			$$ = setBasicType(DT_BOOL);
			BackPatch($1->truelist,$3);
			$$->truelist = $4->truelist;
			$$->falselist = merge($1->falselist,$4->falselist);
		}
		else if(ClubTypeCheck($1,$4)== 0)
		{
			printf("(Line %d) Type Error in constant expression\n",line_number); flag =0 ;
		}
		else 
		{
			if($2->counter ==STAR ||  $2->counter == SLASH || $2->counter == DIV) 
			{ 
				$$ = setType(getArithType($1,$4)); 
				$$->place = get_new_temp(scopeStack->val);
				Add(scopeStack->val,$$->width); // for get_new_temp of $$
				if($1->dataType == DT_INT && $4->dataType == DT_INT) 
				{
					sprintf(tempName,"%s%s","int",$2->entry);
					emitcode(tempName,$$->place,$1->place,$4->place);
				}
				else if($1->dataType == DT_REAL && $4->dataType == DT_REAL) 
				{
					sprintf(tempName,"%s%s","real",$2->entry);
					emitcode(tempName,$$->place,$1->place,$4->place);			
				}
				if($1->dataType == DT_INT && $4->dataType == DT_REAL) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
					emitcode("<IntToReal>",u,$1->place,NULL);
					sprintf(tempName,"%s%s","real",$2->entry);
					emitcode(tempName,$$->place,u,$4->place);
				}
				if($1->dataType == DT_REAL && $4->dataType == DT_INT) 
				{
					char* u = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_REAL);
					emitcode("<IntToReal>",u,$4->place,NULL);
					sprintf(tempName,"%s%s","real",$2->entry);
					emitcode(tempName,$$->place,$1->place,u);
				}			
			} 
			else if($2->counter == MOD || $2->counter== SHR || $2->counter == SHL) 
			{
				if(strictClub($1) == DT_INT && strictClub($4) == DT_INT ) 
				{
					$$ = setBasicType(DT_INT);
					$$->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,$$->width); // for get_new_temp of $$
					emitcode($2->entry,$$->place,$1->place,$4->place);
				}
				else 
				{ 
					flag =0; 
					printf("(Line %d) Type Error in constant expression\n",line_number);
				}
			} 
			else if($2->counter == AND) 
			{ 
				if($1->dataType == DT_INT && (typeCheck($1,$4) ==1)) 
				{
					$$ = setBasicType(DT_INT);
					$$->place = get_new_temp(scopeStack->val);
					Add(scopeStack->val,$$->width); // for get_new_temp of $$
					emitcode("AND",$$->place,$1->place,$4->place);
				}
				else 	
				{
					printf("(Line %d) Type Error in constant expression\n",line_number); 
					flag = 0; 
				} 
			}
			if (flag == 0) 
			{ 
				$$ = setBasicType(DT_ERROR);
				numTypeError++;errorFreeType = 0; 
			}	
		} 
	}
  ; 
  
mulop : STAR {$$ = setBasicType(DT_VOID);	$$->entry = "*"; $$->counter = STAR;} 
  | SLASH {$$ = setBasicType(DT_VOID);	$$->entry = "/"; $$->counter = SLASH;}
  | DIV {$$ = setBasicType(DT_VOID);	$$->entry = "/";  $$->counter = DIV;}
  | MOD {$$ = setBasicType(DT_VOID);	$$->entry = "MOD";  $$->counter = MOD;}
  | SHL {$$ = setBasicType(DT_VOID);	$$->entry = "SHL";  $$->counter = SHL;}
  | SHR {$$ = setBasicType(DT_VOID);	$$->entry = "SHR";  $$->counter = SHR;}
  | AND {$$ = setBasicType(DT_VOID);	$$->entry = "AND";  $$->counter = AND;}
 ;

factor : unsigned_number {$$=$1;}
  | literal {$$=$1;}
  | NIL 
	{
		$$ = setBasicType(DT_VOID); 
		$$->place = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_INT);
		emitcode("NIL",$$->place,NULL,NULL);
	}
  | LSQBRACK elem RSQBRACK { $$=$2;}
  | NOT factor 
	{
		$$ = setType($2);
		$$->truelist = $2->falselist;
		$$->falselist = $2->truelist; 
		sprintf(tempName,"%s %s","NOT",$2->place);
		$$->place = tempName;
	}
  | sign factor 
	{
		$$ = setType($2);
		$$->place = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_INT);
		emitcode($1->code,$$->place,$2->place,NULL);
	}
  | UPARROW factor 
	 {
		 $$ = $2; 
		augmentType(&$$,DT_PTR);
		 $$->place = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_PTR);
		 emitcode("^",$$->place,$2->place,NULL);
	}
  | var_reference 			//function invocation
	{
		if($1->entry != NULL)	
		{
			if($1->dataType == DT_FUNCTION)
	 		{
				if($1->next == NULL)		//no arguments
					$1->next = setBasicType(DT_VOID);
				sym* temp;
				flag = 0;
				if($1->flag == 1)		//object attributes
				{
					stack* tempStack;
					Push(&tempStack,$1->funcAttScope);
					temp = getEntry($1->entry,tempStack);
				}				
				else				//find variable from scope stack
					temp = getEntry($1->entry,scopeStack);
				if(temp == NULL || temp->type == NULL) 		//error
				{
					$$ = setBasicType(DT_ERROR);
					numTypeError++;errorFreeType = 0; 
				}
				else	
				{
					if(temp->type->dataType == DT_FUNCTION)
					{	
						flag = 0;
						counter = 0;
						Type	*tempCall,*tempDef;
						tempCall = $1;
						tempDef = temp->type;
						stack* tempStack;
						Push(&tempStack,temp->type->attScope);
						$$->place = get_new_temp(scopeStack->val); 
						Add(scopeStack->val,getEntry("Result",tempStack)->type->width); 
						while(tempDef !=NULL && tempCall != NULL)				//types for actual parameters and formal parameters
						{
							if(typeCheck(tempCall,tempDef) == 0) 
							{
								if(assignTypeCheck(tempDef,tempCall) == 1) 
								{
									if(counter>=2) 
									{ 
										if(tempCall->dataType == DT_INT)
											emitcode("paramI",tempCall->place,NULL,NULL);
										else if(tempCall->dataType == DT_REAL)
											emitcode("paramF",tempCall->place,NULL,NULL);
										else if(tempCall->dataType == DT_BOOL)
											emitcode("paramB",tempCall->place,NULL,NULL);
										else if(tempCall->dataType == DT_STRING)
											emitcode("paramS",tempCall->place,NULL,NULL);
										else
											emitcode("paramI",tempCall->place,NULL,NULL);
									}
								}
								else	
								{
									flag = 1;
									printf("(Line %d) Incompatible types in Function Call. Found ",line_number); printType(tempCall); printf(" required "); printType(tempDef); $$ = setBasicType(DT_ERROR); 
									numTypeError++;errorFreeType = 0;
									break;
								}
							}			
							if(counter>=2) 
							{ 
								if(tempCall->dataType == DT_INT)
									emitcode("paramI",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_REAL)
									emitcode("paramF",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_BOOL)
									emitcode("paramB",tempCall->place,NULL,NULL);
								else if(tempCall->dataType == DT_STRING)
									emitcode("paramS",tempCall->place,NULL,NULL);
								else
									emitcode("paramI",tempCall->place,NULL,NULL);
							}
							tempCall = tempCall->next;
							tempDef = tempDef->next;
							counter++;
						}
						if((tempDef==NULL && tempCall != NULL) || (tempDef!=NULL && tempCall == NULL)) 
						{	
							flag =1;
							printf("\n(Line %d) Unexpected number of arguments\n",line_number);
						}
						char* cnt = (char*) malloc(10);
						counter = counter - 2;
						sprintf(cnt,"%d",counter);
						if($1->flag == 1)
							sprintf(tempName,"%s@%d",$1->entry,$1->funcAttScope);
						else
							sprintf(tempName,"%s@%d",$1->entry,getEntry($1->entry,scopeStack)->myScope);
						emitcode("call",$$->place,tempName,cnt); 
					}
					else
					{
						printf("\nError in Function Call\n");
						$$ = setBasicType(DT_ERROR);
						numTypeError++;errorFreeType = 0;
					}
					if(flag == 0)
					{
						stack* tempStack;
						Push(&tempStack, temp->type->attScope);
						$$ = getEntry("Result",tempStack)->type;
					}
					else
					{
						printf("\n(Line %d) Error in Function Call\n",line_number);
						$$ = setBasicType(DT_ERROR);
						numTypeError++;errorFreeType = 0; 
					}
				}
			}
			else
				$$ =$1;
		}
		$$->place = $1->place;
	}
  | PTRUE 
	{
		$$ = setBasicType(DT_BOOL); 
		$$->place = "TRUE";
		if(ifFlag == 1) 
		{
			$$->truelist = create_new_list(quadId); 
			emitcode("goto",NULL,"---",NULL);
		}
	}
  | PFALSE 
	{
		$$ = setBasicType(DT_BOOL); 
		$$->place = "FALSE";
		if(ifFlag == 1) 
		{
			$$->falselist = create_new_list(quadId); 
			emitcode("goto",NULL,"---",NULL);
		}
	}
  ; 
  
Marker : 
	{
		$$ = quadId; 
	}
;

Marker2 : 
	{
		$$->nextlist = create_new_list(quadId);
		emitcode("goto",NULL,"---",NULL);
	}
;

var_reference : var_address variable 
	{
		$$ = $2;  
		for(i = $1;i>=1;i--)  augmentType(&$$,DT_PTR); 
	}
  | variable 
	{
		$$ = CopyType2($1); 
		$$->place = (char *)malloc(100); // for place in 3 address code
		if($1->place!=NULL) sprintf($$->place,"%s",$1->place);
	}
  ; 
  
var_address : ADDROF { $$=1;}
  | var_address ADDROF {  $$ = $1 + 1; }
  ; 
  
variable : identifier { $$ = $1; $$->next = NULL; $$->flag=0;}
  | INHERITED identifier { $$ = $2; }
  | LPAREN expr RPAREN { $$ = $2; }
  | LPAREN RPAREN { $$ = setBasicType(DT_VOID); $$->next = NULL; $$->code = "";}
  | variable var_specifiers 
	{
		flag =0;
		sym* temp;
		if($2->counter == -2)
		{
			$$ = getSubType($1);
			sym *tempE = getEntry($1->entry,scopeStack);
			if(tempE != NULL)
			{	
				Type *temp2 = tempE->type;		
				char* tempName2= (char*)malloc(10);
				char* temp = $2->code;		
				sprintf(tempName,"%s",get_new_temp(scopeStack->val)); Add(scopeStack->val,SIZE_INT);
				sprintf(tempName2,"%d",temp2->low);
				emitcode("int-",tempName,strtok(temp,","),tempName2);
				while(temp2->next->next!=NULL )
				{
					sprintf(tempName2,"%d",temp2->next->maxIndex);
					emitcode("int*",tempName,tempName,tempName2);
					emitcode("int+",tempName,tempName,strtok(NULL,","));
					sprintf(tempName2,"%d",temp2->next->low);
					emitcode("int-",tempName,tempName,tempName2);
					temp2 = temp2->next;
					$$ = getSubType($$);
				}
			}
			$$->place = (char *)malloc(100);
			sprintf($$->place,"%s[%s]",$1->place,tempName);
			$$->counter = -3;
		}
		else if($2->counter == -1)
		{	
			stack *tempStack;
			Push(&tempStack, $1->attScope);
			temp = getEntry($2->entry,tempStack);
			if(temp != NULL) 
			{
				$$ = temp->type;
				/* For function in object*/
				if(temp->type->dataType == DT_PROC || temp->type->dataType == DT_FUNCTION)
				{
					$$->flag = 1;
					$$->funcAttScope = $1->attScope;
				}
				else
				{
					if(temp->token==PRIVATE) 
					{
						printf("(Error) :%s is private \n",temp->lexeme);
						numTypeError++;errorFreeType = 0; 
						$$=setBasicType(DT_ERROR);
					}	
					$$->flag=0;
				}
				$$->place = (char *)malloc(100);
				sprintf($$->place,"%s%s@%d",$1->place,$2->code,tempStack->val);
			}
			else
			{
				$$ = setBasicType(DT_ERROR);
				numTypeError++;errorFreeType = 0;
				printf("\n(Line %d) %s not found in scope of %s \n",line_number,$2->entry,$1->entry);
			}
		}
		else if($1->entry != NULL)
		{
			if($1->flag == 1)
			{
				stack *tempStack;
				Push(&tempStack, $1->funcAttScope);
				temp = getEntry($1->entry,tempStack);
			}
			else
				temp = getEntry($1->entry,scopeStack);
			if(temp == NULL || temp->type == NULL)
			{
				$$ = setBasicType(DT_ERROR);
			}
			else	
			{
				if(temp->type->dataType == DT_PROC || temp->type->dataType == DT_FUNCTION )
				{	$1->next = $2;
					$$ = $1;
					$$->counter = $2->counter+1;
					Type* temp1 = $$;
					for(i=1;i<=$$->counter;i++)
					{
						temp1 = temp1->next;
					}
					if($1->flag == 0)
					$$->place = (char *)malloc(100);
					sprintf($$->place,"%s%s",$1->place,$2->code);
				}
				else
				{
					$$ = setBasicType(DT_ERROR);
					numTypeError++;errorFreeType = 0; 
					 $$->next = NULL;
				}
			}
		}
		else
		{
			$$ = setBasicType(DT_ERROR); numTypeError++;errorFreeType = 0; 
			 $$->next = NULL; 
		}
		if(strcmp($1->entry,"WRITE")==0 || strcmp($1->entry,"READ")==0 || strcmp($1->entry,"WRITELN")==0 || strcmp($1->entry,"READLN")==0 )
		{
				$1->next = $2;
				$$ =$1;
				$$->counter = $2->counter+1;
		}
	
	}
  ; 
  
  
var_specifiers : LSQBRACK expr_list RSQBRACK 
	{
		$$ = setBasicType(DT_VOID);
		$$->counter = -2;
		Type* temp;
		temp = $2;
		$$->code = malloc(strlen($2->place)+$2->counter*5+3);
		char *tempPlace1 = (char*)malloc(strlen($2->place)+$2->counter*5+3);
		char *tempPlace2 = (char*)malloc(strlen($2->place)+$2->counter*5+3);
		while(temp!=NULL)	//appending expressions in tempPlace1
		{
			sprintf(tempPlace2,"%s,%s",tempPlace1,temp->place);
			strcpy(tempPlace1,tempPlace2);
			temp= temp->next;
		}
		sprintf($$->code,"%s",tempPlace1+1);
		//sprintf($$->code,"[%s]",$2->place);
	}
  | LSQBRACK RSQBRACK 
	{
		$$ = setBasicType(DT_VOID); 
		$$->counter = -2;
		 $$->code = "[]";
	}
  | LPAREN expr_list RPAREN 
	{
		$$ = setBasicType(DT_VOID); 
		$$->next = $2; 		//stroing the expr list in next
		$$->counter = $2->counter + 1; 
		$$->code = malloc(strlen($2->place)+10);
		sprintf($$->code,"");
	}
  | LPAREN RPAREN 
	{
		$$ = setBasicType(DT_VOID); 
		$$->code = "";
	}
  | DOT identifier  
	{
		$$ = $2; 
		$$ -> counter = -1; 
		$$->code = malloc(strlen($2->place)+10) ; 
		sprintf($$->code,".%s",$2->place);	
	}
  | UPARROW 
	{ 
		$$ = setBasicType(DT_VOID); 
		$$->counter = -2; 
		$$->code = "^"; 
	}
  ; 
  
elem : expr {$$=$1;}
  | expr DOTDOT expr  
	{
		 if($1->dataType == DT_INT && $3->dataType == DT_INT) 
		{
			 $$ = setBasicType(DT_SUBR); 
			 $$->place = get_new_temp(scopeStack->val); Add(scopeStack->val,SIZE_INT);
			// emitcode("DOTDOT",$$->place,$1->place,$3->place);
		} 
		else 
		{ 
			$$ = setBasicType(DT_ERROR); 
			numTypeError++;errorFreeType = 0;  
		}
	}
  ; 
  
literal : CHAR_STRING 
	{
		$$ = setBasicType(DT_STRING); 
		$$->width = strlen($1); 		//width to store_argument the string
		$$->entry = (char*) malloc(strlen($1)+1);
		sprintf($$->entry,"%s",$1);
		$$->next = NULL;
		$$->flag = CHAR_STRING;
		$$->place = $$->entry;
	}
  | ASCIICHAR {$$ = setBasicType(DT_STRING); }
  | CHAR_STRING literal {$$ = setBasicType(DT_STRING); }
  | ASCIICHAR literal {$$ = setBasicType(DT_STRING); }
  ; 
  
real_type_name : REALS {$$ = setBasicType(DT_REAL);}
  | SINGLE {$$ = setBasicType(DT_REAL);}
  | DOUBLE {$$ = setBasicType(DT_REAL);}
  ; 
  
ord_type_name : INTEGER {$$ = setBasicType(DT_INT);}
  | BOOLEAN {$$ = setBasicType(DT_BOOL);}
  | CHAR {$$ = setBasicType(DT_CHAR);}
  ; 
  
string_type_name : STRING {$$ = setBasicType(DT_STRING);}
  ; 
  
property_specifier_directives : DEFAULT 
	{
		$$ = setBasicType(DT_VOID); 
		$$->entry = "DEFAULT";
		$$->place = "DEFAULT";
	}
  | READ 
	{
		$$ = setBasicType(DT_PROC);
		$$->entry = "READ"; 
		$$->place = "READ";
	}
  | WRITELN 
	{
		$$ = setBasicType(DT_PROC); 
		$$->entry = "WRITELN";
		$$->place = "WRITELN";
	}
  | WRITE 
	{
		$$ = setBasicType(DT_PROC); 
		$$->entry = "WRITE"; 
		$$->place = "WRITE";
	}
  | store_argumentD 
	{
		$$ = setBasicType(DT_VOID); 
		$$->entry = "store_argumentD"; 
		$$->place = "store_argumentD";
	}
  | NODEFAULT 
	{
		$$ = setBasicType(DT_VOID); 
		$$->entry = "NODEFAULT"; 
		$$->place = "NODEFAULT";
	}
  | IMPLEMENTS
	{
		$$ = setBasicType(DT_VOID); 
		$$->entry = "IMPLEMENTS";
		$$->place = "IMPLEMENTS";
	}
  | WRITEONLY 
	{
		$$ = setBasicType(DT_VOID);
		$$->entry = "WRITEONLY";
		$$->place = "WRITEONLY";
	}
  | READONLY 
	{
		$$ = setBasicType(DT_VOID);
		$$->entry = "READONLY";
		$$->place = "READONLY"; 
	}
   ;
  
  
non_reserved : AT  {$$ = setBasicType(DT_VOID);}
  | ABSOLUTE {$$ = setBasicType(DT_VOID);}
  | ON {$$ = setBasicType(DT_VOID);}
  | NAME {$$ = setBasicType(DT_VOID);}
  | INDEX {$$ = setBasicType(DT_VOID);}
  | MESSAGE {$$ = setBasicType(DT_VOID);}
  | CONTAINS {$$ = setBasicType(DT_VOID);}
  | REQUIRES {$$ = setBasicType(DT_VOID);}
  | FORWARD {$$ = setBasicType(DT_VOID);}
  | OUT {$$ = setBasicType(DT_VOID);}
  ;

  
visibility_specifier : PUBLISHED {$$ = setBasicType(DT_VOID);}
  | PUBLIC {$$ = setBasicType(DT_VOID);}
  | PROTECTED {$$ = setBasicType(DT_VOID);}
  | PRIVATE {$$ = setBasicType(DT_VOID);}
  ; 
  
other : PACKAGE {$$ = setBasicType(DT_VOID);}
  | UNIT {$$ = setBasicType(DT_VOID);}
  | LIBRARY {$$ = setBasicType(DT_VOID);}
  | PROGRAM {$$ = setBasicType(DT_VOID);}
  | EXTERNAL {$$ = setBasicType(DT_VOID);}
  ;
  
identifier : IDENT 
	{
		sym* temp;
		temp = getEntry($1,scopeStack);
		if(temp == NULL || temp->type == NULL) 	//entry will be created during variable declaration (var_name)
		{
			$$ = setBasicType(DT_ERROR);
			$$->entry = yytext;
			$$->code = "";
			$$->place = $$->entry;	
		}
		else	
		{
			$$ = setType(temp->type);
			$$->attScope = temp->type->attScope;
			$$->entry = getEntry($1,scopeStack)->lexeme;
			$$->next =  temp->type->next;	//if ident list
			$$->code = "";
			$$->place = (char*)malloc (strlen($$->entry));
			sprintf($$->place,"%s@%d",$$->entry,temp->myScope);	//putting variable name along with scope as place
		}
	}
  | real_type_name {$$=$1;}
  | ord_type_name  {$$=$1;}
  | string_type_name {$$=$1;}
  | property_specifier_directives {$$=$1;}
  | non_reserved {$$=$1;}
  | other {$$=$1;}
  ;

%%
void errorLog(){
if (numError>1 && numTypeError==0)printf(" \n ** Your program was erroneous. %d syntax errors found. ** \n\n",numError);
else if (numError==0 && numTypeError>0)printf(" \n ** Your program was erroneous.  ** \n\n");
if (numError>0 && numTypeError>0)printf(" \n ** Your program was erroneous. ** \n\n");
}

void yyerror(char *s) {
   errorFree = 0;
numError = numError + 1;
printf("(Line %d) Syntax Error, Unexpected token : %s \n",line_number,yytext);

}

int main()
{
	char *file_name;
	file_name=(char*)malloc(40*sizeof(char));
	yyparse();
	Print();
	PrintHeader();
	if(errorFreeType == 1 && errorFree == 1)
	{
		printCode();
		strcpy(file_name,"output.s");	
		data = fopen("data","w+");
		text = fopen("text","w+");
		fprintf(data,".data\n");
		fprintf(data,"\tstr: .asciiz \" Program ended. \\n\" \n");
		fprintf(data,"\tnewLine: .asciiz \"\\n\" \n");
		
		for(i=0;i<MAX_SCOPES;i++)
		{
			if(scopeHeader[i] != NULL)
				fprintf(data,"\tscope%d: .space 4\n",i);
		}
		
		fprintf(text,"\n.text\n");
		Codegen();
		fclose(data);
		fclose(text);
		data = fopen("data","r");
		text = fopen("text","r");
		FILE *out = fopen(file_name,"w+");
		char* d = (char*)malloc(20000*sizeof(char));
		char* t = (char*)malloc(20000*sizeof(char));
		int dataFile = fread((void*)d,sizeof(char),20000,data);
		int textFile = fread((void*)t,sizeof(char),20000,text);
		strcat(d,t);
		fwrite(d,sizeof(char), textFile+dataFile,out);
		fclose(data);
		fclose(text);
		fclose(out);
}
}
