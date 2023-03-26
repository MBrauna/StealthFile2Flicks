#include "includes/projectModel.hpp"
#include "includes/stealthFileModel.hpp"

#include <iostream>

int main() {
    sf2f::ProjectModel dados("/teste", "/teste123");
    dados.withFileCount(2);
    std::cout << dados.getPath() << std::endl;
    return 0;
}