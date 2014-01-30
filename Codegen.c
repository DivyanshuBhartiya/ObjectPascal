#include "Definitions.h"
extern unsigned int quadId;
extern char tempName[256];
extern int tempArray[MAX_TEMP_SIZE];
extern FILE *data,*text;

void move_argument(char *s,char* reg){
	stack* codeStack = malloc(sizeof(stack));
	codeStack = NULL;
	int offset;
	char* k;
	int d;
	fprintf(text,"\tmtc1 $%s,$f0\n",reg);
	fprintf(text,"\tcvt.d.w $f0,$f0\n");
	if(strncmp(s,"Result",6)==0) {
		fprintf(text,"\ts.d $f0,0($sp)\n");
	} // storing Result in $s0

	if( s[0] == '_') { // temporary
		offset = tempArray[atoi(s+3)];
		fprintf(text,"\ts.d $f0,-%d($sp)\n",offset);
	}
	else { // identifier
		k = strtok(s,"@"); // strip the name
		d = atoi(strtok(NULL,"@"));
		Push(&codeStack,d); 
		
		offset = getEntry(k,codeStack)->offset;

		fprintf(text,"\tlw $t3,scope%d\n",d);
		fprintf(text,"\ts.d $f0,-%d($t3)\n",offset);

	}
	
}

void load_argument(char *s, char* t){
	stack* codeStack = malloc(sizeof(stack));
	codeStack = NULL;
	int offset;
	char *k,*special,*m,*n;
	int attScope;
	char *objRec;
	strcpy(tempName,s);
	int d;
	fprintf(text,"\t");
	if( s[0] == '_') { //temporary
		offset = tempArray[atoi(s+3)];
		fprintf(text,"lw $%s,-%d($sp)\n",t,offset);
	}	
	else if(isdigit(s[0])) { //number
		fprintf(text,"li $%s,%s\n",t,s);
	}  
	else { // identifier
		objRec = strtok(tempName,"."); 
		if(strlen(s)!=strlen(objRec)) { // record or object's identifier
			special = strtok(NULL,"."); 
			k = strtok(special,"@"); 
			attScope = atoi(strtok(NULL,"@")); 
			Push(&codeStack,attScope); 
			offset = getEntry(k,codeStack)->offset; // offset of k in scope 2
			Pop(&codeStack);
			k = strtok(objRec,"@"); // gives V
			d = atoi(strtok(NULL,"@")); // gives 1
			Push(&codeStack,d);
			attScope = getEntry(k,codeStack)->offset;
			fprintf(text,"lw $t3,scope%d\n",d);
			fprintf(text,"\tlw $%s,-%d($t3)\n",t,(offset+attScope)); 
		}
		else { // identifier
		// Following code works for both c@45 and c@45[_t1_13]
		k = strtok(s,"@"); // strip the name
		m = strtok(NULL,"[");
		n=strtok(NULL,"]");
		if(n == NULL) d = atoi(strtok(m,"@"));
		else d = atoi(m);
		Push(&codeStack,d); 
		offset = getEntry(k,codeStack)->offset;
		if(n != NULL)
		{
			load_argument(n,"t4");
			fprintf(text,"\tli $t5 , 4\n");
			fprintf(text,"\tmul $t4, $t4, $t5\n");
			fprintf(text,"\tlw $t3, scope%d\n",d);
			fprintf(text,"\tsub $t3 ,$t3, $t4\n");
		}
		else
		{
			fprintf(text,"\tlw $t3, scope%d\n",d);
		}
		
		fprintf(text,"\tlw $%s, -%d($t3)\n",t,offset);
		}
	}
	
}



void store_argument(char* s,char* reg){
	stack* codeStack = malloc(sizeof(stack));
	codeStack = NULL;
	int offset;
	char *k,*m,*n;
	char* special;
	int attScope;
	char *objRec;
	strcpy(tempName,s);
	int d;
	if(strncmp(s,"Result",6)==0) {
		fprintf(text,"\tsw $%s,0($sp)\n",reg);
	} 
	if( s[0] == '_') { // temporary
		offset = tempArray[atoi(s+3)];
		fprintf(text,"\tsw $%s,-%d($sp)\n",reg,offset);
	}
	else { // identifier
		objRec = strtok(tempName,"."); 
		if(strlen(s)!=strlen(objRec)) { 
			special = strtok(NULL,"."); 
			k = strtok(special,"@"); 
			attScope = atoi(strtok(NULL,"@")); 
			Push(&codeStack,attScope); 
			offset = getEntry(k,codeStack)->offset; 
			Pop(&codeStack);
			k = strtok(objRec,"@");
			d = atoi(strtok(NULL,"@")); 
			Push(&codeStack,d);
			attScope = getEntry(k,codeStack)->offset;
			fprintf(text,"lw $t3,scope%d\n",d);
			fprintf(text,"\tsw $%s,-%d($t3)\n",reg,(offset+attScope)); 
		}
		else { // identifier
		k = strtok(s,"@"); // strip the name
		m = strtok(NULL,"[");
		n=strtok(NULL,"]");
		if(n == NULL) d = atoi(strtok(m,"@"));
		else d = atoi(m);
		Push(&codeStack,d);
		
		offset = getEntry(k,codeStack)->offset;
		if(n != NULL)
		{
			load_argument(n,"t4");
			fprintf(text,"\tli $t5 , 4\n");
			fprintf(text,"\tmul $t4, $t4, $t5\n");
			fprintf(text,"\tlw $t3, scope%d\n",d);
			fprintf(text,"\tsub $t3 ,$t3, $t4\n");
		}
		else
		{
			fprintf(text,"\tlw $t3,scope%d\n",d);
		}
		fprintf(text,"\tsw $%s,-%d($t3)\n",reg,offset);

		}
	}
		
}

void load_argumentR(char* s,char* t) {
	stack* codeStack = malloc(sizeof(stack));
	codeStack = NULL;
	int offset;
	char *k,*special,*m,*n;
	strcpy(tempName,s);
	int attScope;
	char *objRec;
	int d;
	fprintf(text,"\t");
	if( s[0] == '_') { //temporary
		offset = tempArray[atoi(s+3)];
		fprintf(text,"l.d $%s,-%d($sp)\n",t,offset);
	}	
	else if(isdigit(s[0])) { //number
		fprintf(text,"li.d $%s,%f\n",t,atof(s));
		
	}  
	else { // identifier
		objRec = strtok(tempName,"."); 
		if(strlen(s)!=strlen(objRec)) { 
			special = strtok(NULL,"."); 
			k = strtok(special,"@"); 
			attScope = atoi(strtok(NULL,"@")); 
			Push(&codeStack,attScope); 
			offset = getEntry(k,codeStack)->offset; 
			Pop(&codeStack);
			k = strtok(objRec,"@"); 
			d = atoi(strtok(NULL,"@")); 
			Push(&codeStack,d);
			attScope = getEntry(k,codeStack)->offset;
			fprintf(text,"lw $t3,scope%d\n",d);
			fprintf(text,"\tl.d $%s,-%d($t3)\n",t,(offset+attScope)); 
		}
		else { 
		k = strtok(s,"@"); 
		m = strtok(NULL,"[");
		n=strtok(NULL,"]");
		if(n == NULL) d = atoi(strtok(m,"@"));
		else d = atoi(m);
		Push(&codeStack,d);
		offset = getEntry(k,codeStack)->offset;
		if(n != NULL)
		{
			load_argument(n,"t4");
			fprintf(text,"\tli $t5 , 8\n");
			fprintf(text,"\tmul $t4, $t4, $t5\n");
			fprintf(text,"\tlw $t3, scope%d\n",d);
			fprintf(text,"\tsub $t3 ,$t3, $t4\n");
		}
		else
		{
			fprintf(text,"\tlw $t3, scope%d\n",d);
		}
		
		fprintf(text,"\tl.d $%s, -%d($t3)\n",t,offset);
		}
	}
	
}
void store_argumentR(char* s,char* reg){
	stack* codeStack = malloc(sizeof(stack));
	codeStack = NULL;
	int offset;
	int attScope;
	char *objRec;
	char *k,*special,*m,*n;
	strcpy(tempName,s);
	int d;
	if(strncmp(s,"Result",6)==0) {
		fprintf(text,"\ts.d $%s,0($sp)\n",reg);
	} // storing Result in $s0

	if( s[0] == '_') { // temporary
		offset = tempArray[atoi(s+3)];
		fprintf(text,"\ts.d $%s,-%d($sp)\n",reg,offset);
	}
	else { // identifier
		objRec = strtok(tempName,"."); 
		if(strlen(s)!=strlen(objRec)) { 
			special = strtok(NULL,"."); 
			k = strtok(special,"@"); 
			attScope = atoi(strtok(NULL,"@")); 
			Push(&codeStack,attScope); 
			offset = getEntry(k,codeStack)->offset;
			Pop(&codeStack);
			k = strtok(objRec,"@"); 
			d = atoi(strtok(NULL,"@"));
			Push(&codeStack,d);
			attScope = getEntry(k,codeStack)->offset;
			fprintf(text,"lw $t3,scope%d\n",d);
			fprintf(text,"\ts.d $%s,-%d($t3)\n",reg,(offset+attScope)); 
		}
		else { // identifier
		k = strtok(s,"@"); 
		m = strtok(NULL,"[");
		n=strtok(NULL,"]");
		if(n == NULL) d = atoi(strtok(m,"@"));
		else d = atoi(m);
		Push(&codeStack,d); 
		
		offset = getEntry(k,codeStack)->offset;
		if(n != NULL)
		{
			load_argument(n,"t4");
			fprintf(text,"\tli $t5 , 8\n");
			fprintf(text,"\tmul $t4, $t4, $t5\n");
			fprintf(text,"\tlw $t3, scope%d\n",d);
			fprintf(text,"\tsub $t3 ,$t3, $t4\n");
		}
		else
		{
			fprintf(text,"\tlw $t3,scope%d\n",d);
		}
		fprintf(text,"\ts.d $%s,-%d($t3)\n",reg,offset);

	}
	}
}

void Codegen() {
	//int SIZE = getActivationSize();
	
	stack* codeStack = malloc(sizeof(stack));
	codeStack = NULL;
	int paramNum = 0;
	int numWrites = 1;
	int offset;
	int i,j,scopeId;
	int flag = 0;
	int curScopeSize = 100;
	char *s,*k,*m,*n,*arg1,*arg2;
	char *special;
	for(i=0;i<quadId;i++) {
		//printf("\nquadId:%d",i);
		
					
		if(codelist[i]->op!=NULL) {
			fprintf(text,"L%d:\n",i);
			if(strcmp(codelist[i]->op,":=")==0 ) {
				//printf("\nCalling store_argument on %s",codelist[i]->res);
				strcpy(tempName,codelist[i]->res);
				if(strlen(codelist[i]->res) != strlen(strtok(tempName,"."))) { // record/object
					special  = strtok(NULL,".");
					k = strtok(special,"@");
					Push(&codeStack,atoi(strtok(NULL,"@"))); 
					//printf("\nk:%s",k);
				}
				else {
					strcpy(tempName,codelist[i]->res);
					k = strtok(tempName,"@");
					Push(&codeStack,atoi(strtok(NULL,"@"))); 
					//printf("\nk:%s",k);
				}
				if(strcmp(codelist[i]->arg1,"TRUE") == 0 )
					codelist[i]->arg1 = "1";
				else if(strcmp(codelist[i]->arg1,"FALSE") == 0)
					codelist[i]->arg1 = "0";

				if (getEntry(k,codeStack)->type->dataType == DT_REAL) { 
					//printf("storing real");
					load_argumentR(codelist[i]->arg1,"f0");
					store_argumentR(codelist[i]->res,"f0");
					//fprintf(text,"\tli $v0,3\n\tmov.d $f12,$f0\n\tsyscall\n");
				}
				else {
					
					load_argument(codelist[i]->arg1,"t0");
					store_argument(codelist[i]->res,"t0");
					//fprintf(text,"\tli $v0,1\n\tmove $a0,$t0\n\tsyscall\n");
				
				}
				
				
				codeStack = NULL;
				
				//fprintf(text,"\tli $v0,4\n\tla $a0,newLine\n\tsyscall\n");
								
			}
			else if(strncmp(codelist[i]->op,"int",3) ==0 ) {
				s = codelist[i]->op = codelist[i]->op+3;
				load_argument(codelist[i]->arg1,"t0");
				load_argument(codelist[i]->arg2,"t1");
				fprintf(text,"\t");
				if (strcmp(s,"+")==0 ) 
				{
					fprintf(text,"add $t2,$t0,$t1\n");
				}
				else if(strcmp(s,"-")==0) 
				{
					fprintf(text,"sub $t2,$t0,$t1\n");
				}
				else if(strcmp(s,"/")==0) 
				{
					fprintf(text,"div $t2,$t0,$t1\n");
				}
				else if(strcmp(s,"*")==0) 
				{	
					fprintf(text,"mul $t2,$t1,$t0\n");
				}
				else if(strcmp(s,"MOD")==0) 
				{
					fprintf(text,"rem $t2,$t1,$t0\n");
				}
				else if(strcmp(s,"SHL")==0) 
				{
					fprintf(text,"sll $t2,$t1,$t0\n");
				}
				else if(strcmp(s,"SHR")==0) 
				{
					fprintf(text,"sra $t2,$t1,$t0\n");
				}
				else if(strcmp(s,"AND")==0) 
				{
					fprintf(text,"and $t2,$t1,$t0\n");
				}
				else if(strcmp(s,"OR")==0) 
				{
					fprintf(text,"or $t2,$t1,$t0\n");
				}
				else if(strcmp(s,"XOR")==0) 
				{
					fprintf(text,"xor $t2,$t1,$t0\n");
				}
				store_argument(codelist[i]->res,"t2");
				
			}
			else if(strncmp(codelist[i]->op,"real",4) ==0 ) {
				s = codelist[i]->op = codelist[i]->op+4;
				load_argumentR(codelist[i]->arg1,"f0");
				load_argumentR(codelist[i]->arg2,"f2");
				fprintf(text,"\t");
				if (strcmp(s,"+")==0 ) 
				{
					fprintf(text,"add.d $f4,$f0,$f2\n");
				}
				else if(strcmp(s,"-")==0) 
				{
					fprintf(text,"sub.d $f4,$f0,$f2\n");
				}
				else if(strcmp(s,"/")==0) 
				{
					fprintf(text,"div.d $f4,$f0,$f2\n");
				}
				else if(strcmp(s,"*")==0) 
				{	
					fprintf(text,"mul.d $f4,$f2,$f0\n");
				}
				store_argumentR(codelist[i]->res,"f4");
				
			}
			else if(strcmp(codelist[i]->op,"goto")==0) {
				fprintf(text,"\tj L%s\n",codelist[i]->arg1);				
			}
			else if(strcmp(codelist[i]->op,"Cgoto")==0) {
				strtok(codelist[i]->arg2," "); // removed if
				arg1 = strtok(NULL," ");
				s = strtok(NULL," "); // relop
      				arg2 = strtok(NULL," ");

				load_argument(arg1,"t0"); // first arg
				load_argument(arg2,"t1"); // second arg
			

				fprintf(text,"\t");
				if (strcmp(s,"<")==0 ) 
				{
					fprintf(text,"blt $t0,$t1,L%s\n",codelist[i]->arg1);
				}
				else if (strcmp(s,">")==0 ) 
				{
					fprintf(text,"bgt $t0,$t1,L%s\n",codelist[i]->arg1);
				}
				else if (strcmp(s,"<=")==0 ) 
				{
					fprintf(text,"ble $t0,$t1,L%s\n",codelist[i]->arg1);
				}
				else if (strcmp(s,">=")==0 ) 
				{
					fprintf(text,"bge $t0,$t1,L%s\n",codelist[i]->arg1);
				}
				else if (strcmp(s,"<>")==0 ) 
				{
					fprintf(text,"bne $t0,$t1,L%s\n",codelist[i]->arg1);
				}
				else if (strcmp(s,"=")==0 ) 
				{
					fprintf(text,"beq $t0,$t1,L%s\n",codelist[i]->arg1);
				}
				
				
			}
			else if(strcmp(codelist[i]->op,"START")==0) {
				
				if(strcmp(codelist[i]->res,"main") == 0) {
					fprintf(text,"main: \n",s);
					fprintf(text,"\tsw $sp,scope1\n");
					curScopeSize = scopeHeader[1]->size;
					//printf("%d  #curScopeSize = %d\n",i,curScopeSize);
				}
				else {
					strcpy(tempName,codelist[i]->res); // shape@1.draw@2
					//printf("\n%s\n",codelist[i]->res);
					if( strchr(codelist[i]->res,'.') != NULL ){ //object's proc
						arg1 = strtok(tempName,".");
						arg2 = strtok(NULL,"."); 
						s = strtok(arg2,"@");
						Push(&codeStack,atoi(strtok(NULL,"@")));
						curScopeSize = SizeOf(getEntry(s,codeStack)->type->attScope);
						fprintf(text,"%s: \n",s);
					}
					else {
						s = strtok(codelist[i]->res,"@");
						Push(&codeStack,atoi(strtok(NULL,"@")));
						curScopeSize = scopeHeader[getEntry(s,codeStack)->type->attScope]->size;
						fprintf(text,"%s: \n",s);
					}
					
				}
				fprintf(text,"\tsw $ra,-8($sp)\n");
			}
			else if(strcmp(codelist[i]->op,"RETURN")==0) {
				
				fprintf(text,"\tlw $t0,-12($sp)\n");
				strcpy(tempName,codelist[i]->res);
				if( strchr(codelist[i]->res,'.') != NULL ){ //object's proc
						arg1 = strtok(tempName,".");
						arg2 = strtok(NULL,"."); 
						s = strtok(arg2,"@");
						Push(&codeStack,atoi(strtok(NULL,"@")));
						j = getEntry(s,codeStack)->type->attScope;
						fprintf(text,"\tsw $t0,scope%d\n",j);
				}
				else {
					s = strtok(codelist[i]->res,"@");
					j = atoi(strtok(NULL,"@"));
					Push(&codeStack,j);
					j = getEntry(s,codeStack)->type->attScope;
					fprintf(text,"\tsw $t0,scope%d\n",j);
					
				}
				fprintf(text,"\tlw $ra,-8($sp)\n");
				fprintf(text,"\tjr $ra\n"); // return
			}
			else if(strcmp(codelist[i]->op,"call") == 0 && strcmp(codelist[i]->arg1,"WRITE") == 0){	
			}
			else if(strcmp(codelist[i]->op,"call") == 0 && strcmp(codelist[i]->arg1,"WRITELN") == 0){
				fprintf(text,"\tli $v0,4\n\tla $a0,newLine\n\tsyscall\n");
			}
			else if(strcmp(codelist[i]->op,"call") == 0 && strcmp(codelist[i]->arg1,"READ") == 0){
				
			}
			else if(strcmp(codelist[i]->op,"call") == 0 && strcmp(codelist[i]->arg1,"READLN") == 0){
				
			}
			else if(strcmp(codelist[i]->op,"call") == 0) { 
				paramNum = 0;
				
				fprintf(text,"\tsub $sp,$sp,%d\n",curScopeSize);	
				strcpy(tempName,codelist[i]->arg1);
				if( strchr(codelist[i]->arg1,'.') != NULL ){ //object's proc
						arg1 = strtok(tempName,".");
						arg2 = strtok(NULL,"."); 
						s = strtok(arg2,"@");
						Push(&codeStack,atoi(strtok(NULL,"@")));
						j = getEntry(s,codeStack)->type->attScope;
						fprintf(text,"\tlw $t0,scope%d\n",j);
				}
				else {
					s = strtok(codelist[i]->arg1,"@");
					j = atoi(strtok(NULL,"@"));
					Push(&codeStack,j);
					j = getEntry(s,codeStack)->type->attScope;
					fprintf(text,"\tlw $t0,scope%d\n",j);
				}
				fprintf(text,"\tsw $t0,-12($sp)\n"); // old_sp
				fprintf(text,"\tsw $sp,scope%d\n",j); // put new_sp
		
				fprintf(text,"\tjal %s\n",s);
				fprintf(text,"\tadd $sp,$sp,%d\n",curScopeSize);
				if(codelist[i]->res != NULL) 
				{
					flag = 0;
					s = codelist[i]->res;
					if(s[0] == '_') { // temporary
						offset = tempArray[atoi(s+3)];
						if(tempArray[atoi(s+3)+1]  - tempArray[atoi(s+3)] >4)
							flag =1;
					}
					else { // identifier
						k = strtok(s,"@"); // strip the name
						Push(&codeStack,atoi(strtok(NULL,"@"))); // pushing scope into codeStack
						offset = getEntry(k,codeStack)->offset;
						if (getEntry(k,codeStack)->type->dataType == DT_REAL)
							flag =1;
				
					}
					if(flag = 0) {
						fprintf(text,"\tlw $t3,-%d($sp)\n",curScopeSize);
						fprintf(text,"\tsw $t3,-%d($sp)\n",offset);
					}
					else { // return value was real
						fprintf(text,"\tl.d $f4,-%d($sp)\n",curScopeSize);
						fprintf(text,"\ts.d $f4,-%d($sp)\n",offset);
					}
				}
			}
			else if(strcmp(codelist[i]->op,"paramRI")==0)
			{
				fprintf(text,"\tli $v0, 5 \n\tsyscall \n");
				store_argument(codelist[i]->res,"v0");
				
			}
			else if(strcmp(codelist[i]->op,"paramRF")==0)
			{
				fprintf(text,"\tli $v0, 6 \n\tsyscall \n");
				store_argumentR(codelist[i]->res,"f0");
			}
			else if(strcmp(codelist[i]->op,"paramWI")==0)
			{
				load_argument(codelist[i]->res,"t0");
				fprintf(text,"\tmove $a0, $t0\n");
				fprintf(text,"\tli $v0, 1 \n\tsyscall \n");
			}
			else if(strcmp(codelist[i]->op,"paramWF")==0)
			{
				load_argumentR(codelist[i]->res,"f4");
				fprintf(text,"\tmov.d $f12, $f4\n");
				fprintf(text,"\tli $v0, 3 \n\tsyscall \n");
			}
			else if(strcmp(codelist[i]->op,"paramWS")==0)
			{	
				fprintf(data,"\tprint%d : .asciiz \"%s\"\n",numWrites,strtok(((codelist[i]->res)+1),"\'"));
				  
				  fprintf(text,"\tla $a0,print%d\n",numWrites);
				  numWrites++;
				  fprintf(text,"\tli $v0, 4 \n\tsyscall \n");
			}
			
			else if(strcmp(codelist[i]->op,"paramI")==0) {
					load_argument(codelist[i]->res,"t3");
					fprintf(text,"\tsw $t3,-%d($sp)\n",(paramNum+20)+curScopeSize);
					paramNum = paramNum + 4;					
					
			}
			else if(strcmp(codelist[i]->op,"paramF")==0) {
					load_argumentR(codelist[i]->res,"f4");
					fprintf(text,"\ts.d $f4,-%d($sp)\n",(paramNum+20)+curScopeSize);
					paramNum = paramNum+8;					
			}
			else if(strcmp(codelist[i]->op,"paramB")==0) {
					load_argument(codelist[i]->res,"t3");
					fprintf(text,"\tsw $t3,-%d($sp)\n",(paramNum+20)+curScopeSize);
					paramNum = paramNum + 4;									
			}
			else if(strcmp(codelist[i]->op,"-")==0) {
				load_argument(codelist[i]->arg1,"t0");
				fprintf(text,"\tsub $t3,$zero,$t0\n");
				store_argument(codelist[i]->res,"t3");				
			}
			else if(strcmp(codelist[i]->op,"+")==0) {
				load_argument(codelist[i]->arg1,"t0");
				store_argument(codelist[i]->res,"t0");				
			}
			else if(strcmp(codelist[i]->op,"<IntToReal>")==0) {
				load_argument(codelist[i]->arg1,"t0");
				move_argument(codelist[i]->res,"t0"); // implements mtcz followed by store_argument
			}
		}	
	}
	fprintf(text,"L%d:\n\tli $v0,4\n\tla $a0,str\n\tsyscall\n\tli $v0,10\n\tsyscall",i);
}
