//
// Created by Zza on 2022/5/13.
//

#ifndef FILE_DIRECTORY_SYSTEM_DIRECTORY_BIN_TREE_H
#define FILE_DIRECTORY_SYSTEM_DIRECTORY_BIN_TREE_H

#include <string>
#include <vector>
#include "../FCB/FCB.h"

class Directory_Bin_Tree {
private:
    typedef class bin_dir{
    public:
        bin_dir();
        ~bin_dir();
        explicit bin_dir(std::string name);
        std::string dir_name;
        std::vector<FCB> files;
        bin_dir* chi, *sib;
    } *bin_dir_p;
    bin_dir home;
public:
    bin_dir_p current;

    Directory_Bin_Tree();

    bool cd(const std::string& subdir);

    bool cd_deep(const std::string& path);

    void dir() const;

    void add_folder(std::string name) const;

    void remove_folder(std::string name) const;

    bool search_folder(const std::string& path);
};


#endif //FILE_DIRECTORY_SYSTEM_DIRECTORY_BIN_TREE_H
