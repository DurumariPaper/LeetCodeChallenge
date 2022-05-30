class Solution {
public:
	vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
		unordered_map<string, std::vector<string>> m;
        for (const auto& synonym : synonyms) {
			m[synonym[0]].push_back(synonym[1]);
            m[synonym[1]].push_back(synonym[0]);
        }
		vector<string> v;
        stringstream ss(text);
        string s;
        while (std::getline(ss, s, ' ')) {
            v.push_back(s);
        }
        vector<string> results;
        dfs(results, m, v, 0, "");
		sort(results.begin(), results.end());
        return results;
    }
    
    // DFS to construct synonymous sentences
    void dfs(vector<string>& results, unordered_map<string,vector<string>>& m, const vector<string>& words, int index, const string& sentence) {
        if (index == words.size()) {
            results.push_back(sentence);
            return;
        }
        
        if (m.count(words[index])) {
            unordered_set<string> visited;
            vector<string> synonyms;
            dfs(m, words[index], visited, synonyms);
            for (const auto& synonym : synonyms) {
                dfs(results, m, words, index + 1, (sentence.empty() ? "" : sentence + " ") + synonym);   
            }
        } else {
			dfs(results, m, words, index + 1, (sentence.empty() ? "" : sentence + " ")  + words[index]);
		}
    }
    
    // DFS to construct synonymous words
    void dfs(unordered_map<string,vector<string>>& m, const string& word, unordered_set<string>& visited, vector<string>& synonyms) {
        synonyms.push_back(word);
        visited.insert(word);
        for (const auto& synonym : m[word]) {
            if (!visited.count(synonym)) {
                dfs(m, synonym, visited, synonyms);
            }
        }
    }
};