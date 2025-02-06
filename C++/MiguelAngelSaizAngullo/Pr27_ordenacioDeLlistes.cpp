#include <stdio.h>

int main(void){
    int numerosUsuario[10];
    int contador1, contador2, orden, numeroReservado;

    printf("Introduce 10 numeros:\n");

    for(contador1=0;contador1<sizeof(numerosUsuario)/sizeof(numerosUsuario[0]);contador1++){
        printf("Dame un valor: ");
        scanf("%i",&numerosUsuario[contador1]);
    }

    printf("Numeros iniciales sin ordenar:\n");
    for(contador1 = 0; contador1 < sizeof(numerosUsuario)/sizeof(numerosUsuario[0]); contador1 ++){
        printf("%i ",numerosUsuario[contador1]);
    }

    printf("\nDime el ordern (1. Mayot a menor 2. Menor a mayor): ");
    scanf("%i",&orden);

    if(orden == 2){
        printf("Ordenacion de menor a mayor \n");
        for(contador1 = 0; contador1 < sizeof(numerosUsuario)/sizeof(numerosUsuario[0]) - 1; contador1 ++){
            for (contador2 = contador1 + 1; contador2 < sizeof(numerosUsuario)/sizeof(numerosUsuario[0]); contador2 ++){
                if(numerosUsuario[contador2]<numerosUsuario[contador1]){
                    numeroReservado = numerosUsuario[contador1];
                    numerosUsuario[contador1] = numerosUsuario[contador2];
                    numerosUsuario[contador2] = numeroReservado;
                }
            }
        }

    }else{
        printf("Ordenacion de mayor a menor\n");

        for(contador1 = 0; contador1 < sizeof(numerosUsuario)/sizeof(numerosUsuario[0]) - 1; contador1 ++){
            for (contador2 = contador1 + 1; contador2 < sizeof(numerosUsuario)/sizeof(numerosUsuario[0]); contador2 ++){
                if(numerosUsuario[contador2]>numerosUsuario[contador1]){
                    numeroReservado = numerosUsuario[contador1];
                    numerosUsuario[contador1] = numerosUsuario[contador2];
                    numerosUsuario[contador2] = numeroReservado;
                }
            }
        }
    }

    for(contador1 = 0; contador1 < sizeof(numerosUsuario)/sizeof(numerosUsuario[0]); contador1 ++){
        printf("%i ",numerosUsuario[contador1]);
    }

}
