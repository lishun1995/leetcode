#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
���һ��֧���������ֲ��������ݽṹ��

void addWord(word)
bool search(word)
search(word) �����������ֻ�������ʽ�ַ������ַ���ֻ������ĸ . �� a-z �� . ���Ա�ʾ�κ�һ����ĸ��

ʾ��:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
˵��:

����Լ������е��ʶ�����Сд��ĸ a-z ��ɵġ�
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


class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
		root->isStr = false;
		memset(root->next,NULL,sizeof(root->next));

		node_vec.push_back(root);
	}

	~WordDictionary()
	{
		for (int i = 0; i < node_vec.size(); ++i)
			delete node_vec[i];
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
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

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		if(word.empty())
			return false;

		TrieNode *location = root;
		return _search(word,0,location);
	}

	bool _search(const string &word,int pos,TrieNode *node)
	{
		if(pos == word.size())
			return true;

		if(word[pos] == '.')
		{
			for(int i = 0; i < 26; i++)
			{
				if(node && node->next[i] )
					return _search(word,pos + 1, node->next[i]);
			}
			return false;
		}
		if(node && node->next[word[pos] - 'a'])
		{
			return _search(word,pos + 1,node->next[word[pos] - 'a']);
		}

		return false;
	}

private:
	TrieNode *root;
	vector<TrieNode*> node_vec;
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
*/

int mainsblishun()
{
	bool res;

	WordDictionary* obj = new WordDictionary();
	/*obj->addWord("bad");
	obj->addWord("dad");
	obj->addWord("mad");
	res = obj->search("pad");
	res = obj->search("bad");
	res = obj->search(".ad");
	res = obj->search("b..");*/

	/*
	["WordDictionary","addWord","addWord","search","search","search","search","search","search"]
	[[],["a"],["a"],["."],["a"],["aa"],["a"],[".a"],["a."]]
	*/
	/*
	["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
	[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
	*/

	obj->addWord("a");
	obj->addWord("a");
	res = obj->search(".");
	res = obj->search("a");
	res = obj->search("aa");
	res = obj->search(".a");
	res = obj->search(".a");
	res = obj->search("a.");


	getchar();
	return 0;
}

