#include "../includes/stealthFileModel.hpp"

#include <iostream>
#include <openssl/md5.h>
#include <sstream>
#include <string>
#include <vector>

sf2f::StealthFileModel::StealthFileModel():
    path(nullptr),
    base64(nullptr),
    hash(nullptr),
    isDirectory(true),
    children(){};

sf2f::StealthFileModel::StealthFileModel(
    std::string path = "",
    bool isDirectory = true,
    std::string base64 = ""
):path(path), base64(base64), hash(nullptr), children(){
    sf2f::StealthFileModel::generateHash();
};

sf2f::StealthFileModel::~StealthFileModel(){};

void sf2f::StealthFileModel::generateHash(){
    try {
        unsigned char md[MD5_DIGEST_LENGTH];
        std::string mapped = path + base64;
        for(int childId = 0; childId < children.size(); childId++) {
            mapped += children.at(childId)->hash;
        }

        MD5((const unsigned char*)mapped.c_str(), mapped.length(), md);
        std::string tmpHash = "";
        char buf[3];
        for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
            sprintf(buf, "%02x", md[i]);
            tmpHash += buf;
        }
        hash = tmpHash;
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
    }
}

std::string sf2f::StealthFileModel::getPath() {
    return path;
}

std::string sf2f::StealthFileModel::getBase64() {
    return base64;
}

std::string sf2f::StealthFileModel::getHash() {
    return hash;
}

bool sf2f::StealthFileModel::getIsDirectory() {
    return isDirectory;
}

bool sf2f::StealthFileModel::withPath(std::string value) {
    try {
        path = value;
        generateHash();
        return true;
    } catch(const std::exception& e) {
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::StealthFileModel::withBase64(std::string value) {
    try {
        base64 = value;
        generateHash();
        return true;
    } catch(const std::exception& e) {
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::StealthFileModel::withIsDirectory(bool value) {
    try {
        isDirectory = value;
        generateHash();
        return true;
    } catch(const std::exception& e) {
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::StealthFileModel::addChild(sf2f::StealthFileModel* value) {
    try {
        children.push_back(value);
        generateHash();
        return true;
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::StealthFileModel::removeChild(std::string value) {
    try {
        for(auto childId = children.begin(); childId != children.end(); childId++) {
            if((*childId)->getPath() == value){
                delete *childId;
                children.erase(childId);
            }
        }
        return true;
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }

}