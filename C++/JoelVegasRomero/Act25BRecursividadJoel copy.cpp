#include <stdio.h>

int main(void){
    ///FUNCIONES
    int pedirNumeroUsuario(void);
    int Algoritme(int numeroUsuario);

    int numeroUsuario = pedirNumeroUsuario();
    Algoritme(numeroUsuario);
}

int pedirNumeroUsuario(void){
    int numeroUsuario;
    printf("Indicame un Numero: ");
    scanf("%i",&numeroUsuario);
    if(numeroUsuario <= 0) pedirNumeroUsuario(); else numeroUsuario;
}

int Algoritme(int numeroUsuario){
    printf("%i ",numeroUsuario);
    if (numeroUsuario == 1) return 1;
    if (numeroUsuario%2==0) return Algoritme(numeroUsuario/2); else return Algoritme(3*numeroUsuario+1);
}
