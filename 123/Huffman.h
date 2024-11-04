#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>
#include "Node.h"

// º¯ÊýÉùÃ÷
void genCodes(Node* root, const std::string& str, std::unordered_map<char, std::string>& codes);
std::string encodeMsg(const std::string& msg, std::unordered_map<char, std::string>& codes);
std::string decodeMsg(Node* root, const std::string& encoded);
Node* buildTree(const std::unordered_map<char, int>& freq);

#endif // HUFFMAN_H
