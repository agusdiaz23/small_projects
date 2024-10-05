//Nombre: Federico Alonso
//CI: 54501547
//Email: federico.alonso.redes@gmail.com

#include <string>
#include <cstdlib>
#include <time.h> 
//v_1.0
// Manzanas implementadas. Si la serpiente las come, sumara un punto y sera visible
// Si el usuario anota 3 puntos antes que la serpiente, ganara

// Una funcion que hice para imprimir la serpiente
void print_snake(char main_array[][6]) {
    char row='0';

    // Este loop imprime coordenadas en la parte superior de la array
    printf("  ");
    for(int i=0; i<6;i++) {
        printf(" %c", row+i);
    }
    printf("\n");

    // Este loop imprime la serpiente
    for (int i=0; i<6; i++)  {
        printf("%c ", row+i);
        for (int u=0; u<6; u++)  {
            
            printf("%c", '|');
            if (main_array[i][u]== ' ')
                printf("%c", main_array[i][u]);
            else if(main_array[i][u]=='1' || main_array[i][u]=='2') {
                printf("%c", '$');
            }
            else{
                printf("%c", main_array[i][u]);
            }
        }
        printf("|\n");
    }
    printf("________________________\n");
}


void print_apples(char apple_array[][6]) {
    char row='0';

    // Este loop imprime coordenadas en la parte superior de la array
    printf("  ");
    for(int i=0; i<6;i++) {
        printf(" %c", row+i);
    }
    printf("\n");
    
    // Este loop imprime manzanas
    for(int i=0; i<6; i++) {
        printf("%c ", row+i);
        for(int u=0; u<6; u++) {
            printf("%c", '|');
            if(apple_array[i][u]=='m') {
                printf("%c", apple_array[i][u]);
            }
            else {
                printf("%c", ' ');
            }
        }
        printf("|\n");
    }
    printf("________________________\n");
}

// Hace aparecer la serpiente
void do_spawn_snake(char main_array[][6], char apple_array[][6]) {
    int temp_num, pos_1, pos_2, ant_pos_1, ant_pos_2, position_name=0;
    
    pos_1=rand()%6;   
    pos_2=rand()%6;
    main_array[pos_1][pos_2]='0';

    

    //Este while busca posiciones vecinas a mi posicion cargada
    //Funciona para cada parte de la serpiente
    for(int i = 0; i < 2;i++) {
        ant_pos_1=pos_1; // Esta es la posicion original de mi posicion, guardada para recuperarla bajo ciertas condiciones
        ant_pos_2=pos_2;

        while(main_array[pos_1][pos_2]!= ' '||apple_array[pos_1][pos_2]!=' ') { 
            temp_num=rand()%2;
            if (temp_num==0) { 
                if(pos_1==0)
                    pos_1++;
                else if(pos_1==5)
                    pos_1--;
                else {
                    temp_num=rand()%2;
                    if(temp_num==0)
                        pos_1++;
                    else
                        pos_1--;
                }
            }
            else {
                if(pos_2==0)
                    pos_2++;
                else if(pos_2==5)
                    pos_2--;
                else {
                    temp_num=rand()%2;
                    if(temp_num==0)
                        pos_2++;
                    else   
                        pos_2--;
                }
            }

            // Si tras el loop no encontre una posicion viable, regreso a mi backup y vuelvo a intentar
            if (main_array[pos_1][pos_2] != ' ') {
                pos_1 = ant_pos_1;
                pos_2 = ant_pos_2;
            }
        }
        position_name++;

        //Por cada loop, genero una nueva parte de la serpiente
        main_array[pos_1][pos_2]='0' + position_name;
    }
    

}


void do_spawn_apples(char apple_array[][6], char main_array[][6]) {
    int pos_1, pos_2;
    
    for(int i=0; i<4; i++) {
        do {
            pos_1=rand()%6;
            pos_2=rand()%6;
        }while(main_array[pos_1][pos_2] != ' '||apple_array[pos_1][pos_2]!=' ');
        apple_array[pos_1][pos_2]='m';
    }

}

// Una funcion para tomar un char no repetido de una array 2d, y reemplazarlo por la letra que el usuario elija
void do_replace_number(char main_array[0][6], char replacer_1, char replacer_2) {

    for (int i=0; i<6; i++) {
        for(int u=0; u<6; u++) {
            if(main_array[i][u]==replacer_1) {
                main_array[i][u]=replacer_2;
            }
        }
    }


}

// Esta funcion mueve la serpiente un bloque. Se puede invocar varias veces para que la serpiente se mueva una variable indenfinida de bloques
void do_snake_movement(char main_array[][6]) {
    int temp_num, pos_1, pos_2, ant_pos_1, ant_pos_2;

    // Esta parte del codigo busca la cabeza de la serpiente, la pone en una variable, y me hace un backup
    for (int i=0; i<6; i++) 
        for (int u=0; u<6; u++)
            if(main_array[i][u]=='0') {
                pos_1=i;
                pos_2=u;
            }
    ant_pos_1=pos_1;
    ant_pos_2=pos_2;

    //Este while del codigo busca una posicion vecina valida para mover la cabeza de la serpiente y la mueve
    while(main_array[pos_1][pos_2] != ' ' ) { 
        temp_num=rand()%2;
        if (temp_num==0) { 
            if(pos_1==0)
                pos_1++;
            else if(pos_1==5)
                pos_1--;
            else {
                temp_num=rand()%2;
                if(temp_num==0)
                    pos_1++;
                else
                    pos_1--;
            }
        }
        else {
            if(pos_2==0)
                pos_2++;
            else if(pos_2==5)
                pos_2--;
            else {
                temp_num=rand()%2;
                if(temp_num==0)
                    pos_2++;
                else   
                    pos_2--;
            }
        }

        if (main_array[pos_1][pos_2] != ' ') {
            pos_1 = ant_pos_1;
            pos_2 = ant_pos_2;
        }
    }
    main_array[pos_1][pos_2]='A'; // Esto define la cabeza de mi serpiente

    // El numero de celdas de la serpiente hace el codigo exponencialmente mas dificil, asi que hice un sistema de letras
    //La primera parte mueve la cola. Donde estaba el 0 pone una B, y donde estaba el 1 pone una C. El dos lo borra
    //al poner un numero en otra posicion no tengo que acordarme de la posicion previa
    do_replace_number(main_array, '0', 'B');
    do_replace_number(main_array, '1', 'C');
    do_replace_number(main_array, '2', ' ');

    // Finalmente reemplazo todo por numeros
    do_replace_number(main_array, 'A', '0');
    do_replace_number(main_array, 'B', '1');
    do_replace_number(main_array, 'C', '2');

}

// Esta funcion hace la logica de los puntos para la serpiente y el usuario.
int do_score(char main_array[][6], int pos_1, int pos_2, int score, int &show_snake, int &snake_score) {
    if(main_array[pos_1][pos_2]=='0'||main_array[pos_1][pos_2]=='1'||main_array[pos_1][pos_2]=='2') {
        printf("Serpiente encontrada\n");
        show_snake=3;
        score++;
    }
    else if(show_snake==3) {
        printf("La serpiente se ha comido una manzana\n");
        snake_score++;
    }
    else
        printf("Sigue buscando\n");

    return score;
}


void limpiar_buffer() {
    char loadedChar;

    do {
        loadedChar=getchar();
    }while(loadedChar!='\n');
    
    printf("%c", '\n');

}   

// me dice si la serpiente comio una manzana y si la comio elimina las manzanas y pone el contador de show_snake en 3
int test_snake_eat_apple(char main_array[][6], char apple_array[][6], int show_snake) {
    
    // Me fijo si la cabeza de la serpiente toco una manzana
    for(int i=0; i<6; i++) {
        for(int u=0; u<6; u++) {
            if(main_array[i][u]!=' '&&apple_array[i][u]!=' '){
                show_snake=3;
                
                // Si la serpiente comio manzana, borro todas las manzanas del codigo
                for(int m=0; m<6; m++) {
                    for(int n=0; n<6; n++) {
                        apple_array[m][n]=' ';
                    }
                }
            }
        }
    }
    return show_snake;
}


int main() {
    srand (time(NULL));
    char main_array[6][6], apple_array[6][6], loadedChar;
    int pos_1, pos_2, score=0, snake_score=0, show_snake=0;
    bool user_input = true;

    printf("BIENVENID@ AL JUEGO DE DE LA SERPIENTE\n\n\n");

    // Pone espacios en ambas arrays
    for (int i=0; i<6; i++)  { 
        for (int u=0; u<6; u++)  {
            main_array[i][u] = ' '; apple_array[i][u] = ' ';
        }
    }
    //Spawnea las manzanas y la serpiente para iniciar el juego
    do_spawn_snake(main_array, apple_array);

    do_spawn_apples(apple_array, main_array);
    print_apples(apple_array);

    // Esta es la pieza de codigo que repite todo el juego hasta que el usuario logra ganar o perder
    do {
        // Este fragmento pide el input del usuario, y solo continua si es correcto. Sino continua preguntando
        do {
            user_input=true;

            printf("Encuentre a la serpiente, indique la fila y la columna, separadas por coma:\n");
            do {
                pos_1 = getchar();
            }while(pos_1=='\n');
            
            //Recoge primer char 
            if(pos_1<'0'||pos_1>'5') {
                user_input=false;
                printf("Entrada inválida, vuelva a intentarlo\n");
            }
            //Si char correcto, recoge segundo
            else {
                pos_2=getchar();

                if(pos_2!=',') {
                    user_input=false;
                    printf("Entrada inválida, vuelva a intentarlo\n");
                }
                //Si char correcto, recoge tercero
                else if(pos_2==','&&user_input==true) {
                    pos_2=getchar();
                    
                    if(pos_2<'0'||pos_2>'5') {
                        user_input=false;
                        printf("Entrada inválida, vuelva a intentarlo\n");
                    }
                    else { // Si char correcto, se fija si el ultimo es un enter
                        loadedChar=getchar();
                        if (loadedChar!='\n'){
                            user_input=false;
                            printf("Entrada inválida, vuelva a intentarlo\n");
                        }
                    }
                }
            }

            // Este parte limpia el codigo de enters si mi char actual no es ya un enter
            if(pos_1!='\n'&&pos_2!='\n'&&loadedChar!='\n') {
                limpiar_buffer();
            }

            // Esto convierte el input del usuario en int, si no era ya un int
            pos_1 = pos_1 - 48;
            pos_2 = pos_2 - 48;

        }while(user_input!=true);

        // Esta pieza de codigo mueve la serpiente 'u' veces
        for(int u=0; u<3; u++) {
            do_snake_movement(main_array);
            
            // For cada loop me fijo si comio una manzana
            // Si come una, pongo show_snake en 3
            show_snake = test_snake_eat_apple(main_array, apple_array, show_snake);
        }
        score = do_score(main_array, pos_1, pos_2, score, show_snake, snake_score);

        if(show_snake>0) { // Si mi show_snake es 3, imprimo a la serpiente por primera vez y me aseguro de eliminar las manzanas
            print_snake(main_array);
            show_snake--;
            // Elimino las manzanas de la array
            for(int i=0; i<6; i++) {
                for(int u=0; u<6;u++) {
                    apple_array[i][u]=' ';
                }
            }
            // Cuando ya no muestro a la serpiente, spawneo las manzanas otra vez
            if (show_snake==0) {
                do_spawn_apples(apple_array, main_array);
            }
        }
        else {
            print_apples(apple_array);
        }
   
    }while(score<3&&snake_score<3);
    if (score==3) {
        printf("Lo lograste, has cazado a la serpiente");
    }
    else {
        printf("La serpiente te ha derrotado, suerte la próxima");
    }
    
       
    return 0;
}