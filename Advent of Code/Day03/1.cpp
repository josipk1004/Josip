#include<iostream>
#include<fstream>
#include<string>
#include<math.h>

using namespace std;

int main(){
    ifstream is;
    is.open("data.txt");

    string input;
    int n = 0;
    int field[12] = {0};
    is >> input;

    while(! is.eof()){
        for(int i = 0; i < 12; ++i){
            if(input.at(i) == '1')
                field[i]++;
        }
        ++n;
        is >> input;
    }

    long gama, epsilon;
    gama = epsilon = 0;

    for(int i = 0; i < 12; ++i){
        if(field[i] >= ((n + 1) / 2)){
            gama += pow(2, 11 - i);
        } else {
            epsilon += pow(2, 11 - i);
        }
    }

    cout << epsilon * gama;

}