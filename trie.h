#pragma once
#include <string>

#include "trienode.h"

class Trie
{
	private:
       void getAllChildInner(TrieNode* root, char buf[], std::uint32_t& ind, std::string& outgoingString);	   
	   
	public:
       	Trie();
	    TrieNode *GetNewNode();	
	    void Insert(TrieNode* root, const std::string& key);
		void GetAllChild(TrieNode* root, const std::string& prefix, std::string& outgoingString);
};