#include<stdio.h>
#include<string.h>
#include<stdlib.h>

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */


char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
	struct TreeNode		*queue_ptr[1025], *current_ptr;
	int			queue_index[1025], i, j, count_leaf = 0, q, current_index;
	int			tree[1025], front = 0, back = 1, leaf_flag[1025], index;
	char			**ret = NULL, *temp;	

	if (root == NULL) {
		*returnSize = 0;
		return NULL;
	}

	for (i=0; i<1025; i++)
		leaf_flag[i] = 0;

	//tree[1] = root->val;
	
	queue_ptr[0] = root;
	queue_index[0] = 1;
	while(front < back) {
		/* Dequeue and push children in queue */
		current_ptr = queue_ptr[front];
		current_index = queue_index[front++];
		
		if (current_ptr->left != NULL) {
			queue_index[back] = current_index*2;
			queue_ptr[back++] = current_ptr->left;
		}
		
		if (current_ptr->right != NULL) {
			queue_index[back] = current_index*2+1;
			queue_ptr[back++] = current_ptr->right;
		}
		
		/* Update tree */
		tree[current_index] = current_ptr->val;
		if(current_ptr->left == NULL &&
		   current_ptr->right == NULL) {
			leaf_flag[current_index] = 1;
			count_leaf++;
		}
	}

	/* Allocate memory for answer */
	ret = (char **)malloc(sizeof(char *)*count_leaf);
	for (i=0; i<count_leaf; i++)
		ret[i] = (char *)malloc(sizeof(char)*50);
	j = 0;
	for(i=0; i<1025; i++) {
		if (leaf_flag[i] == 1) {
			index = i;
			ret[j][0] = tree[i]+48;	
			q = 1;
			while(index != 1) {
				index = index/2;
				ret[j][q++] = '>';
				ret[j][q++] = '-';
				ret[j][q++] = index+48;	
			}
			ret[j][q] = '\0';
			temp = strrev(ret[j++]);		
		}
	}
	*returnSize = count_leaf;
	return ret;
}

int main() {
	struct TreeNode		input[10];
	char			**t = NULL;
	int			ans = 0;

	input[1].val = 1;
	input[2].val = 2;
	input[3].val = 3;
	input[4].val = 4;
	input[5].val = 5;
	input[6].val = 6;
	input[7].val = 7;

	input[1].left = &input[2];
	input[1].right = &input[3];
	
	input[2].left = &input[4];
	input[2].right = &input[5];

	input[3].left = &input[6];
	input[3].right = &input[7];

	input[4].left = NULL;
	input[4].right = NULL;

        input[5].left = NULL;
        input[5].right = NULL;

        input[6].left = NULL;
        input[6].right = NULL;

        input[7].left = NULL;
        input[7].right = NULL;

	t = binaryTreePaths(&input[1], &ans);	
	return 0;
}
