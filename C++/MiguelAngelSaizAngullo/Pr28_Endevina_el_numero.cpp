#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarNumeroAleatorio();

int pedirNumeroUsuario();

int calcularMaximo(int numeroAleatorio, int numeroUsuario, int numeroMaximo);

bool comparacionNumeros(int numeroAleatorio, int numeroUsuario);

int calcularMinimo(int numeroAleatorio, int numeroUsuario, int numeroMinimo);

int main(void){
    int numeroAleatorio, numeroUsuario, contador = 0, numeroMinimo = 1, numeroMaximo = 1000;


    bool comparacion = false;

    srand(time(NULL));

    numeroAleatorio = generarNumeroAleatorio();

    do{
        numeroUsuario = pedirNumeroUsuario();

        comparacion = comparacionNumeros(numeroAleatorio, numeroUsuario);

        if (!compararacion){
            numeroMaximo = calcularMaximo(numeroAleatorio, numeroUsuario, numeroMaximo);
            numeroMinimo = calcularMinimo(numeroAleatorio, numeroUsuario, numeroMinimo);
            printf("El numero esta entre el %i y %i\n",numeroMinimo,numeroMaximo);
        }

        contador += 1;

    }while(contador < 10 && !compararacion);

    if(compararacion == true){
        printf("Felicidades! Has adivinado el numero %i en %i intentos.\n", numeroAleatorio, contador);
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

bool comparacionNumeros(int numeroAleatorio, int numeroUsuario){
    return numeroAleatorio == numeroUsuario;
}

int calcularMaximo(int numeroAleatorio, int numeroUsuario, int numeroMaximo){
    return numeroUsuario>numeroAleatorio ? numeroUsuario : numeroMaximo;
}

int calcularMinimo(int numeroAleatorio, int numeroUsuario, int numeroMinimo){
    return numeroUsuario<numeroAleatorio ? numeroUsuario : numeroMinimo;
}

