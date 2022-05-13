//
// Created by Zza on 2022/5/13.
//

#include "Directory_Bin_Tree.h"
#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

Directory_Bin_Tree::Directory_Bin_Tree() {
    this->home.dir_name = "home";
    this->current = &this->home;
}

bool Directory_Bin_Tree::cd(const std::string &subdir) {
    bin_dir_p temp;
    temp = this->current->chi;
    while(temp){
        if(temp->dir_name == subdir){
            this->current = temp;
            return true;
        };
        temp = temp->sib;
    }
    return false;
}

void Directory_Bin_Tree::dir() const {
    bin_dir_p temp;
    cout<<"cur dir:"<<this->current->dir_name<<endl<<"subs:"<<endl;
    temp = this->current->chi;
    while(temp){
        cout<<temp->dir_name<<endl;
        temp = temp->sib;
    }
}

void Directory_Bin_Tree::add_folder(std::string name) const {
    bin_dir_p temp;
    temp = this->current->chi;
    if(!temp){
        this->current->chi = new bin_dir(std::move(name));
        return;
    }
    while(temp->sib){
        temp = temp->sib;
    }
    temp->sib = new bin_dir(std::move(name));
    return;
}

void Directory_Bin_Tree::remove_folder(std::string name) const {
    bin_dir_p temp, del;
    temp = this->current->chi;
    if(temp->dir_name == name){
        this->current->chi = temp->sib;
        temp->sib = nullptr;
        delete temp;
        return;
    };
    while(temp->sib){
        if(temp->sib->dir_name == name){
            del = temp->sib;
            temp->sib = temp->sib->sib;
            del->sib = nullptr;
            delete del;
            return;
        };
        temp = temp->sib;
    }
    cout<<"no such file"<<endl;
}

bool Directory_Bin_Tree::search_folder(const std::string& path) {
    istringstream instr(path);
    string token;
    bin_dir_p cache_cur = current;
    while (getline(instr,token,'/')){
        if(!this->cd(token)){
            current = cache_cur;
            return false;
        }
    }
    current = cache_cur;
    return true;
}

bool Directory_Bin_Tree::cd_deep(const string &path) {
    if(!search_folder(path))return false;
    istringstream instr(path);
    string token;
    while (getline(instr,token,'/')){
        this->cd(token);
    }
    return true;
}

Directory_Bin_Tree::bin_dir::bin_dir() {
    this->chi = nullptr;
    this->sib = nullptr;
}

Directory_Bin_Tree::bin_dir::bin_dir(std::string name) {
    this->chi = nullptr;
    this->sib = nullptr;
    this->dir_name = std::move(name);
}

Directory_Bin_Tree::bin_dir::~bin_dir() {
    delete chi;
    delete sib;
}
