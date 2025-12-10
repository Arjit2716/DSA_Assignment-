
class Node {
public:
    int key;
    int val;
    Node* next;
    Node(int k = -1, int v = -1, Node* n = nullptr) : key(k), val(v), next(n) {}
};

class MyHashMap {
private:
    vector<Node*> map;
    int capacity;

    int hash(int key) const {
        return key % capacity;
    }

public:
    MyHashMap() : capacity(1000) {
        map.resize(capacity);
        for (int i = 0; i < capacity; ++i) {
            map[i] = new Node(); // sentinel head for each bucket
        }
    }

    ~MyHashMap() {
        // free all lists
        for (int i = 0; i < capacity; ++i) {
            Node* cur = map[i];
            while (cur) {
                Node* tmp = cur;
                cur = cur->next;
                delete tmp;
            }
        }
    }

    void put(int key, int value) {
        int hash_key = hash(key);
        Node* cur = map[hash_key];
        // traverse using sentinel -> check cur->next for key
        while (cur->next) {
            if (cur->next->key == key) {
                cur->next->val = value; // update
                return;
            }
            cur = cur->next;
        }
        // insert at tail (after last node)
        cur->next = new Node(key, value);
    }

    int get(int key) {
        int hash_key = hash(key);
        Node* cur = map[hash_key];
        while (cur->next) {
            if (cur->next->key == key) {
                return cur->next->val;
            }
            cur = cur->next;
        }
        return -1;
    }

    void remove(int key) {
        int hash_key = hash(key);
        Node* cur = map[hash_key];
        while (cur->next) {
            if (cur->next->key == key) {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                return;
            }
            cur = cur->next;
        }
    }
};
