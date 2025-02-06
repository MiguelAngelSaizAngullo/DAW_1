 #include <stdio.h>

 int main (void){
    ///VARIABLES
    int menuOpcion,numeroUsuario;
    ///FUNCIONES

    int menuPrincipal(void);
    int opcionMenuUsuario (int opcionMenu,int numeroUsuario);


    menuOpcion = menuPrincipal();
    opcionMenuUsuario(menuOpcion,numeroUsuario);
 }
int pedirNumero(void){
    int numeroUsuario;
    printf("Indicame un numero: ");
    do{
        scanf("%i",&numeroUsuario);
        if(numeroUsuario < 0 || numeroUsuario > 255) printf("ERROR");
    }while(numeroUsuario < 0 || numeroUsuario > 255);
    return numeroUsuario;
}

int menuPrincipal(void){
    int opcion;
    printf("Elige una opcion: \n");
    printf("1. Convertir Decimal a Binari. \n");
    printf("2. Convertir Binari a Decimal. \n");

    do{
        scanf("%i",&opcion);
        if(opcion <= 0 || opcion >= 3) printf("ERROR");
    }while(opcion <= 0 || opcion >= 3);
    return opcion;
 }


 int opcionMenuUsuario (int opcionMenu, int numeroUsuario){
    ///FUNCIONES
    int extraerNumeroBinario (int Decimal);
    void pedirNumeroBinario (void);
    int pedirNumero(void);

    switch(opcionMenu){
        case 1:
            numeroUsuario = pedirNumero();
            extraerNumeroBinario(numeroUsuario);
        break;

        case 2:
            pedirNumeroBinario();
        break;

        default:
            printf("ERROR OPCION NO CONTEMPLADA");
    }
 }

int extraerNumeroBinario (int Decimal){
    int numeroBinario[8], contadorCantidadDecimales = 0,i;

    for (i = 0; Decimal != 0; i++){
        ///FUNCIONES
        int cogerDecimal (int Decimal);


        /// if(Decimal == 0)  return 1; else numeroBinario[i] = extraerNumeroBinario(cogerDecimal(Decimal)/2);
        /// A�ADIR RECURSIVIDAD CUANDO SEA DIVISION/2 = RETURN 0
        numeroBinario[i] = cogerDecimal(Decimal);
        Decimal = Decimal/2;
        contadorCantidadDecimales ++;
    }

    printf("Numero Binario: ");
    for (i--;i >= 0; i--){
       printf("%i",numeroBinario[i]);
    }
 }

 int cogerDecimal (int Decimal){
    if (Decimal%2 != 0) return 1; else return 0;
 }


 void pedirNumeroBinario (void){
    ///FUNCIONES
    int numeroBinarioUsuario (void);
    void mostrarArrayBinario(int numeroBinario[7]);
    void convertirDecimal(int numeroBinario[7]);
    ///VARIABLES
    int numeroBinario[8];

    for (int contador = 0; contador <= 7; contador ++){
        numeroBinario[contador] = numeroBinarioUsuario();
    }
    mostrarArrayBinario(numeroBinario);
    convertirDecimal(numeroBinario);
 }


 int numeroBinarioUsuario (void){
    ///FUNCIONES
    bool comprobacionNumeroBinario(int binario);
    /// VARIABLES
    int binario;

    do{
        printf("Dime un Digito Binario: ");
        scanf("%i",&binario);
        if(comprobacionNumeroBinario(binario)) printf("ERROR, debe ser un Digito binario \n");
    }while(comprobacionNumeroBinario(binario));
    return binario;
 }

 bool comprobacionNumeroBinario(int binario){
    if(binario < 0 || binario > 1) return true; else return false;
 }

 void mostrarArrayBinario(int numeroBinario[7]){
    for(int i = 0; i <=7; i++){
        printf("%i \n",numeroBinario[i]);
    }
 }

 void convertirDecimal(int numeroBinario[7]){
    ///VARIABLE
    int valor = 0,i;
    ///FUNCIONES
    int numeroElevador(int i);

    for (i = 7; i >= 0; i--){
        valor += numeroBinario[i] * numeroElevador(i);
    }
    printf("El valor es: %i",valor);
 }

 int numeroElevador(int i){
    int total = 2;
    if(i == 0) return 1;
    if (i == 1) return 2;
    while (i >= 2){
        total *= 2;
        i --;
    };
    return total;
 }
