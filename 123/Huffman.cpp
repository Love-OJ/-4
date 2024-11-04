#include "Huffman.h"
#include <queue>
#include <vector>

// 比较器，用于优先队列
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq; // 小根堆
    }
};
//写注释
// 生成哈夫曼编码
void genCodes(Node* root, const std::string& str, std::unordered_map<char, std::string>& codes) {
    if (!root) return;

    // 如果是叶子节点，保存编码
    if (!root->left && !root->right) {
        codes[root->ch] = str;
    }

    genCodes(root->left, str + "0", codes);
    genCodes(root->right, str + "1", codes);
}

// 编码报文
std::string encodeMsg(const std::string& msg, std::unordered_map<char, std::string>& codes) {
    std::string encoded;
    for (char ch : msg) {
        encoded += codes[ch];
    }
    return encoded;
}

// 解码报文
std::string decodeMsg(Node* root, const std::string& encoded) {
    std::string decoded;
    Node* currentNode = root;

    for (char bit : encoded) {
        currentNode = (bit == '0') ? currentNode->left : currentNode->right;

        // 到达叶子节点
        if (!currentNode->left && !currentNode->right) {
            decoded += currentNode->ch;
            currentNode = root; // 返回根节点
        }
    }
    return decoded;
}

// 构建哈夫曼树
Node* buildTree(const std::unordered_map<char, int>& freq) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;

    // 将每个字符和频率放入优先队列
    for (const auto& pair : freq) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // 构建哈夫曼树
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        minHeap.push(merged);
    }

    return minHeap.top(); // 返回根节点
}
