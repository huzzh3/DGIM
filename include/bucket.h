#ifndef BUCKET_H
#define BUCKET_H

class Bucket {
private:
    int timeStamp;
    int size;            // The number of digits one

    Bucket *nextBucket;  // Point to the next Bucket
    Bucket *prevBucket;  // Point to the previous Bucket
public:
    Bucket();
    ~Bucket();
    
    void setTimeStamp(int timeStampIn);
    int  getTimeStamp();

    void setSize(int sizeIn);
    int  getSize();

    void setNextBucket(Bucket* nextBucketIn);
    Bucket* getNextBucket();

    void setPrevBucket(Bucket* prevBucketIn);
    Bucket* getPrevBucket();
};



#endif