#include "../includes/projectModel.hpp"

sf2f::ProjectModel::ProjectModel():path(NULL), outputPath(NULL), hash(NULL), root(NULL), fileCount(0){
    sf2f::ProjectModel::generateHash();
};

sf2f::ProjectModel::ProjectModel(
    std::string path = NULL,
    std::string output = NULL,
    std::string hash = NULL
):path(path), outputPath(output), hash(hash), root(NULL), fileCount(0){
    sf2f::ProjectModel::generateHash();
};

sf2f::ProjectModel::~ProjectModel(){};

std::string sf2f::ProjectModel::getPath() {
    return path;
}

std::string sf2f::ProjectModel::getOutputPath() {
    return outputPath;
}

std::string sf2f::ProjectModel::getHash() {
    return hash;
}

sf2f::StealthFileModel* sf2f::ProjectModel::getRoot(){
    return root;
}

int sf2f::ProjectModel::getFileCount() {
    return fileCount;
}

void sf2f::ProjectModel::generateHash(){
    try {
        unsigned char md[MD5_DIGEST_LENGTH];
        std::string mapped = path + outputPath + root->hash;

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

bool sf2f::ProjectModel::withPath(std::string value) {
    try {
        path = value;
        sf2f::ProjectModel::generateHash();
        return true;
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::ProjectModel::withOutputPath(std::string value) {
    try {
        outputPath = value;
        sf2f::ProjectModel::generateHash();
        return true;
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::ProjectModel::withRoot(sf2f::StealthFileModel* value) {
    try {
        root = value;
        sf2f::ProjectModel::generateHash();
        return true;
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::ProjectModel::withFileCount(int value) {
    try {
        fileCount = value;
        sf2f::ProjectModel::generateHash();
        return true;
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}