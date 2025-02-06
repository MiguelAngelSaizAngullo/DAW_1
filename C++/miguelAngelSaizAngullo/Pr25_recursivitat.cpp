#include <stdio.h>

int main(void){
    int numeroUsuario, calculoFibo;

    int realizarFibo(int numeroUsuario);

    void realizarSerie3NMasUno(int numeroUsuario);

    printf("Escribe un numero: ");
    scanf("%i",&numeroUsuario);

    calculoFibo = realizarFibo(numeroUsuario);

    printf("El fibonacci de %i es: %i\n",numeroUsuario,calculoFibo);

    realizarSerie3NMasUno(numeroUsuario);
}

int realizarFibo(int numeroUsuario){
    int calculoFibo = 0, fiboN, fiboNMenos1;

    if (numeroUsuario==1){
         return 1;
    }else if(numeroUsuario==0){
        return 1;
    }else{
        numeroUsuario -= 1;
        fiboN = realizarFibo(numeroUsuario);
        fiboNMenos1 = realizarFibo(numeroUsuario-1);
        calculoFibo = fiboN + fiboNMenos1;
    }

    return calculoFibo;
}

void realizarSerie3NMasUno(int numeroUsuario){
    if (numeroUsuario == 1){
        printf("1");
    }else{
        switch(numeroUsuario%2){
            case 0:
                numeroUsuario = numeroUsuario / 2;
                if(numeroUsuario!=1){
                    printf("%i-",numeroUsuario);
                }
                realizarSerie3NMasUno(numeroUsuario);
                break;
            case 1:
                numeroUsuario = 3 * numeroUsuario + 1;
                if(numeroUsuario!=1){
                    printf("%i-",numeroUsuario);
                }
                realizarSerie3NMasUno(numeroUsuario);
                break;
            default:
                printf("Error");
        }
    }
}
