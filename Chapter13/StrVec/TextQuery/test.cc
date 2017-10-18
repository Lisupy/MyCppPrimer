#include "TextQuery.h"
#include "QueryResult.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void runQueries(std::ifstream &infile){
    TextQuery tq(infile);
    while(true){
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;

        if(!(std::cin>>s) || s == "q")
            break;

        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main(){
    string filename;
    cout<<"Please Input the file name: "<<ends;
    cin>>filename;
    ifstream infile(filename, ios::in);
    runQueries(infile);
}
