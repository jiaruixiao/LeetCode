/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_SIZE 80000
/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    /* 特判 */
    if (!root)  {
        return "[]";
    }
    /* 辅助队列 */
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX_SIZE);
    /* 返回数组 */
    char* res = (char*)calloc(MAX_SIZE, sizeof(char));
    /* 队列指针 */
    int front = 0, rear = 0;
    /* 队列初值 */
    queue[rear++] = root;
    /* 返回数组初值 */
    char tmpChar[10] = {0};
    sprintf(tmpChar, "%d", root->val);
    res[0] = '[';
    strcat(res, tmpChar);
    strcat(res, ",");
    /* 开始BFS */
    while (front < rear) {
        /* 记录当前队尾 */
        int curRear = rear;
        /* 当前层 */
        while (front < curRear) {
            if (queue[front]->left) {   /* 当前节点的左孩子存在 */
                queue[rear++] = queue[front]->left;
                memset(tmpChar, 0, 10);
                sprintf(tmpChar, "%d", queue[front]->left->val);
                strcat(res, tmpChar);
                strcat(res, ",");
            } else {   /* 当前节点的左孩子不存在 */
                strcat(res, "null,");
            }
            if (queue[front]->right) {   /* 当前节点的右孩子存在 */
                queue[rear++] = queue[front]->right;
                memset(tmpChar, 0, 10);
                sprintf(tmpChar, "%d", queue[front]->right->val);
                strcat(res, tmpChar);
                strcat(res, ",");
            } else {   /* 当前节点的右孩子不存在 */
                strcat(res, "null,");
            }
            /* 当前层的下一节点 */
            front++;
        }
    }
    /* 找到最后的那个","将其变为"]" */
    int len = strlen(res);
    for (; len >= 0; len--) {
        if (res[len] >= '0' && res[len] <= '9') {
            len++;
            break;
        }
    }
    res[len] = ']';
    res[len + 1] = '\0';
    /* 返回 */
    return res;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    /* 特判 */
    if (!data || strcmp(data, "[]") == 0) {
        return NULL;
    }
    /* 辅助队列 */
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX_SIZE);
    /* 队列指针 */
    int front = 0, rear = 0;
    /* 记录字符串中的数字 */
    char num[10] = {0};
    memset(num, 0, 10);
    /* point为num的索引指针 */
    int point = 0;
    /* 串长度 */
    int len = strlen(data);
    for (int i = 1; i < len; i++) {
        if (data[i] == ',' || data[i] == ']') { /* 当前单词结束 */
            struct TreeNode* tmp;
            if (strcmp(num, "null") == 0) { /* 当前单词为NULL */
                tmp = NULL;
            } else {
                tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                if (!tmp) {
                    return NULL;
                }
                memset(tmp, 0, sizeof(struct TreeNode));
                tmp->val = atoi(num);
            }
            /* 节点入队列 */
            queue[rear++] = tmp;
            /* num清零 */
            point = 0;
            memset(num, 0, 10);
        } else { /* 当前字符不为单词结束 */
            num[point++] = data[i];
        }
    }
    /* point置为1 */
    point= 1;
    /* 返回结果的根节点 */
    struct TreeNode* root = queue[0];
    /* 层序构造二叉树 */
    for (int i = 0; i < rear; i++) {
        struct TreeNode* tmp = queue[i];
        /* 当前节点不为空 */
        if (tmp) {
            /* 左孩子不为叶子节点 */
            if(point < rear) {
                tmp->left = queue[point];
            }
            /* 右孩子不为叶子节点 */
            if (point + 1 < rear) {
                tmp->right = queue[point + 1];
            }
            /* 指向下一节点的孩子节点 */
            point += 2;
        }
    }
    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
