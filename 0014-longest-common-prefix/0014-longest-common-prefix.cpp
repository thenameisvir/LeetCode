class TrieNode{
  public:
  char value;
  TrieNode* children[26];
  bool isTerminal;
  int childCount;

  TrieNode(char val){
    this->value = val;
    for(int i=0;i<26;i++){
      children[i] = NULL;
    }
    this->isTerminal = false;
    this->childCount = 0;
  }
};
class Solution {
public:
    void insertInTrie(TrieNode* root,string word){
  // if mere word ki length puri ho chuki hai toh uske last ko terminal mark kardo 
  if(word.length()==0){
    root->isTerminal = true;
    return;
  }

  // agar nahi toh uspr iterate karo aur last tak pohoch jao 
  char ch = word[0];
  int index = ch-'a';
  TrieNode* child;
  if(root->children[index]){
    // agar present hai toh uspr chale jao
    child = root->children[index];
  }
  else{
    // agar present nhi hai toh new node banao aur uspr chale jao
    child = new TrieNode(ch);
    root->children[index] = child;
    root->childCount++;
    
  }

  insertInTrie(child,word.substr(1));

}
bool isPresent(TrieNode* root,string word){
  // simplest code hai ye poore trie data structure ka , let's do it
  if(word.length()==0){
    return root->isTerminal;
  }
  // now just iterate baki recursion chota bhai apna toh hai hi
  char ch = word[0];
  int index = ch-'a';
  TrieNode* child;

  if(root->children[index]){
    // agar present hai toh uspr chale jao
    child = root->children[index];
  }
  else{
    return false;
    // return false hi karoge na kyuki kch present hi nahi hai bc idhar
  }

  bool ans =  isPresent(child,word.substr(1));
  return ans;
}
void deleteFromTrie(TrieNode* root,string word){
  if(word.length()==0){
    // bas uske last ko isTerminal ko false mark karde na bc
    root->isTerminal = false;
    return;
  }

  // ab bc baki ka kya same hi kardo na bc
  char ch = word[0];
  int index = ch-'a';
  TrieNode* child;

  if(root->children[index]){
    child = root->children[index];
  }
  else{
    return;
  }

  deleteFromTrie(child,word.substr(1));

}
void suggestionPart2(TrieNode* root,vector<string>&v,string input,string prefix){
  // pelte jao behenchod , agar terminal tk agaye hai toh push kardo vector me
  if(root->isTerminal){
    v.push_back(prefix+input);
  }

  for(int i='a';i<='z';i++){
    int index = i-'a';
    TrieNode* next = root->children[index];

    if(next){
      input.push_back(i);

      suggestionPart2(next,v,input,prefix);

      input.pop_back();
    }
  }

}
void suggestionPart1(TrieNode* root,vector<string>&v,string input,string prefix){
  // ab yaha aa hi gaye hai to vaha tak pohocho jaha sab khatam hota hai
  if(input.length()==0){
    suggestionPart2(root,v,input,prefix);
    return;
  }

  // ab kya bs apne ko toh iterate karna hai 
  char ch = input[0];
  int index = ch-'a';
  TrieNode* child;

  if(root->children[index]){
    child = root->children[index];
  }
  else{
    child = new TrieNode(ch);
    root->children[index] = child;
  }

  suggestionPart1(child,v,input.substr(1),prefix);

}

void findLCP(string &ans,TrieNode* root){
        if(root->isTerminal){
            return;
        }
        TrieNode* child;
        // abhi mai root node pr hu 
        if(root->childCount==1){
            // child tak jao ans me store karwao
            
            for(int i=0;i<26;i++){
                if(root->children[i]){
                    child = root->children[i];
                }
            }
            ans.push_back(child->value);
        }
        else{
            return;
        }

    findLCP(ans,child);

    }


    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        for(int i=0;i<strs.size();i++){
            insertInTrie(root,strs[i]);
        }

        string ans = "";
        string str = strs[0];
        findLCP(ans,root);
        return ans;
    }
};