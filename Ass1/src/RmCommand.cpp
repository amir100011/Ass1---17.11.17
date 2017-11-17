//
// Created by amir on 16/11/17.
//

#include <iostream>
#include "../include/Commands.h"
#include <algorithm>

RmCommand::RmCommand(string args) : BaseCommand(args){};


void RmCommand::execute(FileSystem & fs){

    string path = this->getArgs();

    Directory* lastDir = &fs.getWorkingDirectory();

    if (path[0] == '/')
        cout << "can't remove Root directory" << std::endl;
    else
        lastDir = jumpToNewWorkingDirectory(fs,path);
    
    if( lastDir != nullptr)
    {
        string oldName = path.substr(path.find_last_of("/") + 1, path.size() );//last argument of the path + name to change to
        bool found = false;
        BaseFile* X = (*lastDir).getChildren()[0];
        vector<BaseFile*>::iterator it = (*lastDir).getChildren().begin();
        for(int i = 0; X = (*lastDir).getChildren()[i]; i++){
            if(X->getName().compare(oldName) == 0) {
                delete X;
                found = true;
            }
        }
        if(!found)
            cout << "File/Directory not found in specified path" << std::endl;
    }
    //}
}


string RmCommand::toString(){
    return "rm";
}
