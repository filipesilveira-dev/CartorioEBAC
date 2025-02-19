#include <stdio.h> // biblioteca de comunicação com usuário
#include <stdlib.h> // biblioteca de alocação de espaço na memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca resposnável por cuidar das strings

int registro() // essas três funções não são carregadas quando o sistema é aberto. Apenas que são chamadas lá na função "main ()". Iso otimiza o programa
{
	setlocale (LC_ALL, "Portuguese");
	
	//início da criação de variáveis/strings
	char arquivo[40]; //será realizada a cópia do valor da variável "cpf" para a variável arquivo (?)
	char cpf[40]; // o "40" indica a quantidade máxima de caracteres que podem ser comportados
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int resposta =0;
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf ("%s", cpf); // será "scanneado" o que o usuário responderá na string "char cpf[40]". "%s" se refere a strings (salva uma string)
	
	strcpy (arquivo, cpf); // pela ordem, o valor está sendo '"puxado" do "cpf" para o "arquivo". Responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo "file". A instrução passada ao sistem é que, dentro das bibliotecas, haverá uma estrutura chamada FILE porque será criado um arquivo (*file). o "*" refere que se trata de um ponteiro, ou seja, um ponteiro é uma variável que armazena o endereço de memória de outra variável como seu valor. Uma variável de ponteiro aponta para um tipo de dado (como int) do mesmo tipo e é criada com o *operador. O endereço da variável com a qual você está trabalhando é atribuído ao ponteiro
	file = fopen(arquivo, "w"); // cria o arquivo "file". Esta linha estabelece que o nome do "file" será "arquivo" e que ele será aberto (fopen) um arquivo novo ("w"), no qual será escrito algo ("w" = write)
	fprintf (file, cpf); // aqui está sendo salvo no arquivo ("file") a variável "cpf". o "fprintf" se refere a realizar a função "printf" dentro do arquivo ("f" colocado antes da função "printif")
	fclose (file); // fecha o "file" aberto na linha 20. A escolha do arquivo se chamar da mesma forma que do CPF é porque o cpf é único, diferente das outras características
	
	file = fopen(arquivo, "a"); // o "a" se refere à "atualização". Não se está criando outro arquivo!!!
	fprintf(file, "\t\t"); // essa linha orienta a colocação de uma "," dentro do file
	fclose (file); // o intuito desse comando é organizar as informações dentro do file por meio de vírgulas
	
	printf("Digite o nome a ser cadastrado: "); // mensagem a ser mostrada ao usuário
	scanf("%s", nome); // o que for colocado pelo usuário, será salvo na variável "nome" (linha 10)
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file); // o intuito de todo esse comando é salvar a informação obtida (informada pelo usuário) no file na parte de "nome")
	
	file = fopen(arquivo, "a"); // comando copiado e colado na mudança das instruções do cpf para o nome (agora na mudança do nome para o sobrenome)
	fprintf(file, "\t\t"); // essa linha orienta a colocação de uma "," dentro do file
	fclose (file); // o intuito desse comando é organizar as informações dentro do file por meio de vírgulas (cpf, nome, sobrenome,etc)
	
	printf("Digite o sobrenome a ser cadastrado: "); // mensagem a ser mostrada ao usuário
	scanf("%s", sobrenome); // o que for colocado pelo usuário, será salvo na variável "sobrenome" (linha 11)
	
	file = fopen(arquivo, "a"); // abra o arquivo e atualiza ele com o sobrenome
	fprintf(file, sobrenome);
	fclose(file); // o intuito de todo esse comando é salvar a informação obtida (informada pelo usuário) no file na parte de "sobrenome")
	
	file = fopen(arquivo, "a"); // comando copiado e colado na mudança das instruções do cpf para o nome (agora na mudança do nome para o sobrenome)
	fprintf(file, "\t\t"); // essa linha orienta a colocação de uma "," dentro do file
	fclose (file); // o intuito desse comando é organizar as informações dentro do file por meio de vírgulas (cpf, nome, sobrenome,etc)
	
	printf("Digite o cargo a ser cadastrado: "); // mensagem a ser mostrada ao usuário
	scanf("%s", cargo); // o que for colocado pelo usuário, será salvo na variável "cargo" (linha 12)
	
	file = fopen(arquivo, "a"); // abra o arquivo e atualiza ele com o cargo
	fprintf(file, cargo);
	fclose(file); //os comandos se repetem 4 vezes: uma para cada variável (cpf, nome, sobrenome e cargo)
	
	system ("pause");//função para que o sistema aguarde e não já retorne para o menu
	
	system("cls");
	
	printf("Deseja cadastrar mais algum nome?\n\n");
	printf("Tecle 1 para SIM ou 2 para NÃO \n\n");
	
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
	char conteudo[200]; // vai ser consultado tudo o que estiver na variável
	int resposta =0;
	
	printf("Digite o CPF a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file; // consulte este arquivo
	file = fopen(cpf,"r"); // o "r" está liado a "ler" ("read"). É uma função de consulta (comando de colsultar), diferente de "W" (write/criar) e "a" (atulizar")
	
	if(file == NULL) // função para caso não encontre o valor de cpf digitado (caso não conste na base de dados). Se "file" retornar um valor "nulo" *NULL", mostre a mensagem (printf)
	{
		printf("\nNão foi possível abrir o arquivo. Arquivo não localizado.\n\n"); // cada cpf é um novo arquivo
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //estão sendo salvos os 200 caracteres do arquivo na variável conteúdo. Quando o valor buscar for nulo, a função se encerra
	{
		printf("\nEssas são as informações do usuário: \n\n");
		printf("||CPF\t\t||NOME\t\t||SOBRENOME\t||CARGO\n");
		printf("\n%s", conteudo);
		printf("\n\n"); //enquanto estiver sendo escrito na variável "conteúdo", até "200" valores, os quais estão dentro do "file" (== cpf), retornar o "conteúdo" (%s,conteudo). Até enquanto for diferente de nulo. Quando for igua a nulo [if (file == null], retornar a mensagem que não contém a informação
	}
	
	
	fclose(file);
	system("pause");
	
	system("cls");
	
	printf("Deseja consultar mais algum nome?\n\n");
	printf("Tecle 1 para SIM ou 2 para NÃO \n\n");
	
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
	char cpf[40]; // função char para gerenciamento de strings funciona melhor
	int resposta =0;
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf); // vai olhar o que o usuário colou (resposta à pergunta) e vai registrar na string "cpf"
	
	FILE *file;
	file = fopen(cpf, "r");
		
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema.\n"); 
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usuário deletado com sucesso.\n");
		system("pause");
	}
	
	system("cls");
	
	printf("Deseja deletar mais algum nome?\n\n");
	printf("Tecle 1 para SIM ou 2 para NÃO \n\n");
	
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

int main () // sempre é a primeira função a ser executada pelo sistema. Mesmo se houver função antes, como "int teste ()"
{
	int opcao=0; // um espaço na memória do computador se chama "opção". Definido previamente com "0" para não se torna um valor variável de memória. Respnsável por armazenar as variáeis locais: são as que só funiconam dentro da função (int main, no caso)
	int LacoDeRepeticao=1; // varíavel relacioanda à função for ()
	
	for (LacoDeRepeticao=1;LacoDeRepeticao=1;) // função utilzada para "repetição" ("repita. faça quants vezes eu pedir"). for (Deve ser repetido quando a variável "LacoDeRepeticao" for 1,deve ficar em loop até a variável ser 1); Macete utilizado . O sistema não desliga ao final, e sim retorna ao menu. Ele deve ser colocado após as variáveis e antes do que será repetido (n caso, int main)
	{
	
		system ("cls");
		
		setlocale (LC_ALL, "Portuguese"); // definindo a linguagem
	
		printf ("### Cartório da EBAC ###\n\n"); // início do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1- Registrar Nomes\n");
		printf ("\t2- Consultar Nomes\n");
		printf ("\t3- Deletar Nomes\n"); 
		printf ("\t4- Sair do sistema\n\n");
		printf ("Opção: "); // final do menu
	
		scanf ("%d", &opcao); // funçaõ de escanear o que o usuário coloca. com o %d ele vai escanear o que o usuário vai responder antes para o resultado de referenciado na variável "opção" ("Armazene na vaiável opção - estabelecida na linha 7. No início do int main - o valor que o usuário digitar"). O scanf "pausa" o programa enquanto não obtém uma resposta
	
		system ("cls"); // comando ao sistema para "limpar" a tela , com o intuiro de reduzir a poluição visual para o usuário, após resposta do mesmo
	
		
		switch (opcao)
		{
			case 1: // caso a opção seja 1, mostre "você escolheu: registrar nome"
			registro();// chamada de função registro()
			break; // encerra a opção 1
			
			case 2:
			consulta();// chamada da função consultar()
			break;
			
			case 3:
			deletar();// chamada de função deletar()
			break;
			
			case 4:
			printf ("Obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			default: // caso seja não seja escolhida nehuma das opções disponíveis, retorne "escolha uma opção válida"
			printf("Escolha uma opção válida\n\n"); 
			system ("pause");
			break;
						
		} // final da função switch
		
	} // final da função for ()
}

