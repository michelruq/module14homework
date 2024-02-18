#include <iostream>
#include <string>
#include "trie.h"

std::string test[] =  {"abcd",
                       "acbd",
                       "afgr",
					   "ahij",
					   "aklm",
					   "anop",
					   "aqrs",
					   "atuv",
					   "awxy",
					   "azad",
					   "abfh",
					   "abrs"};

int main(int argc, char* argv[])
{
   TrieNode* root = new TrieNode;
   
   for(uint32_t i = static_cast<uint32_t> (0); i < TrieNode::AlphabetSize; ++i)
   {
	   root->children[i] = nullptr;
   }
   root->mEndOfWord = false;
   
   Trie oTrie;

   for(uint32_t i = {0}; i < sizeof(test)/sizeof(std::string); ++i)
   {
	  oTrie.Insert(root, test[i]);
   }
   
   std::string outgoingString = "";
   oTrie.GetAllChild(root, argv[1], outgoingString);
   std::cout << outgoingString;
   
   delete root;
   
   return 0;	
}