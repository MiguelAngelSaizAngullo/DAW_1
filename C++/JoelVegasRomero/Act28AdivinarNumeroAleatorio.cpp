#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///FUNCIONES
int generarNumeroAleatorio(void);
int gestionJuego(int numeroAleatorio,int numeroDeOportunidades, int rangoNumeroAleatorio[]);
int actualizarVidas(bool resultadoRespuesta,int numeroDeOportunidades);
int pedirNumeroUsuario(int rangoNumeroAleatorio[]);
void mostrarRangoNumeroAleatorio(int numeroUsuario, int numeroAleatorio,int rangoNumeroAleatorio[]);

int main (void){
    int numeroDeOportunidades = 10;
    int rangoNumeroAleatorio[2] = {0,1000};
    ///SEMILLA TEMPORAL
    srand(time(NULL));

    int numeroAleatorio = generarNumeroAleatorio();
    gestionJuego(numeroAleatorio,numeroDeOportunidades,rangoNumeroAleatorio);
}

int generarNumeroAleatorio(void){
    return rand()%1000+1;
}

/// INTENTAR HACER RECURSIVIDAD + NIVELES
int gestionJuego(int numeroAleatorio,int numeroDeOportunidades, int rangoNumeroAleatorio[]){
    int numeroUsuario;
    bool resultadoRespuesta = false;

    /// GUARDO EL VALOR YA QUE SI LUEGO LLAMO A LA FUNCION ME PREGUNTARA POR OTRO NUMERO Y NO QUIERO ESO.
    numeroUsuario = pedirNumeroUsuario(rangoNumeroAleatorio);
    /// CUANDO EL USUARIO NO HACIERTE LE MOSTRARE LAS VIDAS QUE LE QUEDAN Y ENTRE QUE NUMERO ESTA EL ALEATORIO, SI LO ACIERTO ME DIRA EN CUANTO INTENTOS LO HE REALIZADO (DIRECTAMENTE LO RESTO SIN GUARDARLO) Y SALIMOS.
    if (numeroUsuario != numeroAleatorio) numeroDeOportunidades = actualizarVidas(false,numeroDeOportunidades), mostrarRangoNumeroAleatorio(numeroUsuario,numeroAleatorio,rangoNumeroAleatorio);
    else resultadoRespuesta = true,printf("CORRECTE! Los has realizado en %i intents.\n", 10-numeroDeOportunidades) ;

    /// RECURISIVIDAD
    if (numeroDeOportunidades >= 0 && resultadoRespuesta == false) return gestionJuego(numeroAleatorio,numeroDeOportunidades,rangoNumeroAleatorio);
    else printf("Adios ...");;
}

int pedirNumeroUsuario(int rangoNumeroAleatorio[]){
    int numeroUsuario;
    do {
        printf("Que numero crees que es? \n");
        scanf("%i",&numeroUsuario);
        if (numeroUsuario <= rangoNumeroAleatorio[0] || numeroUsuario >= rangoNumeroAleatorio[1]) printf("El numero tiene que estar entre %i y %i \n",rangoNumeroAleatorio[0],rangoNumeroAleatorio[1]);
    }while(numeroUsuario <= rangoNumeroAleatorio[0] || numeroUsuario >= rangoNumeroAleatorio[1]);
    return numeroUsuario;
}

int actualizarVidas(bool resultadoRespuesta,int numeroDeOportunidades){
    /// SI EL NUMERO ES CORECTO NO MODIFICARE LAS VIDAS
    numeroDeOportunidades --;
    printf("Tienes %i Vidas: \n", numeroDeOportunidades);
    /// DEVOLVEMOS LA CANTIDAD DE OPORTUNIDADES / VIDA LE QUEDA AL USUARIO
    return numeroDeOportunidades;
}

void mostrarRangoNumeroAleatorio(int numeroUsuario, int numeroAleatorio,int rangoNumeroAleatorio[]){
    /// SI EL USUARIO INTRODUCE UN NUMERO MAS PEQUEÑO SERA EL NUMERO MINIMO Y SI EL NUMERO INTRODUCE UN NUMERO MAS GRANDE QUE EL ALEATORIO SERA EL MAXIMO PARA DAR LA PISTA
    if(numeroUsuario < numeroAleatorio) rangoNumeroAleatorio[0] = numeroUsuario; else rangoNumeroAleatorio[1] = numeroUsuario;
    printf("Numero esta entre el %i y el %i \n", rangoNumeroAleatorio[0],rangoNumeroAleatorio[1]);
}
