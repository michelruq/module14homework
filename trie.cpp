#include <cstdint>
#include <iostream>

#include "Trie.h"

Trie::Trie()
{
	
}

TrieNode* Trie::GetNewNode()
{
   struct TrieNode * newNode = new TrieNode;
   
   newNode->mEndOfWord = false;
   
   for(uint32_t i = static_cast<uint32_t>(0); i < TrieNode::AlphabetSize; ++i)
   {
	   newNode->children[i] = nullptr;
   }
   
   return newNode;
}

void Trie::Insert(TrieNode* root, const std::string& key) 
{
    struct TrieNode *pCrawl = root;
   
    for (uint32_t i = static_cast<uint32_t>(0); i < key.length(); ++i)
	{
		uint32_t index = key[i] - 'a';
		if (!pCrawl->children[index])
		{
			pCrawl->children[index] = GetNewNode();
		}

		pCrawl = pCrawl->children[index];
	}

	pCrawl->mEndOfWord = true;
}	

void Trie::GetAllChild(TrieNode* root, const std::string& prefix, std::string& outgoingString)
{
	if(!root)
	{
		return;
	}
	
	bool result = true;
	
	for (uint32_t i = static_cast<uint32_t>(0); i < prefix.length(); ++i)
	{
		uint32_t index = prefix[i] - 'a';
		if (!root->children[index])
		{
			result = false;
			break;
		}

		root = root->children[index];
	}
	
    char buf[100] = {};
	std::uint32_t ind = 0;
	if(result)
	{
		getAllChildInner(root, buf, ind, outgoingString);
	}

}

void Trie::getAllChildInner(TrieNode* root, char buf[], std::uint32_t& ind, std::string& outgoingString)
{
	if(!root)
	{
		return;
	}
	
	if(root->mEndOfWord)
	{
		outgoingString += buf;
		outgoingString += '\n';
	}
	
	for(std::uint32_t i = static_cast<std::uint32_t>(0); i < TrieNode::AlphabetSize; ++i)
    {
        if(root->children[i] != nullptr)
        {
            buf[ind] += i + 'a';
			++ind;
            getAllChildInner(root->children[i], buf, ind, outgoingString);
			--ind;
			buf[ind] = '\0';
        }
    }
}
