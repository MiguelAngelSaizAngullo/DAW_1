#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void){
    ///VARIABLES
    int numeroDeOportunidades = 10;
    int pistaUsuario[2] = {0,1000};
    ///FUNCIONES
    int Aleatorio(void);
    int adivinarNumeroAleatorio(int numeroAleatorio,int numeroDeOportunidades, int pistaUsuario[]);
    ///SEMILLA TEMPORAL
    srand(time(NULL));

    int numeroAleatorio = Aleatorio();
    printf("%i \n",numeroAleatorio);
    adivinarNumeroAleatorio(numeroAleatorio,numeroDeOportunidades,pistaUsuario);
}

int Aleatorio(void){
    return rand()%1000;
}

/// INTENTAR HACER RECURSIVIDAD + NIVELES
int adivinarNumeroAleatorio(int numeroAleatorio,int numeroDeOportunidades, int pistaUsuario[]){
    ///FUNCIONES
    int consultarNumeroDeVidas(bool resultadoRespuesta,int numeroDeOportunidades);
    int respuestaUsuario(void);
    void mostrarPistaUsuario(int numeroUsuario, int numeroAleatorio,int pistaUsuario[]);
    ///VARIABLES
    int numeroUsuario;
    bool resultadoRespuesta = false;
    /// GUARDO EL VALOR YA QUE SI LUEGO LLAMO A LA FUNCION ME PREGUNTARA POR OTRO NUMERO Y NO QUIERO ESO.
    numeroUsuario = respuestaUsuario();
    /// CUANDO EL USUARIO NO HACIERTE LE MOSTRARE LAS VIDAS QUE LE QUEDAN Y ENTRE QUE NUMERO ESTA EL ALEATORIO, SI LO ACIERTO ME DIRA EN CUANTO INTENTOS LO HE REALIZADO (DIRECTAMENTE LO RESTO SIN GUARDARLO) Y SALIMOS.
    if (numeroUsuario != numeroAleatorio) numeroDeOportunidades = consultarNumeroDeVidas(false,numeroDeOportunidades), mostrarPistaUsuario(numeroUsuario,numeroAleatorio,pistaUsuario);
    else resultadoRespuesta = true,printf("CORRECTE! Los has realizado en %i intents.\n", 10-numeroDeOportunidades) ;

    /// RECURISIVIDAD
    if (numeroDeOportunidades >= 0 && resultadoRespuesta == false) return adivinarNumeroAleatorio(numeroAleatorio,numeroDeOportunidades,pistaUsuario);else printf("Adios ...");;
}

int respuestaUsuario(void){
    int numeroUsuario;
    printf("Que numero crees que es? \n");
    scanf("%i",&numeroUsuario);
    return numeroUsuario;
}

int consultarNumeroDeVidas(bool resultadoRespuesta,int numeroDeOportunidades){
    /// SI EL NUMERO ES CORECTO NO MODIFICARE LAS VIDAS
    if (resultadoRespuesta) numeroDeOportunidades; else numeroDeOportunidades --;
    printf("Tienes %i Vidas: \n", numeroDeOportunidades);
    /// DEVOLVEMOS LA CANTIDAD DE OPORTUNIDADES / VIDA LE QUEDA AL USUARIO
    return numeroDeOportunidades;
}

void mostrarPistaUsuario(int numeroUsuario, int numeroAleatorio,int pistaUsuario[]){
    /// SI EL USUARIO INTRODUCE UN NUMERO MAS PEQUEÑO SERA EL NUMERO MINIMO Y SI EL NUMERO INTRODUCE UN NUMERO MAS GRANDE QUE EL ALEATORIO SERA EL MAXIMO PARA DAR LA PISTA
    if(numeroUsuario < numeroAleatorio) pistaUsuario[0] = numeroUsuario; else pistaUsuario[1] = numeroUsuario;
    printf("Numero esta entre el %i y el %i \n", pistaUsuario[0],pistaUsuario[1]);
}
