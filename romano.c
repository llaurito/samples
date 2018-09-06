/******************************************************************************

CONVERTE NÚMERO ARÁBICO EM ROMANO OU VICE-VERSA

DATA: 06/09/2018

AUTOR: LUIS LAURITO - +55 (11) 996-852-658

*******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


char input[80];
int numero;
char *romanos[4][9] = { "I","II","III","IV","V","VI","VII","VIII","IX",
						"X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
						"C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
						"M","MM","MMM","MMMM"};

char romano_algarismo[7] = {'I','V','X','L','C','D','M'};
unsigned romano_valor[7] = {1,5,10,50,100,500,1000};

int a_para_romano(int input);
int romano_para_a(char *input);

int main()
{
    printf("Informe o número: ");
    scanf("%s",input);

    numero=atoi(input);
    
    if (numero==0) {
        printf("Informado um número Romano, convertendo para Arábico\n\n");
        printf("\nArábico: %i\n",romano_para_a(input));
    }
    else {
        printf("Informado um número Arábico, convertendo para Romano\n\n");
        numero=a_para_romano(numero);
    }
    return 0;
}

///////////////////////////////////////////
//      CONVERTE ARABICO PARA ROMANO     //
///////////////////////////////////////////
      
int a_para_romano(int input)
{
	int cont,ptr,r;
	char resultado[80]={"\0"};

	for(cont=1000,ptr=3; cont>=1; cont=cont/10,ptr--)
	{
		r = input/cont;

		if (r >= 1)
		{
			input = input % cont;
			strcat(resultado,romanos[ptr][r-1]);
		}
	}
	printf("\nRomano: %s",resultado);
	return (0);
}

///////////////////////////////////////////
//      CONVERTE ROMANO PARA ARABICO     //
///////////////////////////////////////////
int romano_para_a(char *input)

{
	unsigned total=0,cont;
	int i=strlen(input)-1;
    int ultimo;
    
    for (cont = 0; cont<7; cont++)
	{
	    if(*(input+i) == romano_algarismo[cont]) {
	        total += romano_valor[cont];
	        ultimo = romano_valor[cont];
	        break;
	    }
	}
	
	i--;
	
	while(i>=0)
	{
	    for (cont = 0; cont<7; cont++)
		{
		    if(*(input+i) == romano_algarismo[cont]) {
		        if (romano_valor[cont] < ultimo)
		            total -= romano_valor[cont];
		        else {
		            total += romano_valor[cont];
		            ultimo = romano_valor[cont];
		        }
		        break;
		    }
		}
		i--;
	}// end while
	return(total);
}

