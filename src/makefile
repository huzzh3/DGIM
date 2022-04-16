IDIR = ../include
TDIR = ../test
BDIR = ../bin
DDIR = ../data
CC = g++
CFLAGS = -I$(IDIR)
DEPS = $(IDIR)/*.h

all : main.o estimateAndTruth.o generateStream.o bucketList.o bucket.o
	$(CC) -o $(BDIR)/DGIM $(addprefix $(BDIR)/, $^) && ./$(BDIR)/DGIM

main.o : main.cpp $(IDIR)/estimateAndTruth.h $(IDIR)/generateStream.h $(IDIR)/bucketList.h
	$(CC) -c -o $(BDIR)/$@ $< $(CFLAGS)

# Test for 'generate stream'

testGenerateStream : testGenerateStream.o generateStream.o
	$(CC) -o $(BDIR)/$@ $(addprefix $(BDIR)/, $^) $(CFLAGS) && ./$(BDIR)/$@

testGenerateStream.o : $(TDIR)/testGenerateStream.cpp $(IDIR)/generateStream.h $(IDIR)/def.h 
	$(CC) -c -o $(BDIR)/$@ $< $(CFLAGS)

generateStream.o : generateStream.cpp $(IDIR)/generateStream.h $(IDIR)/def.h 
	$(CC) -c -o $(BDIR)/$@ $< $(CFLAGS)

# Test for 'bucketlist'

testBucketList : testBucketList.o bucketList.o bucket.o
	$(CC) -o $(BDIR)/$@ $(addprefix $(BDIR)/, $^) $(CFLAGS) && ./$(BDIR)/$@

testBucketList.o : $(TDIR)/testBucketList.cpp $(IDIR)/bucketList.h
	$(CC) -c -o $(BDIR)/$@ $< $(CFLAGS)

bucketList.o : bucketList.cpp $(IDIR)/bucketList.h
	$(CC) -c -o $(BDIR)/$@ $< $(CFLAGS)

bucket.o : bucket.cpp $(IDIR)/bucket.h
	$(CC) -c -o $(BDIR)/$@ $< $(CFLAGS)

# Test for 'estimateAndTruth'

testEstimateAndTruth : testEstimateAndTruth.o estimateAndTruth.o bucketList.o bucket.o
	$(CC) -o $(BDIR)/$@ $(addprefix $(BDIR)/, $^) $(CFLAGS) && ./$(BDIR)/$@

testEstimateAndTruth.o :  $(TDIR)/testEstimateAndTruth.cpp $(IDIR)/estimateAndTruth.h
	$(CC) -c -o $(BDIR)/$@ $< $(CFLAGS)

estimateAndTruth.o : estimateAndTruth.cpp $(IDIR)/estimateAndTruth.h
	$(CC) -c -o $(BDIR)/$@ $< $(CFLAGS)

# Clean

.PHONY : clean cleanData
clean :
	rm -rf $(BDIR)/*.o 
cleanData :
	rm -rf $(DDIR)/*.dat