#include "../include/generateStream.h"
#include "../include/def.h"
#include <iostream>
#include <fstream>

using namespace std;

bool testGenerateBinaryStream() {
    generateBinaryStream();

    string dataFileName = "Binary_" + to_string(STREAM_LENGTH) + ".dat";
    string dataFilepath =  DATA_LOCATION + dataFileName;
    string fileString;
    ifstream dataFileIn;

    dataFileIn.open(dataFilepath, ios::in);

    if (!dataFileIn.good()) {
        return false;
    }
    
    getline(dataFileIn, fileString);

    if (fileString.size() != STREAM_LENGTH * 2) {
        return false;
    }
    
    return true;
}

bool testGenerateIntegerStream() {
    generateIntegerStream();

    string dataFileName = "Integer_" + to_string(STREAM_LENGTH) + ".dat";
    string dataFilepath =  DATA_LOCATION + dataFileName;
    string fileString;
    ifstream dataFileIn;

    dataFileIn.open(dataFilepath, ios::in);

    if (!dataFileIn.good()) {
        return false;
    }

    string integerString;
    int counter = 0;

    while (!dataFileIn.eof()) {
        dataFileIn >> integerString;
        counter++;
    }

    //  You need to consider the white space at the end of the file
    // so the counter shall be STREAM_LENGTH + 1, not the STREAM_LENGTH
    if (counter != STREAM_LENGTH + 1) {
        return false;
    }
    
    return true;
}

bool testTurnIntegerStreamToBinaryStream() {
    turnIntegerStreamToBinaryStream();

    string dataFileName;
    string dataFilepath;
    string fileString;

    ifstream input;

    for (int i = 0; i < NUM_BITS_OF_INTEGER; i++) {
        dataFileName = "Binary_" + to_string(STREAM_LENGTH) + "_" + to_string(i) + ".dat";
        dataFilepath =  DATA_LOCATION + dataFileName;

        input.open(dataFilepath, ios::in);

        if (!input.good()) {
            return false;
        }

        getline(input, fileString);

        if (fileString.size() != STREAM_LENGTH * 2) {
            cout << fileString.size() << endl;
            input.close();
            return false;
        }

        input.close();
    }

    return true;
}

int main() {
    if (testGenerateBinaryStream()) {
        cout << "generateBinaryStream passed" << endl;
    }
    else {
        cout << "generateBinaryStream failed" << endl;
    }

    if (testGenerateIntegerStream()) {
        cout << "generateIntegerStream passed" << endl;
    }
    else {
        cout << "generateIntegerStream failed" << endl;
    }

    if (testTurnIntegerStreamToBinaryStream()) {
        cout << "turnIntegerStreamToBinaryStream passed" << endl;
    }
    else {
        cout << "turnIntegerStreamToBinaryStream failed" << endl;
    }
}