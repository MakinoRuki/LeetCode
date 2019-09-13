/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
// 每次希望可以remove掉尽可能多的不对的串。
// 因此就猜那个出现最少的串。
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
      for (int i = 0; i < 10; ++i) {
        map<string, int> cnt;
        for (int i = 0; i < wordlist.size(); ++i) {
          cnt[wordlist[i]]++;
        }
        int mincnt = wordlist.size() + 1;
        string mins = "";
        for (auto word : cnt) {
          if (word.second < mincnt) {
            mincnt = word.second;
            mins = word.first;
          }
        }
        int res = master.guess(mins);
        if (res == 6) break;
        vector<string> wordlist2;
        for (int i = 0; i < wordlist.size(); ++i) {
          int num = 0;
          for (int j = 0; j < 6; ++j) {
            if (wordlist[i][j] == mins[j]) num++;
          }
          if (num == res) {
            wordlist2.push_back(wordlist[i]);
          }
        }
        wordlist = wordlist2;
      }
    }
};
