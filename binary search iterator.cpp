{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf200
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 /**\
 * Definition for binary tree\
 * struct TreeNode \{\
 *     int val;\
 *     TreeNode *left;\
 *     TreeNode *right;\
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) \{\}\
 * \};\
 */\
class BSTIterator \{\
public:\
    vector<TreeNode*> nodes;\
    \
    void pushLeft(TreeNode* root) \
    \{\
        TreeNode* iter = root;\
        while (iter != NULL) \
        \{\
            nodes.push_back(iter);\
            iter = iter->left;\
        \}\
    \}\
    BSTIterator(TreeNode *root) \
    \{\
        pushLeft(root);\
    \}\
    /** @return whether we have a next smallest number */\
    bool hasNext() \{\
        return !nodes.empty();\
    \}\
    /** @return the next smallest number */\
    int next() \
    \{\
        TreeNode* current = nodes.back();\
        nodes.pop_back();\
        if (NULL != current->right) pushLeft(current->right);\
        return current->val;\
    \}\
    \
    \
    \
    // BSTIterator(TreeNode *root) \
    //\{\
    //     rooti = root;\
    // \}\
    \
\
//     /** @return whether we have a next smallest number */\
//     bool hasNext() \{\
        \
//         if(rooti != nullptr)\
//         \{\
//             if(rooti->right != nullptr)\
//             \{\
//                 return true;\
//             \}\
//             else\
//             \{\
//                 return true;\
//             \}\
 \
//         \}\
//         else\
//         \{\
//             return false;\
//         \}\
//     \}\
\
//     /** @return the next smallest number */\
//     int next() \{\
        \
//         if(rooti != nullptr)\
//         \{\
//             if(rooti->right != nullptr)\
//             \{\
//                 TreeNode *ptr = rooti->right;\
//                 //TreeNode *prev = \
//                 while(ptr->left != nullptr)\
//                 \{\
//                     ptr = ptr->left;\
//                 \}\
//                 int k = ptr->val;\
//                 ptr = nullptr;\
//                 return k; \
//             \}\
//             else\
//             \{\
//                 int k = rooti->val;\
//                 rooti = nullptr;\
//                 return k; \
                \
//             \}\
//         \}\
//         else\
//         \{\
//             return 0;\
//         \}\
\
//     \}\
    \
// private:\
//     TreeNode *rooti;\
\};\
\
/**\
 * Your BSTIterator will be called like this:\
 * BSTIterator i = BSTIterator(root);\
 * while (i.hasNext()) cout << i.next();\
 */}