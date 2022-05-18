#include <iostream>
#include <vector>
#include "dataReader.hpp"
#include "pokemon.hpp"
#include "pokeDex.hpp"

using namespace std;

int main() {
	DataReader dataReader("text.txt"); //customCont
	PokeDex myDex(dataReader.getNames(),
	              dataReader.getHeights(),
	              dataReader.getWeights(),
	              dataReader.getTypes(),
	              dataReader.getFriends());
	Pokemon arbok = myDex.getPokemonOf(2);
	arbok.info();


	vector<Pokemon> friends = myDex.getFriendOf(arbok);
	for(int i = 0; i < friends.size(); i++) {
		friends[i].info();
	}

    return 0;
}