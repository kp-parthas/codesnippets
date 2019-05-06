#include <stdio.h>
#include <stdlib.h>

/****/
#define MAX_SIZE	10
typedef struct q_s {
	void *data;
	struct q_s *next;
} q_t;

void q_add(q_t **head, void *data)
{
	q_t *curr;
	q_t *node = malloc(sizeof(q_t));
	node->data = data;
	node->next = NULL;
	if (*head == NULL) {
		*head = node;
	} else {
		curr = *head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = node;
	}
}
q_t *q_del(q_t **head)
{
	q_t *curr;
	if (*head != NULL) {
		curr = *head;
		*head = curr->next;
		return curr;
	}
	return NULL;
}

/****/

typedef struct node_s {
	int a;
	struct node_s *left;
	struct node_s *right;
} node_t;

void preorder(node_t *root)
{
	if (root == NULL)
		return;

	printf("%d ", root->a);
	preorder(root->left);
	preorder(root->right);
}

void postorder(node_t *root)
{
	if (root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->a);
}
void inorder(node_t *root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	printf("%d ", root->a);
	inorder(root->right);
}

void bfs(node_t *root)
{
	node_t *curr = root;
	q_t *head = NULL, *q;
	q_add(&head, root);

	while (head != NULL) {
		q = q_del(&head);
		curr = (node_t *)q->data;
		if (curr->left != NULL)
			q_add(&head, curr->left);
		if (curr->right != NULL)
			q_add(&head, curr->right);
		printf("%d ", curr->a);
		free(q);
	}
}

int height(node_t *root)
{
	int lh = 0, rh = 0;

	if (!root) {
		return 0;
	}

	if (root->left) {
		lh = height(root->left);
	}
	if (root->right) {
		rh = height(root->right);
	}
	if (rh > lh) {
		return rh + 1;
	} else {
		return lh + 1;
	}
}

int main()
{
	node_t a1 = {1, NULL, NULL};
	node_t a2 = {2, NULL, NULL};
	node_t a3 = {3, NULL, NULL};
	node_t a4 = {4, NULL, NULL};
	node_t a5 = {5, &a1, &a2};
	node_t a6 = {6, &a3, &a4};
	node_t root = {7, &a5, &a6};

	printf("height = %d\n", height(&root));
	inorder(&root);
	printf("\n");
	preorder(&root);
	printf("\n");
	postorder(&root);
	printf("\n");
	bfs(&root);

}
