//
// Created by amir on 15/11/17.
//

#include <iostream>
#include "../include/Commands.h"
#include <algorithm>



RenameCommand::RenameCommand(string args) : BaseCommand(args){};

void RenameCommand::execute(FileSystem & fs) {

    string Command = this->getArgs();
    int length = Command.size();
    std::size_t pathIndex = Command.find(" ");//return index of the letter after " " in command
    string newName = Command.substr(pathIndex + 1, length);//from start of path to the end of string
    pathIndex = Command.find(" ");
    string path = Command.substr(0, pathIndex); //the path

    Directory* lastDir = jumpToNewWorkingDirectory(fs,path);
    
          if( lastDir != nullptr)
          {
            string oldName = path.substr(path.find_last_of("/") + 1, path.size() );//last argument of the path + name to change to
            bool found = false;
              BaseFile* X = (*lastDir).getChildren()[0];
              vector<BaseFile*>::iterator it = (*lastDir).getChildren().begin();
            for(int i = 0; X = (*lastDir).getChildren()[i]; i++){
                if(X->getName().compare(oldName) == 0) {
                    X->setName(newName);
                    found = true;
                }
            }
            if(!found)
                cout << "File/Directory not found in specified path" << std::endl;
        }
   // }
}
string RenameCommand::toString(){
    return "rename";
}


