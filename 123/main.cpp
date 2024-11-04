#include <iostream>
#include <unordered_map>
#include "Huffman.h"
#include<bits/stdc++.h>
int main() {

    std::string message ;
    std::cin>>message;

    // ͳ���ַ�Ƶ��
    std::unordered_map<char, int> frequency;
    for (char ch : message) {
        frequency[ch]++;
    }

    // ������������
    Node* root = buildTree(frequency);

    // ���ɹ���������
    std::unordered_map<char, std::string> codes;
    genCodes(root, "", codes);

    // ���뱨��
    std::string encodedMessage = encodeMsg(message, codes);
    std::cout << "Encoded Message: " << encodedMessage << std::endl;

    // ���뱨��
    std::string decodedMessage = decodeMsg(root, encodedMessage);

    std::cout << "Decoded Message: " << decodedMessage << std::endl;

    // �����ڴ�
    delete root; // ����������һ���������ݹ�ɾ�����Ľڵ��Ա����ڴ�й©

    return 0;
}
