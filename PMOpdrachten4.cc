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
    nummer = 0;
    for(; macht > 0; macht--){
        nummer *= nummer;
    }
    return nummer;
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
//Opdracht 6+7+8
void copieerBestand(){
    int charCount = 0;
    int lineFeed = 0;
    ifstream input;
    input.open("/home/jellekeul/Projects/invoer.txt");
    ofstream output;
    output.open("/home/jellekeul/Projects/uitvoer.txt");
    char c = input.get();
    while(!input.eof()){
        if(isdigit(c)) cout << c << endl;
        if(c == '\n') lineFeed++;
        else charCount ++;
        output.put(c);
        c = input.get();
    }
    cout << "Characters: " << charCount << "\n" << "File copy succeeded!" << endl;
}
int main(){
    copieerBestand();
    return 1;
}
