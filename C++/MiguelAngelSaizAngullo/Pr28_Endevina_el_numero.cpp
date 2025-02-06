#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int numeroAleatorio, numeroUsuario, contador = 0, numeroMinimo = 1, numeroMaximo = 1000;

    int generarNumeroAleatorio();

    int pedirNumeroUsuario();

    int calcularMaximo(int numeroAleatorio, int numeroUsuario, int numeroMaximo);

    bool compararacionNumeros(int numeroAleatorio, int numeroUsuario);

    int calcularMinimo(int numeroAleatorio, int numeroUsuario, int numeroMinimo);

    bool compararacion = false;

    srand(time(NULL));

    numeroAleatorio = generarNumeroAleatorio();

    do{
        numeroUsuario = pedirNumeroUsuario();

        compararacion = compararacionNumeros(numeroAleatorio, numeroUsuario);

        if (compararacion == false){
            numeroMaximo = calcularMaximo(numeroAleatorio, numeroUsuario, numeroMaximo);
            numeroMinimo = calcularMinimo(numeroAleatorio, numeroUsuario, numeroMinimo);
            printf("El numero esta entre el %i y %i\n",numeroMinimo,numeroMaximo);
        }

        contador += 1;

    }while(contador < 10 && compararacion == false);

    if(compararacion == true){
        printf("Has conseguido en %i intentos adivinar el numero %i",contador,numeroAleatorio);
    }else{
        printf("No has conseguido en %i intentos adivinar el numero %i",contador,numeroAleatorio);
    }


}

int generarNumeroAleatorio(){
    return rand()%1000+1;
}

int pedirNumeroUsuario(){
    int numeroUsuario;

    printf("Escribe un numero: ");
    scanf ("%i",&numeroUsuario);

    return numeroUsuario;
}

bool compararacionNumeros(int numeroAleatorio, int numeroUsuario){
    if (numeroAleatorio == numeroUsuario) return true ; else return false;
}

int calcularMaximo(int numeroAleatorio, int numeroUsuario, int numeroMaximo){
    if(numeroUsuario>numeroAleatorio) return numeroUsuario; else return numeroMaximo;
}

int calcularMinimo(int numeroAleatorio, int numeroUsuario, int numeroMinimo){
    if(numeroUsuario<numeroAleatorio) return numeroUsuario; else return numeroMinimo;
}

