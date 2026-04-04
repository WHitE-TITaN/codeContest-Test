//converting preorder to tree structure
#include <vector>
#include <iostream> 

using namespace std;

//main data structure
class Tree{
  public:
  int data;
  Tree* leftNode = nullptr;     //left child
  Tree* rightNode = nullptr;    //right child
};



//function for tree creation
Tree *preOrderToTree(vector<int> &preorderVector, int &index){
  if(index >= preorderVector.size() || preorderVector[index] == -1){    //if index is out of bound
    index++;
    return nullptr;                                                     //or is null return nullptr
  }

  Tree* root = new Tree();                                                           //create a root
  root->data = preorderVector[index++];                                   //put data;
  root->leftNode = preOrderToTree(preorderVector, index);           //make leftchild
  root->rightNode = preOrderToTree(preorderVector, index);          //make rigthchild

  return root;
}



//function for preordertriversal of the tree
void preOrderTriversal(Tree *head){
  if(head == nullptr) return;

  std::cout<<head->data;
  preOrderTriversal(head->leftNode);
  preOrderTriversal(head->rightNode);
}



int main(){
  vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

  int index = 0;
  Tree *head = preOrderToTree(preorder, index);
  preOrderTriversal(head);

  return 0;
}