// CORSE 5 project 2 secondtry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 
enum engameLEVEL
{
    easy = 1 , medium , hard 
};

enum enmathop
{
    add = 1, substract, multiply , devide , mix 
};

struct allINFO
{
    int playerCORRECTanswer; 

    engameLEVEL gameLEVEL; 
    enmathop mathoperation; 

    int firstRANDOMnumber; 
    int secondRANDOMnumber; 
    int finalRESULT;
    int myanswer;
    int correctRESULT;
    int round; 
    int test;
};

int readnumber(string msg)
{
    int number; 

    cout << msg << endl; 

    cin >> number; 

    return number; 
}

int frandomNUMBER(int from, int to)
{

    int random = rand() % (to - from + 1) + from;

    return random; 

}

engameLEVEL fgamelevel()
{
    int gamelevel = 0; 

    cout << "please enter GAME DIFICULTY level [1] EASY - [2] MEDIUM - [3] HARD : "; cin >> gamelevel; 

    return engameLEVEL(gamelevel);

}

enmathop fmathoperation()
{
    int mathop = 0; 

    cout << "please enter MATH OPERATION type add = 1, substract = 2, multiply = 3, devide = 4, mix = 5 : "; cin >> mathop; 

    return enmathop(mathop);

}

int randomnumberACCORDINGtodifficulty( engameLEVEL difficulty)
{
    switch (difficulty)
    {
    case easy: 
        return frandomNUMBER(1, 10);
        break;
    case medium: 
        return frandomNUMBER(10, 50);
        break;
    case hard: 
        return frandomNUMBER(50, 200);

        break;
    default:
        break;
    }

}
 

enmathop getRANDOMoperationType()
{

    return (enmathop)frandomNUMBER(1, 4);

}



int result(enmathop &mathOP , int &firstRANDOM , int &secondRANDOM)
{  
    
    switch (mathOP)
    {
    case add: 
        return firstRANDOM + secondRANDOM ;
        break;
    case substract: 
        return firstRANDOM - secondRANDOM ;
        break;
    case multiply: 
        return firstRANDOM * secondRANDOM;
        break;
    case devide: 
        return firstRANDOM / secondRANDOM;
        break; 
    default:
        break;
    }




} 

void playerRESULT(allINFO &info)
{
    if (info.correctRESULT == info.myanswer)
    {
        info.playerCORRECTanswer++;  

        system("color 2f");

        cout << "correct answer ! " << endl;
    }

    else 
    {  
        system("color 4f");

        cout << "wrong answer ! correct answer is: " << info.correctRESULT << endl;

     }
}

string characterOFmathOPeration(enmathop mathop)
{
    switch (mathop)
    { case add: 
        return "+";
    case substract: 
        return "-"; 
    case multiply: 
        return "*"; 
    case devide : 
        return "/";
    default:
        break;
    }







} 
 
string wonORlost(allINFO info)
{
    if (info.playerCORRECTanswer > (info.round / 2))
    {
        return "CONGRATS !!! you won this math GAME ";
    }

    else return "HARD LUCK !!! you lost this math GAME ";
}

void finalresultFUNCTION(allINFO info)
{  
    cout << "        GAME OVER        \n" << endl; 

    cout << "        " << wonORlost(info) << endl;

    cout << "        Total rounds: " << info.round << endl;

    cout << "        WON rounds " << info.playerCORRECTanswer << endl;



}

void playround(allINFO &info)
{  
    int round = 0;
    cout << "please enter the number of rounds you want to play: "; cin >>round; 

    info.round = round;
    info.gameLEVEL = fgamelevel(); 
    info.mathoperation = fmathoperation();


    if (info.mathoperation == enmathop::mix)
    {
        info.mathoperation = getRANDOMoperationType();
    }



    for (int i = 0; i < round; i++)
    {  


        info.mathoperation = getRANDOMoperationType();

       
        cout << "  ROUND [" << i + 1 << "] / [" << round << "] " << endl; 



        info.firstRANDOMnumber = randomnumberACCORDINGtodifficulty(info.gameLEVEL);

        cout << info.firstRANDOMnumber << endl;

        info.secondRANDOMnumber = randomnumberACCORDINGtodifficulty(info.gameLEVEL); 

        cout << characterOFmathOPeration(info.mathoperation) << endl;

        cout << info.secondRANDOMnumber << endl;

        cout << "--------" << endl; 

        cin >> info.myanswer; 

        info.correctRESULT = result(info.mathoperation, info.firstRANDOMnumber, info.secondRANDOMnumber);
        

        playerRESULT(info); cout << "\n" << endl;

    } 




}

void game()
{
    int yesNO = 0;

    int round = 0; 

    allINFO info; 
    
    info.test = 0;
    info.playerCORRECTanswer = 0;
    do
    {
        playround(info);
        

        system("COLOR 0F");

        system("cls");


        finalresultFUNCTION(info);

        cout << endl;

        cout << "do you still want to play ! " << endl; 
        cout << "enter [1] for YES [2] for NO: "; cin >> yesNO;





    } while (yesNO == 1);



}




int main()
{
    srand((unsigned)time(NULL));

    
    game();



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
