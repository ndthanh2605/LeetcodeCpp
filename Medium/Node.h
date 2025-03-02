struct ListNode {
	int val;
	ListNode* next;
	ListNode* prev;
	ListNode() : val(0), next(nullptr), prev(nullptr) {}
	ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next), prev(nullptr) {}
	
};