//
//  main.cpp
//  MaxIncreasingSubsequence
//
//  Created by adeeb mohammed on 22/09/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <climits>

// time complexity is o(n ^ 2)
// space complexity is o(n)

std::vector<std::vector<int>> buildSequence(std::vector<int> array,
                                            std::vector<int> sequences,
                                            int currentIdx,
                                            int maxSum){
    std::vector<std::vector<int>> sequence{{},{}};
    sequence[0].push_back(maxSum);
    while (currentIdx != INT_MIN) {
        sequence[1].insert(sequence[1].begin(), array[currentIdx]);
        currentIdx = sequences[currentIdx];
    }
    return sequence;
}

std::vector<std::vector<int>> maxSumIncreasingSubsequence(std::vector<int> array) {
    // array for storing the sum of numbers
    std::vector<int> maxSums = array;
    // array for sequence to find out the indices which forms the max sequence.
    std::vector<int> sequences(array.size(),INT_MIN);
    
    int maxSumsIdx = 0;
    
    for (int i = 0; i < array.size(); i++) {
        // the current number upto which we are checking for the maximum sum upto that limit
        int currentNum = array[i];
        for (int j = 0; j < i; j ++) {
            // each number has to be taken upto current number for building the increasing subsequence
            int otherNum = array[j];
            if (currentNum > otherNum && maxSums[j] + currentNum >= maxSums[i]) {
                maxSums[i] = maxSums[j] + currentNum;
                sequences[i] = j;
            }
        }
        if (maxSums[i] > maxSums[maxSumsIdx]) {
            maxSumsIdx = i;
        }
    }
    
    return buildSequence(array, sequences, maxSumsIdx, maxSums[maxSumsIdx]);
}

int main(int argc, const char * argv[]) {
    std::cout << "Max Increasing Subsequence" << std::endl;
    return 0;
}
