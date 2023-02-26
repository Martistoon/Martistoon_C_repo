#include <stdio.h>
#include <stdlib.h>
#include <locale.h>;

struct node    //Estrutura base do nó
{
    char pessoa[50];
    struct node *pLink; //Após a criação da lista, utilizando o malloc no maind, atualizamos o pLink com a posição de cada elemento novo
};

void displayLL(struct node *p)
{
    printf("Mostrando a lista:\n");
    if(p)
    {
        do
        {
            printf("| %s |", p->pessoa);
            p=p->pLink;
        }
        while(p);
    }
    else
    {
        printf("Lista vazia.");
    }
}

void deletar(struct node *p, char pag[50])
{
    struct node *pLink2 = p;
    struct node *pLink3 ;
    if(p)
    {
        do
        {
            pLink3 = p->pLink;
            if(strcmp(p->pessoa, pag) == 0)
            {
                puts("DADO LOCALIZADO E APAGADO!\n");
                p=pLink2;
                p->pLink = pLink3;
                break;
            }
            pLink2= p;
            p=p->pLink;
        }while(p);
    }
    else
    {
        printf("Dado não localizado");
    }
}

void alterar(struct node *p, char pag[50])
{
    char novoD[50];
    if(p)
    {
        do
        {
            if(strcmp(p->pessoa, pag) == 0)
            {
                printf("Novo dado a ser inserido: ");
                scanf("%s", &novoD);
                strcpy(p->pessoa,novoD);
                break;
            }
            p=p->pLink;
        }while(p);
    }
    else
    {
        printf("Dado não localizado");
    }
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    struct node *Apoint0 = NULL;
    struct node *Apoint1 = NULL;
    struct node *Apoint2 = NULL;
    struct node *Apoint3 = NULL;
    struct node *Apoint4 = NULL;

    char nome[50], esc[50];

    while(1)
    {
        int op;

        puts("--SELECIONE UMA DAS OPÇÕES ABAIXO--");
        puts("[0] Encerrar programa\n[1] Adicionar nomes\n[2] Alterar nome\n[3] Deletar nome\n[4] Imprimir lista");
        puts("-----------------------------------");
        printf(": ");
        scanf("%i", &op);
        system("cls");

        switch(op)
        {
            case 0:
                puts("\nFIM DO PROGRAMA!\n");
                exit(0);
            break;

            case 1:
                printf("Digite N nomes:\n");

                scanf("%s", &nome);
                Apoint0 = (struct node*) malloc(sizeof(struct node*)); //Criação do link entre os nós
                strcpy(Apoint0->pessoa,nome);
                /////////////////////////////////////////////////////////////////////////////////////
                scanf("%s", &nome);
                Apoint1 = (struct node*) malloc(sizeof(struct node*)); //Criação do link entre os nós
                strcpy(Apoint1->pessoa,nome);
                /////////////////////////////////////////////////////////////////////////////////////
                scanf("%s", &nome);
                Apoint2 = (struct node*) malloc(sizeof(struct node*)); //Criação do link entre os nós
                strcpy(Apoint2->pessoa,nome);
                /////////////////////////////////////////////////////////////////////////////////////
                scanf("%s", &nome);
                Apoint3 = (struct node*) malloc(sizeof(struct node*)); //Criação do link entre os nós
                strcpy(Apoint3->pessoa,nome);

                /////////////////////////////////////////////////////////////////////////////////////
                scanf("%s", &nome);
                Apoint4= (struct node*) malloc(sizeof(struct node*)); //Criação do link entre os nós
                strcpy(Apoint4->pessoa,nome);

                Apoint0 -> pLink = Apoint1;
                Apoint1 -> pLink = Apoint2;
                Apoint2 -> pLink = Apoint3;
                Apoint3 -> pLink = Apoint4;
                Apoint4 -> pLink = NULL;
            break;

            case 2:
                printf("Escrava o nome a ser ALTERADO: ");
                scanf("%s", &esc);
                alterar(Apoint0, esc);
            break;

            case 3:
                printf("Escreva o nome a ser APAGADO: ");
                scanf("%s", &esc);
                deletar(Apoint0, esc);
            break;

            case 4:
                if(Apoint0)
                {
                    displayLL(Apoint0);
                }
                else
                {
                    puts("SEM DADOS ARMAZENADOS!");
                }
                puts("\n");
            break;

            default:
                printf("\nOPÇÃO %i INVÁLIDA!\n\n", op);
            break;
        }
        system("pause");
        system("cls");
    }
}
