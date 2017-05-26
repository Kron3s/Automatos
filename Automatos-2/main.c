#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
 int funcTransicao(int q , char a){
    int resultado ;

  switch(q){

    case 0:       
                     if( a == 'b')
                        resultado = 1;
                    else if (a == 'a')
                        resultado  = 2;
                    break;


    case 1: 
                    if( a == 'b')
                        resultado = 3;
                    else if (a == 'a')
                        resultado  = 4;
                    break;

    case 2:         if( a == 'b')
                        resultado = 5;
                    else if (a == 'a')
                        resultado  = 6;
                    break;

    case 3:        if( a == 'b')
                        resultado = 7;
                    else if (a == 'a')
                        resultado  = 8;
                    break;

    case 4:         if( a == 'b')
                        resultado = 9;
                    else if (a == 'a')
                        resultado  = 8;
                    break;

    case 5:         if( a == 'b')
                        resultado = 10;
                    else if (a == 'a')
                        resultado  = 8;
                    break;

    case 6:         if( a == 'b')
                        resultado = 11;
                    else if (a == 'a')
                        resultado  = 8;
                    break;

    case 7:               if( a == 'b')
                        resultado = 7;
                    else if (a == 'a')
                        resultado  = 12;
                    break;

    case 8:         if( a == 'b')
                        resultado =8 ;
                    else if (a == 'a')
                        resultado  = 8;
                    break;

    case 9:       if( a == 'b')
                        resultado =10;
                    else if (a == 'a')
                        resultado  =13;
                    break;

    case 10:        if( a == 'b')
                        resultado =7;
                    else if (a == 'a')
                        resultado  = 12;
                    break;

    case 11:        if( a == 'b')
                        resultado = 10;
                    else if (a == 'a')
                        resultado  =13 ;
                    break;

    case 12:       if( a == 'b')
                        resultado = 9;
                    else if (a == 'a')
                        resultado  =14 ;
                    break;

    case 13:        if( a == 'b')
                        resultado = 9;
                    else if (a == 'a')
                        resultado  = 14;
                    break;

    case 14:        if( a == 'b')
                        resultado = 11;
                    else if (a == 'a')
                        resultado  = 15;
                    break;

    case 15:       if( a == 'b')
                        resultado =11 ;
                    else if (a == 'a')
                        resultado  = 15;
                    break;


  }
  return resultado;

 }



int transicaoEx(int q,char *w){

  if(strlen(w)==0){
    return 0;
  }  

  char*palavra =(char*)malloc(sizeof(strlen(w)-1));
   char x;
  int tamanho = strlen(w)-1;
  x = w[tamanho];
  strncpy(palavra,w,tamanho);

  int t = funcTransicao(transicaoEx(q,palavra),x);

  return t;

}

void pertence(int estado, int *finais){
   
   for (int i = 0; i < sizeof(finais); ++i)
   {
       if (estado == finais[i]){
          printf("A palavra é aceita pelo automato\n");
          return;
       }

      
   }
    printf("A palavra nao e aceita pelo automato\n");


}

int main(void ) {

     int finais[4] = {7, 9, 12, 14};
     int inicial  = 0;
     char palavra[100];

     printf("DIGITE A PALAVRA\n");
     scanf("%s",palavra);


     int estado;
     estado= transicaoEx(inicial,palavra);
     pertence(estado,finais);


    

     
    

    return 0;
}