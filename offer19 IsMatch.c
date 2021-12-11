struct node{//代表有限状态自动机的节点
	struct rev *revlist;
	struct node *next;
};

struct rev{//代表以某个点为起点的有限状态自动机的连接线
	char matchChar;
	struct node *matchNode;
	struct rev *nextRev;
};

bool match(char *s, struct node *now){
	if (s[0] == '\0'){//字符检测结束，判断是否为最终节点
		if (now->revlist->nextRev == NULL){//节点自己为终止状态
			return true;
		}
		else{//判断节点是否可以通过匹配空值到达终止状态
			struct node *temp=now;
			while (temp->next != NULL)
				temp = temp->next;
			if (temp->revlist->nextRev == NULL)
				return true;
			else
				return false;
		}
	}
	else{//否则遍历节点所有的边
		struct rev *temp = now->revlist;
		while (temp != NULL){
			if (temp->matchChar == s[0] || temp->matchChar == '.'){//如果匹配，则递归
				if (match(s + 1, temp->matchNode) == true)
					return true;
			}
			temp = temp->nextRev;
		}
	}
	return false;
}

bool isMatch(char * s, char * p){
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->revlist = (struct rev*)malloc(sizeof(struct rev));
	head->revlist->matchChar = '\0';
	head->revlist->matchNode = NULL;
	head->revlist->nextRev = NULL;
	head->next = NULL;
	struct node *now = head;
	char *p_ptr = p;
	//构建有限状态自动机
	while (p_ptr[0] != '\0'){
		if (p_ptr[1] == '*'){//如果是*匹配
			struct node *newNode = NULL;
			newNode = (struct node*)malloc(sizeof(struct node));
			newNode->revlist = (struct rev*)malloc(sizeof(struct rev));
			newNode->revlist->matchChar = p_ptr[0];
			newNode->revlist->matchNode = newNode;
			newNode->revlist->nextRev = NULL;
			newNode->next = NULL;
			struct node *temp = now;
			struct rev *nowList = NULL;
			while (1){
				nowList = temp->revlist;
				while (nowList->nextRev != NULL)
					nowList = nowList->nextRev;
				nowList->nextRev = (struct rev*)malloc(sizeof(struct rev));
				nowList = nowList->nextRev;
				nowList->matchChar = p_ptr[0];
				nowList->matchNode = newNode;
				nowList->nextRev = NULL;
				if (temp->next == NULL){
					temp->next = newNode;
					break;
				}
				temp = temp->next;
			}
			p_ptr += 2;
		}
		else{//如果不是*匹配
			struct node *newNode = NULL;
			newNode = (struct node*)malloc(sizeof(struct node));
			newNode->revlist = (struct rev*)malloc(sizeof(struct rev));
			newNode->revlist->matchChar = '\0';
			newNode->revlist->matchNode = NULL;
			newNode->revlist->nextRev = NULL;
			newNode->next = NULL;
			struct rev *nowList = NULL;
			while (now != NULL){
				nowList = now->revlist;
				while (nowList->nextRev != NULL)
					nowList = nowList->nextRev;
				nowList->nextRev = (struct rev*)malloc(sizeof(struct rev));
				nowList = nowList->nextRev;
				nowList->matchChar = p_ptr[0];
				nowList->matchNode = newNode;
				nowList->nextRev = NULL;
				now = now->next;
			}
			now = newNode;
			p_ptr += 1;
		}
	}
	//遍历有限状态自动机，利用回溯
	return match(s, head);
}
