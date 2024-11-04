#include "Huffman.h"
#include <queue>
#include <vector>

// �Ƚ������������ȶ���
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq; // С����
    }
};

// ���ɹ���������
void genCodes(Node* root, const std::string& str, std::unordered_map<char, std::string>& codes) {
    if (!root) return;

    // �����Ҷ�ӽڵ㣬�������
    if (!root->left && !root->right) {
        codes[root->ch] = str;
    }

    genCodes(root->left, str + "0", codes);
    genCodes(root->right, str + "1", codes);
}

// ���뱨��
std::string encodeMsg(const std::string& msg, std::unordered_map<char, std::string>& codes) {
    std::string encoded;
    for (char ch : msg) {
        encoded += codes[ch];
    }
    return encoded;
}

// ���뱨��
std::string decodeMsg(Node* root, const std::string& encoded) {
    std::string decoded;
    Node* currentNode = root;

    for (char bit : encoded) {
        currentNode = (bit == '0') ? currentNode->left : currentNode->right;

        // ����Ҷ�ӽڵ�
        if (!currentNode->left && !currentNode->right) {
            decoded += currentNode->ch;
            currentNode = root; // ���ظ��ڵ�
        }
    }
    return decoded;
}

// ������������
Node* buildTree(const std::unordered_map<char, int>& freq) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;

    // ��ÿ���ַ���Ƶ�ʷ������ȶ���
    for (const auto& pair : freq) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // ������������
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        minHeap.push(merged);
    }

    return minHeap.top(); // ���ظ��ڵ�
}
