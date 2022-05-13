//
// Created by Zza on 2022/5/13.
//

#include "Directory_Tree.h"

#include <utility>

Directory_Tree::Directory_Tree() {

}

Directory_Tree::Directory::Directory() {
    this->super = nullptr;
}

Directory_Tree::Directory::Directory(Directory_Tree::Directory* father, std::string name) {
    this->super = father;
    this->dir_name = name;
}
