#include "../include/estimateAndTruth.h"
#include "../include/generateStream.h"
#include "../include/bucketList.h"
#include <math.h>

int main() {
    generateIntegerStream();
    turnIntegerStreamToBinaryStream();

    string dataFileName;
    string integerDataFileName;
    BucketList bucketList[NUM_BITS_OF_INTEGER];
    int estimateValue[NUM_BITS_OF_INTEGER];
    int truthValue;

    for (int i = 0; i < NUM_BITS_OF_INTEGER; i++) {
        dataFileName = "Binary_" + to_string(STREAM_LENGTH) + "_" + to_string(i) + ".dat";
        bucketList[i].openDataFile(dataFileName);
    }

    integerDataFileName = "Integer_" + to_string(STREAM_LENGTH) + ".dat";

    for (int i = 0; i < (int)(STREAM_LENGTH / RECORD_LENGTH); i++) {
        
        if (PRINT_BUCKET_LIST) {
            if (i == 0) {
                cout << "****************************************" << endl;
                cout << "Timestamp = " << 10000 << endl;
            }
            else if (RECORD_LENGTH * (i + 1) == STREAM_LENGTH / 2 || RECORD_LENGTH * (i + 1) == STREAM_LENGTH) {
                cout << "****************************************" << endl;
                cout << "Timestamp = " << RECORD_LENGTH * (i + 1) << endl;
            }
        }

        for (int j = 0; j < NUM_BITS_OF_INTEGER; j++) {
            bucketList[j].readFileAndUpdateBucketList(RECORD_LENGTH * i);

            estimateValue[j] = estimate(&bucketList[j], RECORD_LENGTH * (i + 1));
        }

        int estimateIntegerSum = 0;

        for (int j = 0; j < NUM_BITS_OF_INTEGER; j++) {
            estimateIntegerSum += estimateValue[j] * pow(2, j);
        }

        truthValue = truth(integerDataFileName, RECORD_LENGTH * (i + 1));

        if (PRINT_ESTIMATE_AND_TRUTH) {
            cout << "Timestamp = " << RECORD_LENGTH * (i + 1) << endl;
            cout << "\testimate: " << estimateIntegerSum << endl;
            cout << "\ttruth: " << truthValue << endl;
            cout << endl;
        }
        
    }

    
}
