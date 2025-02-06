#include <stdio.h>

int main (void){
    ///FUNCIONES
    int pedirNumeroUsuario(void);
    int caluclarFibo(int numeroFibo);

    int numeroFibo = pedirNumeroUsuario();
    printf("El fibonacci de %i es: %i", numeroFibo,caluclarFibo(numeroFibo));
}

int pedirNumeroUsuario(void){
    int numeroUsuario;
    printf("Indicame el Numbero Fibo: ");
    scanf("%i",&numeroUsuario);
    if(numeroUsuario < 0) pedirNumeroUsuario(); else return numeroUsuario;
}

int caluclarFibo(int numeroFibo){
    if (numeroFibo == 0) return 0;
    if (numeroFibo == 1) return 1;
    ///
    return caluclarFibo(numeroFibo-1) + caluclarFibo(numeroFibo-2);
}
