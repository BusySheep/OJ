#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
private:
    const int HASH_SIZE = 1000000007;
    int convert(long hash, string& s, int begin, vector<string>& words, unordered_map<long, int>& wordsMap) {
        if (wordsMap.count(hash) > 0) {
            string& word = words[wordsMap[hash]];
            for (int i = 0; i < word.length(); i++) {
                if (s[begin + i] != word[i]) return -1;
            }
            return wordsMap[hash];
        }
        return -1;
    }
    int countNotZero(vector<int>& rest) {
        int count = 0;
        for (int i = 0; i < rest.size(); i++) {
            if (rest[i] > 0) count++;
        }
        return count;
    }
    long powMod(int a, int e, int mod) {
        if (e == 0) return 1;
        if (e == 1) return a % mod;
        long temp = powMod(a, e / 2, mod);
        temp *= temp;
        temp %= mod;
        if (e & 1) {
            temp *= a;
            temp %= mod;
        }
        return temp;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() == 0 || words[0].length() == 0 || words.size() * words[0].length() > s.length()) return vector<int>();
        
        unordered_map<long, int> wordsMap;
        unordered_map<string, int> existWord;
        vector<int> capacity(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            long hash = 0;
            for (int j = 0; j < words[i].length(); j++) {
                hash *= 26;
                hash += words[i][j] - 'a';
                hash %= HASH_SIZE;
            }
            if (existWord.count(words[i]) == 0) {
                wordsMap[hash] = i;
                existWord[words[i]] = i;
                capacity[i]++;
            } else {
                capacity[existWord[words[i]]]++;
            }
        }
        
        vector<int> wordsIndex;
        long hash = 0;
        int i;
        int len = words[0].length();
        for (i = 0; i < len; i++) {
            hash *= 26;
            hash += s[i] - 'a';
            hash %= HASH_SIZE;
        }
        wordsIndex.push_back(convert(hash, s, 0, words, wordsMap));
        long power = powMod(26, len - 1, HASH_SIZE);
        for (; i < s.length(); i++) {
            hash -= (s[i - len] - 'a') * power;
            hash %= HASH_SIZE;
            if (hash < 0) hash += HASH_SIZE;
            hash *= 26;
            hash += s[i] - 'a';
            hash %= HASH_SIZE;
            wordsIndex.push_back(convert(hash, s, i - len + 1, words, wordsMap));
        }
        
        vector<int> result;
        for (int begin = 0; begin < len; begin++) {
            int i = begin;
            int j = begin;
            bool flag = false;
            vector<int> rest = capacity;
            int restNumber = countNotZero(rest);
            while (j < wordsIndex.size()) {
                if (wordsIndex[j] == -1) {
                    flag = true;
                    i = j + len;
                    j += len;
                    continue;
                }
                if (flag) {
                    rest = capacity;
                    restNumber = countNotZero(rest);
                    flag = false;
                }
                if (rest[wordsIndex[j]] > 0) {
                    rest[wordsIndex[j]]--;
                    if (rest[wordsIndex[j]] == 0) {
                        restNumber--;
                    }
                    if (restNumber == 0) {
                        result.push_back(i);
                    }
                    j += len;
                } else {
                    while (rest[wordsIndex[j]] == 0) {
                        rest[wordsIndex[i]]++;
                        if (rest[wordsIndex[i]] == 1) {
                            restNumber++;
                        }
                        i += len;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    string s = "dlmogiklbqfggokuonfgugiyammwvwhbjvrqgdbjtipcwzwmobtjjdhmpvknrsqbpjtvmwfifukbwgokjjvvmeheatttljwdupygofotcywygmksvipkmyqmrjifueiouiukoldqlzquocojkdvzdlnuuvbqajewubgiolazmsvaujmfohervtorppipbolvrtdfefhqxcrrofycmewjykbnzjeazrxrkayohfgekzwyewctbyczidokoskojihvkflslryxruvxrzquytvgyjsndddmnkhzrstclsbeowchwsbwnwemhxbkcgwpqfqjzmmlenpumrckmdgzcmnjjqulwscoytyxhkklzahntjzfphhruwadnwpjptypmwovizijzqzuzycogjhahkdugugxoemccbymagvbyuxytzobkwbsigoobuoraatedrqfamiyigydhpeslhmvoajrxzixabcfvslxgvvpbwujlzdygptureloetogxslsmyrtuokxkeivflvmcoiutwkzryfoqsidtzypqkmaqxywktknisjdoteisjykdhpyipnyzcbqzzolsyycsjfjdjrxupjayzyhqohqqiirjyccwdgoomxtxqqugcwedwntkxlcfvvrtatpfbgtnfnnwfjchfikdwgotrsanorgqmyvoeqdldshldlsiufoslencwprmhyevwzlcqrpvlzgpkbzggnytrnxqdpekpjhnivraogwzfeoqfoynbzgvmelpvpbkyjxjgojuwhtcmkurysfbrnwerjvozxazixionukkbfonpihpcorwbpcvzxjaukzejksxeejhkxxzhgpjuihvxjqyhaydmaivkcuqhdztcyulelvyteutokrxmscasmwepswyyxrawnmazjbsnvndhfcwzfwrruxinvilsbnopbroksiapwfydkwcptvipstepbphffyugrktlsvaqaatkxxbssmhmhmbidjpijjravklofnghnaumxvesjoeqcibhtqsccjextpnaeuhtwdgvbknkaubccemvuezyndwiujkyftrbxxzykmkkilpkrdhohgmwjigduqdbjvdgueggqrtbeknwnvkubysnjysdowgztjipnowghpjmbwkorwkvuckfaciqaprvazlqqjyxahlbdxpxvzusdexfiivlzogbotrgerfeathgqydmxzgcddhnleykthmjcfphzwnzpvfgtkutjavoffcrjcdejrpoxevydkxsffabruwbwtrcytvkyyqhqgvpmsnpdmiktinlflmdffffzcrxbigtqeicyxudlcofmdqtpexwjebkhtjidsdtwlvwkpavtqaitsbkyagifiumdewgwzzumwqyoqtjgwrcqvmpvtzadtogxmmvnlrzjixxathjpylhvzwruvtxpkdowrmkedlonjloeuxtvkcqjzjeuddlnhalamvfrhvfsitwdsryetqnu";
    vector<string> words = {"pbolvrtdfefhqxcrrofyc","mewjykbnzjeazrxrkayoh","fgekzwyewctbyczidokos","kojihvkflslryxruvxrzq","uytvgyjsndddmnkhzrstc","lsbeowchwsbwnwemhxbkc","gwpqfqjzmmlenpumrckmd","gzcmnjjqulwscoytyxhkk","lzahntjzfphhruwadnwpj","ptypmwovizijzqzuzycog","jhahkdugugxoemccbymag","vbyuxytzobkwbsigoobuo","raatedrqfamiyigydhpes","lhmvoajrxzixabcfvslxg","vvpbwujlzdygptureloet","ogxslsmyrtuokxkeivflv","mcoiutwkzryfoqsidtzyp","qkmaqxywktknisjdoteis","jykdhpyipnyzcbqzzolsy","ycsjfjdjrxupjayzyhqoh","qqiirjyccwdgoomxtxqqu","gcwedwntkxlcfvvrtatpf","bgtnfnnwfjchfikdwgotr","sanorgqmyvoeqdldshldl","siufoslencwprmhyevwzl","cqrpvlzgpkbzggnytrnxq"};
    vector<int> ans = Solution().findSubstring(s, words);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}