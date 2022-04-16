#include "../include/estimateAndTruth.h"

int estimate(BucketList *bucketList, int curTimestamp) {
    int res = 0;
    Bucket *searchptr = bucketList->getBucketListHead();

    while (searchptr->getTimeStamp() < curTimestamp - QUERY_LENGTH + 1) {
        searchptr = searchptr->getNextBucket();
    }

    res += searchptr->getSize() / 2;
    searchptr = searchptr->getNextBucket();

    while (searchptr != nullptr) {
        res += searchptr->getSize();
        searchptr = searchptr->getNextBucket();
    }

    return res;
}

int truth(string fileName, int curTimestamp) {
    string dataFilepath =  DATA_LOCATION + fileName;
    string singleDataString;
    int    singleData;
    ifstream dataFileIn;
    int res = 0;

    dataFileIn.open(dataFilepath, ios::in);

    for (int i = 1; i <= curTimestamp - QUERY_LENGTH; i++) {
        dataFileIn >> singleDataString;
    }

    for (int i = 1; i <= QUERY_LENGTH; i++) {
        dataFileIn >> singleDataString;
        singleData = stoi(singleDataString);

        res += singleData;
    }

    return res;
}