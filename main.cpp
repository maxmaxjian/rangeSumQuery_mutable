#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <numeric>
#include <functional>

bool operator==(const std::pair<size_t, size_t> & p1, const std::pair<size_t, size_t> & p2) {
    return p1.first == p2.first && p1.second == p2.second;
}

class PairHasher {
  public:
    size_t operator()(const std::pair<size_t, size_t> & p) const {
        return std::hash<long>()(long(p.first))^std::hash<long>()(long(p.second));
    }
};

class NumArray {
  public:
    NumArray(const std::vector<int> & nums) {
        myArray = nums;
    }

    int sumRange(size_t i, size_t j) {
        std::pair<size_t, size_t> p = std::make_pair(i,j);
        if (results.find(p) == results.end()) {
            std::cout << "pair(" << p.first << "," << p.second << ") does not exist!" << std::endl;
            results[p] = sumRange_impl(i,j);
        }
        return results[p];
    }

    int sumRange_impl(size_t i, size_t j) {
        return std::accumulate(myArray.begin()+i, myArray.begin()+j+1, 0);
    }

  private:
    std::vector<int> myArray;
    std::unordered_map<std::pair<size_t, size_t>, int, PairHasher> results;
};

int main() {
    std::vector<int> nums{-2,0,3,-5,2,-1};
    NumArray numArr(nums);
    std::cout << "numArr.sumRange(0,2) = " << numArr.sumRange(0,2) << std::endl;
    std::cout << "numArr.sumRange(2,5) = " << numArr.sumRange(2,5) << std::endl;
    std::cout << "numArr.sumRange(0,5) = " << numArr.sumRange(0,5) << std::endl;
    std::cout << "numArr.sumRange(0,2) = " << numArr.sumRange(0,2) << std::endl;
    std::cout << "numArr.sumRange(2,5) = " << numArr.sumRange(2,5) << std::endl;
    std::cout << "numArr.sumRange(0,5) = " << numArr.sumRange(0,5) << std::endl;

    return 0;
}
