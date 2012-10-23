#include <iostream>
#include <string.h>
using namespace std;

const int branchNum = 26;	// 声明常量
int i;

struct Trie_node
{
	bool isStr;	// 记录此处是否构成一个串
	Trie_node *next[branchNum];	// 指向各个子树的指针，下标0-25代表26个字符
	Trie_node():isStr(false)
	{
		memset(next, NULL, sizeof(next));
	}
};

class Trie
{
public:
	Trie();
	void insert(const char* word);
	bool search(char* word);
	void deleteTrie(Trie_node *root);
private:
	Trie_node* root;
};

Trie::Trie()
{
	root = new Trie_node();
}

void Trie::insert(const char* word)
{
	Trie_node *location = root;
	while(*word)
	{
		if(location->next[*word-'a'] == NULL)	//不存在则建立
		{
			Trie_node *tmp = new Trie_node();
			location->next[*word-'a'] = tmp;
		}
		location = location->next[*word-'a'];	// 每插入一步，相当于有一个新串经过，指针要向下移动
		word++;
	}
	location->isStr = true;	// 到达尾部，标记一个串
}

bool Trie::search(char *word)
{
	Trie_node *location = root;
	while(*word && location){
		location = location->next[*word-'a'];
		word++;
	}
	return (location!=NULL && location->isStr);
}

void Trie::deleteTrie(Trie_node *root)
{
	for(int i = 0; i < branchNum; i++)
	{
		if(root->next[i] != NULL)
		{
			deleteTrie(root->next[i]);
		}
	}
	delete root;
}

int main()	// 简单测试
{
	Trie t;
	t.insert("a");
	t.insert("abandon");
	char *c = "abandoned";
	t.insert(c);
	t.insert("abashed");
	if(t.search("abashed"))
        cout << "true" << endl;
    if(t.search("a"))
        cout << "true" << endl;
    if(t.search("abab"))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
