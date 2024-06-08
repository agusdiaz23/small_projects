#include <string>
#include <cstdlib>
#include <time.h> 
//v_0.2
// Snake will be two cells long, and It will move in the array, taking different paths

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


int do_snake_movement(char main_array[][6]) {
    int temp_num, pos_1, pos_2, ant_pos_1, ant_pos_2;

    // Busco la cabeza de la serpiente
    for (int i=0; i<6; i++)  {
        for (int u=0; u<6; u++)  {
            if(main_array[i][u]=='0') {
                pos_1=i;
                pos_2=u;
            }
        }
    }
    // Dejo guardada la posicion de la cabeza
    ant_pos_1 = pos_1;
    ant_pos_2 = pos_2;


    //This while will look for empty cells. Once it finds one, It will put the symbol on it.
    while(main_array[pos_1][pos_2] != ' ' ) { 
        temp_num=rand()%2;
        if (temp_num==0) { 
            // If snake's head in the column cero or 5, move it to the right or to the left. If not in 0, do the same, but to any neighboring cell
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
        // In this case, It will move in between rows under that rules commented at the if
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
    main_array[pos_1][pos_2]='0'; // Pongo la cabeza en la nueva posicion

    for (int i=0; i<6; i++)  { // Busco la cola de la serpiente, para eliminarla antes de moverla, así no se repite
        for (int u=0; u<6; u++)  {
            if(main_array[i][u]=='1') {
                main_array[i][u]=' ';
            }

        }
    }

    main_array[ant_pos_1][ant_pos_2]='1';
    
    return 0;
}


// Main function
int main() {
    srand (time(NULL));
    char main_array[6][6];
    int pos_1, pos_2;

    for (int i=0; i<6; i++)  { // Puts empty spaces in array
        for (int u=0; u<6; u++)  {
            main_array[i][u] = ' ';
        }
    }

    // Defines started position for the snake's head
    pos_1=rand()%6;   
    pos_2=rand()%6;
    main_array[pos_1][pos_2]='0';

    //Moves snake two blocks
    for (int u=0;u<4;u++) {
        for(int i=0; i<2;i++) {
            do_snake_movement(main_array);
        }
        print_array(main_array);
    }


    // Ahora tengo la serpiente en posicion.
    
        


}