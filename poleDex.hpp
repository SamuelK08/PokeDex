#ifndef pokeDex_hpp
#define pokeDex_hpp

class PokeDex {

public:
    PokeDex();

    Pokemon getPokemonOf(int inputI);
    std::vector<Pokemon> getFriendOf(Pokemon inputPokemon);



private:

    std::vector<std::string> names;
    std::vector<std::string> heights;
    std::vector<std::string> weights;
    std::vector<std::string> types;
    std::vector<std::string> friends;

    std::vector<Pokemon> pokemons;


};




#include "pokeDex.cpp"
#endif