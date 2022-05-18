#ifndef pokemon_cpp
#define pokemon_cpp
#include <vector>

class Pokemon {

public:
    Pokemon();
    Pokemon(std::string name,
            std::string height,
            std::string weight,
            std::string type,
            std::vector<std::string> friends);

    void info();

    std::string getName();
    std::string getHeight();
    std::string getWeight();
    std::string getType();
    std::vector<std::string> getFriends();

private:
    std::string repeatChar(char repeat, int count);
    std::string name;
    std::string height;
    std::string weight;
    std::string type;
    std::vector<std::string> friends;
};

#include "pokemon.cpp"
#endif