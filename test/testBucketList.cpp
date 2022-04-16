#include "../include/bucketList.h"

bool testPrintBucketList() {
    BucketList bucketList;
    bucketList.printBucketList();

    Bucket *bucket1;
    Bucket *bucket2;

    bucket1 = new Bucket();
    bucket2 = new Bucket();

    bucket1->setTimeStamp(1);
    bucket1->setSize(1);
    bucket2->setTimeStamp(3);
    bucket2->setSize(1);
    
    bucketList.setBucketListHead(bucket1);
    bucketList.setBucketListTail(bucket1);

    bucketList.printBucketList();

    bucket1->setNextBucket(bucket2);
    bucket2->setPrevBucket(bucket2);
    bucketList.setBucketListTail(bucket2);

    bucketList.printBucketList();

    return true;
}

bool testReadFileAndUpdateBucketList() {
    string dataFileName = "Binary_" + to_string(STREAM_LENGTH) + ".dat";

    BucketList bucketList;
    bucketList.openDataFile(dataFileName);
    bucketList.readFileAndUpdateBucketList(0);
    bucketList.printBucketList();

    return true;
}

int main() {
    if (testPrintBucketList()) {
        cout << "printBucketList passed" << endl;
    }
    else {
        cout << "printBucketList failed" << endl;
    }

    if (testReadFileAndUpdateBucketList()) {
        cout << "readFileAndUpdateBucketList passed" << endl;
    }
    else {
        cout << "readFileAndUpdateBucketList failed" << endl;
    }
}