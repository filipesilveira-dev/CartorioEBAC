#include <stdio.h> // biblioteca de comunica��o com usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca resposn�vel por cuidar das strings

int registro() // essas tr�s fun��es n�o s�o carregadas quando o sistema � aberto. Apenas que s�o chamadas l� na fun��o "main ()". Iso otimiza o programa
{
	setlocale (LC_ALL, "Portuguese");
	
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40]; //ser� realizada a c�pia do valor da vari�vel "cpf" para a vari�vel arquivo (?)
	char cpf[40]; // o "40" indica a quantidade m�xima de caracteres que podem ser comportados
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int resposta =0;
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf ("%s", cpf); // ser� "scanneado" o que o usu�rio responder� na string "char cpf[40]". "%s" se refere a strings (salva uma string)
	
	strcpy (arquivo, cpf); // pela ordem, o valor est� sendo '"puxado" do "cpf" para o "arquivo". Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo "file". A instru��o passada ao sistem � que, dentro das bibliotecas, haver� uma estrutura chamada FILE porque ser� criado um arquivo (*file). o "*" refere que se trata de um ponteiro, ou seja, um ponteiro � uma vari�vel que armazena o endere�o de mem�ria de outra vari�vel como seu valor. Uma vari�vel de ponteiro aponta para um tipo de dado (como int) do mesmo tipo e � criada com o *operador. O endere�o da vari�vel com a qual voc� est� trabalhando � atribu�do ao ponteiro
	file = fopen(arquivo, "w"); // cria o arquivo "file". Esta linha estabelece que o nome do "file" ser� "arquivo" e que ele ser� aberto (fopen) um arquivo novo ("w"), no qual ser� escrito algo ("w" = write)
	fprintf (file, "CPF - ");
	fprintf (file, cpf); // aqui est� sendo salvo no arquivo ("file") a vari�vel "cpf". o "fprintf" se refere a realizar a fun��o "printf" dentro do arquivo ("f" colocado antes da fun��o "printif")
	fclose (file); // fecha o "file" aberto na linha 20. A escolha do arquivo se chamar da mesma forma que do CPF � porque o cpf � �nico, diferente das outras caracter�sticas
	
	file = fopen(arquivo, "a"); // o "a" se refere � "atualiza��o". N�o se est� criando outro arquivo!!!
	fprintf(file, ", Nome - "); // essa linha orienta a coloca��o de uma "," dentro do file
	fclose (file); // o intuito desse comando � organizar as informa��es dentro do file por meio de v�rgulas
	
	printf("Digite o nome a ser cadastrado: "); // mensagem a ser mostrada ao usu�rio
	scanf("%s", nome); // o que for colocado pelo usu�rio, ser� salvo na vari�vel "nome" (linha 10)
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file); // o intuito de todo esse comando � salvar a informa��o obtida (informada pelo usu�rio) no file na parte de "nome")
	
	file = fopen(arquivo, "a"); // comando copiado e colado na mudan�a das instru��es do cpf para o nome (agora na mudan�a do nome para o sobrenome)
	fprintf(file, ", Sobrenome - "); // essa linha orienta a coloca��o de uma "," dentro do file
	fclose (file); // o intuito desse comando � organizar as informa��es dentro do file por meio de v�rgulas (cpf, nome, sobrenome,etc)
	
	printf("Digite o sobrenome a ser cadastrado: "); // mensagem a ser mostrada ao usu�rio
	scanf("%s", sobrenome); // o que for colocado pelo usu�rio, ser� salvo na vari�vel "sobrenome" (linha 11)
	
	file = fopen(arquivo, "a"); // abra o arquivo e atualiza ele com o sobrenome
	fprintf(file, sobrenome);
	fclose(file); // o intuito de todo esse comando � salvar a informa��o obtida (informada pelo usu�rio) no file na parte de "sobrenome")
	
	file = fopen(arquivo, "a"); // comando copiado e colado na mudan�a das instru��es do cpf para o nome (agora na mudan�a do nome para o sobrenome)
	fprintf(file, ", Cargo - "); // essa linha orienta a coloca��o de uma "," dentro do file
	fclose (file); // o intuito desse comando � organizar as informa��es dentro do file por meio de v�rgulas (cpf, nome, sobrenome,etc)
	
	printf("Digite o cargo a ser cadastrado: "); // mensagem a ser mostrada ao usu�rio
	scanf("%s", cargo); // o que for colocado pelo usu�rio, ser� salvo na vari�vel "cargo" (linha 12)
	
	file = fopen(arquivo, "a"); // abra o arquivo e atualiza ele com o cargo
	fprintf(file, cargo);
	fclose(file); //os comandos se repetem 4 vezes: uma para cada vari�vel (cpf, nome, sobrenome e cargo)
	
	system ("pause");//fun��o para que o sistema aguarde e n�o j� retorne para o menu
	
	system("cls");
	
	printf("Deseja cadastrar mais algum nome?\n\n");
	printf("Tecle 1 para SIM ou 2 para N�O \n\n");
	
	scanf("%d", &resposta);
	
	system ("cls");
	
	switch (resposta)
	{
		case 1:
		registro();
		break;
		
		case 2:
		return 0;
		break;
	}
	
	system("pause");
}

int consulta()
{
	setlocale (LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200]; // vai ser consultado tudo o que estiver na vari�vel
	int resposta =0;
	
	printf("Digite o CPF a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file; // consulte este arquivo
	file = fopen(cpf,"r"); // o "r" est� liado a "ler" ("read"). � uma fun��o de consulta (comando de colsultar), diferente de "W" (write/criar) e "a" (atulizar")
	
	if(file == NULL) // fun��o para caso n�o encontre o valor de cpf digitado (caso n�o conste na base de dados). Se "file" retornar um valor "nulo" *NULL", mostre a mensagem (printf)
	{
		printf("\nN�o foi poss�vel abrir o arquivo. Arquivo n�o localizado.\n\n"); // cada cpf � um novo arquivo
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //est�o sendo salvos os 200 caracteres do arquivo na vari�vel conte�do. Quando o valor buscar for nulo, a fun��o se encerra
	{
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n"); //enquanto estiver sendo escrito na vari�vel "conte�do", at� "200" valores, os quais est�o dentro do "file" (== cpf), retornar o "conte�do" (%s,conteudo). At� enquanto for diferente de nulo. Quando for igua a nulo [if (file == null], retornar a mensagem que n�o cont�m a informa��o
	}
	
	
	fclose(file);
	system("pause");
	
	system("cls");
	
	printf("Deseja consultar mais algum nome?\n\n");
	printf("Tecle 1 para SIM ou 2 para N�O \n\n");
	
	scanf("%d", &resposta);
	
	system ("cls");
	
	switch (resposta)
	{
		case 1:
		consulta();
		break;
		
		case 2:
		return 0;
		break;
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40]; // fun��o char para gerenciamento de strings funciona melhor
	int resposta =0;
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf); // vai olhar o que o usu�rio colou (resposta � pergunta) e vai registrar na string "cpf"
	
	FILE *file;
	file = fopen(cpf, "r");
		
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema.\n"); 
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usu�rio deletado com sucesso.\n");
		system("pause");
	}
	
	system("cls");
	
	printf("Deseja deletar mais algum nome?\n\n");
	printf("Tecle 1 para SIM ou 2 para N�O \n\n");
	
	scanf("%d", &resposta);
	
	system ("cls");
	
	switch (resposta)
	{
		case 1:
		deletar();
		break;
		
		case 2:
		return 0;
		break;
	}
	
	system("pause");
}

int main () // sempre � a primeira fun��o a ser executada pelo sistema. Mesmo se houver fun��o antes, como "int teste ()"
{
	int opcao=0; // um espa�o na mem�ria do computador se chama "op��o". Definido previamente com "0" para n�o se torna um valor vari�vel de mem�ria. Respns�vel por armazenar as vari�eis locais: s�o as que s� funiconam dentro da fun��o (int main, no caso)
	int LacoDeRepeticao=1; // var�avel relacioanda � fun��o for ()
	
	for (LacoDeRepeticao=1;LacoDeRepeticao=1;) // fun��o utilzada para "repeti��o" ("repita. fa�a quants vezes eu pedir"). for (Deve ser repetido quando a vari�vel "LacoDeRepeticao" for 1,deve ficar em loop at� a vari�vel ser 1); Macete utilizado . O sistema n�o desliga ao final, e sim retorna ao menu. Ele deve ser colocado ap�s as vari�veis e antes do que ser� repetido (n caso, int main)
	{
	
		system ("cls");
		
		setlocale (LC_ALL, "Portuguese"); // definindo a linguagem
	
		printf ("### Cart�rio da EBAC ###\n\n"); // in�cio do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1- Registrar Nomes\n");
		printf ("\t2- Consultar Nomes\n");
		printf ("\t3- Deletar Nomes\n"); 
		printf ("\t4- Sair do sistema\n\n");
		printf ("Op��o: "); // final do menu
	
		scanf ("%d", &opcao); // fun�a� de escanear o que o usu�rio coloca. com o %d ele vai escanear o que o usu�rio vai responder antes para o resultado de referenciado na vari�vel "op��o" ("Armazene na vai�vel op��o - estabelecida na linha 7. No in�cio do int main - o valor que o usu�rio digitar"). O scanf "pausa" o programa enquanto n�o obt�m uma resposta
	
		system ("cls"); // comando ao sistema para "limpar" a tela , com o intuiro de reduzir a polui��o visual para o usu�rio, ap�s resposta do mesmo
	
		
		switch (opcao)
		{
			case 1: // caso a op��o seja 1, mostre "voc� escolheu: registrar nome"
			registro();// chamada de fun��o registro()
			break; // encerra a op��o 1
			
			case 2:
			consulta();// chamada da fun��o consultar()
			break;
			
			case 3:
			deletar();// chamada de fun��o deletar()
			break;
			
			case 4:
			printf ("Obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			default: // caso seja n�o seja escolhida nehuma das op��es dispon�veis, retorne "escolha uma op��o v�lida"
			printf("Escolha uma op��o v�lida\n\n"); 
			system ("pause");
			break;
						
		} // final da fun��o switch
		
	} // final da fun��o for ()
}

