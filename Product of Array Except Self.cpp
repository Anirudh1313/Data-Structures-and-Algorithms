{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf200
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution \{\
public:\
    vector<int> productExceptSelf(vector<int>& nums) \{\
        \
        \
        //store forward product while storing in a container and backward product in a container\
        \
        int sz = nums.size();\
        vector<int> kf;\
        \
        kf.push_back(nums[0]);\
        for(int i = 1; i < sz; i++)\
        \{\
            kf.push_back(nums[i]*kf[i-1]);\
        \}\
        \
        vector<int> kb(sz, 1);\
        kb[sz-1] = nums[sz-1];\
        for(int i = sz-2; i >= 0; i--)\
        \{\
            kb[i] = (nums[i]*kb[i+1]);\
        \}\
        \
        vector<int> res;\
        res.push_back(kb[1]);\
        for(int i = 1; i < sz-1; i++)\
        \{\
            res.push_back(kf[i-1]*kb[i+1]);\
        \}\
        res.push_back(kf[sz-2]);\
        \
        return res;\
    \}\
\};}