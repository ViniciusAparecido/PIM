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
typedef struct{
    char client[20];
    char cli_tele[20];
    char cli_cpf[50];
    float cli_mensa;
}clientes;


clientes clientesvet[5];

//PROTOTIPACÃO
void mascara(char *cli_tele, char formato[]);

clientes lercliente(){
    clientes cl;{
        int i,p,d1,d2,s,t,u = 0;
        char confi[1];
        char sim[1] = "s";
                printf("\n********************************\n");
                printf("\nDigite o nome do cliente: ");
                scanf("%s", &cl.client);
                do{
                printf("\nDigite o CPF do cliente: ");
                scanf("%d",&cl.cli_cpf);
                scanf("%*c");
                for(i=1; i<9; i++){
                    p+=cl.cli_cpf[i]*(11-i);
                }
                d1=p%11;
                if(d1 < 2){
                    d1=0;
                }
                else{
                    d1 = 11 - d1;
                }p = 0;

                for(i=1;i<9;i++){
                p+=cl.cli_cpf[i]*(12-i);
                }
                d2=(p+(d1*2))%11;
                if(d2<2){
                    d2=0;
                }
                else{
                    d2=d2-11;
                }
                s = 1;
                if(cl.cli_cpf[10]==d1&&cl.cli_cpf[11]==d2){
                    s = 0;
                }
                else{
                    printf("\n******CPF_Invalido*****\n");
                    printf("***********************\n");
                }
                }while(s != 0);
                printf("\nDigite o telefone do cliente: ");
                scanf("%s", &cl.cli_tele);
                mascara(cl.cli_tele,"(**)****-*****");
                printf("\n");
                printf("\nDigite o valor da mensalidade: ");
                scanf("%f", &cl.cli_mensa);
                printf("\n********************************\n\n");
            }

    return cl;
};

void mascara(char *cli_tele, char formato[]){
     char aux[100];
     int i = 0;

     while(*cli_tele)
     {
        if(formato[i] != '*')
        {
           aux[i] = formato[i];
           i++;
        }
        else
        {
           aux[i] = *cli_tele;
           cli_tele++;
           i++;
        }
     }
     aux[i] = 0;

     printf("\t%s",aux);
     getchar();
}

void exibircliente(clientes elt){
      printf("\tNome: %s", elt.client);
      printf("\tMensalidade: R$%.2f\n\n", elt.cli_mensa);

};

int tam = 5;

void imprimicliente(){
int i;
for(i = 0; i < tam; i++)
    printf("\nNome: %d\tTelefone: %s, CPF: %s, Mensalidade: %f", clientesvet[i].client, clientesvet[i].cli_tele, clientesvet[i].cli_cpf, clientesvet[i].cli_mensa);
};

void imprimirclienteconsulta(clientes e){
    printf("\nNome: %d\n", e.client);
    printf("\tTelefone: %i", e.cli_tele);
    printf("\tCPF: %s", e.cli_cpf);
    printf("\tMensalidade: R$%.2f\n", e.cli_mensa);
};


//Nosso registro para armazenar um tipo chamado produto
typedef struct{
      int codigo;
      char nome[50];
      char marca[50];
      float valor;
      int quantidade;
} produto;
//vetor global do tipo produto

produto estoque[5];


//função que lê um produto do teclado e retorna para quem chamou
produto lerproduto(){
      produto el;
      printf("\nDigite o codigo: ");
      scanf("%d", &el.codigo);
      scanf("%*c");
      printf("\nDigite o nome: ");
      fgets(el.nome, 49, stdin);
      printf("Digite a marca: ");
      fgets(el.marca, 49, stdin);
      printf("Valor: ");
      scanf("%f", &el.valor);
      printf("Digite a quantidade: ");
      scanf("%d", &el.quantidade);
      return el;//retorno do produto preenchido para quem chamou
};

//procedimento para imprimir um produto na tela
void exibir(produto elt){
      printf("\n\tCodigo: %d\n", elt.codigo);
      printf("\tNome: %s", elt.nome);
      printf("\tMarca: %s", elt.marca);
      printf("\tValor R$%.2f\n", elt.valor);
      printf("\tQuantidade: %d\n\n", elt.quantidade);
};

void imprimiCodigoNome(){
int i;
for(i = 0; i < tam; i++)
    printf("\nCodigo: %d\tNome: %s", estoque[i].codigo, estoque[i].nome);
};

void imprimirproduto(produto e){
    printf("\nCodigo: %d\n", e.codigo);
    printf("\tNome: %s", e.nome);
    printf("\tMarca: %s", e.marca);
    printf("\tValor: R$%.2f\n", e.valor);
    printf("\tQuantidade: %d\n\n", e.quantidade);
};

//função que tenta realizar uma venda
//retorna 1 se conseguiu vender (se há estoque disponível)
//retorna 0 se não conseguir vender (quantidade igual a zero)
//a venda subtrai 1 da quantidade disponível
struct{
int au1, au2, venda;
float valorpacial, valortotal;
} relvenda;

void vender(){
        int cod, i;
        imprimiCodigoNome();// imprime na tela código e nome de todos os produtos
        printf("Qual_o_codigo_do_produto?: ");
        scanf("%d", &cod);
        for(i = 0; i < tam; i++) {//procura o item a ser vendido pelo código
                if(cod == estoque[i].codigo) {
                         if(estoque[i].quantidade > 0){//verifica se está disponível no estoque
                                estoque[i].quantidade--;
                                relvenda.valorpacial = estoque[i].quantidade * estoque[i].valor;
                                relvenda.venda = relvenda.venda + 1;
                                relvenda.au1 = relvenda.venda;
                                relvenda.valortotal += relvenda.valorpacial;
                                printf("\n*****Venda_realizada_com_sucesso!!!*****\n");
                        }else{
                             printf("\n*****Nao_foi_possivel_realizar_a_venda._Verifique_seu_estoque*****\n");
                        }
                }
        }
};


int atualizarEstoque(){
        int cod, i, qt;
        imprimiCodigoNome();//imprime na tela código e nome de todos os eletrônicos
        printf("Qual_o_codigo_do_produto?: ");
        scanf("%d", &cod);
        for(i = 0; i < tam; i++) {//procura o item a ser atualizado pelo código
                if(cod == estoque[i].codigo) {
                            printf("nQual_a_quantidade? ");//pede ao usuário a quantidade a ser adicionada
                            scanf("%d", &qt);
                            estoque[i].quantidade += qt;// atualiza a quantidade em estoque
                            return 1;//atualização efetuada com sucesso
                }
            }
            return 0;// não foi possível efetuar a atualização
};

void main(){
    //Formatação para português
    setlocale(LC_ALL, "Portuguese");

   //Variáveis
    int aumensa, i, valormensa,
    au, au2, au3, cont1, cont2, cont3,
    cont4, cont5, op, op2, op3, op4, op5, cli, esta;
    float caixa, soma;

    //variaveis para o login
    char login[15] = "adm";
    char login1[15];
    char senha[15] = "123";
    char senha1[15];
    int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

    //Tela de login
    printf("\n********LOGIN********\n");
      while(!login_efetuado){
        printf("Digite o Login: ");
        scanf("%s", &login1);

        printf("Digite a Senha: ");
        scanf("%s", &senha1);

        if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0){
            printf("\n\n****LOGADO!****\n\n");
            login_efetuado = 1;
        }
        else
            printf("\n\n****DADOS_INVALIDOS!****\n\n");
    }
    printf("\n**********************\n");

    //Menu principal
    do{
        printf("\n****MENU_PRINCIPAL****\n");
        printf("\n-----Cadastro-----");
        printf("\n[1] Cadastrar_funcionario");
        printf("\n[2] Cadastrar_cliente");
        printf("\n[3] Cadastrar_produto");
        printf("\n\n-----Altercao/Consultas-----");
        printf("\n[4] Menu_de_alteracao_de_dados");
        printf("\n[5] Menu_de_consultas");
        printf("\n\n-----Gerencia-----");
        printf("\n[6] Menu_do_gerente");
        printf("\n\n-----Vendas-----");
        printf("\n[7] Vender_produtos");
        printf("\n\n------------------");
        printf("\n[0] Sair \n");
        printf("\nEscolha_uma_opcao: ");
        scanf("%d", &op);
        printf("\n********************************\n\n");
     //Seleção de funções do menu principal
     switch(op){
        //Função de cadastro de funcionario
        case 1:
            for (cont5 = 0; cont5 < 1; cont5++){
                struct funcionario fcad;
            printf("\n********************************\n\n");
                printf("\nDigite_o_nome_do_funcionario: ");
                scanf("%s", &fcad.fun[cont5]);
                printf("\nDigite_o_CPF_do_funcionario: ");
                scanf("%i", &fcad.cpf[cont5]);
                printf("\nDigite_o_telefone_do_funcionario: ");
                scanf("%i", &fcad.tele[cont5]);
               printf("\n********************************\n\n");
               }
                break;

        //Função para cadastro de clientes
        case 2: printf("\n****VOCÊ_ESTÁ_NO_CADASTRO_DE_CLIENTES****\n\n");
                 printf("\n********************************\n");
                clientes cl = lercliente();
                // preenche o vetor (clientes) pedindos os dados ao usuário
                for(i = 0; i < tam; i++){
                    clientesvet[i] = lercliente();
                    }
                printf("\n********************************\n\n");
                break;

        //Menu de cadastro de produtos
        case 3: printf("\n****VOCÊ_ESTÁ_NO_CADASTRO_DE_PRODUTOS****\n\n");
                 printf("\n********************************\n");
                produto el = lerproduto();
                // preenche o vetor (estoque) pedindos os dados ao usuário
                for(i = 0; i < tam; i++){
                    estoque[i] = lerproduto();
                    }
                printf("\n********************************\n\n");
        break;


        //Menu de alterção de dados
        case 4:     do{
                        printf("\n****MENU_DE_ALTERAÇÃO_DE_DADOS****\n");
                        printf("[1] Alterar_dados_dos_funcionários\n");
                        printf("[2] Alterar_dados_do_Estoque\n");
                        printf("[0] sair\n");
                        printf("\nEscolha_uma_opção: ");
                        scanf("%d", &op3);
                        printf("\n********************************\n\n");

                        //Seleção de funções do  menu de alteração dos dados
                        switch(op3){
                            //função de alteração de dados dos funcionários
                            case 1: printf("escolha_o_funário_de_0_a_49: ");
                            scanf("%d", &au);
                            struct funcionario fcad;
                            printf("Digite_o_nome_do_funcionário: ");
                            scanf("%s", &fcad.fun[au]);
                            printf("Digite_o_CPF_do_funcionário: ");
                            scanf("%d", &fcad.cpf[au]);
                            printf("Digite_o_telefone_do_funcionário: ");
                            scanf("%d", &fcad.tele[au]);
                            break;

                            //Função de alteração de dados
                           case 2: //atualizar estoque
                            if(atualizarEstoque())
                                printf("\nEstoque_atualizado!!!\n");
                            else
                                printf("\nErro_ao_atualizar_o_estoque!\n");
                            break;

                            case 0://Função de saida do menu de alteração
                           printf("\n********************************\n");
                            printf("\nSaiu_da_opção_de_cadastro_de_produto.\n");
                            printf("\n********************************\n\n");
                            break;

                            //Função default usada caso o usuario coloque uma opção invalida
                            default: printf("\n*****Opção_invlida!.Tente_novamente.*****\n");
                        }
                    }while(op3 != 0);
                break;

        //Menu de consultas
        case 5:     do{
                        printf("****MENU _DE_CONSULTAS****\n");
                        printf("[1] Consultar_estoque\n");
                        printf("[2] Consultar_clientes\n");
                        printf("[0] sair\n");
                        printf("\nEscolha uma opcao: ");
                        scanf("%d", &op4);
                        printf("\n********************************\n\n");

                        //Seleção de funções do menu de consultas
                        switch (op4){
                        //Função para mostrar estoque
                        case 1: //imprimir todos os produtos
                                for(i = 0; i < tam; i++) {
                                printf("\nProduto_indice %d\n", i);
                                imprimirproduto(estoque[i]);
                                 }
                        break;

                        //Função para mostrar clientes
                        case 2:
                                for(i = 0; i < 5; i++) {
                                printf("\nindice %d\n", i);
                                exibircliente(clientesvet[i]);
                                 }
                        break;

                        //Saida do menu de consultas
                        case 0:
                            printf("\n********************************\n");
                            printf("Você_saiu_do_menu_de_consultas.");
                            printf("\n********************************\n\n");
                        break;

                        //Função default usada caso o usuario coloque uma opção invalida
                        default: printf("\n*****Opcao_invlida!._Tente_novamente.*****\n");
                        }
                    }while(op4 != 0);
                    break;

        //Menu do gerente
        case 6:  do{
                    printf("****MENU _DE_CONSULTAS****\n");
                    printf("[1] Relatorio_do_faturamento_diario_ou_mensal\n");
                    printf("[2] Relatório_de_vendas\n");
                    printf("[0] Sair \n");
                    printf("\nEscolha uma opcao: ");
                    scanf("%d", &op5);
                    printf("\n********************************\n\n");

                    //Seleção de funções do menu do gerente
                    switch(op5){
                    //Função para o faturamento mensal
                    case 1: printf("****Faturamento_mensal****\n");
                            printf("\nValor_total_das_vendas: R$%.2f", relvenda.valortotal);
                            printf("\nComissao_paga_ao_Funcionario: R$%.2f\n", relvenda.valortotal * 0.05);
                            printf("\n********************************\n\n");

                    break;
                    //Função de relatorio de vendas
                    case 2: printf("****Relatorio_vendas****\n");
                            printf("Nesse_mes_tivemos_um_total_de: %d vendas.", relvenda.au1);
                            printf("\n********************************\n\n");
                    break;

                    //Função default usada caso o usuario coloque uma opção invalida
                    default: printf("\n*****Opcao_invlida!._Tente_novamente.*****\n");
                    }
                }while(op5 != 0);
                break;

        case 7: // vender um produto
             vender();
             break;

        //Encerramento do programa
        case 0: printf("\n\nPrograma _encerrado.\n\n");
             break;

        //Função default usada caso o usuario coloque uma opção invalida
        default: printf("\n*****Opcao_invlida!._Tente_novamente.*****\n");
      }
    }while(op != 0);
};
