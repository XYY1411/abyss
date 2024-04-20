#include "dataclass.hpp"

// Class Data::Character
Data::Type Data::TypeSelect;
const std::string Data::Character::name(void) { return strName; }
const int Data::Character::star(void) { return iStar; }
const Data::Character::WeaponType Data::Character::weaponType(void) {
    return eWeaponType;
}
const Data::Character::ElementType Data::Character::elementType(void) {
    return eElementType;
}
const Data::Character::ModelType Data::Character::modelType(void) {
    return eModelType;
}
const int Data::Character::birthmonth(void) { return iBirthmonth; }
const Data::Character::State Data::Character::state(void) { return eState; }
const bool Data::Character::vision(void) { return bVision; }
const Data::Character::WeaponType Data::Character::str2eW(
    std::string strWeaponType) {
    if (strWeaponType == "Sword") {
        return Data::Character::Sword;
    } else if (strWeaponType == "Claymore") {
        return Data::Character::Claymore;
    } else if (strWeaponType == "Polearm") {
        return Data::Character::Polearm;
    } else if (strWeaponType == "Bow") {
        return Data::Character::Bow;
    } else if (strWeaponType == "Catalyst") {
        return Data::Character::Catalyst;
    } else {
        return Data::Character::Sword;
    }
}
const Data::Character::ElementType Data::Character::str2eE(
    std::string strElementType) {
    if (strElementType == "Pyro") {
        return Data::Character::Pyro;
    } else if (strElementType == "Hydro") {
        return Data::Character::Hydro;
    } else if (strElementType == "Dendro") {
        return Data::Character::Dendro;
    } else if (strElementType == "Electro") {
        return Data::Character::Electro;
    } else if (strElementType == "Anemo") {
        return Data::Character::Anemo;
    } else if (strElementType == "Cryo") {
        return Data::Character::Cryo;
    } else if (strElementType == "Geo") {
        return Data::Character::Geo;
    } else if (strElementType == "Muilt") {
        return Data::Character::Muilt;
    } else {
        return Data::Character::Pyro;
    }
}
const Data::Character::ModelType Data::Character::str2eM(
    std::string strModelType) {
    if (strModelType == "AM") {
        return Data::Character::AM;
    } else if (strModelType == "AW") {
        return Data::Character::AW;
    } else if (strModelType == "BY") {
        return Data::Character::BY;
    } else if (strModelType == "GL") {
        return Data::Character::GL;
    } else if (strModelType == "LL") {
        return Data::Character::LL;
    } else {
        return Data::Character::AM;
    }
}
const Data::Character::State Data::Character::str2eS(std::string strState) {
    if (strState == "Mondstadt") {
        return Data::Character::Mondstadt;
    } else if (strState == "Liyue") {
        return Data::Character::Liyue;
    } else if (strState == "Inazuma") {
        return Data::Character::Inazuma;
    } else if (strState == "Sumeru") {
        return Data::Character::Sumeru;
    } else if (strState == "Fontaine") {
        return Data::Character::Fontaine;
    } else if (strState == "Natlan") {
        return Data::Character::Natlan;
    } else if (strState == "Snezhnaya") {
        return Data::Character::Snezhnaya;
    } else if (strState == "Khaenriah") {
        return Data::Character::Khaenriah;
    } else if (strState == "Celestia") {
        return Data::Character::Celestia;
    } else if (strState == "Horizon") {
        return Data::Character::Horizon;
    } else {
        return Data::Character::Mondstadt;
    }
}
const std::string Data::Character::e2strW(
    Data::Character::WeaponType eWeaponType) {
    switch (eWeaponType) {
        case Data::Character::Sword:
            return "Sword";
        case Data::Character::Claymore:
            return "Claymore";
        case Data::Character::Polearm:
            return "Polearm";
        case Data::Character::Bow:
            return "Bow";
        case Data::Character::Catalyst:
            return "Catalyst";
        default:
            return "Sword";
    }
}
const std::string Data::Character::e2strE(
    Data::Character::ElementType eElementType) {
    switch (eElementType) {
        case Data::Character::Pyro:
            return "Pyro";
        case Data::Character::Hydro:
            return "Hydro";
        case Data::Character::Dendro:
            return "Dendro";
        case Data::Character::Electro:
            return "Electro";
        case Data::Character::Anemo:
            return "Anemo";
        case Data::Character::Cryo:
            return "Cryo";
        case Data::Character::Geo:
            return "Geo";
        case Data::Character::Muilt:
            return "Muilt";
        default:
            return "Pyro";
    }
}
const std::string Data::Character::e2strM(
    Data::Character::ModelType eModelType) {
    switch (eModelType) {
        case Data::Character::AM:
            return "AM";
        case Data::Character::AW:
            return "AW";
        case Data::Character::BY:
            return "BY";
        case Data::Character::GL:
            return "GL";
        case Data::Character::LL:
            return "LL";
        default:
            return "AM";
    }
}
const std::string Data::Character::e2strS(Data::Character::State eState) {
    switch (eState) {
        case Data::Character::Mondstadt:
            return "Mondstadt";
        case Data::Character::Liyue:
            return "Liyue";
        case Data::Character::Inazuma:
            return "Inazuma";
        case Data::Character::Sumeru:
            return "Sumeru";
        case Data::Character::Fontaine:
            return "Fontaine";
        case Data::Character::Natlan:
            return "Natlan";
        case Data::Character::Snezhnaya:
            return "Snezhnaya";
        case Data::Character::Khaenriah:
            return "Khaenriah";
        case Data::Character::Celestia:
            return "Celestia";
        case Data::Character::Horizon:
            return "Horizon";
        default:
            return "Mondstadt";
    }
}
Data::Character::Character() {}
Data::Character::Character(std::string strName, int iStar,
                           std::string strWeaponType,
                           std::string strElementType, std::string strModelType,
                           int iBirthmonth, std::string strState,
                           bool bVision) {
    this->strName = strName;
    this->iStar = iStar;
    this->eWeaponType = str2eW(strWeaponType);
    this->eElementType = str2eE(strElementType);
    this->eModelType = str2eM(strModelType);
    this->iBirthmonth = iBirthmonth;
    this->eState = str2eS(strState);
    this->bVision = bVision;
}
Data::Character::~Character() {}

const bool Data::Character::operator==(const Data::Character &rhs) const {
    bool flag = true;
    if (Data::TypeSelect & Data::Sstar) {
        flag = flag && (iStar == rhs.iStar);
    }
    if (Data::TypeSelect & Data::SWeaponType) {
        flag = flag && (eWeaponType == rhs.eWeaponType);
    }
    if (Data::TypeSelect & Data::SElementType) {
        flag = flag && (eElementType == rhs.eElementType);
    }
    if (Data::TypeSelect & Data::SModelType) {
        flag = flag && (eModelType == rhs.eModelType);
    }
    if (Data::TypeSelect & Data::SBirthmonth) {
        flag = flag && (iBirthmonth == rhs.iBirthmonth);
    }
    if (Data::TypeSelect & Data::SState) {
        flag = flag && (eState == rhs.eState);
    }
    if (Data::TypeSelect & Data::SVision) {
        flag = flag && (bVision == rhs.bVision);
    }
    return flag;
}