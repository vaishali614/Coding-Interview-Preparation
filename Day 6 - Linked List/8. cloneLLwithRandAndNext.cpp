/** Clone a LL with next and random pointer **/
/*
1. Use hashmaps to store the deepcopy of every node and then make the connections in the second traversal. // T: O(N) + O(N) = O(2 * N), S: O(N)
	Node* copyRandomList(Node* head) {
	    	if(head == NULL)
		    return NULL;

		map<Node*, Node*> deepCopy;
		Node* temp = head;
		while(temp){
		    Node* copy = new Node(temp->val);
		    deepCopy[temp] = copy;
		    temp = temp->next;
		}

		temp = head;
		while(temp){
		    Node* copy = deepCopy[temp];
		    copy->next = deepCopy[temp->next];
		    copy->random = deepCopy[temp->random];
		    temp = temp->next;
		}
		return deepCopy[head];
	}
2. 3 step process // T: O(N), S: O(1)
	- Create deep copy nodes and insert in between two nodes. Eg. 1 -> 2 -> NULL => 1 -> 1' -> 2 -> 2' -> NULL
	- Connect random pointers: curr->next->random = curr->random->next
	- curr = curr->next->next
	- Separate original and deep copy LL 
*/

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
