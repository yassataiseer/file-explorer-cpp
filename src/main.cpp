#include <iostream>
#include <map>
#include <string>

#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <iterator> 
#include <iomanip>	
#include <filesystem>
#include "utils.h"
#include <chrono>
#include <ctime>   

using namespace std;
using namespace std::filesystem; 
using namespace std::chrono;
/*
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m";
const string BLACK = "\033[30m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
*/



void print_directory(path directorypath, bool more_info) {
    set_color(MAGENTA);

    if (exists(directorypath) && is_directory(directorypath)) {
        cout << "---- Listing directory: " << directorypath << " ----" << endl;
        cout << "---------------------------------------------" << endl;

        for (const auto& entry : directory_iterator(directorypath)) {
            string type = is_directory(entry.path()) ? "[Directory]" : "[File]";
            string name = entry.path().filename().string();

            cout << left << setw(40) << name;

            if (more_info) {
                if (!is_directory(entry.path())) {
                    auto size = file_size(entry.path());
                    //auto ftime = last_write_time(entry.path());
                    auto sctp = -1;

                    cout << setw(15) << size << " bytes"
                         << setw(25) << sctp
                         << type << endl;
                } else {
                    cout << setw(15) << "---" << setw(25) << "---"<< type << endl;
                }
            } else {
                cout << type << endl;
            }
        }
    } else {
        cerr << "Directory not found." << endl;
    }

    reset_color();
}


void change_path(path *directorypath){
    set_color(CYAN);
    cout<<"Your current path is: "<<RED<<*directorypath<<endl;
    set_color(MAGENTA);
    cout<<"new path: ";
    path newPath;
    cin>>newPath;
    *directorypath = newPath;
}


int main(){
    


        // Define the directory path to list files from 
    path directorypath = "/usr/local"; 
    reset_color();
    cout<<"Welcome to File Explorer C++"<<endl;
    cout<<"Type 'help' for a list of functions you can use"<<endl;
    
    while (true){
        reset_color();
        cout<<"current path: "<<directorypath<<endl;
        
        string input;
        //cin>>input;
        getline(cin,input);
        if(input.find("print_dir") == 0){
            bool moreInfo = false;
            if (input.find("-info") != std::string::npos) {
                moreInfo = true;
            }
        
            print_directory(directorypath,moreInfo);
        }
        
        if(input=="break"){
            break;
        }

        if(input.find("change_path") == 0){
            change_path(&directorypath);

        } 


    }
    cout<<WHITE;
    return 0;
}


