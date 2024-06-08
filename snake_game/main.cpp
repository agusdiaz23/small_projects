#include <string>
#include <cstdlib>
#include <time.h> 
//v_0.3
// Snake will be tree cells long, and It will move in the array, taking different paths

// Una funcion que hice para imprimir la array a voluntad, asi no tengo que poner un for loop cada vez
int print_array(char main_array[][6]) { // Summon function at will to print it out
    for (int i=0; i<6; i++)  {
        for (int u=0; u<6; u++)  {
            printf("%c", '|');
            printf("%c", main_array[i][u]);
        }
        printf("|\n");
    }
    printf("________________________\n");
    return 0;
}

// Hace aparecer la serpiente
int do_spawn_snake(char main_array[][6]) {
    int temp_num, pos_1, pos_2, ant_pos_1, ant_pos_2, position_name=0;
    
    pos_1=rand()%6;   
    pos_2=rand()%6;
    main_array[pos_1][pos_2]='0';

    

    //Este while busca posiciones vecinas a mi posicion cargada
    for(int i = 0; i < 2;i++) {
        ant_pos_1=pos_1; // Esta es la posicion original de mi posicion, guardada para recuperarla bajo ciertas condiciones
        ant_pos_2=pos_2;

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
        position_name++;
        main_array[pos_1][pos_2]='0' + position_name;
    }
    
    
    return 0;
}

// Una funcion para tomar un char no repetido de una array 2d, y reeplazarlo por la letra que el usuario elija
int do_replace_number(char main_array[0][6], char replacer_1, char replacer_2) {
    

    for (int i=0; i<6; i++) {
        for(int u=0; u<6; u++) {
            if(main_array[i][u]==replacer_1) {
                main_array[i][u]=replacer_2;
            }
        }
    }

    return 0;
}

// Esta funcion mueve la serpiente un bloque. Se puede invocar varias veces para que la serpiente se mueva una variable indenfinida de bloques
int do_snake_movement(char main_array[][6]) {
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
    main_array[pos_1][pos_2]='A'; // 

    // El numero de celdas de la serpiente, hace el codigo exponencialmente mas dificil, asi que hice un sistema de letras para hacerlo sencillo y escalable
    // Reeplaza los valores en la siguiente posicion de la serpiente
    // Los reeplaza por letras, asi el numero no se multiplica
    // Luego los vuelve a convertir en numeros
    do_replace_number(main_array, '0', 'B');
    do_replace_number(main_array, '1', 'C');
    do_replace_number(main_array, '2', ' ');

    do_replace_number(main_array, 'A', '0');
    do_replace_number(main_array, 'B', '1');
    do_replace_number(main_array, 'C', '2');
    
    return 0;
}


// Main function
int main() {
    srand (time(NULL));
    char main_array[6][6];
    int pos_1, pos_2, movimientos;

    for (int i=0; i<6; i++)  { // Puts empty spaces in array
        for (int u=0; u<6; u++)  {
            main_array[i][u] = ' ';
        }
    }

    //Spawnea las tres celdas originales de la serpiente. Van a estar en una posicion al azar
    do_spawn_snake(main_array);
    print_array(main_array);

    movimientos = 5; // Este loop pone a voluntad del programador la cantidad de movimientos de tres que hara la serpiente
    for (int i=0; i<movimientos; i++) {
        for(int u=0; u<3; u++) {
        do_snake_movement(main_array);
        }
        print_array(main_array);
    }
        
    return 0;

}