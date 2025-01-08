#include <stdio.h>   // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  // Biblioteca de aloca��o de mem�ria
#include <locale.h>  // Biblioteca de localiza��o por regi�o
#include <string.h>  // Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
    setlocale(LC_ALL, "Portuguese"); // Define a linguagem para Portugu�s
  //inicio cria��o de vari�veis/string
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char arquivo[50]; // Vari�vel para o nome do arquivo
    //Final da crio��o de Vari�veis/String
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); // Respons�vel por copiar o valor da string
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Abre o arquivo 
    fprintf(file, "%s", cpf); // Salva o valor da vari�vel
    fclose(file); // Fecha o arquivo 
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: "); //Salva a informa��o cadastrada
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //Salva o sobrenome do usu�rio
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

int consultar() //faz a consulta da disponibilidade do usu�rio no sistema por CPF
{
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: "); //Faz a verifica��o se o CPF est� disponivel
    scanf("%s", cpf); 
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) //Caso n�o haja o CPF digitado ser� exibido:
    printf("N�o foi localizado\n");
    
    
    printf("\nEssas s�o as informa��es do usu�rio:\n"); //Quando encontrado, � mostrado antes das infos
    while (fgets(conteudo, 200, file) != NULL) 
    {
        printf("%s", conteudo);
    }
    printf("\n\n");
    fclose(file);
    
    system("pause");
}

int deletar() //Deleta o usu�rio caso esteja cadastrado no sistema
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: "); 
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("Usu�rio n�o se encontra ou o CPF foi deletado do sistema!.\n");
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
    int opcao = 0; // Definindo vari�veis

    setlocale(LC_ALL, "Portuguese"); // Define a linguagem para Portugu�s

    // Loop cont�nuo usando while
    while (1)
    {
        system("cls"); // Limpa a tela no Windows

        // Exibe o menu
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n\n");
    
        // L� a op��o do usu�rio
        scanf("%d", &opcao);

        system("cls"); // Limpa a tela ap�s a entrada

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
                printf("Op��o inv�lida! Tente novamente.\n");
                system("pause");
                break;
        }
    }

    return 0;
}
