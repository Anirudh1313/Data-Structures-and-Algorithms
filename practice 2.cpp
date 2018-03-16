{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf200
{\fonttbl\f0\fnil\fcharset0 Monaco;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red0\green80\blue50;\red0\green0\blue192;}
{\*\expandedcolortbl;;\csgenericrgb\c24706\c49804\c37255;\csgenericrgb\c49804\c0\c33333;\csgenericrgb\c16471\c0\c100000;
\csgenericrgb\c0\c31373\c19608;\csgenericrgb\c0\c0\c75294;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs22 \cf2 //============================================================================\cf0 \
\cf2 // Name        : fractions.cpp\cf0 \
\cf2 // Author      : \ul Krishna\ulnone  \ul sai\ulnone  \ul anirudh\cf0 \ulnone \
\cf2 // Version     :\cf0 \
\cf2 // Copyright   : Your copyright notice\cf0 \
\cf2 // Description : Hello World in C++, \ul Ansi\ulnone -style\cf0 \
\cf2 //============================================================================\cf0 \
\
\pard\pardeftab720\partightenfactor0
\cf3 #include\cf0  \cf4 <iostream>\cf0 \
\pard\pardeftab720\partightenfactor0
\cf2 //#include <pair>\cf0 \
\pard\pardeftab720\partightenfactor0
\cf3 #include\cf0  \cf4 <vector>\cf0 \
\cf3 #include\cf0  \cf4 <cmath>\cf0 \
\cf3 #include\cf0  \cf4 <stack>\cf0 \
\cf3 #include\cf0  \cf4 <set>\cf0 \
\
\cf3 using\cf0  \cf3 namespace\cf0  std;\
\
\
\pard\pardeftab720\partightenfactor0
\cf5 string\cf0  reverse_string(\cf5 string\cf0  input);\
\cf5 vector\cf0 <\cf3 int\cf0 > intersect(\cf5 vector\cf0 <\cf3 int\cf0 >& nums1, \cf5 vector\cf0 <\cf3 int\cf0 >& nums2);\
\cf5 string\cf0  addBinary(\cf5 string\cf0  a, \cf5 string\cf0  b);\
\pard\pardeftab720\partightenfactor0
\cf3 bool\cf0  isPalindrome(\cf5 string\cf0  s);\
\cf3 void\cf0  rec(\cf5 vector\cf0  <\cf5 vector\cf0 <\cf3 int\cf0 > > &sort, \cf5 vector\cf0 <\cf3 int\cf0 > elem, \cf3 const\cf0  \cf5 vector\cf0 <\cf3 int\cf0 > &nums, \cf3 int\cf0  i, \cf3 int\cf0  sz, \cf3 bool\cf0  k);\
\pard\pardeftab720\partightenfactor0
\cf5 vector\cf0 < \cf5 vector\cf0 <\cf3 int\cf0 > > subsets(\cf5 vector\cf0 <\cf3 int\cf0 >& nums);\
\
\pard\pardeftab720\partightenfactor0
\cf3 bool\cf0  isValid(\cf5 string\cf0  s);\
\
\
\cf3 struct\cf0  \cf5 Interval\cf0  \{\
    \cf3 int\cf0  \cf6 start\cf0 ;\
    \cf3 int\cf0  \cf6 end\cf0 ;\
    Interval() : \cf6 start\cf0 (0), \cf6 end\cf0 (0) \{\}\
    Interval(\cf3 int\cf0  s, \cf3 int\cf0  e) : \cf6 start\cf0 (s), \cf6 end\cf0 (e) \{\}\
\};\
\
\pard\pardeftab720\partightenfactor0
\cf5 vector\cf0 <\cf5 Interval\cf0 > merge(\cf5 vector\cf0 <\cf5 Interval\cf0 >& intervals);\
\
\pard\pardeftab720\partightenfactor0
\cf3 class\cf0  \cf5 Solution\cf0 \
\
\{\
\cf3 public\cf0 :\
    \cf5 vector\cf0 <\cf3 int\cf0 > kthSmallestPrimeFraction(\cf5 vector\cf0 <\cf3 int\cf0 >& A, \cf3 int\cf0  K)\
    \{\
    	\cf5 vector\cf0 < \cf5 pair\cf0 <\cf3 int\cf0 , \cf3 int\cf0 > > fractions;\
        \cf3 int\cf0  count = 0;\
        \cf3 for\cf0 (\cf3 int\cf0  i = A.size()-1; i > 0; i--)\
        \{\
            \cf3 for\cf0 (\cf3 int\cf0  j = 0; j < i; j++)\
            \{\
                count++;\
                fractions.push_back(make_pair(A[j],A[i]));\
\
            \}\
\
        \}\
\
        quick_sort(fractions, 0, fractions.size()-1);\
        \cf5 vector\cf0 <\cf3 int\cf0 > result;\
        result.push_back(fractions[K].\cf6 first\cf0 );\
        result.push_back(fractions[K].\cf6 second\cf0 );\
\
        \cf3 return\cf0  result;\
    \}\
\
\
    \cf3 void\cf0  quick_sort(\cf5 vector\cf0 < \cf5 pair\cf0 <\cf3 int\cf0 , \cf3 int\cf0 > >& fractions, \cf3 int\cf0  left, \cf3 int\cf0  right)\
    \ul \{\ulnone \
        \cf3 int\cf0  pivot = choose_pivot(fractions, left, right);\
        \cf3 int\cf0  part = partition(fractions, left, right, pivot);\
        quick_sort(fractions, left, part-1);\
        quick_sort(fractions, part+1, right);\
\
    \}\
\
    \cf3 int\cf0  partition(\cf5 vector\cf0 < \cf5 pair\cf0 <\cf3 int\cf0 , \cf3 int\cf0 > >& fractions, \cf3 int\cf0  left, \cf3 int\cf0  right, \cf3 int\cf0  pivot)\
    \{\
        \cf3 int\cf0  i = left;\
        \cf3 int\cf0  j = right;\
\
        \cf3 while\cf0 (i < j)\
        \{\
            \cf3 while\cf0 (fractions[i].\cf6 first\cf0 /fractions[i].\cf6 second\cf0  < fractions[pivot].\cf6 first\cf0 /fractions[pivot].\cf6 second\cf0  && i < right-1)\
            \{\
                i++;\
            \}\
\
            \cf3 while\cf0 (fractions[j].\cf6 first\cf0 /fractions[j].\cf6 second\cf0  > fractions[pivot].\cf6 first\cf0 /fractions[j].\cf6 second\cf0  && j > left)\
            \{\
                j--;\
            \}\
\
            swap(fractions, i, j);\
        \}\
        swap(fractions, i, right);\
\
        \cf3 return\cf0  i;\
    \}\
\
    \cf3 int\cf0  choose_pivot(\cf5 vector\cf0 < \cf5 pair\cf0 <\cf3 int\cf0 , \cf3 int\cf0 > >& fractions, \cf3 int\cf0  left, \cf3 int\cf0  right)\
    \{\
        \cf3 int\cf0  center = (left+right)/2;\
        \cf3 if\cf0 (fractions[center].\cf6 first\cf0 /fractions[center].\cf6 second\cf0  < fractions[left].\cf6 first\cf0 /fractions[left].\cf6 second\cf0 )  \{swap(fractions, center, left);\}\
        \cf3 if\cf0 (fractions[left].\cf6 first\cf0 /fractions[left].\cf6 second\cf0  < fractions[right].\cf6 first\cf0 /fractions[right].\cf6 second\cf0 )  \{swap(fractions, right, left);\}\
        \cf3 if\cf0 (fractions[right].\cf6 first\cf0 /fractions[right].\cf6 second\cf0  < fractions[center].\cf6 first\cf0 /fractions[center].\cf6 second\cf0 )  \{swap(fractions, center, right);\}\
\
        \cf3 return\cf0  center;\
    \}\
\
    \cf3 void\cf0  swap(\cf5 vector\cf0 < \cf5 pair\cf0 <\cf3 int\cf0 , \cf3 int\cf0 > >& fractions, \cf3 int\cf0  i, \cf3 int\cf0  j)\
    \{\
        \cf5 pair\cf0 <\cf3 int\cf0 , \cf3 int\cf0 > temp = fractions[i];\
        fractions[i] = fractions[j];\
        fractions[j] = temp;\
    \}\
\
\cf3 private\cf0 :\
    \cf2 //vector< pair<int, \ul int\ulnone > > fractions;\cf0 \
\
\};\
\
\cf3 int\cf0  reverse(\cf3 int\cf0  x);\
\
\cf3 double\cf0  findMedianSortedArrays(\cf5 vector\cf0 <\cf3 int\cf0 >& nums1, \cf5 vector\cf0 <\cf3 int\cf0 >& nums2) \{\
\
    \cf3 int\cf0  sz1 = nums1.size();\
    \cf3 int\cf0  sz2 = nums2.size();\
    \cf3 int\cf0  size = sz1+sz2;\
    \cf3 int\cf0  mid;\
    \cf3 bool\cf0  even;\
    \cf3 if\cf0 (size%2 == 0)\
    \{\
        even = \cf3 true\cf0 ;\
        mid = size/2 - 1;  \cf2 //index is position -1\cf0 \
    \}\
    \cf3 else\cf0 \
    \{\
        even = \cf3 false\cf0 ;\
        mid = (size/2);\
    \}\
\
    \cf3 double\cf0  median;\
    \cf3 if\cf0 (sz1 > sz2)\
    \{\
        \cf3 if\cf0 (even)\
        \{\
            median = (nums1[mid] + nums1[mid+1])/2;\
        \}\
        \cf3 else\cf0 \
        \{\
            median = (nums1[mid]);\
        \}\
    \}\
    \cf3 else\cf0 \
    \{\
        mid = mid - sz1;\
        \cf3 if\cf0 (even)\
        \{\
            median = (nums2[mid] + nums2[mid+1])/2;\
            \cf2 //mid = mid - sz1;\cf0 \
        \}\
        \cf3 else\cf0 \
        \{\
            median = nums2[mid];\
        \}\
    \}\
\
    \cf3 return\cf0  median;\
\
\}\
\
\
\cf3 int\cf0  main() \{\
	cout << \cf4 "!!!Hello World!!!"\cf0  << endl; \cf2 // prints !!!Hello World!!!\cf0 \
\pard\pardeftab720\partightenfactor0
\cf2 //	Solution s1;\cf0 \
\cf2 //	vector\ul <int>\ulnone  a;\cf0 \
\cf2 //	a.push_back(1);\cf0 \
\cf2 //	a.push_back(3);\cf0 \
\cf2 //	a.push_back(5);\cf0 \
\cf2 //	a.push_back(7);\cf0 \
\cf2 //\cf0 \
\cf2 //	vector\ul <int>\ulnone  r = s1.kthSmallestPrimeFraction(a, 1);\cf0 \
\cf2 //	\ul cout\ulnone  << r[0] << r[1];\cf0 \
\
\cf2 //	vector\ul <int>\ulnone  nums1;\cf0 \
\cf2 //	vector\ul <int>\ulnone  nums2;\cf0 \
\cf2 //\cf0 \
\cf2 //	nums1.push_back(1);\cf0 \
\cf2 //	nums1.push_back(3);\cf0 \
\cf2 //\cf0 \
\cf2 //	nums2.push_back(2);\cf0 \
\cf2 //\cf0 \
\cf2 //	double median = findMedianSortedArrays(nums1, nums2);\cf0 \
\cf2 //\cf0 \
\cf2 //\cf0 \
\cf2 //	\ul cout\ulnone  << median << \ul endl\ulnone ;\cf0 \
\
\cf2 //	\ul int\ulnone  i= 0;\cf0 \
\cf2 //	while(i < 10)\cf0 \
\cf2 //	\{\cf0 \
\cf2 //		i++;\cf0 \
\cf2 //	\}\cf0 \
\cf2 //\cf0 \
\cf2 //\cf0 \
\cf2 //	\ul cout\ulnone  << i << \ul endl\ulnone ;\cf0 \
\cf2 //\cf0 \
\cf2 //	\ul int\ulnone  k = 123;\cf0 \
\cf2 //	\ul cout\ulnone  << reverse(k) << \ul endl\ulnone ;\cf0 \
\
\cf2 //\cf0 \
\cf2 //	string a = "11";\cf0 \
\cf2 //	string b = "10";\cf0 \
\cf2 //	string \ul ret\ulnone  = addBinary(a, b);\cf0 \
\cf2 //\cf0 \
\cf2 //	\ul cout\ulnone  << \ul ret\ulnone ;\cf0 \
\
\
\cf2 //	string k = "\ul ab\ulnone ";\cf0 \
\cf2 //	string b = "\ul ba\ulnone ";\cf0 \
\cf2 //	if(k == b)\cf0 \
\cf2 //		\ul cout\ulnone  << "yes";\cf0 \
\cf2 //	else\cf0 \
\cf2 //		\ul cout\ulnone  << "no";\cf0 \
\cf2 //	\ul cout\ulnone  << isPalindrome(k) << \ul endl\ulnone ;\cf0 \
\
\cf2 //	vector\ul <int>\ulnone  \ul nums\ulnone ;\cf0 \
\cf2 //	nums.push_back(1);\cf0 \
\cf2 //	nums.push_back(2);\cf0 \
\cf2 //	//nums.push_back(3);\cf0 \
\cf2 //	//nums.push_back(4);\cf0 \
\cf2 //	vector< vector\ul <int>\ulnone  > k = subsets(\ul nums\ulnone );\cf0 \
\
\cf2 //	string p = "()";\cf0 \
\cf2 //	if(isValid(p))\cf0 \
\cf2 //	\{\cf0 \
\cf2 //		\ul cout\ulnone  << "yes" << \ul endl\ulnone ;\cf0 \
\cf2 //	\}\cf0 \
\cf2 //	else\cf0 \
\cf2 //	\{\cf0 \
\cf2 //		\ul cout\ulnone  << " no" << \ul endl\ulnone ;\cf0 \
\cf2 //	\}\cf0 \
\
\cf2 //	Interval(1,3);\cf0 \
\cf2 //	Interval(2,5);\cf0 \
\cf2 //	Interval(8,10);\cf0 \
\cf2 //	Interval(15,18);\cf0 \
	\cf5 vector\cf0 <\cf5 Interval\cf0 > in;\
	in.push_back(\cf5 Interval\cf0 (1,3));\
	in.push_back(\cf5 Interval\cf0 (2,5));\
	in.push_back(\cf5 Interval\cf0 (8,10));\
	in.push_back(\cf5 Interval\cf0 (15,18));\
	\cf5 vector\cf0 <\cf5 Interval\cf0 > k = merge(in);\
\
	cout << k.size() << endl;\
\
	\cf2 //char a = 'A';\cf0 \
\cf2 //	\ul int\ulnone  a = 65;\cf0 \
\cf2 //	\ul cout\ulnone  << char(a);\cf0 \
\cf2 //\cf0 \
\cf2 //	set\ul <int>\ulnone  \ul myset\ulnone ;\cf0 \
\cf2 //	for (\ul int\ulnone  i=5; i>0; i--) myset.insert(i*10);\cf0 \
\cf2 //	myset.insert(-4);\cf0 \
\cf2 //	myset.insert(30);\cf0 \
\cf2 //\cf0 \
\cf2 //	\ul cout\ulnone  << \ul endl\ulnone  << *myset.begin() << ", " << *(myset.upper_bound()) << \ul endl\ulnone ;\cf0 \
\cf2 //	for(auto a : \ul myset\ulnone )\cf0 \
\cf2 //	\{\cf0 \
\cf2 //		\ul cout\ulnone  << a << ", ";\cf0 \
\cf2 //	\}\cf0 \
\
	  \cf5 vector\cf0 <\cf3 int\cf0 > myvector;\
\
	  myvector.push_back(100);\
	  myvector.push_back(150);\
	  myvector.push_back(180);\
	  \cf5 vector\cf0 <\cf3 int\cf0 >::\cf5 iterator\cf0  it;\
\
	  it = myvector.begin()+1;\
	  it = myvector.insert ( it , 200 );\
	  \cf2 //it = myvector.erase(it);\cf0 \
	  cout << \cf4 "\ul iit\ulnone  "\cf0  << *--it << endl;\
\
	  myvector.insert (it,2,300);\
\
	  \cf2 // "it" no longer valid, get a new one:\cf0 \
	  it = myvector.begin();\
\
	  \cf5 vector\cf0 <\cf3 int\cf0 > anothervector (2,400);\
	  myvector.insert (it+2,anothervector.begin(),anothervector.end());\
\
	  \cf3 for\cf0  (it=myvector.begin(); it<myvector.end(); it++)\
		  cout << \cf4 ' '\cf0  << *it;\
	  cout << \cf4 '\\n'\cf0 ;\
\
	\cf3 return\cf0  0;\
\}\
\
\pard\pardeftab720\partightenfactor0
\cf5 vector\cf0 <\cf5 Interval\cf0 > merge(\cf5 vector\cf0 <\cf5 Interval\cf0 >& intervals) \{\
\
    \cf3 int\cf0  a, b;\
    \cf3 if\cf0 (intervals.size() == 0)\
        \cf3 return\cf0  intervals;\
    \cf3 else\cf0  \cf3 if\cf0 (intervals.size() == 1)\
        \cf3 return\cf0  intervals;\
\
    \cf3 for\cf0 (\cf3 int\cf0  i = 0; i < intervals.size()-1; i++)\
    \{\
        \cf3 for\cf0 (\cf3 int\cf0  j = i+1; j < intervals.size(); j++)\
        \{\
            \cf3 if\cf0 (((intervals[i].\cf6 start\cf0  > intervals[j].\cf6 start\cf0  && intervals[i].\cf6 start\cf0  > intervals[j].\cf6 end\cf0 ) &&\
               (intervals[i].\cf6 end\cf0  > intervals[j].\cf6 start\cf0  && intervals[i].\cf6 end\cf0  > intervals[j].\cf6 end\cf0 )) ||\
               ((intervals[i].\cf6 start\cf0  < intervals[j].\cf6 start\cf0  && intervals[i].\cf6 start\cf0  < intervals[j].\cf6 end\cf0 ) &&\
                (intervals[i].\cf6 end\cf0  < intervals[j].\cf6 start\cf0  && intervals[i].\cf6 end\cf0  < intervals[j].\cf6 end\cf0 )))\
            \{\
                \cf3 continue\cf0 ;\
            \}\
            \cf3 else\cf0 \
            \{\
                \cf3 if\cf0 (intervals[i].\cf6 start\cf0  < intervals[i].\cf6 end\cf0  &&\
                    intervals[i].\cf6 start\cf0  < intervals[j].\cf6 start\cf0  &&\
                    intervals[i].\cf6 start\cf0  < intervals[j].\cf6 end\cf0 )\
                \{\
                     a = intervals[i].\cf6 start\cf0 ;\
                \}\
                \cf3 else\cf0  \cf3 if\cf0 (intervals[i].\cf6 end\cf0  < intervals[i].\cf6 start\cf0  &&\
                    intervals[i].\cf6 end\cf0  < intervals[j].\cf6 start\cf0  &&\
                    intervals[i].\cf6 end\cf0  < intervals[j].\cf6 end\cf0 )\
                \{\
                     a = intervals[i].\cf6 end\cf0 ;\
                \}\
                \cf3 else\cf0  \cf3 if\cf0 (intervals[j].\cf6 end\cf0  < intervals[j].\cf6 start\cf0  &&\
                    intervals[j].\cf6 end\cf0  < intervals[i].\cf6 start\cf0  &&\
                    intervals[j].\cf6 end\cf0  < intervals[i].\cf6 end\cf0 )\
                \{\
                     a = intervals[j].\cf6 end\cf0 ;\
                \}\
                \cf3 else\cf0  \cf3 if\cf0 (intervals[j].\cf6 start\cf0  < intervals[i].\cf6 start\cf0  &&\
                    intervals[j].\cf6 start\cf0  < intervals[i].\cf6 end\cf0  &&\
                    intervals[j].\cf6 start\cf0  < intervals[j].\cf6 end\cf0 )\
                \{\
                     a = intervals[j].\cf6 start\cf0 ;\
                \}\
\
\
                \cf3 if\cf0 (intervals[i].\cf6 start\cf0  > intervals[i].\cf6 end\cf0  &&\
                    intervals[i].\cf6 start\cf0  > intervals[j].\cf6 start\cf0  &&\
                    intervals[i].\cf6 start\cf0  > intervals[j].\cf6 end\cf0 )\
                \{\
                     b = intervals[i].\cf6 start\cf0 ;\
                \}\
                \cf3 else\cf0  \cf3 if\cf0 (intervals[i].\cf6 end\cf0  > intervals[i].\cf6 start\cf0  &&\
                    intervals[i].\cf6 end\cf0  > intervals[j].\cf6 start\cf0  &&\
                    intervals[i].\cf6 end\cf0  > intervals[j].\cf6 end\cf0 )\
                \{\
                     b = intervals[i].\cf6 end\cf0 ;\
                \}\
                \cf3 else\cf0  \cf3 if\cf0 (intervals[j].\cf6 end\cf0  > intervals[j].\cf6 start\cf0  &&\
                    intervals[j].\cf6 end\cf0  > intervals[i].\cf6 start\cf0  &&\
                    intervals[j].\cf6 end\cf0  > intervals[i].\cf6 end\cf0 )\
                \{\
                     b = intervals[j].\cf6 end\cf0 ;\
                \}\
                \cf3 else\cf0  \cf3 if\cf0 (intervals[j].\cf6 start\cf0  > intervals[i].\cf6 start\cf0  &&\
                    intervals[j].\cf6 start\cf0  > intervals[i].\cf6 end\cf0  &&\
                    intervals[j].\cf6 start\cf0  > intervals[j].\cf6 end\cf0 )\
                \{\
                     b = intervals[j].\cf6 start\cf0 ;\
                \}\
\
                \cf3 if\cf0 (intervals[i].\cf6 start\cf0  == intervals[j].\cf6 start\cf0  && intervals[i].\cf6 end\cf0  == intervals[j].\cf6 end\cf0 )\
                \{\
                    a = intervals[i].\cf6 start\cf0 ;\
                    b = intervals[j].\cf6 end\cf0 ;\
                \}\
                intervals.push_back(\cf5 Interval\cf0 (a,b));\
                \cf3 if\cf0 (i < j)\
                \{\
                    intervals.erase(intervals.begin()+i);\
                    i--;\
                    intervals.erase(intervals.begin()+j);\
                    j--;\
                \}\
                \cf3 else\cf0 \
                \{\
                    intervals.erase(intervals.begin()+i);\
                    i--;\
                    intervals.erase(intervals.begin()+j);\
                    j--;\
                \}\
                i = -1;\
\
                \cf3 break\cf0 ;\
            \}\
        \}\
    \}\
    \cf3 return\cf0  intervals;\
\}\
\
\pard\pardeftab720\partightenfactor0
\cf3 bool\cf0  isValid(\cf5 string\cf0  s)\
\{\
\
\pard\pardeftab720\partightenfactor0
\cf2 //         \ul int\ulnone  opening_count = 0;\cf0 \
    \cf2 //if(s.length()-1%2)\cf0 \
    \cf2 //    return false;\cf0 \
\
\
    \cf5 stack\cf0 <\cf3 char\cf0 > st;\
    cout << s.length() << \cf4 " \ul len\ulnone "\cf0  << endl;\
    \cf3 for\cf0 (\cf3 int\cf0  i = 0; i < s.length(); i++)\
    \{\
        \cf3 if\cf0 ((s[i] == \cf4 '('\cf0 || s[i] == \cf4 '\{'\cf0  || s[i] == \cf4 '['\cf0 ))\
        \{\
            st.push(s[i]);\
        \}\
        \cf3 else\cf0 \
        \{\
            \cf3 if\cf0 (st.empty())\
                \cf3 return\cf0  \cf3 false\cf0 ;\
\
\
            \cf3 if\cf0 (s[i] == \cf4 ')'\cf0 )\
            \{\
                \cf3 if\cf0 (st.top() != \cf4 '('\cf0 )\
                    \cf3 return\cf0  \cf3 false\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (s[i] == \cf4 '\}'\cf0 )\
            \{\
                \cf3 if\cf0 (st.top() != \cf4 '\{'\cf0 )\
                    \cf3 return\cf0  \cf3 false\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (s[i] == \cf4 ']'\cf0 )\
            \{\
                \cf3 if\cf0 (st.top() != \cf4 '['\cf0 )\
                \{\
                    \cf3 return\cf0  \cf3 false\cf0 ;\
                \}\
            \}\
            \cf3 else\cf0 \
            \{\
                \cf3 \ul \ulc3 false\cf0 \ulc0 ;\ulnone \
            \}\
            \cf2 //i++;\cf0 \
            cout << st.size() << \cf4 " \ul stlen\ulnone "\cf0  << endl;\
            st.pop();\
        \}\
    \}\
\
    cout << st.size() << \cf4 " \ul stlen\ulnone "\cf0  << endl;\
    \cf3 if\cf0 (st.empty())\
        \cf3 return\cf0  \cf3 true\cf0 ;\
    \cf3 else\cf0 \
        \cf3 return\cf0  \cf3 false\cf0 ;\
\}\
\
\pard\pardeftab720\partightenfactor0
\cf3 int\cf0  reverse(\cf3 int\cf0  x) \{\
    \cf3 int\cf0  k = 0;\
    \cf3 int\cf0  r = 0;\
    \cf3 \ul \ulc3 int\cf0 \ulc0  i = 0;\ulnone \
    \cf5 string\cf0  s = \cf4 ""\cf0 ;\
\
    \cf5 vector\cf0 <\cf3 int\cf0 > input;\
    \cf3 while\cf0 (x > 0)\
    \{\
        k = x%10;\
        x /= 10;\
\
        input.push_back(k);\
\
    \}\
\
    \cf3 int\cf0  sum = 0;\
    \cf3 for\cf0 (\cf3 int\cf0  i = input.size()-1; i >= 0; i--)\
    \{\
    		sum += input[i]*pow(10, input.size()-1-i);\
    \}\
\
    cout << sum << endl;\
\
    \cf3 return\cf0  r;\
\
\}\
\
\
\pard\pardeftab720\partightenfactor0
\cf5 vector\cf0 <\cf3 int\cf0 > intersect(\cf5 vector\cf0 <\cf3 int\cf0 >& nums1, \cf5 vector\cf0 <\cf3 int\cf0 >& nums2) \{\
\
    \cf5 vector\cf0 <\cf3 int\cf0 > out;\
    \cf3 for\cf0 (\cf3 int\cf0  i = 0; i < nums1.size(); i++)\
    \{\
        \cf3 for\cf0 (\cf3 int\cf0  j = 0; j < nums2.size(); j++)\
        \{\
            \cf3 if\cf0 (nums1[i] == nums2[j])\
            \{\
                out.push_back(nums1[i]);\
                nums2.erase(nums2.begin()+j);\
                j--;\
            \}\
        \}\
    \}\
\
    \cf3 return\cf0  out;\
\}\
\
\
\cf5 string\cf0  addBinary(\cf5 string\cf0  a, \cf5 string\cf0  b)\
\{\
\
    \cf3 int\cf0  i = a.length()-1;\
    \cf3 int\cf0  j = b.length()-1;\
\
    \cf3 if\cf0 (i > j)\
    \{\
        \cf5 string\cf0  b_z;\
        \cf3 for\cf0 (\cf3 int\cf0  k = 0; k < i-j; k++)\
            b_z += \cf4 '0'\cf0 ;\
\
        b = b_z + b;\
        \cf5 string\cf0  c;\
        \cf5 string\cf0  r;\
        c[i+1] = \cf4 '0'\cf0 ;\
\
        \cf3 while\cf0 (i > 0)\
        \{\
            \cf3 if\cf0 ((a[i] == \cf4 '1'\cf0 ) && (b[i] == \cf4 '1'\cf0 ) && (c[i+1] == \cf4 '0'\cf0 ))\
            \{\
                c[i] = \cf4 '1'\cf0 ;\
                r[i+1] = \cf4 '0'\cf0 ;\
\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[i] == \cf4 '1'\cf0  && b[i] == \cf4 '1'\cf0  && c[i+1] == \cf4 '1'\cf0 )\
            \{\
                r[i+1] = \cf4 '1'\cf0 ;\
                c[i] = \cf4 '1'\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[i] == \cf4 '0'\cf0  && b[i] == \cf4 '1'\cf0  && c[i+1] == \cf4 '1'\cf0 )\
            \{\
                r[i+1] = \cf4 '0'\cf0 ;\
                c[i] = \cf4 '1'\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[i] == \cf4 '1'\cf0  && b[i] == \cf4 '0'\cf0  && c[i+1] == \cf4 '1'\cf0 )\
            \{\
                r[i+1] = \cf4 '0'\cf0 ;\
                c[i] = \cf4 '1'\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[i] == \cf4 '0'\cf0  && b[i] == \cf4 '0'\cf0  && c[i+1] == \cf4 '0'\cf0 )\
            \{\
                r[i+1] = \cf4 '0'\cf0 ;\
                c[i] = \cf4 '0'\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[i] == \cf4 '0'\cf0  && b[i] == \cf4 '0'\cf0  && c[i+1] == \cf4 '1'\cf0 )\
            \{\
                r[i+1] = \cf4 '1'\cf0 ;\
                c[i] = \cf4 '0'\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[i] == \cf4 '0'\cf0  && b[i] == \cf4 '1'\cf0  && c[i+1] == \cf4 '0'\cf0 )\
            \{\
                r[i+1] = \cf4 '1'\cf0 ;\
                c[i] = \cf4 '0'\cf0 ;\
            \}\
            i--;\
        \}\
        \cf3 if\cf0 (c[0] == \cf4 '1'\cf0 )\
            r[0] = \cf4 '1'\cf0 ;\
        \cf3 else\cf0 \
            r[0] = \cf4 '0'\cf0 ;\
\
        \cf3 return\cf0  r;\
    \}\
    \cf3 else\cf0 \
    \{\
        \cf5 string\cf0  a_z;\
        \cf3 for\cf0 (\cf3 int\cf0  k = 0; k < j-i; k++)\
            a_z += \cf4 '0'\cf0 ;\
\
        a = a_z + a;\
        \cf5 string\cf0  c;\
        \cf5 string\cf0  r;\
        c[j+1] = \cf4 '0'\cf0 ;\
        \cf3 while\cf0 (j > 0)\
        \{\
            \cf3 if\cf0 (a[j] == \cf4 '1'\cf0  && b[j] == \cf4 '1'\cf0  && c[j+1] == \cf4 '0'\cf0 )\
            \{\
                c[j] = \cf4 '1'\cf0 ;\
                r[j+1] = \cf4 '0'\cf0 ;\
\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[j] == \cf4 '1'\cf0  && b[j] == \cf4 '1'\cf0  && c[j+1] == \cf4 '1'\cf0 )\
            \{\
                r[j+1] = \cf4 '1'\cf0 ;\
                c[j] = \cf4 '1'\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[j] == \cf4 '0'\cf0  && b[j] == \cf4 '1'\cf0  && c[j+1] == \cf4 '1'\cf0 )\
            \{\
                r[j+1] = \cf4 '0'\cf0 ;\
                c[j] = \cf4 '1'\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[j] == \cf4 '1'\cf0  && b[j] == \cf4 '0'\cf0  && c[j+1] == \cf4 '1'\cf0 )\
            \{\
                r[j+1] = \cf4 '0'\cf0 ;\
                c[j] = \cf4 '1'\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[j] == \cf4 '0'\cf0  && b[j] == \cf4 '0'\cf0  && c[j+1] == \cf4 '0'\cf0 )\
            \{\
                r[j+1] = \cf4 '0'\cf0 ;\
                c[j] = \cf4 '0'\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[j] == \cf4 '0'\cf0  && b[j] == \cf4 '0'\cf0  && c[j+1] == \cf4 '1'\cf0 )\
            \{\
                r[j+1] = \cf4 '1'\cf0 ;\
                c[j] = \cf4 '0'\cf0 ;\
            \}\
            \cf3 else\cf0  \cf3 if\cf0 (a[j] == \cf4 '0'\cf0  && b[j] == \cf4 '1'\cf0  && c[j+1] == \cf4 '0'\cf0 )\
            \{\
                r[j+1] = \cf4 '1'\cf0 ;\
                c[j] = \cf4 '0'\cf0 ;\
            \}\
\
            j--;\
        \}\
\
        \cf3 if\cf0 (c[0] == \cf4 '1'\cf0 )\
            r[0] = \cf4 '1'\cf0 ;\
        \cf3 else\cf0 \
            r[0] = \cf4 '0'\cf0 ;\
\
\
        \cf3 return\cf0  r;\
    \}\
\
\}\
\
\
\pard\pardeftab720\partightenfactor0
\cf3 bool\cf0  isPalindrome(\cf5 string\cf0  s)\
\{\
    \cf5 string\cf0  input = \cf4 ""\cf0 ;\
\
    \cf3 for\cf0 (\cf3 int\cf0  i = 0; i < s.length(); i++)\
    \{\
        \cf3 if\cf0 (isdigit(s[i]) || isalpha(s[i]))\
        \{\
            input += s[i];\
        \}\
    \}\
\
    \cf5 string\cf0  rev = reverse_string(input);\
    \cf3 if\cf0 (input == rev)\
    \{\
        \cf3 return\cf0  \cf3 true\cf0 ;\
    \}\
    \cf3 else\cf0 \
    \{\
        \cf3 return\cf0  \cf3 false\cf0 ;\
    \}\
\}\
\
\pard\pardeftab720\partightenfactor0
\cf5 string\cf0  reverse_string(\cf5 string\cf0  input)\
\{\
    \cf3 for\cf0 (\cf3 int\cf0  i = 0; i < input.length()/2; i++)\
    \{\
        swap(input[i], input[input.length()-i-1]);\
    \}\
    cout << input[0] << \cf4 ", "\cf0  << input[1] << endl;\
    \cf3 return\cf0  input;\
\}\
\
\cf5 vector\cf0 < \cf5 vector\cf0 <\cf3 int\cf0 > > subsets(\cf5 vector\cf0 <\cf3 int\cf0 >& nums) \{\
\
    \cf5 vector\cf0 < \cf5 vector\cf0 <\cf3 int\cf0 > > sort;\
    \cf5 vector\cf0 <\cf3 int\cf0 > elem;\
    rec(sort, elem, nums, 0, nums.size(), \cf3 false\cf0 );\
    cout<<sort.size()<<endl;\
\pard\pardeftab720\partightenfactor0
\cf2 //    for(\ul int\ulnone  i = 0; i < sort.size(); i++)\cf0 \
\cf2 //    \{\cf0 \
\cf2 //        for(\ul int\ulnone  j = 0; j < sort[i].size(); j++)\cf0 \
\cf2 //        \{\cf0 \
\cf2 //            \ul cout\ulnone  << sort[i][j] << ", ";\cf0 \
\cf2 //        \}\cf0 \
\cf2 //        \ul cout\ulnone  << \ul endl\ulnone ;\cf0 \
\cf2 //    \}\cf0 \
    \cf3 return\cf0  sort;\
\
\}\
\
\cf2 //recursive way of subset calculations\cf0 \
\
\pard\pardeftab720\partightenfactor0
\cf3 void\cf0  rec(\cf5 vector\cf0 < \cf5 vector\cf0 <\cf3 int\cf0 > > &sort, \cf5 vector\cf0 <\cf3 int\cf0 > elem, \cf3 const\cf0  \cf5 vector\cf0 <\cf3 int\cf0 > &nums, \cf3 int\cf0  i, \cf3 int\cf0  sz, \cf3 bool\cf0  k)\
\{\
    \cf3 if\cf0 (i == sz)\
    \{\
        sort.push_back(elem);\
        \cf3 for\cf0 (\cf3 int\cf0  j = 0; j < elem.size(); j++)\
        \{\
            cout << elem[j] << \cf4 ", "\cf0 ;\
        \}\
        cout << endl;\
\
        \cf3 return\cf0 ;\
    \}\
\
\
    rec(sort, elem, nums, i+1, sz, \cf3 false\cf0 );\
    elem.push_back(nums[i]);\
    rec(sort, elem, nums, i+1, sz, \cf3 true\cf0 );\
\
\}\
\
}