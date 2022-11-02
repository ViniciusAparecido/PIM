//Bibliotecas 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Estrutura cadastro de funcionário
struct funcionario{
    char fun[50];
    int cpf[50], tele[50];
    float salario[10];
};

//Estrutura cadastro de cliente
struct cliente{
    char client[100];
    int cli_cpf[100], cli_tele[100];
    float mensa[100];
};
//Estrutura cadastro de produto
typedef struct {
    int cod[50];
    char nome[50];
    char categoria[50];
    float valor[50];
} produto;


 //Relatório de vendas, caixas, fluxo de funcionarios e clientes
 void relEstoque(produto produto){
    int cont1;
    printf(" Código      Nome        Categória   Valor \n");
    for (cont1 = 0; cont1 = 50; cont1++){
        printf("\n%d", produto.cod[cont1]);
        printf("%c", produto.nome[cont1]);
        printf("%c", produto.categoria[cont1]);
        printf("\n%.2f", produto.valor[cont1]);
    }
 };

 void relVendas(){

 };

 void relCaixas(){

 };

 void relFluxo(){

 };


 // Funções

 // *** Vendas ****

// Suplemento, vestuarios, coqueteleira, bebidas, equipamento
 void venderProduto(int codigo){ 
    produto produtoVendido;
 };

//Programa principal
void main(){

    //Formatação pra português
    setlocale(LC_ALL, "Portuguese");

    //Variáveis
    int aumensa, valormensa, clientcad1, clientcad2, codigo, 
    au, au2, au3, esto[10][10], lin, col, cont1, cont2, cont3, 
    cont4, cont5, op, op2, op3, op4, op5, cli, esta, qnt_prod, esto1, esto2, qntCadastrarProd = 0;
    float caixa, soma;
    char login[20], senha[8];

    produto produtosVendidos[50];
    produto produtosCadastrados[50];
    produto produto;

    //Tela de login
    printf("\n********LOGIN********\n");
    printf("\nDigite seu login: ");
    scanf("%s", &login);
    printf("\nDigite sua senha: ");
    scanf("%s", &senha);
    printf("\n**********************\n");

    //Menu principal
    do{
        printf("\n****MENU_PRINCIPAL_CADASTRO****\n");
        printf("[1] Cadastrar funcionário\n");
        printf("[2] Cadastrar cliente\n");
        printf("[3] Cadastrar produto\n");
        printf("[4] Menu de alteração de dados\n");
        printf("[5] Menu de consultas \n");
        printf("[6] Menu do gerente\n");
        printf("[0] Sair \n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &op);
        printf("\n********************************\n\n");

    //Seleção de funções do menu principal 
     switch(op){
        //Função de cadastro de funcionario
        case 1:
            for (cont5 = 0; cont5 < 1; cont5++){
                struct funcionario fcad;
            printf("\n********************************\n\n");
                printf("\nDigite o nome do funcionario: ");
                scanf("%s", &fcad.fun[cont5]);
                printf("\nDigite o CPF do funcionario: ");
                scanf("%i", &fcad.cpf[cont5]);
                printf("\nDigite o telefone do funcionario: ");
                scanf("%i", &fcad.tele[cont5]);
               printf("\n********************************\n\n");
               }
                break;

        //refazer
        case 2: printf("\n********************************\n\n");
                printf("Digite o quantos clientes serão cadastrados: ");
                scanf("%d", &au2);
                for (cont1 = 0; cont1 < au2; cont1++){
                struct cliente fclint;
                printf("\nDigite o nome do cliente: ");
                scanf("%s", &fclint.client[cont1]);
                printf("\nDigite o cpf do cliente: ");
                scanf("%i", &fclint.cli_cpf[cont1]);
                printf("\nDigite o telefone do cliente: ");
                scanf("%i", &fclint.cli_tele[cont1]);
                printf("\nDigite o valor da mensalidade: ");
                scanf("%f", &fclint.mensa[cont1]);
               printf("\n********************************\n\n");
               }
                clientcad1 = au2;
                valormensa = cont1;
                break;

        //Menu de cadastro de produtos 
        case 3: printf("\n****VOCÊ_ESTÁ_NO_MENU_DE_CADASTRO_DE_PRODUTOS****\n\n");
                    do{
                        printf("[1] cadastrar produto\n");
                        printf("[0] sair\n");
                        printf("\nEscolha uma opção: ");
                        scanf("%d", &op2);

                    //Seleção de funções do menu de cadastro de produtos
                    switch(op2){
                            //Cadastrar Produtos
                            case 1: 
                            printf("\n********************************\n\n");
                            printf("\nDigite quantos produtos vão ser cadastrados: ");
                            scanf("%d", &qntCadastrarProd);
                            printf("\n********************************\n\n");
                                for (cont1 = 0; cont1 < qntCadastrarProd; cont1++){
                                    printf("Digite o código do produto: ");
                                    scanf("%d", &produto.cod[cont1]);
                                    printf("Digite o nome do produto: ");
                                    scanf("%s", &produto.nome[cont1]);
                                    printf("Digite a categoria: ");
                                    scanf("%s", &produto.categoria[cont1]);
                                    printf("Digite o valor: ");
                                    scanf("%f", &produto.valor[cont1]);
                                    printf("\n********************************\n\n");

                                    produtosCadastrados[cont1] = produto;
                                }
                                break;

                            //Saindo do menu de produtos    
                            case 0:
                               printf("\n********************************\n\n");
                               printf("\nSaiu da opção de cadastro de produto.\n");
                               printf("\n********************************\n\n");
                                break;
                         
                        }
                    }while(op2 != 0);
                break;

        //Menu de alterção de dados 
        case 4: printf("\n****MENU_DE_ALTERAÇÃO_DE_DADOS****\n");
                    do{
                        printf("[1] Alterar dados dos funcionários\n");
                        printf("[2] Alterar dados dos clientes\n");
                        printf("[3] Alterar dados do Estoque\n");
                        printf("[0] sair\n");
                        printf("\nEscolha uma opção: ");
                        printf("\n********************************\n\n");
                        scanf("%d", &op3);

                        //Seleção de funções do  menu de alteração dos dados 
                        switch(op3){
                            //função de alteração de dados dos funcionários
                            case 1: printf("escolha o funário de 0 a 49: ");
                            scanf("%d", &au);
                            struct funcionario fcad;
                            printf("Digite o nome do funcionário: ");
                            scanf("%s", &fcad.fun[au]);
                            printf("Digite o cpf do funcionário: ");
                            scanf("%d", &fcad.cpf[au]);
                            printf("Digite o telefone do funcionário: ");
                            scanf("%d", &fcad.tele[au]);
                            break;

                            //Função de alteração de dados dos clientes 
                            case 2: printf("escolha um cliente de 0  99: ");
                            scanf("%d", &au);
                            struct cliente fclint;
                            printf("Digite o nome do cliente: ");
                            scanf("%s", &fclint.client[au]);
                            printf("Digite o cpf do cliente: ");
                            scanf("%d", &fclint.cli_cpf[au]);
                            printf("Digite o telefone do cliente: ");
                            scanf("%d", &fclint.cli_tele[au]);
                            break;

                            //Função de alteração de dados dos
                            case 3: printf("\nEscolha a pratileira do estoque: \n");
                            scanf("%d", &esto1);
                            printf("\nEscolha a coluna do estoque: \n");
                            scanf("%d", &esto2);
                            for (lin = 0; lin < esto1; lin = esto1){
                                for (col = 0; col < esto2; col = esto2){
                                printf("Entre com o novo produto: ");
                                scanf("%d", &esto[lin][col]);
                                printf("Novo produto subtituido com sucesso.\n");
                                }
                            }
                            break;

                            case 0://Função de saida do menu de alteção
                           printf("\n********************************\n\n");
                            printf("\nSaiu da opção de cadastro de produto.\n");
                            printf("\n********************************\n\n");
                            break;

                        }
                    }while(op3 != 0);
                break;

        //Menu de consultas
        case 5: printf("****MENU _DE_CONSULTAS****\n");
                    do{
                        printf("[1] Consultar estoque\n");
                        printf("[2] Consultar mensalidade\n");
                        printf("[3] Consultar produtos\n");
                        printf("[4] Consultar ficha de cadastro\n");
                        printf("[5] Consultar horários disponíveis\n");
                        printf("[0] sair\n");
                        printf("\nEscolha uma opção: ");
                        scanf("%d", &op4);
                        printf("\n********************************\n\n");

                        //Seleção de funções do menu de consultas
                        switch (op4){
                        //Função para mostrar estoque     
                        case 1: relEstoque(produto);
                                printf("\n*******************************\n");
                                break;

                        //Função para consultar clientes
                        case 2: printf("Digite o número do cliente para a consulta: ");
                                scanf("%d", &au3);
                                struct cliente fclint;
                                printf("aqui está a mensalidade do cliente: %f", fclint.mensa[au3]);
                                printf("\n********************************\n\n");
                        break;

                        //Função para consultar produto
                        case 3: printf("Digite o número do produto para consulta: ");
                                au = 0;
                                scanf("%d", &au);
                                printf("aqui está o produto: %d\n\n"); 
                        break;

                        //Função para ficha de cadastro
                        case 4: au2 = 0;
                                printf("Digite o número da ficha: ");
                                scanf("%d", &au2);
                                struct cliente fclient;
                                printf("aqui está a ficha do cliente: -cpf: %d, -telefone: %d, -mensalidade: %.2f\n", fclient.cli_cpf[au2], fclient.cli_tele[au2], fclient.mensa[au2]);
                        break;

                        //case 5:
                        //break;

                        //Saida do menu de consultas
                        case 0: 
                            printf("\n********************************\n\n");
                            printf("Você saiu do menu de consultas.");
                            printf("\n********************************\n\n");
                        break; 

                      }
                    }while(op4 != 0);
                    
                break;

        //Menu do gerente 
        case 6: printf("****MENU_DO_GERENTE****\n");
                do{
                    printf("[1] Relatório do faturamento diário ou mensal\n");
                    printf("[2] Relatório do estoque\n");
                    printf("[3] Relatório de vendas\n");
                    printf("[4] Relatório de caixa\n");
                    printf("[5] Relatório de fluxo de fúncionarios e clientes\n");
                    printf("[0] Sair \n");
                    printf("\nEscolha uma opção: ");
                    scanf("%d", &op5);
                    printf("\n********************************\n\n");

                    //Seleção de funções do menu do gerente 
                    switch(op5){
                    //Função para o faturamento mensa/diario
                    case 1: printf("****Faturamento_mensal****\n");
                            struct cliente mensacli;        
                            soma = clientcad1 * mensacli.mensa[0];
                            printf("O faturamento mensal foi de: %.2f\n", soma);
                            printf("\n********************************\n\n");
                            
                    break;

                    //Função para checar capacidade de armazenamento 
                    case 2: printf("****Relatório_de_estoque****\n");
                            if (esto[lin][col] != esto[10][10]){
                                printf("Estoque disponivel!\n");
                                printf("\n********************************\n\n");
                            }else{printf("Estoque cheio!\n");}
                            printf("\n********************************\n\n");
                            
                    }
                }while (op5 != 0); 
                break;

        //Encerramento do programa
        case 0: printf("\n\nPrograma _encerrado.\n\n");
                break;
        
      }
    }while(op != 0);
}