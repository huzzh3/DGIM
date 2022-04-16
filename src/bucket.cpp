#include "../include/bucket.h"

Bucket::Bucket() {
    timeStamp  = -1;
    size       = -1;
    nextBucket = nullptr;
    prevBucket = nullptr;
}

Bucket::~Bucket() {
    nextBucket = nullptr;
    prevBucket = nullptr;
}

void Bucket::setTimeStamp(int timeStampIn) {
    timeStamp = timeStampIn;
}

int Bucket::getTimeStamp() {
    return timeStamp;
}

void Bucket::setSize(int sizeIn) {
    size = sizeIn;
}

int  Bucket::getSize() {
    return size;
}

void Bucket::setNextBucket(Bucket *nextBucketIn) {
    nextBucket = nextBucketIn;
}

Bucket* Bucket::getNextBucket() {
    return nextBucket;
}

void Bucket::setPrevBucket(Bucket *prevBucketIn) {
    prevBucket = prevBucketIn;
}

Bucket* Bucket::getPrevBucket() {
    return prevBucket;
}