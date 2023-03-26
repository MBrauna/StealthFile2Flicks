#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H

#include <string>
#include "stealthFileModel.hpp"

namespace sf2f {
    class ProjectModel {
        private:
            std::string path;
            std::string outputPath;
            std::string hash;
            sf2f::StealthFileModel* root;
            int fileCount;
        public:
            ProjectModel();
            ProjectModel(std::string path, std::string output);
            ~ProjectModel();

            std::string getPath();
            std::string getOutputPath();
            std::string getHash();
            sf2f::StealthFileModel* getRoot();
            int getFileCount();

            void generateHash();

            bool withPath(std::string value);
            bool withOutputPath(std::string value);
            bool withRoot(sf2f::StealthFileModel* value);
            bool withFileCount(int value);
    };
}

#endif