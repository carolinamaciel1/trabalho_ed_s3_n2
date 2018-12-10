#include <stdio.h>
#include <stdlib.h>

//funções para estrutura e criação da arvore
struct tipoItem {
  int chave;
}; typedef struct tipoItem Item;

typedef struct no *apontador;

struct no {
  Item item;
  apontador esq;
  apontador dir;
}; typedef struct no No;


No* cria_arvore(Item i, No* sae, No* sad){
    No* pp=(No*)malloc(sizeof(No));
    pp->item = i;
    pp->esq = sae;
    pp->dir = sad;
return pp;
}



//funções de inserção de nó
void insere(Item x, apontador *p) {
  if ((*p) == NULL) {
     *p = (apontador) malloc(sizeof(No));
     (*p)->item = x;
     (*p)->esq = NULL;
     (*p)->dir = NULL;
  }
  else if (x.chave < (*p)->item.chave)
	  insere(x, &((*p)->esq));
       else insere(x, &((*p)->dir));
}

void inserirNos(apontador *raiz) {
    int qtd;
    Item x;
    printf("Informe a quantidade de alunos:");
    scanf("%d",&qtd);
    while(qtd>0) {
        printf("Informe a nota do aluno:");
        scanf("%d", &x.chave);
        insere(x, raiz);
    qtd--;
  }
      printf("Lista criada!");
}

//funções para imprimir os nós em ordem RED
void visitaRaiz(apontador no) {
  printf("%d ", no->item.chave);
}

void pre_ordem(apontador p) {
  if (p != NULL) {
     visitaRaiz(p);
     pre_ordem(p->esq);
     pre_ordem(p->dir);
  }
}


//funções para remover nós
void antecessor(apontador q, apontador *r) {
  if ((*r)->dir != NULL)
     antecessor(q, &((*r)->dir));
  else {
     q->item = (*r)->item;
     q = *r;
     *r = (*r)->esq;
     free(q);
  }
}


void retira(Item x, apontador *p, int *operacao) {
  apontador aux;
  if ((*p) == NULL)
     *operacao = 0;
  else if (x.chave < (*p)->item.chave)
	  retira(x, (&(*p)->esq), operacao);
       else if (x.chave > (*p)->item.chave)
	       retira(x, (&(*p)->dir), operacao);
	    else {
	       *operacao = 1;
	       if ((*p)->dir == NULL) {
		  aux = *p;
		  *p = (*p)->esq;
		  free(aux);
	       }
	       else if ((*p)->esq == NULL) {
		       aux = *p;
		       *p = (*p)->dir;
		       free(aux);
	            }
		    else antecessor((*p), (&(*p)->esq));
	    }
}

void removerNos(apontador *raiz) {
  Item x;
  int operacao;
    printf("Informe a nota a ser excluida: ");
    scanf("%d", &x.chave);
    retira(x, raiz, &operacao);
    if (operacao == 1)
       printf("\nItem removido com sucesso !!!");
    else printf("\Erro: Registro nao encontrado.");
}


//funções de maior e menor nota
void maiorNota(No *x){
      while(x->dir!=NULL){
           x=x->dir;
    }
    printf("%d",x->item.chave);

}

void menorNota(No *x){
      while(x->esq!=NULL){
           x=x->esq;
    }
    printf("%d",x->item.chave);

}



int main(){
    apontador raiz;
    raiz = NULL;
    printf("************SISTEMA DE NOTAS************\n\n");
    printf("\n1) Criar lista alunos");
    printf("\n2) Maior nota obtida no teste");
    printf("\n3) Menor nota obtida no teste");
    printf("\n4) Excluir nota");
    printf("\n5) Mostrar notas");
    printf("\n0) Sair");

    while(1){
        int opc;
        printf("\n\nDigite uma opc:");
        scanf("%d",&opc);
        if(opc==0){
            break;
        }
        else if(opc==1){
            inserirNos(&raiz);
        }else if(opc==2){
                maiorNota(raiz);
        }else if(opc==3){
                menorNota(raiz);
        }else if(opc==4){
            removerNos(&raiz);
        }else if(opc==5){
            pre_ordem(raiz);
        };
    }
}
