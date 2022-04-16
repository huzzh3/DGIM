#include "../include/estimateAndTruth.h"

bool testEstimate() {
    string dataFileName = "Binary_" + to_string(STREAM_LENGTH) + ".dat";

    BucketList bucketList;
    bucketList.openDataFile(dataFileName);
    bucketList.readFileAndUpdateBucketList(0);

    cout << "estimate: " << estimate(&bucketList, STREAM_LENGTH) << endl;

    return true;
}

bool testTruth() {
    string dataFileName = "Binary_" + to_string(STREAM_LENGTH) + ".dat";

    cout << "truth: " << truth(dataFileName, STREAM_LENGTH) << endl;

    return true;
}

int main() {
    testEstimate();
    testTruth();
}