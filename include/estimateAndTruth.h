#ifndef ESTIMATE_AND_TRUTH_H
#define ESTIMATE_AND_TRUTH_H

#include "../include/bucketList.h"

int estimate(BucketList *bucketList, int curTimestamp);

int truth(string fileName, int curTimestamp);

#endif