#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

//Opdracht 1
int telop(int x, int y){
    return x + y;
}
//Opdracht 2
void voidTelop(int x, int y, int & z){
    z = x + y;
}
//Opdracht 3
void telBreukOp(int teller1, int noemer1, int teller2, int noemer2, int & ateller, int & anoemer){
    ateller = (noemer2 * teller1) + (noemer1 * teller2);
    anoemer = noemer1 * noemer2;
}
//Opdracht 4
double macht(double nummer, int macht){
    double returnValue = 1;
    for(;macht > 0; macht--){
        returnValue *= nummer;
    }
    return returnValue;
}
//Opdracht 5
int splitInRegels(int nummer){
    int resultaat;
    while(nummer != 0){
        int rest = nummer % 10;
        resultaat += rest;
        nummer -= rest;
        nummer /= 10;
        cout << rest << endl;
    }
    return resultaat;
}
//Opdracht 10
int addDigitOnRight(int number, int add){
    return (number * 10) + add;
}
//Opdracht 11
void verwerkGetal(int & currentNumber, bool & digitFound){
    cout << "Squared encountered number: " << macht(currentNumber,2) << endl;
    currentNumber = 0;
    digitFound = false;
}

//Opdracht 6+7+8+9+10
void copieerBestand(){
    int charCount = 0;
    int lineFeed = 0;
    //Wijzig path zo nodig.
    ifstream input;
    input.open("/home/jellekeul/git-repositories/Projects/invoer.txt");
    ofstream output;
    output.open("/home/jellekeul/git-repositories/Projects/uitvoer.txt");
    char c = input.get();
    int currentNumber = 0;
    bool digitFound = false;
    while(!input.eof()){
        if(isdigit(c)){
            if(!digitFound) digitFound = true;
            currentNumber = addDigitOnRight(currentNumber, (int)c - 48);
        } else if(digitFound){
            verwerkGetal(currentNumber, digitFound);
        }
        if(c == '\n') lineFeed++;
        else charCount ++;
        output.put(c);
        c = input.get();
    }
    cout << "Characters: " << charCount << "\nLinefeed: " << lineFeed << "\nFile copy succeeded!" << endl;
}
int main(){
    copieerBestand();
    return 1;
}
