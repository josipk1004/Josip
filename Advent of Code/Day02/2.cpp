#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream is;
    is.open("data.txt");

    string keyWord;
    long depth, horizontal, data, aim;
    depth = aim = horizontal = 0;
    
    is >> keyWord;
    while(keyWord != "stop"){
        is >> data;
        if(keyWord == "up") aim -= data;
        else if(keyWord == "down") aim += data;
        else if(keyWord == "forward") {
            horizontal += data;
            depth += aim * data;
        }
        
        is >> keyWord;
    }
    
    cout << depth * horizontal;
}