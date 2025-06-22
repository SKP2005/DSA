class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>list;
        for(auto word:wordList){
            list.insert(word);
        }
        queue<string>q;
        q.push(beginWord);
        int ans=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string word=q.front();
                if(word==endWord) return ans;
                q.pop();
                list.erase(word);
                for(int k=0;k<word.size();k++){
                    char c=word[k];
                    for(int j=0;j<26;j++){
                        word[k]='a'+j;
                        if(list.find(word)!=list.end()){
                            q.push(word);
                            list.erase(word);
                        }
                    }
                    word[k]=c;
                }
                
            }
            ans++;
        }
        return 0;
    }
};