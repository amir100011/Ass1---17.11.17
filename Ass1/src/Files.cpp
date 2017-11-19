/*
 * Files.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: amir
 */

#include "../include/Files.h"

using namespace std;

File::File(std::string name, int size): BaseFile(name) , size(size){}


int File::getSize(){
	return size;
}

bool File::isDirectory(BaseFile *file) {
	return false;
}
File::File(const File& other) :BaseFile(other.getName()) , size(other.size){}//copy constructor

//TODO -implement
File& File:: operator=(const File& other) {//copy assignment operator
	if(this == & other)
		return *this;
	else{
		this->setName(other.getName());
		this->size = (other.size);
	}
}
 File::File(File&& other):BaseFile(other.getName()){
	 
 }//move constructor
File& File:: operator=(File&& other){}//move operator