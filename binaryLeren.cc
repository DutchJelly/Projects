#include <iostream>
#include <cstdlib>
#include <ctime>

void printInfo(){
    std::cout << "This program is made to teach you how to read binary digits.\n"
    << "Author: Jelle Keulemans \n";
}
void printBits(bool* bits, int length){
    for(int i = 0; i < length; i++){
        if(bits[i]){
            std::cout << "1";
        } else{
            std::cout << "0";
        }
    }
    std::cout << std::endl;
}

bool* convertToBinary(int decimal, bool bits[], int bitLength){
    for(int i = bitLength-1; i >= 0; i--){
        if(decimal != 0){
            if(decimal%2 == 0){
                bits[i] = false;
            } else{
                bits[i] = true;
                decimal -= 1;
            }
            decimal = decimal/2;
        } else{
            bits[i] = false;
        }
    }
    return bits;
}

int main(){
    printInfo();
    srand(time(NULL));

    bool bits[8];
    bool* bitsPointer = bits;

    int randomlyGenerated;
    int givenAnswer;
    int repeat;

    std::cout << "How many do you think you can solve without making an error?\n";
    std::cin >> repeat;

    for(int i = 0; i < repeat; i++){
        randomlyGenerated = rand()%256+1;
        bitsPointer = convertToBinary(randomlyGenerated,bitsPointer, 8);
        std::cout << "What is the decimal notation of the following binary number?\n";
        printBits(bitsPointer, 8);
        std::cin >> givenAnswer;
        if(givenAnswer != randomlyGenerated){
            std::cout << "The answer should've been " << randomlyGenerated << ". You're starting over!\n";
            i = 0;
        }else{
            std::cout << "That answer was correct! You only have to answer " << (repeat-i) << " more!\n";
        }
    }
    std::cout << "\nCongratulations! You reached the end.\n";
}
