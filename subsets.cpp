{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf200
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution \{\
public:\
    vector<vector<int>> subsets(vector<int>& nums) \{\
        \
    //     vector< vector<int> > sort;\
    //     vector<int> elem;\
    //     rec(sort, elem, nums, 0, nums.size(), false);\
    //     cout<<sort.size()<<endl;\
    // //    for(int i = 0; i < sort.size(); i++)\
    // //    \{\
    // //        for(int j = 0; j < sort[i].size(); j++)\
    // //        \{\
    // //            cout << sort[i][j] << ", ";\
    // //        \}\
    // //        cout << endl;\
    // //    \}\
    //     return sort;\
        \
        \
        \
        \
                vector<vector<int> > result(1, vector<int>()); \
        \
        cout << "--> " << result.size() << endl;\
        //Iterating one by one through the set of which we need to find the subsets of\
        for(int i = 0; i < nums.size(); i++) \
        \{\
            int n = result.size(); //Taking the original size of the subset\
            for(int j = 0; j < n; j++) \
            \{ \
                result.push_back(result[j]); //Now adding those elements back again \
                result.back().push_back(nums[i]); //Now taking the last element and adding the new element to it\
            \}\
        \}\
        \
        return result;\
//         int sz = nums.size();\
//         int i = pow(2, sz);\
        \
//         int j = 0;\
    \
//         vector<int> elem;\
//         int count = 0;\
        \
\
//         int n = 3;\
//         int r = 2;\
        \
    \
\
//     \}\
    \
//     void fr(int n, int r)\
//     \{\
//         int i, j = i+1;\
//         for(; i < r; i++)\
//         \{\
//             elem.push_back(nums[i]);\
//             f3_1(n, r);\
//             i--;\
//         \}\
//     \}\
    \
//     void f3_1(int n, int r)\
//     \{\
//             for(; j < n; j++)\
//             \{\
//                 elem.push_back(nums[j]);\
//                 if(j == n-1)\
//                     i++;\
//                     j=i+1;\
//                 else\
//                     subset.push_back(elem);\
//                     break;\
//             \}\
//     \}\
        \
    \}\
    \
void rec(vector< vector<int> > &sort, vector<int> elem, const vector<int> &nums, int i, int sz, bool k)\
\{\
    if(i == sz)\
    \{\
        sort.push_back(elem);\
        for(int j = 0; j < elem.size(); j++)\
        \{\
            cout << elem[j] << ", ";\
        \}\
        cout << endl;\
\
        return;\
    \}\
\
    \
    rec(sort, elem, nums, i+1, sz, false);\
    elem.push_back(nums[i]);\
    rec(sort, elem, nums, i+1, sz, true);\
\
\}\
\};}