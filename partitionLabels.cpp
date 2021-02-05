// partitionLabels.cpp
// https://leetcode.com/problems/partition-labels/

/**
 * A string S of lowercase English letters is given.
 * We want to partition this string into as many parts
 * as possible so that each letter appears in at most
 * one part, and return a list of integers representing
 * the size of these parts.
 * 
 * Example 1:
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 */

 /**
Inputs: lowercase letters
Outputs: list of integers
Constraints: at least one letter, O(n) time O(1) space
Edge Cases: "a", "aaa", "abc"
 */

// 012345678901234567890123
// ababcbacadefegdehijhklij

// a: 0, 8
// b: 1, 5
// c: 4, 7
// d: 9, 14
// e: 10, 15
// f: 11, 11
// g: 13, 13
// h: 16, 19
// i: 17, 22
// j: 18, 23
// k: 20, 20

// Current parition: 0, 8
 
// 
// a0 > 8
// b1 > 5
// a2, is m[a] > curr part max? then it's seen/ we dont care. not 8, skip
// b3, seen not 8, skip
// c4 > 7, not 8, continue
// b5, seen, not 8, skip
// a6, seen, not 8, skip
// c7, seen, not 8, skip
// a8, this is the end of this partition. push 8-0+1 to results[]
// d9. This is a new parition. [9, 14].

// https://en.cppreference.com/w/cpp/container/map

#include <map>

class Solution {
public:
    vector<int> partitionLabels(string S) {
        //create a map <char,index>
        //create part var
        //loop through whole string
        //if index = current part
        //  push to results
        //if index > current partition
        //  initiate the partition current index to map(current index)
        //if is greater, set part to map(cur index)
        //return results
        vector<int> results;
        if(S.size() == 1) {
            results.push_back(1);
            return results;
        }
        map<char,int> last;
        for(int i = 0;i < S.size();i++) {
            last[S.at(i)] = i;
        }
        if(last.size() == 1) {
            results.push_back(last[S.at(0)] + 1);
            return results;
        }
        int start = 0;
        int part = last[S.at(0)];
        for(int i = 0;i < S.size();i++) {
            if(i == part) {
                results.push_back(part-start+1);
                if(i+1 < S.size()) {
                    start = i + 1;
                    part = last[S.at(start)];
                }
            }
            if(last[S.at(i)] > part) {
                part = last[S.at(i)];
            }
        }
        return results;
    }
};

// "ababcbacadefegdehijhklij"
// "a"
// "abc"
// "aaa"
// "aaba"