//
// Created by Zza on 2022/5/13.
//

#include "Interface.h"
#include <string>
#include <vector>
#include <sstream>



void Interface::main_show() {
    cout<<"commands:\n"
          "cd [directory name]: change current dir\n"
          "dir: show the indent of cur dir\n"
          "mkdir [name]: make dir\n"
          "rmdir [name]: remove dir\n"
          "ser [Relative path]: check folder\n"
          "q: to quit\n";
}

command_pack Interface::arise_command() {
    std::istringstream foo;
    string command, com;
    command_pack req;
    cout<<"input:";
    getline(cin,command);
    foo.str(command);
    while (foo>>com){
        req.push_back(com);
    };
    return req;
}

void Interface::analyse_command(const command_pack& req) {
    auto com = req.begin();
    if(*com == "cd"){
        ++com;
        if(com == req.end()){
            cout<<"do not get dir"<<endl;
        } else{
            this->index.cd(*com);
        }
    }else if (*com == "dir"){
        ++com;
        this->index.dir();
    }else if (*com == "mkdir"){
        ++com;
        if(com == req.end()){
            cout<<"do not get dir name"<<endl;
        } else{
            this->index.add_folder(*com);
        }
    } else{
        cout<<"error command"<<endl;
    }
}

void Interface::main() {
    command_pack req;
    this->main_show();
    while (true){
        req = this->arise_command();
        if(req[0] == "q")break;
        this->analyse_command(req);
    }
}
