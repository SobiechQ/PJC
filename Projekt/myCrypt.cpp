#include <string>
#include <fmt/printf.h>
#include <map>
#include <vector>
#include <random>

//
// Created by mikol on 18.05.2023.
//
/**
 * Encrypts given value by a passed key. Keys are salted, fed with random trash data and mixed so every useage of this algorythm results in different meessage.
 * When encrypting, hash is automatically retrived from message
 * @param value
 * @param key
 * @return
 */
auto enc2(const std::string &value, const std::string &key) -> void {
    using namespace std;
    string keyTmp = "b109f3bbbc244eb82441917ed06d618b9008dd09b3befd1b5e07394c706a8bb980b1d7785e5976ec049b46df5f1326af5a2ea6d103fd07c95385ffab0cacbc86"; //128 chars, 64 numbers, 32 letters possible to encrypt
    std::vector<pair<int, char>> valuePositioned;
    for (int i = 0; i < value.size(); ++i)
        valuePositioned.push_back(pair<int, char>(i, value[i]));
    std::vector<pair<int, char>> copyOfValuePositioned = valuePositioned;
    for (int i = valuePositioned.size(); i < keyTmp.size() / 4; ++i) {
        int random = rand() % copyOfValuePositioned.size();
        //i take one random value from copy and assign it to a valuePositioned vector, so its length matches sha512 length
        valuePositioned.push_back(copyOfValuePositioned[random]);
    }
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(valuePositioned), std::end(valuePositioned), rng);
    for (auto i: valuePositioned) {
        fmt::print("{}", i.first);
        fmt::print("{}", i.second);
        fmt::print(" ");
    }

    std::vector<int> parsedHex; // 64 decimal integers from sha 512 hash.
    for (int i = 0; i < keyTmp.size(); i += 2) {
        string hexValFromKey;
        hexValFromKey += keyTmp[i];
        hexValFromKey += keyTmp[i + 1];
        parsedHex.push_back(stoi(hexValFromKey, 0, 16));
    }
    string output;
    for (int i = 0; i < parsedHex.size(); i++) {
        i % 2 == 0 ?
                output += valuePositioned[i / 2].first + parsedHex[i] :
                output += valuePositioned[i / 2].second + parsedHex[i];
    }
    cout << " " << '\n';
    for (auto i: valuePositioned) {
        fmt::print("{}", i.first);
        fmt::print("{}", i.second);
        fmt::print(" ");
    }


}

auto decrypt(const std::string &value, const std::string &key) -> void {


}

