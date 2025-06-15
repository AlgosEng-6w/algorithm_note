#include<iostream>
#include<vector>
using namespace std;

// 二分法的前提：1. 有序 2. 无重复元素

// 法一：左闭右闭
int insert(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size();
    while(right >= left){
        int middle = (left + right)/2;
        if (nums[middle] == target) return middle;
        else if (nums[middle] < target) left = middle+1;
        else right = middle-1;
    }
    return -1;
}

// 法二：左闭右开
int insert_1(vector<int>& nums, int target){
    int left = 0;
    int right = nums.size();
    while (left < right){
        int middle = (left + right)/2;
        if (nums[middle] == target) return middle;
        else if (nums[middle] < target) left = middle+1;
        else right = middle;
    }
    return -1;
}