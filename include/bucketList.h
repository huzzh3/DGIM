#ifndef BUCKETLIST_H
#define BUCKETLIST_H

#include "../include/bucket.h"
#include "../include/def.h"
#include <fstream>
#include <iostream>

using namespace std;

class BucketList {
private:
    Bucket *bucketListHead;
    Bucket *bucketListTail;

    ifstream dataFileIn;
public:
    BucketList();
    ~BucketList();

    void setBucketListHead(Bucket *bucketIn);
    Bucket* getBucketListHead();

    void setBucketListTail(Bucket *bucketIn);
    Bucket* getBucketListTail();

    void openDataFile(string dataFileName);
    void readFileAndUpdateBucketList(int startTimestamp);

    void mergeBucket(Bucket *curBucket);
    void deleteBucket(int curTimeStamp);

    void printBucketList();
};

#endif