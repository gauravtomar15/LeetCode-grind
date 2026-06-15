class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            mp[wordList[i]] = 1;
        }
        if (mp.find(beginWord) == mp.end()) {
            mp[beginWord] = 1;
        }
        if (mp.find(endWord) == mp.end()) {
            return 0;
        }
        queue<pair<string, int>> bfsQueue;
        bfsQueue.push({beginWord, 1});
        mp.erase(beginWord);

        while (!bfsQueue.empty()) {
            pair<string, int> p = bfsQueue.front();
            bfsQueue.pop();
            string newWord = p.first;
            int val = p.second;
            if (newWord == endWord) {
                return val;
            }
            for (int i = 0; i < newWord.size(); i++) {
                char c = newWord[i];
                for (int j = 97; j <= 122; j++) {
                    if (c == j)
                        continue;
                    newWord[i] = j;
                    if (mp.find(newWord) != mp.end()) {
                        bfsQueue.push({newWord, val + 1});
                        mp.erase(newWord);
                    }
                }
                newWord[i] = c;
            }
        }
        return 0;
    }
};