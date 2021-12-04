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
        if(keyWord == "up") depth -= data;
        else if(keyWord == "down") depth += data;
        else if(keyWord == "forward") horizontal += data;
        
        is >> keyWord;
    }
    
    cout << depth * horizontal;
}