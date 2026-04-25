#ifndef MIN_MERGE_COST_HPP
#define MIN_MERGE_COST_HPP

#include <vector>
#include <queue>
#include <functional>

inline int min_merge_cost(const std::vector<int>& files) {
    if (files.size() <= 1) {
        return 0;
    }

    std::priority_queue<int, std::vector<int>,  std::greater<int>> min_heap(files.begin(), files.end());

    int total_cost =0;

    while (min_heap.size() > 1) {
        int first_smallest = min_heap.top();
       min_heap.pop();
        
        int second_smallest = min_heap.top();
        min_heap.pop();

        int merge_cost = first_smallest + second_smallest;
        total_cost += merge_cost ;

        min_heap.push(merge_cost);
    }

    return total_cost;
}
#endif 


