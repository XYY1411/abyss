/**
 * @brief A program to make random abyss for Genshin Impact.
 * @author XYY1411
 * @copyright (c) 2024 Equinox
 * @version 0.1
 * @date 2024-04-05 15:46
 */

// Compiler Environment Check
#define DEBUG
#if __cplusplus < 201103L
#error "C++11 or later is required."
#endif
#ifndef __WIN64
#error "Windows 64-bit is required."
#endif
#ifndef __GNUG__
#error "GNU G++ is required."
#endif

// Compiler Environment Check End

// Stdanderd C++ Library

#include <iostream>
#include <string>
#include <vector>

// Standard C Library

#include <cstdlib>

// Third Party Library

#include <getopt.h>

// Custom Library

#include "dataclass.hpp"
#include "random_generate.hpp"

// Global Variables

const std::string strVersion("0.1");

/**
 * @brief Print the help guide of the program.
 * @author XYY1411
 * @return void
 * @throw None
 * @since 0.1
 * @version 0.1
 * @date 2024-04-05 16:09
 */
void PrintHlepGuide(void) noexcept {
    std::cout << "Usage: abyss [options]\n";
    std::cout << "Options:\n";
    std::cout << "\t-h\tShow this help message and exit.\n";
    std::cout << "\t-v\tShow version information and exit.\n";
    std::cout << "\t-d\tSpecify the data file.\n";
    std::cout << std::endl;
    return;
}
void scan(std::string strDataFile,
          std::vector<Data::Character *> &vecCharacter);

std::string Ordinal(int n) noexcept {
    if (n % 100 / 10 == 1) {
        return "th";
    }
    switch (n % 10) {
        case 1:
            return "st";
        case 2:
            return "nd";
        case 3:
            return "rd";
        default:
            return "th";
    }
}

/**
 * @brief The main function of the program.
 * @author XYY1411
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return The exit code.
 * @date 2024-04-05 15:49
 */
int main(int argc, char *argv[]) {
    int opt;
    if (argc == 1) {
        std::cerr << "Arguments required!\n";
        PrintHlepGuide();
        return 1;
    }
    std::string strDataFile;
    while (opt = getopt(argc, argv, "hvd:"), opt != -1) {
        switch (opt) {
            case 'h':
                PrintHlepGuide();
                return 0;
            case 'v':
                std::cout << "Abyss " << strVersion << std::endl;
                return 0;
            case 'd':
                strDataFile = std::string(optarg);
                break;
            default:
                std::cerr << "Invalid option.\n";
                return 1;
        }
    }
    std::vector<Data::Character *> vecCharacter;
    try {
        scan(strDataFile, vecCharacter);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }
    int n;
    std::cout << "How many characters do you want to choose: ";
    std::cin >> n;
    std::cout << "Select limit(1 for yes, 0 for no):\n"
                 "Star, WeaponType, ElementType, ModelType, Birthmonth, State, "
                 "Vision\n";
    int limit;
    for (int i = 0; i < 7; i++) {
        std::cin >> limit;
        if (limit) {
            Data::TypeSelect =
                static_cast<Data::Type>(Data::TypeSelect | (1 << i));
        }
    }
    std::vector<Data::Character *> itCharacter[4];
    for (int i = 0; i < n; i++) {
        int a = RandG::RandomGenerate(0, 7);
        int b = RandG::RandomGenerate(0, 4);
        int c = RandG::RandomGenerate(4, 5);
        int d = RandG::RandomGenerate(0, 4);
        int e = RandG::RandomGenerate(1, 12);
        int f = RandG::RandomGenerate(0, 9);
        int g = RandG::RandomGenerate(0, 1);
        Data::Character tmp(
            std::string(""), c,
            Data::Character::e2strW(Data::Character::WeaponType(b)),
            Data::Character::e2strE(Data::Character::ElementType(a)),
            Data::Character::e2strM(Data::Character::ModelType(d)), e,
            Data::Character::e2strS(Data::Character::State(f)), g);
        for (auto it : vecCharacter) {
            if (tmp == *it) {
                itCharacter[i].push_back(it);
            }
        }
        if (itCharacter[i].empty()) {
            i--;
            continue;
        }
        std::cout << "Now choose your " << i + 1 << Ordinal(i + 1)
                  << " character. \n";
        if (Data::TypeSelect & Data::SElementType)
            std::cout << "The Element of this Character is "
                      << Data::Character::e2strE(
                             Data::Character::ElementType(a))
                      << '.' << std::endl;
        if (Data::TypeSelect & Data::SWeaponType)
            std::cout << "The Weapon of this Character is "
                      << Data::Character::e2strW(Data::Character::WeaponType(b))
                      << '.' << std::endl;
        if (Data::TypeSelect & Data::Sstar)
            std::cout << "The Star of this Character is " << c << '.'
                      << std::endl;
        if (Data::TypeSelect & Data::SModelType)
            std::cout << "The Model of this Character is "
                      << Data::Character::e2strM(Data::Character::ModelType(d))
                      << '.' << std::endl;
        if (Data::TypeSelect & Data::SBirthmonth)
            std::cout << "The Birthmonth of this Character is " << e << '.'
                      << std::endl;
        if (Data::TypeSelect & Data::SState)
            std::cout << "The State of this Character is "
                      << Data::Character::e2strS(Data::Character::State(f))
                      << '.' << std::endl;
        if (Data::TypeSelect & Data::SVision)
            std::cout << "The Character " << (g ? "has" : "doesn't have")
                      << " a Vision." << std::endl;
        std::cout << "You can Choose: ";
        for (auto it : itCharacter[i]) {
            std::cout << it->name() << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}