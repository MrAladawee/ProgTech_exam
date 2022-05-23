#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

void add(tree*& root, string new_word, double score, int level) {
    if (!root) { // root == nullptr
        tree* newelem = new tree;
        newelem->name = new_word;
        newelem->lvl = level;
        newelem->av_score = score;
        root = newelem;
        return;
    }

    if (root->name > new_word) {
        add(root->left, new_word, score, level+1);
        return;
    }

    if (root->name < new_word) {
        add(root->right, new_word, score, level + 1);
        return;
    }
    if (root->name == new_word) {
        root->count++;
        return;
    }
}

void showTree(tree* root, int level) {

    if (!root) {
        return;
    }

    if (root->left != nullptr) { showTree(root->left, level); }
    for (int i = 0; i < root->lvl; i++) {
        cout << ".";
    }
    cout << root->name << " (" << root->av_score << ") " << endl;
    if (root->right != nullptr) { showTree(root->right, level--); }

}

bool find_in_tree(tree* root, string find_word) { 

    if (!root) { return false; } 
    
    if (root->word == find_word) { 
        cout << find_word << " (" << root->count << ") lvl:" << root->lvl << endl; 
        return true; 

    } 

    if (root->word > find_word) { 
        if (root->left == nullptr) { 
            cout << "not_found"<<endl; 
            return false; 
        } 

        else { return find_in_tree(root->left, find_word); } 
    } 

    if (root->word < find_word) { 
        if (root->right == nullptr) { 
            cout << "not_found" << endl; 
            return false; 
        } 

        else { return find_in_tree(root->right, find_word); } 
    } 
}

void clearTree(tree* node){
    if(node != NULL){
        if(node->left != NULL)
            clearTree(node->left);
        if(node->right != NULL)
            clearTree(node->right);
        delete node;
    }
}
