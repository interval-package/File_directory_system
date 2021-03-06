//
// Created by Zza on 2022/5/13.
//

#ifndef FILE_DIRECTORY_SYSTEM_DIRECTORY_TREE_H
#define FILE_DIRECTORY_SYSTEM_DIRECTORY_TREE_H

#include "../FCB/FCB.h"
#include <vector>
#include <string>

class Directory_Tree {
private:
//    这里没有使用二叉树实现，麻了
    typedef class Directory {
        std::vector<FCB> files;
        Directory* super;
        std::vector<Directory*> subs;
    public:
        Directory();
        Directory(Directory*,std::string);

        friend Directory_Tree;
        std::string dir_name;
    } *Tree_p;
    Directory home;
public:
    Tree_p current;
    Directory_Tree();

    void cd(const std::string& subdir);

    void dir() const;

    void add_folder(std::string name) const;
};


#endif //FILE_DIRECTORY_SYSTEM_DIRECTORY_TREE_H
