//https://contest.yandex.ru/contest/29188/problems/D/

#include "funcs.h"
#include <bits/stdc++.h>

/*! @brief First argument, that returns true for given func
 *
 * @tparam Func function polong longer, lambda, on given vector should have
 * that form: "___---"
 * @param func function polong longer, lambda, that should accept long long as input
 * @param left Left limit
 * @param right Right limit
 * @param tol Tolerance
 * @return value
 */
template<typename Func>
long long indexOfFirst(Func func, long long left, long long right){
    while (left<right){
        long long middle = (left+right)/2;
        if(func(middle)){
            right = middle;
        } else {
            left = middle+1;
        }
    }
    return left;
}

template<typename Func>
void findRange(Func func, long long & left, long long & right){
    bool vLeft, vRight;
    long long steps = 10;
    while ((steps-->0)&&
           (vLeft = func(left))==(vRight = func(right))
            ){
        if(vLeft)
            left = 0;
        if(!vRight)
            right*=2;
    }
}

void parseFile(std::istream & input, std::ostream & output){
    long long perf1, rest1, perf2, rest2, trees;
    input>>perf1>> rest1>> perf2>> rest2>> trees;

    long long left = trees/(perf1+perf2)-1;
    long long right = 2*trees/(perf1+perf2)+1;

    auto func=[&rest1, &perf1, &rest2, &perf2, &trees]
            (long long days){
        return (days-days/rest1)*perf1 + (days-days/rest2)*perf2 >= trees;
    };

    findRange(func,left,right);

    if(func(left)==func(right)){
        return;
    }

    long long ans = indexOfFirst(func,left,right);

    output<<ans<<'\n';
}
