template <typename T>
class AVLNode {
public:
	T data;
	AVL Node* left;
	AVL Node* right;
	int height;

	AVL Node(T value): 
		data(value),
		left(nullptr),
		right(nullptr),
		height(1){}
	    ~AVL Node() {}
};