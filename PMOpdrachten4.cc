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
//opdracht 14
char toUpperCase(char c){
    int asciiIndex = (int)c;
    if(asciiIndex >= 97 && asciiIndex <= 122)
        return (char)(asciiIndex - 32);
    return c;
}
//opdracht 15
char returnFirstAlphabetically(char c1, char c2){
    return (int)c1 < (int)c2 ? c1 : c2;
}
//opdracht 16
void swapParameters(int & p1, int & p2){
    int p1Copy = p1;
    p1 = p2;
    p2 = p1Copy;
}
//opdracht 17
void printMultiplicates(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << i*j << "  ";
        }
        cout << endl;
    }
}
//Opdracht 18
void printCallAmount(){
    static int amount = 0;
    amount++;
    cout << "I've been called " << amount << " times!" << endl;
}
//Opdracht 19
void followFormla(int startWith, int continueFor, bool printBetweenValues){
    //using formula f(x) = 3x+1
    if(printBetweenValues){
        for(int i = 0; i < continueFor; i++){
            cout << (3*(i+startWith) + 1) << endl;
        }
    }
    cout << (3*(continueFor+startWith) + 1) << endl;
}
//Only used to test functions.
int main(){
    int input;
    cout << "Enter number: ";
    cin >> input;
    cout << endl;
    printMultiplicates(input);

    return 1;
}
