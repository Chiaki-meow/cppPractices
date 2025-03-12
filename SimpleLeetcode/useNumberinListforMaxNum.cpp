//
// Created by Chiaki_meow on 2025/3/3.
//

//

#include <iostream>

auto maxNum = [](int num, std::vector<int>& options){
    std::vector<int> digits;
    for(; num > 0; num /= 10){
        digits.push_back(num % 10);
    }
    int n = digits.size(), num_options = options.size();
    std::reverse(digits.begin(), digits.end());
    std::sort(options.begin(), options.end());
    auto dfs = [&](auto&& dfs, int i, int cur, bool pre, bool high) -> int {
        if(i == n){
            return cur;
        }
        cur *= 10;
        for(int j = num_options - 1; j >= 0; j--){
            if(high && (options[j] > digits[i])){
                continue;
            }
            int test = dfs(dfs, i + 1, cur + options[j], pre && (options[j] == 0), high && (options[j] == digits[i]));
            if(test >= 0){
                return test;
            }
        }
        if(pre && i < n - 1){
            int test = dfs(dfs, i + 1, cur, pre, false);
            if(test >= 0){
                return test;
            }
        }
        return -1;
    };
    return dfs(dfs, 0, 0, true, true);
};