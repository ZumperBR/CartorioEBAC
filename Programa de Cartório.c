#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
    //Final da cria��o de vari�veis/string
   
   printf("Digite o CPF do usu�rio a ser cadastrado: "); //Coletando informa��o do usu�rio
   scanf("%s", cpf); //"%s" refere-se a string
   
   strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
   
   FILE *file; //Cria o arquivo
   file = fopen(arquivo, "w"); //Cria o arquivo e o "w" siginifica escrever   
   fprintf(file,cpf);  //Salva o valor da vari�vel
   fclose(file); //Fecha o arquivo
   
   file = fopen(arquivo, "a"); //Cria o arquivo/ "a" significa arquivo atualizado
   fprintf(file,","); // "," significa separa��o
   fclose(file); //Fecha o arquivo
   
   printf("Digite o nome do usu�rio a ser cadastrado: "); //Coleta inform��es do usu�rio
   scanf("%s",nome); // "%s" Refere-se a string
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome do usu�rio a ser cadastrado: ");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo do usu�rio a ser cadastrado: ");
   scanf("%s",cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
   
   
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" significa ler o arquivo
	
	if(file == NULL) // "==" siginifica compara��o/ "NULL" signifiva nulo
	{
		printf("N�o foi porssivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // "while" significa enquanto
	{
		printf("\nEssas s�o as inform��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" significa "Read" que � ler
	
	if(file == NULL) // "NULL" significa nulo
	{
		printf("O CPF do usu�rio foi deletado com sucesso!.\n");
		system("pause");
	}
	
}



int main()

    {
	int opcao=0; // Definindo variantes
	int x=1;
	
	for(x=1;x=1;)
	{

     system("cls");
     
   	 setlocale(LC_ALL, "Portuguese" ); //Definindo a linguagem
	
	 printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	 printf("Escolha a op��o desejada do menu:\n\n");
	 printf("\t1 - Resgistrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n"); 
	 printf("Op��o: ");//Fim do menu
	
	 scanf("%d", &opcao); //Armazenando as escolhas do usu�rio
	
	 system("cls"); //Respons�vel por limpar a tela
	 
	 switch(opcao) //Inicio da sele��o do menu
	 {
	 	case 1:
	 	registro(); //chamada de fun��es
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		
		default:
		printf("Essa op��o n�o est� disponivel!\n");
		system("pause");
		break;
			
	 }
	
	/*
	 if(opcao==1) //Inicio da sele��o
	 {
		printf("Voc� escolheu o resgistro de nomes\n");
		system("pause");
	 }
	 if(opcao==2)
	 {
		printf("Voc� escolheu consultar os nomes\n");
		system("pause");
	 }
	 if(opcao==3)
	 {
		printf("Voc� escolheu deletar os nomes\n");
		system("pause");
	 }
	 if(opcao>=4 || opcao<=0)
	 {
		printf("Essa op��o n�o est� disponivel\n");
		system("pause");
	 }//Fim da sele��o
	*/
	
    }
}
