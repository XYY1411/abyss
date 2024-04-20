#include "random_generate.hpp"

extern int RandG::RandomGenerate(int l, int r) noexcept {
    std::random_device seed;
    std::mt19937 rd(seed());
    std::uniform_int_distribution<int> dist(l, r);
    return dist(rd);
}