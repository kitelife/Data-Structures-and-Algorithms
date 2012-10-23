/*
 * Trie, 又称字典树、单词查找树，是一种树形结构，用于保存大量的字符串。优点是：利用字符串的公共前缀来节约存储空间。
 * 其基本性质可以归纳为：
 * 1. 根节点不包含字符，除根节点外每一个节点都只包含一个字符
 * 2. 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串
 * 3. 每个节点的所有子节点包含的字符都不相同
 * */
/*
 * Name: Trie树的基本实现
 * Description：Trie树的基本实现，包括查找、插入和删除操作
 * */
#include <algorithm>
#include <iostream>
using namespace std;

const int sonnum = 26, base = 'a';
struct Trie
{
	int num;	// to remember how many word can reach here, that is to say, prefix
	bool terminal;	// if terminal==true, the current point has no following point
	struct Trie* son[sonnum];	// the following point
};

Trie* NewTrie()	// create a new node
{
	Trie* temp = new Trie;
	temp->num = 1;
	temp->terminal = false;
	for(int i = 0; i < sonnum; ++i)
		temp->son[i] = NULL;
	return temp;
}

void Insert(Trie *pnt, char *s, int len)	// insert a new word to Trie tree
{
	Trie* temp = pnt;
	for(int i=0; i<len; ++i)
	{
		if(temp->son[s[i]-base]==NULL)
			temp->son[s[i]-base]=NewTrie();
		else
			temp->son[s[i]-base]->num++;
		temp = temp->son[s[i]-base];
	}
	temp->terminal=true;
}

void Delete(Trie *pnt)	// delete the whole tree
{
	if(pnt != NULL)
	{
		for(int i=0; i < sonnum; ++i)
			if(pnt->son[i] != NULL)
				Delete(pnt->son[i]);
		delete pnt;
		pnt = NULL;
	}
}

Trie* Find(Trie *pnt, char *s, int len)	// trie to find the current word
{
	Trie* temp = pnt;
	for(int i=0; i < len; ++i)
	{
		if(temp->son[s[i]-base] != NULL)
			temp = temp->son[s[i]-base];
		else
			return NULL;
	}
	return temp;
}
