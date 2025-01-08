#include <stdio.h>   // Biblioteca de comunicação com o usuário
#include <stdlib.h>  // Biblioteca de alocação de memória
#include <locale.h>  // Biblioteca de localização por região
#include <string.h>  // Biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
    setlocale(LC_ALL, "Portuguese"); // Define a linguagem para Português
  //inicio criação de variáveis/string
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char arquivo[50]; // Variável para o nome do arquivo
    //Final da crioção de Variáveis/String
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); // Responsável por copiar o valor da string
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Abre o arquivo 
    fprintf(file, "%s", cpf); // Salva o valor da variável
    fclose(file); // Fecha o arquivo 
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: "); //Salva a informação cadastrada
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //Salva o sobrenome do usuário
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);
    
    system("pause");
    return 0;
}

int consultar() //faz a consulta da disponibilidade do usuário no sistema por CPF
{
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: "); //Faz a verificação se o CPF está disponivel
    scanf("%s", cpf); 
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) //Caso não haja o CPF digitado será exibido:
    printf("Não foi localizado\n");
    
    
    printf("\nEssas são as informações do usuário:\n"); //Quando encontrado, é mostrado antes das infos
    while (fgets(conteudo, 200, file) != NULL) 
    {
        printf("%s", conteudo);
    }
    printf("\n\n");
    fclose(file);
    
    system("pause");
}

int deletar() //Deleta o usuário caso esteja cadastrado no sistema
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: "); 
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("Usuário não se encontra ou o CPF foi deletado do sistema!.\n");
    	system("pause");
    	
	}

}

int sair()
{
    printf("Saindo do sistema...\n");
    system("pause");
    return 0;
}

int main()
{
    int opcao = 0; // Definindo variáveis

    setlocale(LC_ALL, "Portuguese"); // Define a linguagem para Português

    // Loop contínuo usando while
    while (1)
    {
        system("cls"); // Limpa a tela no Windows

        // Exibe o menu
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n\n");
    
        // Lê a opção do usuário
        scanf("%d", &opcao);

        system("cls"); // Limpa a tela após a entrada

        switch(opcao)
        {
            case 1:
                registro();
                break;
            
            case 2:
                consultar();
                break;
            
            case 3:
                deletar();
                break;
            
            case 4:
                sair();
                return 0;  // Termina o programa
                
            default:
                printf("Opção inválida! Tente novamente.\n");
                system("pause");
                break;
        }
    }

    return 0;
}
