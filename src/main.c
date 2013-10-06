#include <convert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define  OPERATION_PLUS '+'

struct operand 
{
	char value[100];
	struct operand *next;
	struct operand *prev;
};


void executeCommand( char command[] ) 
{
	int commandLen = strlen(command);

	struct operand *initVal = NULL;
	struct operand *currentVal = NULL;
	initVal = (struct operand*) calloc( sizeof(struct operand ) , 1 ) ;
	currentVal = initVal;

	currentVal->next = NULL;
	currentVal->prev = NULL;

	char ch ;

	int i = 0 ;
	int v_iter = 0 ;

	int params = 1 ; 

	while (i < commandLen ) {
		if ( command[i] == OPERATION_PLUS || i == commandLen || command[i] == '\n' || command[i] == EOF){
			printf("value: %s, char: %c \n" , currentVal->value , command[i] ) ;
			currentVal->next = (struct operand * ) calloc( sizeof(struct operand), 1 ) ;
			currentVal->next->next = NULL;
			currentVal->next->prev = currentVal;
			currentVal = currentVal->next;
			v_iter = 0;
			params +=1;
		} else if ( command[i] >= '0'  && command[i] <= '9'  || command[i] == '.') {
			currentVal->value[v_iter] = command[i];			
			v_iter++;
			printf("currentoperand: %p, char: %c, value: %s \n" , currentVal, command[i] , currentVal->value);
		} else if ( command[i] == ' ' || command[i] == '\t') {
			// skp 
		} else {
			printf("met char: %c \n" , command[i] ) ;
			break;
		}
		i++;
	}

	double result;

	do {
		printf("operandId: %p, value: %s , prev : %p \n" , currentVal, currentVal->value, currentVal->prev) ;
		result += p_atof( currentVal->value , strlen(currentVal->value));
		currentVal = currentVal->prev;
		
	} while(currentVal != NULL);

	printf("result: %f \n" , result ) ;

}


int main(int argc, char *argv[])
{
	char ch ;
	char command[100];
	bzero(command, 100) ;
	int i = 0;
	while( ( ch = getchar() ) != EOF  && ch != '\n' && i < 100){
		command[i++] = ch;
	}

	executeCommand(command);
	return 0;
}
