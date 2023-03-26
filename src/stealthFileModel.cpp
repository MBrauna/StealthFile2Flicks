#include "../includes/stealthFileModel.hpp"

sf2f::StealthFileModel::StealthFileModel():path(NULL), base64(NULL), hash(NULL), isDirectory(true), children(NULL){
    sf2f::StealthFileModel::generateHash();
};

sf2f::StealthFileModel::StealthFileModel(
    std::string path = NULL,
    bool isDirectory = true,
    std::string base64 = NULL
):path(path), base64(base64), hash(""), children(){
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
        sf2f::StealthFileModel::generateHash();
        return true;
    } catch(const std::exception& e) {
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::StealthFileModel::withBase64(std::string value) {
    try {
        base64 = value;
        sf2f::StealthFileModel::generateHash();
        return true;
    } catch(const std::exception& e) {
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::StealthFileModel::withIsDirectory(bool value) {
    try {
        isDirectory = value;
        sf2f::StealthFileModel::generateHash();
        return true;
    } catch(const std::exception& e) {
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::StealthFileModel::addChild(sf2f::StealthFileModel* value) {
    try {
        children.push_back(value);
        sf2f::StealthFileModel::generateHash();
        return true;
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::StealthFileModel::removeChild(std::string value) {
    try {
        for(int childId = 0; childId < children.size(); childId++){
            if(children.at(childId)->getPath() == value){
                children.erase(children.begin() + childId);
            }
        }
        sf2f::StealthFileModel::generateHash();
        return true;
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }

}