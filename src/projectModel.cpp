#include "./../includes/projectModel.hpp"

#include <iostream>
#include <sstream>
#include <openssl/md5.h>

sf2f::ProjectModel::ProjectModel():
    hash(""),
    entryPath(""),
    outputPath(""),
    fileCount(0){};

sf2f::ProjectModel::~ProjectModel(){};

std::string sf2f::ProjectModel::getHash() {
    return hash;
}

std::string sf2f::ProjectModel::getEntryPath() {
    return entryPath;
}

std::string sf2f::ProjectModel::getOutputPath() {
    return outputPath;
}

int sf2f::ProjectModel::getFileCount() {
    return fileCount;
}

bool sf2f::ProjectModel::setEntryPath(std::string value) {
    try {
        entryPath = value;
        generateHash();
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::ProjectModel::setOutputPath(std::string value) {
    try {
        outputPath = value;
        generateHash();
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

bool sf2f::ProjectModel::setFileCount(int value) {
    try {
        fileCount = value;
        generateHash();
    } catch(const std::exception& e){
        std::cerr << typeid(*this).name() << e.what() << std::endl;
        return false;
    }
}

void sf2f::ProjectModel::generateHash() {
    try {
        unsigned char md[MD5_DIGEST_LENGTH];
        std::string mapped = entryPath + outputPath + std::to_string(fileCount);

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