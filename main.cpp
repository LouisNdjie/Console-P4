#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

void drawgrille(int grille[7][6]);
bool playTurn(int grille[7][6], int column, int player);
int score(int grille[7][6]);

int main(int argc, char** argv){

    bool running = true;
    int grille[7][6] = {};
    std::string choix;

    int player = 1;
        int win = 0;
        int option = 0;
        bool play = true;
        int ia = 0;


    while (running){
        
        //Définition des modes de jeu 
        std::cout << "|----------------------------------mode de jeu----------------------------------|\n";
        std::cout << "|                        [1] - player 1 VS player 2                             |\n";
        std::cout << "|                        [2] - player 1 VS IA                                   |\n";
        std::cout << "|                        [3] - exit                                             |\n";
        std::cout << "|-------------------------------------------------------------------------------|\n";
        std::cout << " Choisissez une option : ";
        std::cin >>option;

        //Initialisation des modes de jeu
        switch(option)
        {
            case 1 :
                system("cls");
                drawgrille(grille);
            while (play)
            {
                
                std::cout << "player_" << player << " -> col :";
                std::cin >> choix;
                
                if(choix[0] == '0')
                {
                    choix[0] = '1';
                }

                if (choix == "exit"){
                    break;
                }

                bool success = false;

                if (choix.size() == 1){
                    if (choix[0] >= '0' && choix[0] <= '7'){
                        int col = choix[0]  - '0';

                        success = playTurn(grille, col, player);
                    }
                }


                if (!success){
                    std::cout << "votre choix est incorrect\n";
                } else{
                    if (player == 1) player = 2;
                    else player = 1;
                }

                drawgrille(grille);

                win = score(grille);

                if (win == 1)
                {
                    std::cout<<"le player 1 a gagne \n";
                    play = false;
                    running = false;

                }else if (win == 2)
                {
                    std::cout<<"le player 2 a gagne\n";
                    play = false;
                    running = false;
                }
        
            }
            
            break;

            case 2 :
                system("cls");
                drawgrille(grille);
            while(play)
            {
                std::cout << "player_" << player << " -> col :";
                std::cin >> choix;
                
                if(choix[0] == '0')
                {
                    choix[0] = '1';
                }

                if (choix == "exit")
                {
                    break;
                }

                bool success = false;

                if (choix.size() == 1)
                {
                    if (choix[0] >= '0' && choix[0] <= '7')
                    {
                        int col = choix[0]  - '0';

                        success = playTurn(grille, col, player);
                    }
                }


                if (!success)
                {
                    std::cout << "votre choix est incorrect\n";

                } else
                {
                    if (player == 1) player = 2;
                }

                if(player == 2)
                {
                    srand(time(NULL));
                    ia = rand() % 7;

                    if(ia == 0)
                    {
                        ia = 1;
                    }

                    success = playTurn(grille, ia, player);
                }

                if (!success)
                {

                    std::cout << "votre choix est incorrect\n";

                } else
                {
                    if (player == 2) player = 1;
                }

                drawgrille(grille);

                win = score(grille);

                if (win == 1)
                {
                    std::cout<<"le player 1 a gagne \n";
                    play = false;
                    running = false;

                }else if (win == 2)
                {
                    std::cout<<"L' IA a gagne\n";
                    play = false;
                    running = false;
                }
            }
            break;

            case 3 :
            running = false;
            break;
        }

    }
    return 0;
}


// 0, 1, 2
void drawgrille(int grille[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        std::cout << "|";
        for (int col = 0; col < 7; col++){
            if (grille[col][ligne] == 1){
                std::cout << "\033[31m*\033[37m";
            } else 
            if (grille[col][ligne] == 2){
                std::cout << "\033[32m*\033[37m";
            }
            else {
                std::cout << "\033[37m*\033[37m";
            }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool playTurn(int grille[7][6], int column, int player){
    for (int line = 5 ; line >= 0; line--){
        if (grille[column - 1][line] == 0){
            grille[column - 1][line] = player;
            return true;
        }
    }
    return false;
}

int score(int grille[7][6]){
    
    int win;

    for(int col = 0; col < 7; col++){
        for(int line = 0; line < 6; line++){
            if((grille[col][line] == 1 && grille[col][line+1] == 1 && grille[col][line+2] == 1 && grille[col][line+3] == 1) || (grille[col][line] == 1 && grille[col+1][line] == 1 && grille[col+2][line] == 1 && grille[col+3][line] == 1) || (grille[col][line] == 1 && grille[col+1][line+1] == 1 && grille[col+2][line+2] == 1 && grille[col+3][line+3] == 1) || (grille[col][line] == 1 && grille[col+1][line-1] == 1 && grille[col+2][line-2] == 1 && grille[col+3][line-3] == 1)){
               win = 1;
            }

            if((grille[col][line] == 2 && grille[col][line+1] == 2 && grille[col][line+2] == 2 && grille[col][line+3] == 2) || (grille[col][line] == 2 && grille[col+1][line] == 2 && grille[col+2][line] == 2 && grille[col+3][line] == 2) || (grille[col][line] == 2 && grille[col+1][line+1] == 2 && grille[col+2][line+2] == 2 && grille[col+3][line+3] == 2) || (grille[col][line] == 2 && grille[col+1][line-1] == 2 && grille[col+2][line-2] == 2 && grille[col+3][line-3] == 2)){
                win = 2;
            }
        }
    }
    return win;
}