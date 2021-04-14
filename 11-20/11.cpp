class TrieNode{
public:
    TrieNode* next[26];
    int endHere;
    
    TrieNode(){
        memset(next,0,sizeof(next));
        endHere = 0;
    }
};

class Trie {
public:
    
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
       root = new TrieNode();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        int n = word.length();
        
        if(n == 0){
            return ;
        }
        
        for(int i=0; i<n; i++){
            
            if(curr->next[word[i] - 'a'] == NULL){
                curr->next[word[i] - 'a'] = new TrieNode();
            }
            
            curr = curr->next[word[i] - 'a'];
        }
        
        curr->endHere++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = find(word);
        
        return p != NULL && p->endHere != 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = find(prefix);
        
        return p != NULL;
    }
    
    bool isLast(TrieNode* node){
        for(int i=0; i<26; i++){
            if(node->next[i] != NULL){
                return false;
            }
        }
        
        return true;
    }
    
    TrieNode* find(string word){
        TrieNode* curr = root;
        int n = word.length();
        
        for(int i=0; i<n && curr != NULL; i++){
           
            curr = curr->next[word[i] - 'a'];
        }
        
        return curr;
    }
    
    void suggestions(string currWord, TrieNode* node, vector<string> &ans){
        if(node->endHere){
            ans.push_back(currWord);
        }
        
        if(isLast(node)){
            return ;
        }
        
        for(int i=0; i<26; i++){
            if(node->next[i] != NULL){
                currWord += ('a' + i);
                suggestions(currWord, node->next[i], ans);
                currWord.pop_back();
            }
        }
    }
    
    vector<string> autoComplete(string query){
        int n = query.size();
        
        bool prefixPresent = startWith(query);
        
        if(!prefixPresent){
            return {};
        }
        
        TrieNode* curr = find(query);
        bool wordPresent = curr->endHere != 0;
        
        if(isLast && wordPresent){
            return {query};
        }
        
        else if(!last){
            
            vector<string> ans;
            
            suggestions(query,curr,ans);
            
            
            return ans;
        }
        
    }
};

