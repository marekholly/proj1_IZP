/*
Marek Holly (xholly01)
Project 1 - prace s textem
splnene aj premiove zadanie
*/


#include<stdio.h>
#include<stdlib.h>

/*
Template of represented characters, (BEAUTIFIED for better readability)
contains all characters represented by a digit on the same index(e. g. for digit 4 -> template[4] contains 4, g, h, i)
*/
char const template[10][6] = {{'0', '+'},           {'1'},
                              {'2', 'a', 'b', 'c'}, {'3', 'd', 'e', 'f'},
                              {'4', 'g', 'h', 'i'}, {'5', 'j', 'k', 'l'},
                              {'6', 'm', 'n', 'o'}, {'7', 'p', 'q', 'r', 's'},
                              {'8', 't', 'u', 'v'}, {'9', 'w', 'x', 'y', 'z'}};

/*
Function returns decapitalized character
*/
char decapitalize(char c){
    if(c >= 'A' && c <= 'Z') c += ('a' - 'A'); //due to ASCII
    return c;
}

/*
Function returns integer from char (0-9)
*/
int char_to_int(char c){
    if(c >= '0' && c <= '9') {
        c -= '0'; //due to ASCII
        return c;
    } else return -1;
}

/*
Returns 1 if tested character was found in template on given index
*/
int check_char(char tested, char given_char){

    int template_index = char_to_int(given_char); //index of wanted character in template
    if(template_index == -1){  //given_char wasnt a number (dialpad only contains numbers)
        fprintf(stderr, "Argument can only contain numbers 0-9\n Program stopped\n");
        exit(1);
    }

    int current_index = 0;   //index of currently represented symbol
    tested = decapitalize(tested);  
    
    //iterate through template
    while (template[template_index][current_index] != 0){

        if((template[template_index][current_index]) == tested) {
            return 1; //tested character was found in template
        } else {
            current_index++; //jumps onto next item
        }
    }
    
    return 0; //tested character was not found

}

/* 
FUNCTION FOR LOADING INPUT
loads string from stdin into array
if EOF is found, returns EOF otherwise returns 1
*/
int load_data(char *string){
    int c;
    int length = 0;
    
    while ((c = getchar()) != EOF && c != '\n'){
        if(length < 100){
            string[length] = c;
            length++;
        } else {
            fprintf(stderr, "The input name exceeded maximum character limit(100)\nProgram stopped\n");
            exit (1);
        };
    }

    string[length] = 0; //end of string

    if(c == EOF) return EOF;
    else return 1;

}

/*
Returns 1 if given string contained all represented symbols from given argv[1]
otherwise returns 0
*/
int check_string(char *string, char *wanted){

    int wanted_index = 0; //index of currently tested character from argv[1]
    int check_index = 0; //index of element from string, which will be checked

    while (wanted[wanted_index] != 0){

        while (string[check_index] != 0){

            if( check_char(string[check_index], wanted[wanted_index]) ){
                //currently checked char represented wanted symbol(from argv[1])
                wanted_index++;
                check_index++;
                break;
            } 
            else {
                check_index++;
            }
        }

        if(string[check_index] == 0) break; //string doesnt contain wanted sequence

    }

    if(wanted[wanted_index] == 0) { //wanted sequence reached its end
        return 1;
    }
    else return 0; //wanted sequence didnt reach its end, not all symbols were present in string
}


int main(int argc, char *argv[])
{
    int found_count = 0;

    char name[101];
    char number[101];

    while ((load_data(name) != EOF) && (load_data(number) != EOF)){

        if(argc < 2){  //if there was no argument, skip the checking procces
            printf("%s, %s\n", name, number);
            found_count++;
        } 
        
        else {  //if there was an argument
            if(check_string(name, argv[1])){
                printf("%s, %s\n", name, number);
                found_count++; //name contained argv[1]
            }
            else if(check_string(number, argv[1])){
                printf("%s, %s\n", name, number);
                found_count++; //number contained argv[1]
            }
        }
    }

    if(found_count == 0) { //if no contact matched
        fprintf(stderr, "Not found\n");
        return 1;
    }
    else return 0;
}
