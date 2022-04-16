#include "../include/generateStream.h"
#include "../include/def.h"
#include <string>
#include <fstream>

using namespace std;

void generateBinaryStream() {
    // Create the stream data file
    string dataFileName = "Binary_" + to_string(STREAM_LENGTH) + ".dat";
    string dataFilepath =  DATA_LOCATION + dataFileName;

    ofstream output;
    output.open(dataFilepath, ios::out);

    // Create random binary data
    srand(time(NULL));

    int randomBinaryNumber;
    string randomBinaryString;
    
    for (int i = 0; i < STREAM_LENGTH; i++) {
        randomBinaryNumber = rand() % 2;
        randomBinaryString = to_string(randomBinaryNumber) + " ";

        output.write(randomBinaryString.c_str(), randomBinaryString.size());
    }

    // Close the file
    output.close();
}

void generateIntegerStream() {
    // Create the stream data file
    string dataFileName = "Integer_" + to_string(STREAM_LENGTH) + ".dat";
    string dataFilepath =  DATA_LOCATION + dataFileName;

    ofstream output;
    output.open(dataFilepath, ios::out);

    // Create random binary data
    srand(time(NULL));

    int randomIntegerNumber;
    string randomIntegerString;
    
    for (int i = 0; i < STREAM_LENGTH; i++) {
        randomIntegerNumber = rand() % 128;
        randomIntegerString = to_string(randomIntegerNumber) + " ";

        output.write(randomIntegerString.c_str(), randomIntegerString.size());
    }

    // Close the file
    output.close();
}

void turnIntegerStreamToBinaryStream() {
    string dataFileName = "Integer_" + to_string(STREAM_LENGTH) + ".dat";
    string dataFilepath =  DATA_LOCATION + dataFileName;

    ofstream output[NUM_BITS_OF_INTEGER];
    ifstream input;

    string singleDataString;
    int    singleData;

    input.open(dataFilepath, ios::in);

    for (int i = 0; i < NUM_BITS_OF_INTEGER; i++) {
        dataFileName = "Binary_" + to_string(STREAM_LENGTH) + "_" + to_string(i) + ".dat";
        dataFilepath = DATA_LOCATION + dataFileName;

        output[i].open(dataFilepath, ios::out);
    }

    for (int i = 0; i < STREAM_LENGTH; i++) {
        input >> singleDataString;
        singleData = stoi(singleDataString);
        int bit;
        string bitString;

        for (int i = 0; i < NUM_BITS_OF_INTEGER; i++) {
            bit = singleData % 2;
            singleData /= 2;
            bitString = to_string(bit) + " ";

            output[i].write(bitString.c_str(), bitString.size());
        }
    }

    for (int i = 0; i < NUM_BITS_OF_INTEGER; i++) {
        output[i].close();
    }

    input.close();
}