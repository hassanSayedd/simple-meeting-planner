using namespace std;
class BinarySearchTree {
	public:
		BinarySearchTree();
		bool isEmpty() const;
		void getData(string &n,int &d,int &h);
		void add(string &n,const int &d,const int &h);
		BinarySearchTree * retrieve(const int &d,const int &h);
		BinarySearchTree * left();
		BinarySearchTree * right();
		void makeLeft(BinarySearchTree * T1);
		void makeRight(BinarySearchTree * T1);
		string find(const int &d,const int &h);
		void modify(string &n,const int &d,const int &h); //
		BinarySearchTree* delet(BinarySearchTree * root,const int &d,const int &h); //
		void print(BinarySearchTree * T1);
		BinarySearchTree* FindMin(BinarySearchTree* root);

	private:
		bool nullTree;
		string name;
		int day;
		int hour;
		BinarySearchTree * leftTree;
		BinarySearchTree * rightTree;
};
