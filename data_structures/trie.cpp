// Also called prefix tree; a special form of a N-ary tree.

#include <unordered_map>
#include <iostream>
class TrieNode {
public:
  std::string val;
  std::unordered_map<char, TrieNode*> children;
  bool is_string;
};

class Trie {
private:
  

public:


};