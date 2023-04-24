#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
    //Final da criação de variáveis/string
   
   printf("Digite o CPF do usuário a ser cadastrado: "); //Coletando informação do usuário
   scanf("%s", cpf); //"%s" refere-se a string
   
   strcpy(arquivo, cpf); //Responsável por copiar os valores das string
   
   FILE *file; //Cria o arquivo
   file = fopen(arquivo, "w"); //Cria o arquivo e o "w" siginifica escrever   
   fprintf(file,cpf);  //Salva o valor da variável
   fclose(file); //Fecha o arquivo
   
   file = fopen(arquivo, "a"); //Cria o arquivo/ "a" significa arquivo atualizado
   fprintf(file,","); // "," significa separação
   fclose(file); //Fecha o arquivo
   
   printf("Digite o nome do usuário a ser cadastrado: "); //Coleta informções do usuário
   scanf("%s",nome); // "%s" Refere-se a string
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome do usuário a ser cadastrado: ");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo do usuário a ser cadastrado: ");
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
	
	printf("Digite o CPF do usuário a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" significa ler o arquivo
	
	if(file == NULL) // "==" siginifica comparação/ "NULL" signifiva nulo
	{
		printf("Não foi porssivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // "while" significa enquanto
	{
		printf("\nEssas são as informções do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" significa "Read" que é ler
	
	if(file == NULL) // "NULL" significa nulo
	{
		printf("O CPF do usuário foi deletado com sucesso!.\n");
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
	
	 printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1 - Resgistrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n"); 
	 printf("Opção: ");//Fim do menu
	
	 scanf("%d", &opcao); //Armazenando as escolhas do usuário
	
	 system("cls"); //Responsável por limpar a tela
	 
	 switch(opcao) //Inicio da seleção do menu
	 {
	 	case 1:
	 	registro(); //chamada de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		
		default:
		printf("Essa opção não está disponivel!\n");
		system("pause");
		break;
			
	 }
	
	/*
	 if(opcao==1) //Inicio da seleção
	 {
		printf("Você escolheu o resgistro de nomes\n");
		system("pause");
	 }
	 if(opcao==2)
	 {
		printf("Você escolheu consultar os nomes\n");
		system("pause");
	 }
	 if(opcao==3)
	 {
		printf("Você escolheu deletar os nomes\n");
		system("pause");
	 }
	 if(opcao>=4 || opcao<=0)
	 {
		printf("Essa opção não está disponivel\n");
		system("pause");
	 }//Fim da seleção
	*/
	
    }
}
