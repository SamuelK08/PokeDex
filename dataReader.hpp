#ifndef dataReader_hpp
#define dataReader_hpp
#include <vector>
#include <iostream>
#include <fstream>

class DataReader {
public:
    DataReader();
    DataReader(std::string inputFileName);

    std::vector<std::string> getNames();
    std::vector<std::string> getHeights();
    std::vector<std::string> getWeights();
    std::vector<std::string> getTypes();
    std::vector<std::vector<std::string>> getFriends();

private:
    void readFileOf(std::string& fileName);
    void seperateNames(std::string line, int& i);
    void seperateHeights(std::string line, int& i);
    void seperateWeights(std::string line, int& i);
    void seperateTypes(std::string line, int& i);
    void seperateFriends(std::string line, int& i);
    bool isValid(std::string line);

    std::vector<std::string> names;
    std::vector<std::string> heights;
    std::vector<std::string> weights;
    std::vector<std::string> types;

    std::vector<std::vector<std::string>> friends;
};

#include "dataReader.cpp"
#endif