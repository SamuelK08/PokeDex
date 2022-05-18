#include "pokeDex.hpp"


PokeDex::PokeDex(std::vector<std::string> names,
                 std::vector<std::string> heights,
                 std::vector<std::string> weights,
                 std::vector<std::string> types,
                 std::vector<std::vector<std::string>> friends) {
    this -> names = names;
    this -> heights = heights;
    this -> weights = weights;
    this -> types = types;
    this -> friends = friends;

    for(int i = 0; i < names.size(); i++) {
        Pokemon tempPokemon(names[i], heights[i], weights[i], types[i], friends[i]);
        pokemons.push_back(tempPokemon);
    }
}

Pokemon PokeDex::getPokemonOf(int inputI) {
    //save into pokemon datatype
    return pokemons[inputI];
}

std::vector<Pokemon> PokeDex::getFriendOf(Pokemon inputPokemon) {
    //inputPokemon.getFriends(); <- vector<string> = {"A", "B"}
    // return {Pokemon <- A, Pokemon <- B}

    // for(nameIndex ~ inpuP.getFrien.size()) {
    //     string currentPokemonName = inputPokemon.getFriends()[i]; //"A"
    //     for(pokemonIndex ~ pokemons.size()) {
    //         if(pokemons[pokmoneIndex].getName() == currentPokemonName) {
    //             result.push_back(pokemons[pokemondIdex]);
    //         }
    //     }
    // }

    std::vector<Pokemon> result;
    for(int i = 0; i < (inputPokemon.getFriends()).size(); i++) {
        std::string currentName = inputPokemon.getFriends()[i];
        for(int j = 0; j < pokemons.size(); j++) {
            if(pokemons[j].getName() == currentName) {
                result.push_back(pokemons[j]);
            }
        }
    }
    return result;
}