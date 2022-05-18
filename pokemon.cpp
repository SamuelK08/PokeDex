#include "pokemon.hpp"

Pokemon::Pokemon() {
    //what kind of data

}

Pokemon::Pokemon(std::string name,
                 std::string height,
                 std::string weight,
                 std::string type,
                 std::vector<std::string> friends) {
    this -> name = name;
    this -> height = height;
    this -> weight = weight;
    this -> type = type;
    this -> friends = friends;
}

std::string Pokemon::repeatChar(char repeat, int count) {
    std::string result = "";
    for(int i = 0; i < count; i++) {
        result += repeat;
    }
    return result;
}


std::string Pokemon::getName() {
    return name;
}
std::string Pokemon::getHeight() {
    return height;
}
std::string Pokemon::getWeight() {
    return weight;
}
std::string Pokemon::getType() {
    return type;
}

std::vector<std::string> Pokemon::getFriends() {
    return friends;
}


void Pokemon::info() {
    int dashCount = (20 - name.size()) / 2;
    int typeCount = 20 - (8 + type.size());
    int weightCount = 20 - (10 + weight.size());
    int heightCount = 20 - (10 + height.size());
    int friendsCount = 20 - (9 + friends.size());

    std::cout << repeatChar('-', dashCount) << name << repeatChar('-', dashCount);
    if(name.size() % 2 != 0) {
        std::cout << '-';
    }
    std::cout << std::endl;
    std::cout << "|type: " << type << repeatChar(' ', typeCount) << "|" << std::endl;
    std::cout << "|weight: " << weight << repeatChar(' ', weightCount) << "|" << std::endl;
    std::cout << "|height: " << height << repeatChar(' ', heightCount) << "|" << std::endl;
    std::cout << "|friends: " << friends.size() << repeatChar(' ', friendsCount) << "|" << std::endl;
    std::cout << repeatChar('-', 20) << std::endl;
}