#include<iostream>
#include<fstream>
#include<string>
#include<iterator>
#include<list>
#include<cmath>

using namespace std;

int main(){
    ifstream is;
    is.open("data.txt");

    list<string> dataList1, dataList2;
    string data;
    is >> data;

    while(! is.eof()){
        dataList1.push_back(data);
        dataList2.push_back(data);
        is >> data;
    }

    int nO, nC;
    char removeOx, removeCo;
    bool endO, endC;
    endO = endC = false;
    for(int i = 0; i < 12; ++i){
        nO = nC = 0;
        list<string>::iterator it;
        if(!endO){
            for(it = dataList1.begin(); it != dataList1.end(); ++it){
                if((*it).at(i) == '1')
                    ++nO;
            }

            if(nO >= ((dataList1.size() + 1) / 2)){
                removeOx = '0';
            } else{
                removeOx = '1';
            }

            for(it = dataList1.begin(); it != dataList1.end();){
                data = *it;
                if(data.at(i) == removeOx){
                dataList1.erase(it++);
                if(dataList1.size() == 1){
                    endO = true;
                    break;
                }
            } else {
                ++it;
            }
        }
        }

        if(!endC){
        for(it = dataList2.begin(); it != dataList2.end(); ++it){
            if((*it).at(i) == '1')
                ++nC;
        }

        if(nC >= ((dataList2.size() + 1) / 2)){
            removeCo = '1';
        }
        else{
            removeCo = '0';
        }
        
        for(it = dataList2.begin(); it != dataList2.end();){
            data = *it;
            if(data.at(i) == removeCo){
                if(dataList2.size() == 1){
                    endC = true;
                    break;
                }
                dataList2.erase(it++);
            } else {
                ++it;
            }
        }
        }

        if(endO && endC)
            break;
    }

    string o = dataList1.front();
    string c = dataList2.front();
    int oN, cN;
    oN = cN = 0;
    for(int i = 0; i < 12; ++i){
        oN += pow(2, 11 - i) * (o.at(i) - '0');
        cN += pow(2,11 - i ) * (c.at(i) - '0');
    }

    cout << oN * cN;

}