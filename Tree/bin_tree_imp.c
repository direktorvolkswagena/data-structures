#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;


TreeNode *get_node(int val);
void tree_display(TreeNode *root);


int main()
{
  TreeNode *N1 =
  return 0;
}


TreeNode *get_node(int val)
{
  TreeNode *new_node = malloc(sizeof(TreeNode));

  if(new_node != NULL)
  {
    new_node -> data = val;
    new_node -> left = NULL;
    new_node -> right = NULL;
  }

  return new_node;
}

void tree_display(TreeNode *root)
{
  if(root == NULL)
  {
    printf("Empty tree!\n");
    return;
  }

  printf("Value = %d\n", root -> data);

}
