#include <limits>
#include <map>

#include <iostream>

template<typename K, typename V>
class interval_map
{
    std::map<K, V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map(V const &val)
    {
        m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign(K const &keyBegin, K const &keyEnd, V const &val)
    {
        if (!(keyBegin < keyEnd)) {
            return;
        }

        auto beginItr = m_map.find(keyBegin);
        auto predBeginItr = --m_map.upper_bound(keyBegin);
        auto nextBeginItr = m_map.upper_bound(keyBegin);
        
        auto endItr = m_map.find(keyEnd);
        auto predEndItr = --m_map.upper_bound(keyEnd);
        auto nextEndItr = m_map.upper_bound(keyEnd);

        // What happens when an interval is inserted
        // Case 1a
        // Former: ...|----------|-----...-----|----------...
        // Alter : ...|----------p-----...-----n----------...
        // Later : ...|----------b-----...-----e----------...
        // Case 1b
        // Former: ...|----------|--...--------|----------...
        // Alter : ...|----------p--...---n----|----------...
        // Later : ...|----------b--...---e----|----------...
        if (beginItr != m_map.end()) {
            auto orig_val = beginItr->second;
            m_map.at(keyBegin) = val;
            if (endItr != m_map.end()) {
                m_map.erase(nextBeginItr, endItr);
            } else {
                m_map.erase(nextBeginItr, nextEndItr);
                m_map.insert(m_map.end(), std::make_pair(keyEnd, orig_val));
            }
        }
        // Case 2a
        // Former: ...|----------|----------|----------...
        // Alter : ...|----------|-----p----n----------...
        // Later : ...|----------|-----b----e----------...
        // Case 2b
        // Former: ...|----------|----------|----------...
        // Alter : ...|----------|--p-------*-n--------...
        // Later : ...|----------|--b---------e--------...
        else {
            auto orig_val = predEndItr->second;
            // m_map.at(keyBegin) = val;
            m_map.insert(m_map.end(), std::make_pair(keyBegin, val));
            if (endItr != m_map.end()) {
                m_map.erase(nextBeginItr, endItr);
            } else {
                m_map.erase(nextBeginItr, nextEndItr);
            }
            // m_map.at(keyEnd) = orig_val;
            m_map.insert(m_map.end(), std::make_pair(keyEnd, orig_val));
        }
    }

    // look-up of the value associated with key
    V const &operator[](K const &key) const { return (--m_map.upper_bound(key))->second; }
};


class interval_map_test
{
private:
    interval_map<unsigned int, char> m_imap;

protected:
    void setup()
    {
        m_imap.assign(0, 3, 'A');
        m_imap.assign(3, 5, 'B');
        m_imap.assign(5, 8, 'A');
    }
    void clear() { m_imap = interval_map<unsigned int, char>('X'); }

    void test_0() {
        std::cout << "Test 0" << std::endl;
        setup();
        for (int i = 0; i < 10; ++i) {
            std::cout << "(" << i << ", " << m_imap[i] << ")" << std::endl;
        }
        clear();
    }

    void test_1a() {
        std::cout << "Test 1a" << std::endl;
        setup();
        m_imap.assign(0, 3, 'C');
        for (int i = 0; i < 10; ++i) {
            std::cout << "(" << i << ", " << m_imap[i] << ")" << std::endl;
        }
        clear();
    }

    void test_1b() {
        std::cout << "Test 1b" << std::endl;
        setup();
        m_imap.assign(0, 2, 'C');
        for (int i = 0; i < 10; ++i) {
            std::cout << "(" << i << ", " << m_imap[i] << ")" << std::endl;
        }
        clear();
    }

    void test_2a() {
        std::cout << "Test 2a" << std::endl;
        setup();
        m_imap.assign(1, 3, 'C');
        for (int i = 0; i < 10; ++i) {
            std::cout << "(" << i << ", " << m_imap[i] << ")" << std::endl;
        }
        clear();
    }

    void test_2b() {
        std::cout << "Test 2b" << std::endl;
        setup();
        m_imap.assign(1, 6, 'C');
        for (int i = 0; i < 10; ++i) {
            std::cout << "(" << i << ", " << m_imap[i] << ")" << std::endl;
        }
    }

public:
    interval_map_test(): m_imap('X') {

    }
    ~interval_map_test() {

    }

    void test_all_cases() {
        test_0();
        test_1a();
        test_1b();
        test_2a();
        test_2b();
    }

    void run() {
        test_all_cases();
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.

int main()
{
    interval_map_test test;
    test.run();
    return 0;
}