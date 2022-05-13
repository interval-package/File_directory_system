//
// Created by Zza on 2022/5/13.
//

#ifndef FILE_DIRECTORY_SYSTEM_INTERFACE_H
#define FILE_DIRECTORY_SYSTEM_INTERFACE_H

#include <iostream>
#include <vector>
#include "../kernel/Directory_Tree/Directory_Tree.h"
using namespace std;
typedef vector<string> command_pack;


class Interface {
    Directory_Tree index;
public:
    static void refresh(){
        system("cls");
    }

    static void main_show();

    static string arise_command();

    void analyse_command(const command_pack&);

    void cd(string);

    void dir();
};


#endif //FILE_DIRECTORY_SYSTEM_INTERFACE_H
