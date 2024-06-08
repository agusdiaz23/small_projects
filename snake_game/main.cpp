#include <string>
#include <cstdlib>
#include <time.h> 
//v_0.1
// Generates array of 6x6 with  blank spaces in each slot
// Makes function for printing out array, for doing so at will
// Moves 0 (snake's head) troughout the array. Leaves trace behind

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

int defines_head_position(char main_array[][6]) {
    int temp_num, pos1, pos2, ant_pos1, ant_pos2;

    // Looks for snake's head position. It's necessary of the logic of the function
    for (int i=0; i<6; i++)  {
        for (int u=0; u<6; u++)  {
            if(main_array[i][u]=='0') {
                pos1=i;
                pos2=u;
            }
        }
    }

    // If my random number is 0, then It'll move between columns, by changing only one of the coords.
    ant_pos1=pos1;
    ant_pos2=pos2;
    while(main_array[pos1][pos2] != ' ' ) { 
        //This while, will look for empty cells. Once it finds one, It will put the symbol on it.
        temp_num=rand()%2;
        if (temp_num==0) { 
            temp_num=rand()%2;
            // If snake's head in the column cero or 5, move it to the right or to the left. If not in 0, do the same, but to any neighboring cell
            if(pos1==0)
                pos1++;
            else if(pos1==5)
                pos1--;
            else {
                temp_num=rand()%2;
                if(temp_num==0)
                    pos1++;
                else
                    pos1--;
            }
        }
        // In this case, It will move in between rows under that rules commented at the if
        else {
            temp_num=rand()%2;
            if(pos2==0)
                pos2++;
            else if(pos2==5)
                pos2--;
            else {
                temp_num=rand()%2;
                if(temp_num==0)
                    pos2++;
                else   
                    pos2--;
            }
        }
    }

    // Where the head was, It puts a tail in instead
    main_array[ant_pos1][ant_pos2] = '#';

    main_array[pos1][pos2]='0';

    return 0;
}


// Main function
int main() {
    srand (time(NULL));
    char main_array[6][6];
    int pos1, pos2;

    for (int i=0; i<6; i++)  { // Puts empty spaces in array
        for (int u=0; u<6; u++)  {
            main_array[i][u] = ' ';
        }
    }

    // Defines started position for the snake's head
    pos1=rand()%6;   
    pos2=rand()%6;
    main_array[pos1][pos2]='0';
    print_array(main_array);

    int count = 0;
    while(count < 5) {
        defines_head_position(main_array);
        print_array(main_array);
        count++;
    }

}