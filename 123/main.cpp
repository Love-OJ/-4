#include <iostream>
#include <unordered_map>
#include "Huffman.h"
#include<bits/stdc++.h>
int main() {

    std::string message ;
    std::cin>>message;

    // 统计字符频率
    std::unordered_map<char, int> frequency;
    for (char ch : message) {
        frequency[ch]++;
    }

    // 构建哈夫曼树
    Node* root = buildTree(frequency);

    // 生成哈夫曼编码
    std::unordered_map<char, std::string> codes;
    genCodes(root, "", codes);

    // 编码报文
    std::string encodedMessage = encodeMsg(message, codes);
    std::cout << "Encoded Message: " << encodedMessage << std::endl;

    // 解码报文
    std::string decodedMessage = decodeMsg(root, encodedMessage);

    std::cout << "Decoded Message: " << decodedMessage << std::endl;

    // 清理内存
    delete root; // 这里可以添加一个函数来递归删除树的节点以避免内存泄漏

    return 0;
}
