#include "dataReader.hpp"

DataReader::DataReader() {

}

DataReader::DataReader(std::string inputFileName) {
    readFileOf(inputFileName);
}

//One function does one task
void DataReader::readFileOf(std::string& fileName) {
    std::string line = "";
    std::ifstream file(fileName);
    if(file.is_open()) {
        while(getline(file, line)) {
            int i = 0;
            if(isValid(line)) {
                seperateNames(line, i);
                seperateHeights(line, i);
                seperateWeights(line, i);
                seperateTypes(line, i);
                seperateFriends(line, i);
            }

        }
        file.close();
    }
}

bool DataReader::isValid(std::string line) {
    bool isComment = false;
    for(int i = 0; i < line.size(); i++) {
        if(i != line.size()) {
            if(line[i] == '/' && line[i + 1] == '/') {
                isComment = true;
            }
        }
    }
    return !isComment;
}

void DataReader::seperateNames(std::string line, int& i) {
    //"Abra / 2'11" / 43 lbs / psychic / Arbok, Charmander"
    std::string tempName = "";
    while(line[i] != ' ') {
        tempName += line[i];
        i++;
    }
    names.push_back(tempName);
    i += 3;
    //std::cout << "Names I: " << i << std::endl;
}

void DataReader::seperateHeights(std::string line, int& i) {
    std::string tempHeight = "";
    while(line[i] != ' ') {
        tempHeight += line[i];
        i++;
    }

    heights.push_back(tempHeight);
    i += 3;
    //td::cout << "Heights I: " << i << std::endl;
}

void DataReader::seperateWeights(std::string line, int& i) {
    std::string tempWeight = "";
    //bool hasFoundSpace = false; //don't use bool
    int spaceCounter = 0;
    //43 lbs
    //add space counter when see space
    while(line[i] != ' ' || spaceCounter < 1) { //👀 - look for when not space
        if(line[i] == ' ') {
            spaceCounter++;
        }
        tempWeight += line[i];
        i++;
    }
    // std::cout << "tempWeight: " << tempWeight << ", " << tempWeight.size() << std::endl;
    weights.push_back(tempWeight);
    i += 3;
    //std::cout << "Weights I: " << i << std::endl;
}

void DataReader::seperateTypes(std::string line, int& i) {
    std::string tempType = "";
    while(line[i] != ' ') {
        tempType += line[i];
        i++;
    }

    types.push_back(tempType);
    i += 3;
    //std::cout << "Types I: " << i << std::endl;
}

void DataReader::seperateFriends(std::string line, int& i) {
    std::vector<std::string> tempFriends; //<- this is an element
    std::string friendsForVector = "";
    for(int j = i; j < line.size(); j++) {
        if(line[j] != ',' && line[j] != ' ') {
            friendsForVector += line[j];
        } else if(friendsForVector.size() != 0) {
            tempFriends.push_back(friendsForVector);
            friendsForVector = "";
        }

        if(j == line.size() - 1) {
            // std::cout << "at end: " << friendsForVector << std::endl;
            tempFriends.push_back(friendsForVector);
            friendsForVector = "";
            j += 2;
        }
    }
    friends.push_back(tempFriends);
}

std::vector<std::string> DataReader::getNames() {
    return names;
}

std::vector<std::string> DataReader::getHeights() {
    return heights;
}

std::vector<std::string> DataReader::getWeights() {
    return weights;
}

std::vector<std::string> DataReader::getTypes() {
    return types;
}

std::vector<std::vector<std::string>> DataReader::getFriends() {
    return friends;
}