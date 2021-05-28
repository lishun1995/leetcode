#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
ʵ��һ�� Trie (ǰ׺��)������ insert, search, �� startsWith ������������

ʾ��:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // ���� true
trie.search("app");     // ���� false
trie.startsWith("app"); // ���� true
trie.insert("app");   
trie.search("app");     // ���� true
˵��:

����Լ������е����붼����Сд��ĸ a-z ���ɵġ�
��֤���������Ϊ�ǿ��ַ�����
*/

struct TrieNode
{
	bool isStr;
	TrieNode *next[26];

	TrieNode(){
		isStr= false;
	}

	~TrieNode()
	{
		//delete[] next;
	}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
		root->isStr = false;
		memset(root->next,NULL,sizeof(root->next));
        
        node_vec.push_back(root);
    }
    
	~Trie(){
		 for (int i = 0; i < node_vec.size(); ++i)
            delete node_vec[i];
	}

    /** Inserts a word into the trie. */
    void insert(string word) {
		TrieNode *Location = root;

        for (int i = 0; i < word.size(); i ++)
        {
			if(Location->next[word[i] - 'a'] == NULL)
			{
				TrieNode *newNode = new TrieNode;
				newNode->isStr = false;
				memset(newNode->next,NULL,sizeof(newNode->next));

				Location->next[word[i] - 'a'] = newNode;
			}
			Location = Location->next[word[i] - 'a'];
        }
		Location->isStr = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *location = root;

		for (int i = 0; i < word.size(); i++)
		{
			if(location)
			{
				location = location->next[word[i] - 'a'];
			}
			else
			{
				return false;
			}
		}
        
        if(location)
        {
            return location->isStr;
        }
		return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         TrieNode *location = root;

		 for(int i = 0; i < prefix.size(); i++ )
		 {
			 if(location)
			 {
				 location = location->next[prefix[i] - 'a'];
			 }
			 else
			 {
				 return false;
			 }
		 }
         
        if(location == NULL)
        {
            return false;
        }
		 return true ;
    }

private:
	TrieNode *root;
    vector<TrieNode*> node_vec;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int mainTries()
{
	bool res = false;

	Trie *trie = new Trie();

	//trie->insert("apple");
	//res = trie->search("apple");   // ���� true
	//res = trie->search("app");     // ���� false
	//res = trie->startsWith("app"); // ���� true
	//trie->insert("app");   
	//res = trie->search("app");     // ���� true

	res = trie->startsWith("a"); 

	return 0;
}