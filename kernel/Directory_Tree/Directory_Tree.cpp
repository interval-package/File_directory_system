//
// Created by Zza on 2022/5/13.
//

#include "Directory_Tree.h"
#include <iostream>
#include <utility>

using namespace std;

Directory_Tree::Directory_Tree() {
    this->current = &this->home;
    this->home.dir_name = "home";
}

void Directory_Tree::cd(const std::string& subdir) {
    if(subdir == ".."){
        this->current = this->current->super;
        return;
    }

    if(subdir == "."){
        return;
    }

    for(auto & sub : this->current->subs){
        if(sub->dir_name ==  subdir){
            this->current = sub;
            return;
        }
    }

    cout<<"no such file"<<endl;
}

void Directory_Tree::dir() const {
    cout<<"current directory: "<<this->current->dir_name<<endl;
    cout<<"sub dirs: "<<endl;
    for(auto & item : this->current->subs){
        cout<<item->dir_name<<endl;
    }
    for(auto & file : this->current->files){
        cout<<file.filename<<endl;
    }
}

void Directory_Tree::add_folder(std::string name) const {
    this->current->subs.push_back(new Directory(this->current,std::move(name)));
}

Directory_Tree::Directory::Directory() {
    this->super = nullptr;
}

Directory_Tree::Directory::Directory(Directory_Tree::Directory* father, std::string name) {
    this->super = father;
    this->dir_name = std::move(name);
}
