/**
 * @file dataclass.hpp
 * @brief A Class for character data.
 * @author XYY1411
 * @copyright (c) 2024 Equinox
 * @version 0.1
 * @date 2024-04-07 11:52
 * @since 0.1
 */

#ifndef DATA_CLASS_HPP
#define DATA_CLASS_HPP

// Stdanderd C++ Library

#include <iostream>
#include <string>

namespace Data {
enum Type : int {
    Sstar = 0b1,
    SWeaponType = 0b10,
    SElementType = 0b100,
    SModelType = 0b1000,
    SBirthmonth = 0b10000,
    SState = 0b100000,
    SVision = 0b1000000
};
extern Type TypeSelect;
class Character {
   public:
    enum WeaponType { Sword, Claymore, Polearm, Bow, Catalyst };
    enum ElementType { Pyro, Hydro, Dendro, Electro, Anemo, Cryo, Geo, Muilt };
    enum ModelType { AM, AW, BY, GL, LL };
    enum State {
        Mondstadt,
        Liyue,
        Inazuma,
        Sumeru,
        Fontaine,
        Natlan,
        Snezhnaya,
        Khaenriah,
        Celestia,
        Horizon
    };
    const std::string name(void);
    const int star(void);
    const WeaponType weaponType(void);
    const ElementType elementType(void);
    const ModelType modelType(void);
    const int birthmonth(void);
    const State state(void);
    const bool vision(void);
    static const WeaponType str2eW(std::string strWeaponType);
    static const ElementType str2eE(std::string strElementType);
    static const ModelType str2eM(std::string strModelType);
    static const State str2eS(std::string strState);
    static const std::string e2strW(WeaponType eWeaponType);
    static const std::string e2strE(ElementType eElementType);
    static const std::string e2strM(ModelType eModelType);
    static const std::string e2strS(State eState);
    Character();
    Character(std::string strName, int iStar, std::string strWeaponType,
              std::string strElementType, std::string strModelType,
              int iBirthmonth, std::string strState, bool bVision);
    ~Character();
    const bool operator==(const Character &rhs) const;

   private:
    std::string strName;
    int iStar;
    WeaponType eWeaponType;
    ElementType eElementType;
    ModelType eModelType;
    int iBirthmonth;
    State eState;
    bool bVision;
};  // class Character
}  // namespace Data

#endif  // DATA_CLASS_HPP