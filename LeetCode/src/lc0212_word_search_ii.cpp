/*
 * LeetCode算法练习
 * Description  : LeetCode题库212题, https://leetcode-cn.com/problems/word-search-ii/
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
#include "lc0212_word_search_ii.h"

using namespace std;

struct TrieNode {
    string word;
    unordered_map<char, TrieNode *> child;
    TrieNode() {
        word = "";
    }
};

void InsertTrie(TrieNode* root, string& word) {
    TrieNode* node = root;
    for (auto& c : word) {
        if (!node->child.count(c)) {
            node->child.emplace(c, new TrieNode());
        }
        node = node->child[c];
    }
    node->word = word;
}

class WordSearch {
public:
    WordSearch(vector<vector<char>>& board) : board(board), R(board.size()), C(board[0].size()) {}

    void Find(TrieNode* root, vector<string>& ret) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                DfsFind(i, j, root);
            }
        }

        for (auto& word : reserve) {
            ret.emplace_back(word);
        }
    }

private:
    void DfsFind(int x, int y, TrieNode* root)
    {
        char c = board[x][y];

        if (!root->child.count(c)) {
            return;
        }

        root = root->child[c];
        if (root->word.size()) {
            reserve.insert(root->word);
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int nextX = x + dir[i].first;
            int nextY = y + dir[i].second;
            if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C || board[nextX][nextY] == '#') {
                continue;
            }
            DfsFind(nextX, nextY, root);
        }
        board[x][y] = c;
    }

    vector<vector<char>>& board;
    const int R;
    const int C;
    set<string> reserve;
    vector<pair<int, int>> dir = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        WordSearch ws(board);
        for (auto& word : words) {
            InsertTrie(root, word);
        }
        vector<string> ret;
        ws.Find(root, ret);
        return ret;
    }
};

void LC0212Test()
{
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'}, 
        {'e', 't', 'a', 'e'}, 
        {'i', 'h', 'k', 'r'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain"};
    Solution solu;
    auto result = solu.findWords(board, words);
    WriteVector<string>(result);
}