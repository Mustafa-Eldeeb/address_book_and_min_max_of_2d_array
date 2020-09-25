// CPP program to display content of Trie 
#include <iostream> 
#include <string.h> 
#define alpha_size 26 
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0]) 

using namespace std; 

// Trie node 
struct TrieNode 
{ 
    string address;
	struct TrieNode* children[alpha_size]; 


	bool isLeaf; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode* create_node() 
{ 
	struct TrieNode* pNode = new TrieNode; 

	for (int i = 0; i < alpha_size; i++) 
		pNode->children[i] = NULL; 

	pNode->isLeaf = false; 

	return pNode; 
}; 

// function to insert a node in Trie 
void insert_node(struct TrieNode* root, char* name,string addr) 
{ 
	int level; 
	int length = strlen(name); 
	struct TrieNode* pc = root; 

	for (level = 0; level < length; level++) 
	{ 
		int index = name[level] - 'a'; 

		if (pc->children[index] == NULL) 
			pc->children[index] = create_node(); 

		pc = pc->children[index]; 
	} 
    pc->address=addr;

	pc->isLeaf = true; 
} 

// function to check if current node is leaf node or not 
bool isLeafNode(struct TrieNode* root) 
{ 
	return root->isLeaf != false; 
} 

//func to search
bool search(struct TrieNode *root, string key,string addr) 
{ 
    struct TrieNode *pc = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pc->children[index]) 
		{
			cout<<"				No name found !!"<<std::endl;
            return false; 
		}
        pc = pc->children[index]; 
    } 
	if(pc->address != addr)
	{
		cout<<"				address doesn't match with name !!"<<std::endl;
		return false;
	}
	cout<<"				found !!\n"<<std::endl;
    return (pc != NULL && pc->isLeaf ); 
} 
// function to display the content of Trie 
void display(struct TrieNode* root, char str[],int level=0) 
{ 
    
	// If node is leaf node, it indicates end 
	// of string, so a null character is added 
	// and string is displayed 
	if (isLeafNode(root)) 
	{ 
		str[level] = '\0'; 
		cout << str <<"			"<<root->address<< endl; 
		cout<<std::endl;
	} 

	int i; 
	for (i = 0; i < alpha_size; i++) 
	{ 
		// if NON NULL child is found 
		// add parent key to str and 
		// call the display function recursively 
		// for child node 
		if (root->children[i]) 
		{ 
			str[level] = i + 'a'; 
			display(root->children[i], str, level + 1); 
		} 
	} 
    //cout<<root->address<<std::endl;
} 

//the driver program for testing
int main() 
{ 
	// names and addresses to be inserted in Trie 
	char names[][8] = { "auatafa", "ahmed", "tamer", "john", 
					"zidan", "kareem", "ronaldo", "nour" };
    
	string addresses[8] = { "14 damanhour", "29 mustafa st cairo", "21 st fakeAddress", "24-st.a aswan", 
					"Giza", "12_st.cairo", "12st.oman", "Alexandria" }; 

	struct TrieNode* book1 = create_node(); 

	// to insert names with addresses in Trie 
	for (int j = 0; j < ARRAY_SIZE(names); j++) 
		insert_node(book1, names[j],addresses[j]); 

	//int level = 1; 
	char str[20]; 

	// to visiualize or print the contents 
	cout << "Content of address book : " << endl; 

	cout<<std::endl;

	display(book1, str,0); 

	cout << "\nsearching for wrong name : \n\n" ;
	search(book1,"saad","12_st.cairo");
	cout << "\nsearching for wrong address : \n" << endl;
	search(book1,"kareem","14253_st.helawn");
	cout << "\nsearching for both correct name and address  : \n" << endl;
	search(book1,"kareem","12_st.cairo");
	//cout<<search(book1,"saad","helawn")<<std::endl;
} 
