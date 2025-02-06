#include <stdio.h>

int main(void){
    int menuOpciones(void);

    void pasarDecimalBinario(int n);

    void pasarBinarioDecimal(int numeroBinarioUsuario[8]);

    int opcion, numeroUsuario, numeroDecimal, numeroBinarioUsuario[8];

    opcion = menuOpciones();

    switch(opcion){
        case 1:
            do{
                printf("Escribe un numero decimal: ");
                scanf("%i",&numeroUsuario);
            }while(numeroUsuario<=0 || numeroUsuario > 255);

             pasarDecimalBinario(numeroUsuario);

            break;
        case 2:
                for(int contador=0;contador<=7;contador++){
                    do{
                        printf("Escribe un numero binario: ");
                        scanf("%i",&numeroBinarioUsuario[contador]);
                    }while(numeroBinarioUsuario[contador]<0 || numeroBinarioUsuario[contador]>1);

                }

                printf("El numero binario introducido es: ");

                for(int contador=7;contador>=0;contador--){
                    printf("%i",numeroBinarioUsuario[contador]);
                }

                printf("\n");

                pasarBinarioDecimal(numeroBinarioUsuario);
            break;
        default:
            printf("Opcion incorrecta");

    }

}

int menuOpciones(void){
    int opcion, contador;

    do{
        printf("1. Convertir de decimal a binario\n");
        printf("2. Convertir de binario a decimal\n");

        printf("Escoge una opcion: ");
        scanf("%i",&opcion);
    }while(opcion<=0 || opcion>2);
    return opcion;
}

void pasarDecimalBinario(int numeroUsuario){
    int numerosBinarios[8], resultado = numeroUsuario, contador = 0;

    for(int i=0;resultado!=0;i++){
        numerosBinarios[i] = resultado%2;
        resultado = resultado /2;
        contador += 1;
    }

    for(int i=contador-1;i>=0;i--){
        printf("%i",numerosBinarios[i]);
    }

}

int calcular_potencia(int numero, int potencia){
    int contador = 1, res = numero;

    if(potencia == 0){
        return 1;
    }else if(potencia == 1){
        return numero;
    }else{
        do{
            res = res * numero;
            contador += 1;
        }while(contador < potencia);

        return(res);
    }
}

void pasarBinarioDecimal(int numeroBinarioUsuario[8]){

    int numeroDecimal = 0;

    for(int contador=0;contador<=7;contador++){
        if(numeroBinarioUsuario[contador] == 1){
            numeroDecimal = numeroDecimal + calcular_potencia(2,contador);
        }
    }

    printf("El numero decimal es: %i",numeroDecimal);
}
