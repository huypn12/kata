#define USE_MEDIAN_OF_MEDIAN 0
#define USE_QUICK_SELECT 1
#define USE_HEAP_SELECT 2
#define USE_FLOYD_RIVEST 3

extern int MedianOfMedian(int *A, int l, int r, int k);
extern int QuickSelect(int *A, int l, int r, int k);
extern int HeapSelect(int *A, int l, int r, int k);
extern int FloydRivest(int *A, int l, int r, int k);

int (*GetKthSelectImpl(int alg))(int*, int, int, int)
{
    switch (alg) {
    case USE_MEDIAN_OF_MEDIAN:
      return MedianOfMedian;
    case USE_QUICK_SELECT:
        return QuickSelect;
    }
}
