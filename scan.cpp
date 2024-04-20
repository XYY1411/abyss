#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "dataclass.hpp"

void scan(std::string strDataFile,
          std::vector<Data::Character *> &vecCharacter) {
    std::ifstream ifs(strDataFile);
    if (!ifs) {
        throw std::runtime_error(std::string("Cannot open the file ") +
                                 strDataFile + std::string("!"));
    }
    std::string strLine;
    std::getline(ifs, strLine);
    while (std::getline(ifs, strLine)) {
        std::replace(strLine.begin(), strLine.end(), ',', ' ');
        std::istringstream iss(strLine);
        std::string strName;
        int iStar;
        std::string strWeaponType;
        std::string strElementType;
        std::string strModelType;
        int iBirthmonth;
        std::string strState;
        bool bVision;
        iss >> strName >> iStar >> strWeaponType >> strElementType >>
            strModelType >> iBirthmonth >> strState >> bVision;
        vecCharacter.push_back(
            new Data::Character(strName, iStar, strWeaponType, strElementType,
                                strModelType, iBirthmonth, strState, bVision));
    }
    ifs.close();
    return;
}
