#include "../include/bucketList.h"

BucketList::BucketList() {
    bucketListHead = nullptr;
    bucketListTail = nullptr;
}

BucketList::~BucketList() {
    dataFileIn.close();

    if (bucketListHead != nullptr || bucketListTail != nullptr) {
        Bucket *searchptr1 = nullptr;
        Bucket *searchptr2 = bucketListHead;

        while (searchptr2 != nullptr) {
            searchptr1 = searchptr2;
            searchptr2 = searchptr2->getNextBucket();
            delete searchptr1;
        }

        bucketListHead = nullptr;
        bucketListTail = nullptr;
    }
}

void BucketList::setBucketListHead(Bucket *bucketIn) {
    bucketListHead = bucketIn;
}

Bucket* BucketList::getBucketListHead() {
    return bucketListHead;
}

void BucketList::setBucketListTail(Bucket *bucketIn) {
    bucketListTail = bucketIn;
}

Bucket* BucketList::getBucketListTail() {
    return bucketListTail;
}

void BucketList::openDataFile(string dataFileName) {
    string dataFilepath =  DATA_LOCATION + dataFileName;

    dataFileIn.open(dataFilepath, ios::in);
}

void BucketList::readFileAndUpdateBucketList(int beginTimestamp) {
    string singleDataString;
    int    singleData;

    if (WINDOW_SIZE > STREAM_LENGTH) {
        cout << "err: window size is larger than stream length" << endl;
        return;
    }

    for (int i = 1; i <= RECORD_LENGTH; i++) {
        dataFileIn >> singleDataString;

        singleData = stoi(singleDataString);

        // Detele the bucket which is out-of-date if necessary
        deleteBucket(i + beginTimestamp);

        if (singleData == 1) {
            // Create new bucket
            Bucket *newBucket = new Bucket();

            newBucket->setTimeStamp(i + beginTimestamp);
            newBucket->setSize(1);

            if (bucketListHead == nullptr && bucketListTail == nullptr) {
                bucketListHead = newBucket;
                bucketListTail = newBucket;
            }
            else {
                bucketListTail->setNextBucket(newBucket);
                newBucket->setPrevBucket(bucketListTail);
                bucketListTail = newBucket;
            }

            // Merge the bucket if neccessary
            mergeBucket(newBucket);
        }

        if (PRINT_BUCKET_LIST) {
            if (i + beginTimestamp == WINDOW_SIZE || i + beginTimestamp == STREAM_LENGTH / 2 || i + beginTimestamp == STREAM_LENGTH) {
                printBucketList();
                cout << endl;
            }
        }
    }
}

void BucketList::mergeBucket(Bucket *curBucket) {
    if (curBucket->getPrevBucket() == nullptr || curBucket->getPrevBucket()->getSize() != curBucket->getSize()) {
        return;
    }
    
    // 'bucketTemp' may need to merge
    Bucket *bucketTemp = curBucket->getPrevBucket();
    Bucket *bucketTempPrev = bucketTemp->getPrevBucket();

    if (bucketTemp == nullptr || bucketTempPrev == nullptr) {
        return;
    }

    while (bucketTemp != nullptr && bucketTempPrev != nullptr && bucketTemp->getSize() == bucketTempPrev->getSize()) {
        bucketTemp->setSize(2 * bucketTemp->getSize());
        
        if (bucketTempPrev->getPrevBucket() != nullptr) {
            bucketTemp->setPrevBucket(bucketTempPrev->getPrevBucket());
            bucketTempPrev->getPrevBucket()->setNextBucket(bucketTemp);
        }
        else {
            bucketListHead = bucketTemp;
            bucketTemp->setPrevBucket(nullptr);
        }

        delete bucketTempPrev;

        bucketTemp = bucketTemp->getPrevBucket();

        if (bucketTemp != nullptr) {
            bucketTempPrev = bucketTemp->getPrevBucket();
        }
    }
}

void BucketList::deleteBucket(int curTimeStamp) {
    if (curTimeStamp <= WINDOW_SIZE) {
        return;
    }

    if (bucketListHead->getTimeStamp() <= curTimeStamp - WINDOW_SIZE) {
        Bucket *bucketTemp = bucketListHead;
        bucketListHead = bucketListHead->getNextBucket();
        bucketListHead->setPrevBucket(nullptr);

        delete bucketTemp;
    }
}

void BucketList::printBucketList() {
    if (bucketListHead == nullptr && bucketListTail == nullptr) {
        cout << "bucket list is empty" << endl;

        return;
    }

    Bucket *searchptr = bucketListHead;

    while (searchptr != nullptr) {
        cout << "(" << searchptr->getTimeStamp() << "," << searchptr->getSize() << ")"  << "->";
        searchptr = searchptr->getNextBucket();
    }

    cout << "null" << endl;
}