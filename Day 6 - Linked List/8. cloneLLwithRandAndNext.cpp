class Node{
	Node* next, *rand;
	int data;
};

Node* addDup(Node* head){
	Node* temp = head;
	while(temp){
		Node* dup = new Node(temp->data);
		Node* nxt = temp->next;
		temp->next = dup;
		dup->next = nxt;
		temp = temp->next->next;
	}
	return head;
}

Node* seperateDup(Node* head){
	Node* temp = head, *dup = head->next, *dupTail = head->next;
	while(temp && temp->next){
		temp->next = temp->next->next;
		if(temp->next)
			dupTail->next = temp->next->next;
		else
			dupTail->next = NULL;
		temp = temp->next;
		dupTail = dupTail->next;
	}
	return dup;
}

Node* random(Node* head){
	if(head == NULL)
		return NULL;
	head = addDup(head);
	Node* temp = head;
	while(temp && temp->next){
		if(temp->rand)
			temp->next->rand = temp->rand->next;
		else 
			temp->next->rand = NULL;
		temp = temp->next->next;
	} 
	Node* dup = seperateDup(head);
	return dup; // (the copy of list will be at every second next ptr)
}
