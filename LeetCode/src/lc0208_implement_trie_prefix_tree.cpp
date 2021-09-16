/*
 * LeetCode算法练习
 * Description  : LeetCode题库208题, https://leetcode-cn.com/problems/implement-trie-prefix-tree/
 * Author       : 李阳
 * Created      : 2021-09-16
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0208_implement_trie_prefix_tree.h"

using namespace std;

namespace use_vec {
#define MAX 26
struct TrieNode {
    bool isEnd;
    vector<TrieNode *> child;
    TrieNode() {
        isEnd = false;
        child = vector<TrieNode *>(26, nullptr);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()){}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tmpNode = root;
        for (auto& c : word) {
            int index = c - 'a';
            if (tmpNode->child[index] == nullptr) {
                tmpNode->child[index] = new TrieNode();
            }
            tmpNode = tmpNode->child[index];
        }
        tmpNode->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto tmpNode = find(word);
        return tmpNode != nullptr && tmpNode->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto tmpNode = find(prefix);
        return tmpNode != nullptr;
    };
private:
    TrieNode* root;

    TrieNode* find(string word)
    {
        TrieNode* tmpNode = root;
        for (auto& c : word) {
            int index = c - 'a';
            if (tmpNode->child[index] == nullptr) {
                return nullptr;
            }
            tmpNode = tmpNode->child[index];
        }
        return tmpNode;
    }
};
}

namespace usr_map {
struct TrieNode {
    string word;
    unordered_map<char, TrieNode *> child;
    TrieNode() {
        word = "";
        unordered_map<char, TrieNode *> child;
    };
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tmpNode = root;
        for (auto& c : word) {
            if (!tmpNode->child.count(c)) {
                tmpNode->child[c] = new TrieNode();
            }
            tmpNode = tmpNode->child[c];
        }
        tmpNode->word = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* tmpNode = root;
        for(auto& c : word) {
            if (!tmpNode->child.count(c)) {
                return false;
            }
            tmpNode = tmpNode->child[c];
        }
        return tmpNode->word.size() > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* tmpNode = root;
        for(auto& c : prefix) {
            if (!tmpNode->child.count(c)) {
                return false;
            }
            tmpNode = tmpNode->child[c];
        }
        return true;
    }
private:
    TrieNode* root;
};
}

void LC0208Test()
{
    using namespace use_vec;
    Trie t;
    t.insert("abc");
    PrintBool(t.search("abc"));
}