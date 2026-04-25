#ifndef SORT_SQN_HPP
#define SORT_SQN_HPP

#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>

inline std::vector<int> top_sqrtN_sorted(const std::vector<int>& v) {
    if (v.empty()) {
        return {};
    }

    int n = v.size();
    int k = static_cast<int>(std::ceil(std::sqrt(n)));

    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    for (int num :  v) {
        if ( min_heap.size()  < k) {

            min_heap.push(num);
        } else if (num > min_heap.top()) {
             min_heap.pop();
              min_heap.push(num);
        }
    }

    std::vector<int> result;
    result.reserve(k); 
    
    while (!min_heap.empty() ) 
     {
        result.push_back(min_heap.top( ));
        min_heap.pop( );
    }

    std::reverse(result.begin(), result.end());
    return result;
}

#endif 