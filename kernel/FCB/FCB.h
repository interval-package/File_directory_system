//
// Created by Zza on 2022/5/13.
//

#ifndef FILE_DIRECTORY_SYSTEM_FCB_H
#define FILE_DIRECTORY_SYSTEM_FCB_H

#include "../Indexing_Node/Indexing_Node.h"
#include <string>

class FCB {
public:
    std::string filename;
    int info;
    Indexing_Node data;
};


#endif //FILE_DIRECTORY_SYSTEM_FCB_H
