#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream is;
    is.open("data.txt");

    unsigned long long nums[9] = {0};
    unsigned long long data;
    char help;

    is >> data;
    nums[data] += 1;
    while(! is.eof()){
        is >> help;
        is >> data;
        nums[data] += 1;
    }


    for(int i = 0; i < 256; ++i){
        data = nums[0];
        for(int j = 1; j < 7; ++j){
            nums[j - 1] = nums[j];
        }
        nums[6] = data + nums[7];
        nums[7] = nums[8];
        nums[8] = data;
    }

    data = 0;
    for(int i = 0; i < 9; ++i)
        data += nums[i];

    cout << data;

}