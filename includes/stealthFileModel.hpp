#ifndef STEALTHFILEMODEL_H
#define STEALTHFILEMODEL_H

#include <string>
#include <vector>

namespace sf2f {
    class StealthFileModel {
        public:
            std::string path;
            std::string base64;
            std::string hash;
            
            std::vector<sf2f::StealthFileModel*> children;
            bool isDirectory;
        private:
            StealthFileModel();
            StealthFileModel(std::string path = "", bool isDirectory = true, std::string base64 = "");
            ~StealthFileModel();

            void generateHash();

            std::string getPath();
            std::string getBase64();
            std::string getHash();
            bool getIsDirectory();

            bool withPath(std::string value);
            bool withBase64(std::string value);
            bool withIsDirectory(bool value);

            bool addChild(sf2f::StealthFileModel* value);
            bool removeChild(std::string value);
    };
}

#endif