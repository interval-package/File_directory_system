//
// Created by Zza on 2022/5/13.
//

#include "Interface.h"
#include <string>
#include <vector>



void Interface::main_show() {
    cout<<"commands:\n"
          "cd [directory name]:\t\n"
          "dir:\tshow the indent of cur directory\n"
          "\n"
          "\n"
          "\n"<<endl;
}

string Interface::arise_command() {
    string command;
    command_pack req;
    cout<<"input: ";
    while(cin>>command){
        req.push_back(command);
    }
    return command;
}

void Interface::analyse_command(const command_pack& req) {
    string com = req.front();
    if(com == "cd"){
        if(req.empty()){
            cout<<"do not get dir"<<endl;
        } else{
            this->cd(req.front());
        }
        return;
    }else if (com == "dir"){
        dir();
    } else{
        cout<<"error command"<<endl;
    }
}
