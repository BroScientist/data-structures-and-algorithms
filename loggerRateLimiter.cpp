#include <iostream>
#inclue <string>
#include <map>

class Logger {
public:
    map<string, int> hashtable;

    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        // if message has not appeared before OR the last instance of that message occured 10 or more timestamps ago
        // update the hashtable and return true
        if (hashtable.find(message) == hashtable.end() || timestamp >= hashtable[message] + 10)
        {
            hashtable[message] = timestamp;
            return true;
        }
        // else return false
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */