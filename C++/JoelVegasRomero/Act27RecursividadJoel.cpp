 #include <stdio.h>

 int main (void){
    int listaUsuario [10];
    int i,j,orden,aux;

    printf("Introduce 10 numeros: \n");
    for (i = 0; i <= 9; i++){
        printf("Dame un valor: ");
        scanf("%i",&listaUsuario[i]);
    }

    //MOSTRAMOS EL VECTOR NORMAL
    printf("EL vector Incial es: \n");
    for(i = 0; i <= 9; i++){
        printf("%i ",listaUsuario[i]);
    }

    // PREGUNTAMOS POR ORDEN
    printf("Dime el orden: \n1. Mayor a menor\n.2 Menor a Mayor: ");
    scanf("%i",&orden);

    if(orden==2){
        //ORDENAMOS DE MENOR A MAYOR
        for (i = 0; i <= 8; i++){
            for(j = i+1;j <= 9; j++){
                if(listaUsuario[j] < listaUsuario[i]){
                    aux = listaUsuario[i];
                    listaUsuario[i] = listaUsuario[j];
                    listaUsuario[j] = aux;
                }
            }
        }
    }else{
        //ORDENACION DE MAYOR A MENOR
        for (i = 0; i <= 8; i++){
            for(j = i+1;j <= 9; j++){
                if(listaUsuario[j] > listaUsuario[i]){
                    aux = listaUsuario[i];
                    listaUsuario[i] = listaUsuario[j];
                    listaUsuario[j] = aux;
                }
            }
        }
    }

    //MOSTRAMOS EL VECTOR ORDENADO
    printf("EL vector ordenado es: \n");
    for(i = 0; i <= 9; i++){
        printf("%i ",listaUsuario[i]);
    }

 }
