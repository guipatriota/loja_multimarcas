// Neste exercício você deverá conectar seu banco de dados utilizando um arquivo .h (dbloja.h) e eliminar o uso do arquivo dados.h 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

#include "dbloja.h"

#include "aux.h"
#include "api.h"
//#include "dados.h"
#include "seguro.h"


int qtd, opcao = -1;
int pedido[] = { 0 };
int i;
int quantidadedeprodutos;
//char * marca[6] = {"","","","","",""};

int menu(void) {

	cls();

	printf_s("\t\t\t############################################################\n");
	printf_s("\t\t\t               Bem Vindo à LOJA MULTIMARCAS      \n");
	printf_s("\t\t\t############################################################\n\n");

	printf_s("\t\t\t*********************  Nossos Carros  **********************\n\n");
	printf_s("\t\t\t############################################################\n");

	int i;


	for (i = 1; i <= quantidadedeprodutos; ++i) {
		printf_s("\t\t\t|  %d    |  %s    |  %s    |   R$%.2f  |\n", i, modelo[i - 1], marca[i - 1], valor[i - 1]);
	};
	printf_s("\t\t\t|-------|--------------------------------------------------|\n");
	printf_s("\t\t\t|  0    |    Para finalizar o pedido                       |\n");
	printf_s("\t\t\t############################################################\n");
	printf_s("\n");

	return 0;
}

double resumocompra() {//int pedido[quantidadedeprodutos]){
	double valortotal = 0.0;
	int i;
	for (i = 0; i < quantidadedeprodutos; ++i) {
		valortotal += pedido[i] * valor[i];
	}
	printf_s("\t\t\tO valor da sua compra é: R$%.2f\n\n", valortotal);
	return valortotal;
}

double comprovantecompra(char* Nome) {
	cls();
	int i;
	printf_s("\t\t\t##################################################\n");
	printf_s("\t\t\t                Obrigado por comprar              \n");
	printf_s("\t\t\t                        na                        \n");
	printf_s("\t\t\t                 Loja Multimarcas                 \n");
	printf_s("\t\t\t##################################################\n\n");

	printf_s("\t\t\t*****************  Sua Compra  *******************\n\n");
	printf_s("\t\t\t##################################################\n");
	double valortotal = resumocompra();
	printf_s("\t\t\tProduto       Marca       Quantidade   Valor total\n");
	for (i = 0; i < quantidadedeprodutos; ++i) {
		if (pedido[i] > 0) {
			printf_s("\t\t\t%s    %s       %d       R$%.2f\n", modelo[i], marca[i], pedido[i], valor[i] * pedido[i]);
		};
	};
	printf_s("\n\t\t\tTOTAL DA COMPRA: R$%.2f\n", valortotal);
	printf_s("\n\t\t\t\tA senha é: %s\n", Nome);

	return valortotal;
}

int solicitapedido(char* Nome, double resultado) {
	opcao = -1;
	char c;
	while ((opcao < 0) || (opcao > quantidadedeprodutos))
	{

		menu();
		resumocompra();
		if (resultado == 0) {
			printf_s("\t\t\tOlá %s! Por favor, digite o seu pedido: ", Nome);
		}
		else {
			printf_s("\n\t\t\tDeseja algo mais? (0 para finalizar) ");//caso exista outra escolha pelo usuário.
		};
		scanf_s("%d", &opcao);
		while ((c = getchar()) != '\n' && c != EOF) {};

		if ((opcao < 0) || (opcao > quantidadedeprodutos)) {
			menu();
			printf_s("\n\n\tOpção inválida. Favor escolher algum item existente no menu...\n\n\n\n");
			system("pause");
		};
		if (opcao == 0) {
			return 0;
		};
	}

	printf_s("\t\t\tDigite a quantidade de %s que você deseja pedir: ", modelo[opcao - 1]);
	scanf_s("%d", &qtd);
	while ((c = getchar()) != '\n' && c != EOF) {};

	pedido[opcao - 1] += qtd;

	return 0;
}

int main(int argc, char* argv[]) {
	//Setando a localidade como a mesma atual do usuário. Isso nos
	setlocale(LC_ALL, "");
	//Configuração do console do windows para suportar entradas de texto com acentuação:
	unsigned int novoCp = 1252; //1252 = ANSI latin 1 Windows

	//Armazenamento do codepage original do console para reposição da configuração ao final:
	unsigned int cpIn = GetConsoleCP();        //Se usa para saber o codepage de entrada atual
	unsigned int cpOut = GetConsoleOutputCP(); //Se usa para saber o codepage de saída atual
	//printf_s("cpOut: %d\n", cpOut);
	//printf_s("cpIn: %d\n", cpIn);
	//printf_s("cpNew: %d\n", novoCp);
	//printf_s("%s", senha);
	//printf_s("%s", senha);
	SetConsoleCP(novoCp);
	SetConsoleOutputCP(novoCp);

	
	quantidadedeprodutos = contarCarros();
	//marcas(marca, quantidadedeprodutos);
	//printf_s("%s", marca[2]);
	//system("Pause");
	//exit(1);
	//for (i = 0; i < quantidadedeprodutos; i++) {
	//	pedido[i] = 0;
	//};

	mostra_tabelas();
	system("Pause");
	cls();
	mostra_carros();
	system("Pause");
	//exit(1);
	//Estabelecendo o codepage de entrada e saída para 1252(latin1).
	
	
	//Reset da memória dos pedidos para zero:
	//memset(pedido, 0, sizeof(pedido));
	memset(pedido, 0, quantidadedeprodutos);

	double resultado = 0.0;

	menu();

	char Nome[50];

	char c;

	printf_s("\t\t\tDigite seu nome: ");
	scanf_s("%s", Nome, (unsigned)_countof(Nome));
	while ((c = getchar()) != '\n' && c != EOF) {};

	putchar('\n');

	opcao = -1;

	while (opcao != 0)
	{
		// Mostra menu inicial e solicita pedidos
		solicitapedido(Nome, resultado);

		resultado = resumocompra();

		if (opcao == 0) {//para finalizar o codigo.
			menu();
			//resultado = resumocompra();
			if (resultado != 0) {
				printf_s("\n\t\t\tA senha é: %s\n\n", Nome);
				printf_s("\t\t\tO valor final da sua compra é: R$%.2f", resultado);
				comprovantecompra(Nome);
				//salvardados(Nome);
			}
			else {
				printf_s("\n\n\t\t\t\tNenhum produto foi comprado.");
			}
			printf_s("\n\n\t\t\t\t    Volte Sempre!\n\n\n");
			break;
		}



	}

	system("Pause");

	//Antes de encerrar o programa, devemos retornar às configurações originais do console:
	//setlocale(LC_ALL, "C");
	SetConsoleCP(cpIn);
	SetConsoleOutputCP(cpOut);

	return 0;
}