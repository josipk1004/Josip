#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<iterator>

//result 4495

using namespace std;

int main(){
    ifstream is;
    is.open("data.txt");

    string line;
    getline(is, line);
    
    stringstream ss;
    ss << line;

    vector<int*> bingo;
    while(! is.eof()){
        int* matrix = new int[36];
        for(int i = 0; i < 5; ++i)
            matrix[i * 6 + 5] = 0;
        for(int j = 0; j < 5; ++j)
            matrix[5 * 6 + j] = 0;
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5; ++j){
                is >> matrix[i * 6 + j];
                matrix[5*6 + j] += matrix[i * 6 + j];
                matrix[i * 6 + 5] += matrix[i * 6 + j];
            }
        }

        bingo.push_back(matrix);
    }

    int result = 0;
    bool end = false, erased = false;
    int n; char c;
    while(! ss.eof()){
        ss >> n;
        ss >> c;
        for(vector<int*>::iterator it = bingo.begin(); it != bingo.end();){
            bool found = false;
            erased = false;
            for(int k = 0; k < 5; ++k){
                for(int l = 0; l < 5; ++l){
                    if(n == (*it)[k * 6 + l]){
                        found = true;
                        (*it)[k * 6 + l] = -1;
                        (*it)[k * 6 + 5] -= n + 1;
                        (*it)[5 * 6 + l] -= n + 1;
                        if((*it)[k * 6 + 5] == -5 || (*it)[6 * 5 + l] == -5){
                            if(bingo.size() == 1){
                                end = true;
                                for(int m = 0; m < 5; ++m){
                                for(int o = 0; o < 5; ++o){
                                    if((*it)[m * 6 + o] > 0)
                                        result += (*it)[m * 6 + o];
                                }
                            }
                            result *= n;
                            } else {
                                bingo.erase(it);
                                erased = true;
                            }
                        }
                        break;
                    }
                }
                if(found) break;
            }
            if(!erased) ++it;
            if(end) break;
        }
        if (end) break;
    }

    std::cout << result;
}