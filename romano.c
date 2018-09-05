////////////////////////////////////////////////////////////
//                                                        //
// CONVERTE NUMERO ARABICO EM ROMANO E VICE-VERSA         //
//                                                        //
// DATA: 05/09/2018                                       //
//                                                        //
// AUTOR: LUIS LAURITO - +55 (11) 996-852-658             //
//                                                        //
////////////////////////////////////////////////////////////

#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

	char input[80];
	int digit;


char *romanos[4][9] = { "I","II","III","IV","V","VI","VII","VIII","IX","X",
						"XX","XXX","XL","L","LX","LXX","LXXX","XC","C","CC",
						"CCC","CD","D","DC","DCC","DCCC","CM",
						"M","MM","MMM"};

char romano_algarismo[7] = {'I','V','X','L','C','D','M'};
unsigned romano_valor[7] = {1,5,10,50,100,500,1000};

char *a_para_romano(int input);
int romano_para_a(char *input);

///////////////////////////////////////////
//      CONVERTE ARABICO PARA ROMANO     //
///////////////////////////////////////////
      
char *a_para_romano(int input)
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
	return (resultado);
}

///////////////////////////////////////////
//      CONVERTE ROMANO PARA ARABICO     //
///////////////////////////////////////////
int romano_para_a(char *input)

{
	unsigned total=0,cont,cont1;

	while(*input != NULL)
	{
		if(*input == romano_algarismo[6])	// COMPARA COM ´M´
			total += romano_valor[6];		// SOMA 1000
		else
		{
			for (cont = 0; cont<6; cont++)
			{
				if (*input == romano_algarismo[cont])
				{
					// SE ALGARISMO DA DIREITA FOR MAIOR DO QUE O ATUAL, SUBTRAI. EX.: IX
					
					for (cont1=cont+1; cont1<6; cont1++)
						if (*(input+1)==romano_algarismo[cont1])
						{
							total +=(romano_valor[cont1] - romano_valor[cont]);
							input++;
							break;
						}
						// SE ALGARISMO DA DIREITA FOR MENOR DO QUE O ATUAL, SOMA. EX.: XI
						
						if (cont1==6)
							total += romano_valor[cont];
						break;
				}// end if
			}// end for
		} // end else
		input++; 
	}// end while
	return(total);
}

main()
{
  char input[80], A,B,C, resp;
	int numero,opcao;

	do{
		PRINCIPAL:
			cout<<"\n************************************************************";
			cout<<"\n**	PROGRAMA PARA CONVERTER ARÁBICO EM ROMANO E VICE-VERSA **";
			cout<<"\n************************************************************";
			cout<<"\n\nPressione 1 para converter Arábico para Romano";
			cout<<"\nPressione 2 para converter Romano para Arábico";
			cout<<"\n\n\n\nQual é a sua opção?  ";
			cin>>choice;

		switch(choice)
		{
		case 1:
		}
			printf("\nEntre o número Arábico: ");
				scanf("%s",input);
				if (isdigit(input[0]))
				{
					numero = atoi(input);
					if(numero >= 3900|| numero <=0)
						printf("\nSó pode ser entre 1 e 3899 ");
					else
						printf("\nO número Romano é %s",a_para_romano (numero));

				}
					else
						cout<<"\nEntrada Incorreta! Favor corrigir";
						
						goto CONTINUA;
		}
		
		case 2:
		{
			printf("\nEntre um número Romano em letras maiúsculas: ");	
			cin>>input;
			printf("\nO número Arábico é %d",romano_para_a(input));
			getch();
			goto CONTINUA;
		}
		
		default:
		{
			cout<<"\nEntrada Incorreta!";
			goto PRINCIPAL;
		}
		
		CONTINUA:
			cout<<"\n\nQuer continuar?";
			cout<<"\nPressione S para Sim e N para Não";
			cout<<"\nQual é a sua escolha? ";
			cin>>resp;

	} while (resp == 's' || resp == 'S');


	cout<<"\n\nFIM DO PROGRAMA";
	getch();
	return 0;
}