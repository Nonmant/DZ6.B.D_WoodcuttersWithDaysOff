//https://contest.yandex.ru/contest/29188/problems/

#include "funcs.h"
#include <bits/stdc++.h>

/*! @brief First argument, that returns true for given func
 *
 * @tparam Func function pointer, lambda, on given vector should have
 * that form: "___---"
 * @param func function pointer, lambda, that should accept int as input
 * @param left Left limit
 * @param right Right limit
 * @param tol Tolerance
 * @return value
 */
template<typename Func>
int indexOfFirst(Func func, int left, int right){
    while (left<right){
        int middle = (left+right)/2;
        if(func(middle)){
            right = middle;
        } else {
            left = middle+1;
        }
    }
    return left;
}

template<typename Func>
void findRange(Func func, int & left, int & right){
    bool vLeft, vRight;
    int steps = 10;
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
    int perf1, rest1, perf2, rest2, trees;
    input>>perf1>> rest1>> perf2>> rest2>> trees;

    int left = trees/(perf1+perf2)-1;
    int right = 2*trees/(perf1+perf2)+1;

    auto func=[&rest1, &perf1, &rest2, &perf2, &trees]
            (int days){
        return (days-days/rest1)*perf1 + (days-days/rest2)*perf2 >= trees;
    };

    findRange(func,left,right);

    if(func(left)==func(right)){
        return;
    }

    int ans = indexOfFirst(func,left,right);

    output<<ans<<'\n';
}
