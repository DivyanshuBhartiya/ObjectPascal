#include "Definitions.h"
extern unsigned int quadId;


void emitcode(char *operation, char * operand1, char * operand2, char * operand3 ) {
	codelist[quadId] = (code *)malloc(sizeof(code));
	codelist[quadId]->op = (char *)malloc(100);
	codelist[quadId]->op = NULL;
	codelist[quadId]->res = (char *)malloc(100);
	codelist[quadId]->res = NULL;	
	codelist[quadId]->arg1 = (char *)malloc(100);
	codelist[quadId]->arg1 = NULL;
	codelist[quadId]->arg2 = (char *)malloc(100);
	codelist[quadId]->arg2 = NULL;
	
	if(operation != NULL)
		codelist[quadId]->op = strdup(operation);

	if(operand1 !=NULL)
        	 codelist[quadId]->res = strdup(operand1);

	if(operand2 !=NULL)
         	codelist[quadId]->arg1 = strdup(operand2);

         if(operand3 !=NULL)
		codelist[quadId]->arg2 = strdup(operand3);
	
	 quadId++ ;

}

void printCode()
{
  	int i;
	for (i = 0; i < quadId; i++)
	{
		printf("%d:\t", i); 
		if(codelist[i]!=NULL) 
		{
			if(strcmp(codelist[i]->op,"Cgoto")==0 && codelist[i]->arg2!=NULL) 
			{
				if(codelist[i]->arg2!=NULL)
					printf("%s\t",codelist[i]->arg2);
				if(codelist[i]->op!=NULL)
	                		printf("%s\t",((codelist[i]->op)+1));
	//                 	if(codelist[i]->res!=NULL)  
	// 			printf("%s\t",codelist[i]->res);
				if(codelist[i]->arg1!=NULL)
					printf("%s\t",codelist[i]->arg1);
			}
			else 
			{
		                if(codelist[i]->op!=NULL)
		                	printf("%s\t",codelist[i]->op);
		                if(codelist[i]->res!=NULL)  
					printf("%s\t",codelist[i]->res);
				if(codelist[i]->arg1!=NULL)
					printf("%s\t",codelist[i]->arg1);
				if(codelist[i]->arg2!=NULL)
					printf("%s\t",codelist[i]->arg2);
			}
			printf("\n");
		}
    	}	
	printf("\n");
}	

void ChangeLabel(char *s,int i) {
	codelist[i]->res = s;	
}
