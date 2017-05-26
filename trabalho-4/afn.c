#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct no{
    char info;
    struct no* prox;
}tno;

typedef struct{
    tno* inicio;
}lista;


lista* inicializar(){
    lista*  novo= (lista*) malloc (sizeof(lista));
     novo->inicio  =NULL;
    return novo;
}

void inserir(lista* l, char x){

    tno* no = (tno*) malloc (sizeof(tno));
    no->info = x;
    no->prox = NULL;

    if(!l->inicio){
        l->inicio = no;
    }
    else{
        tno* aux = l->inicio;

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
}



char remover_primeiro(lista* l){
    char c;
    tno* aux = l->inicio;
    if(!aux->prox){
        c = aux->info;
        free(aux);
        l->inicio = NULL;
       inserir(l, '&');
        return c;
    }

    l->inicio = aux->prox;
    c = aux->info;
    free(aux);
    return c;
}


lista *transicao(lista *f,char a){

 lista *estado = inicializar();
 tno * aux = f->inicio;


 while(aux){

    if(aux->info == '0'){
             if(a == 'b')
             	inserir(estado,'0');
             else if (a =='a'){
             	inserir(estado,'0');
             	inserir(estado,'1');
             }

         }

             if(aux->info == '1'){
                 if (a =='b')
                 	inserir(estado,'2');
                 else if (a=='a')
                 	inserir(estado,'2');
             }

             if(aux->info =='2'){
             	if (a =='b')
             		inserir(estado,'3');
             	else if(a=='a')
             		inserir(estado,'3');
             }

             aux = aux->prox;
 
    }

  return estado;


 }

lista *transicaoEst(char q, lista *w){
 lista *f = inicializar();
 inserir(f,q);

 while(w->inicio->info !='&'){
   f = transicao(f,remover_primeiro(w));



 }
return f;




}


void imprimir_lista(lista* l){
    tno* aux = l->inicio;
    puts("Lista");
    while(aux){
        printf("%c\n ", aux->info);
        aux = aux->prox;
    }
    
}
void aceita(lista *l,char final){
     
     tno * aux  = l->inicio;
     while(aux!=NULL){
        
        if(aux->info == final){
        	printf("A palavra é aceita pelo AFN\n");
        	return;
        }

      aux = aux->prox;

     }
     printf("A palavra nao é aceita pelo AFN\n");

   } 



int main(int argc, char const *argv[])
{
	lista *palavra = inicializar();
	char simbolos[20];
    char inicial = '0';
    char final  = '3';

    printf("AFN DA expressao regular : (a+b)*a(a+b)(a+b)\n");

    printf("digite a palvra\n");
scanf("%s",simbolos);


    for (int i = 0; i < strlen(simbolos); ++i)
    {
       inserir(palavra,simbolos[i]);
    }
    
    lista * estado;
    estado  = transicaoEst(inicial, palavra);
    //imprimir_lista(estado);
   aceita(estado,final);




	return 0;
}






