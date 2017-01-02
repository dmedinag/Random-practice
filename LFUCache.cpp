class LFUCache {
    struct CacheElem {
        int key = -1;       // key value
        int value = -1;     // stored value
        uint timesUsed = 0; // counter
        uint indexLRU;      // The higher the more recently used
        CacheElem(uint lru = 0) : indexLRU(lru) {}
    };
    CacheElem *elems;
    int size;
    uint counterLRU = 0;

    void setKey( int key, int value, int index ) {
        elems[index].key = key;
        elems[index].value = value;
        elems[index].indexLRU = ++counterLRU;
        elems[index].timesUsed = 1;
        return;
    }

public:
    LFUCache(int capacity) : size(capacity) {
        // create the cache with undefined content
        // size as specified
        elems = new CacheElem[capacity];
    }

    int get(int key) {

        if(out) cout << setw(3) << op++ << ": GET [" << key << "]:\n";

        // iterate over the items in the cache
        for( uint i = 0; i < size; ++i ) {

            // return the value of the key if found in the cache
            if( elems[i].key == key ) {
                // update metadata for LRU and LFU replacement
                elems[i].indexLRU = ++counterLRU;
                ++elems[i].timesUsed;
                return elems[i].value;
            }
        }

        // Return -1 when value not found
        return -1;
    }

    void set(int key, int value) {

        uint leavingLFU = 0, leavingLRU = 0;
        vector< uint > leavingLFUc;

        // iterate over the items in the cache
        for( uint i = 0; i < size; ++i ) {

            if( elems[i].key == -1 ) { setKey( key, value, i ); return; }
            // update the value for the key if found
            if( elems[i].key == key ) {
                // update metadata for LRU and LFU replacement
                elems[i].value = value;
                elems[i].indexLRU = ++counterLRU;
                ++elems[i].timesUsed;
                return;
            }

            // in case we have to replace it, keep track of item to be replaced!
            if( ! i || elems[leavingLFU].timesUsed > elems[i].timesUsed ) {
                leavingLFU = i;
                leavingLFUc.clear();
            } else if( elems[leavingLFU].timesUsed == elems[i].timesUsed ) {
                if( leavingLFUc.empty() ) {
                    leavingLFUc.push_back( leavingLFU );
                    leavingLRU = leavingLFU;
                }
                leavingLFUc.push_back(i);
                int prev = leavingLRU;
                leavingLRU = *min_element(leavingLFUc.begin(), leavingLFUc.end());
            }
        }

        // REPLACEMENT: when the key is new to the cache, find the element that
        // should leave the cache and replace it by the new one.
        if( leavingLFUc.empty() ) { setKey( key, value, leavingLFU ); return; }

        setKey( key, value, leavingLRU );
    }
};
