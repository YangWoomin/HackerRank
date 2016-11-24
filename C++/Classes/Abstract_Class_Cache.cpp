#include "header.h"

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {
protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function
};

class LRUCache : public Cache {
public:
	LRUCache(int capacity) {
		this->cp = capacity;
		head = NULL;
		tail = NULL;
	}

	Node* findNode(int key) {
		if (mp.find(key) != mp.end()) {
			return mp.at(key);
		}
		else {
			return NULL;
		}
	}

	void setNodeFirst(Node* node) {
		if (head == node) {
			return;
		}
		else if(tail == node) {
			tail = tail->prev;
			head = node;
		}
		else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
			node->prev = tail;
			node->next = head;
			head = node;
		}
	}

	void insertNode(int key, int value) {
		if (cp < 1) return;
		Node *node = new Node(key, value);
		if (node == NULL) {
			return;
		}
		mp.insert(pair<int, Node*>(key, node));
		if (head != NULL) {
			if (head->next != NULL) {
				node->next = head;
				node->prev = head->prev;
				node->prev->next = node;
				head->prev = node;
			}
			else {
				head->next = node;
				head->prev = node;
				node->next = head;
				node->prev = head;
				tail = head;
			}
		}
		else {
			tail = node;
		}
		head = node;

		if (mp.size() > cp) {
			int delKey = tail->key;
			tail = tail->prev;
			delete mp.at(delKey);
			mp.erase(delKey);
		}
	}

	void set(int key, int value) {
		Node *node = findNode(key);
		if (node == NULL) {
			insertNode(key, value);
		}
		else {
			node->value = value;
			setNodeFirst(node);
		}
	}

	int get(int key) {
		Node *node = findNode(key);
		if (node == NULL) {
			return -1;
		}
		else {
			setNodeFirst(node);
			return node->value;
		}
	}

	~LRUCache() {
		map<int, Node*>::iterator mi;
		for (mi = mp.begin(); mi != mp.end(); mi++) {
			delete mi->second;
		}
	}
};

void cacheTest() {
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i<n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}
}