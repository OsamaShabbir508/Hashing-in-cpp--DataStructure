// Hashing-Chaining.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node()
	{
		data = NULL;
		next = NULL;
	}
};
class HashTable
{
public:
	Node* ChainStart;
	HashTable()
	{
		ChainStart = NULL;
	}

};

class Hash
{
public:
	HashTable* Hash_bucket = new HashTable[10];// habtable bana rha node type ka jo null kr ra construc m.
	
	Hash()
	{
		for (int i = 0; i < 10; i++)
		{
			Hash_bucket[i].ChainStart = NULL;//new HashTable();
		}
	}

	int hash(int key)
	{
		return key % 10;
	}
	void Insert(int key)
	{
		int possIn_hashBucket = hash(key);
		if (Hash_bucket[possIn_hashBucket].ChainStart==NULL)// dkh rha k h.table ksi chain ko point kr rh ya nh.
		{
			Node* chain_node = new Node;
			chain_node->data = key;
			Hash_bucket[possIn_hashBucket].ChainStart = chain_node;
		}
		else
		{// chain mojod hia ,lehaza ak new node insert kro or jo phly s mokod h uska address new waly k next m dalo,
			//ab hashtable new waly ko point kry.
			Node* chain_node = new Node;
			chain_node->data = key;
			Node* prev_chainnode=Hash_bucket[possIn_hashBucket].ChainStart;
			chain_node->next = prev_chainnode;
			Hash_bucket[possIn_hashBucket].ChainStart = chain_node;
			//Node* constructing_chain = &Hash_bucket[possIn_hashBucket]; ye end main append krwany ka code hai
			//isi lie isy commment kia. uapr shuru m append krwa rha.
			//while (constructing_chain->next != NULL)
			//{
			//	constructing_chain = constructing_chain->next;
			//}
			//constructing_chain->next = chain_node;
		}
	}
	void Search(int key)
	{
		int  possIn_hashBucket = hash(key);
		//Node* Bucket_addres = Hash_bucket[possIn_hashBucket];
		if (Hash_bucket[possIn_hashBucket].ChainStart==NULL)// hash table k pointer k against koi chain nh.
		{
			cout << " The element " << key << " is not Present\n";
		}
		else
		{   
			Node* Bucket_addres = Hash_bucket[possIn_hashBucket].ChainStart;//h.table k againts chain k adress lerha
			bool notfind = true;
			while (Bucket_addres != NULL)
			{
				if (Bucket_addres->data == key)
				{
					notfind = false;
					cout << " The element " << key << " is Present\n";
					break;
				}
				else
				{
					Bucket_addres = Bucket_addres->next;
				}
			}
			if (notfind == true)
			{
				cout << " The element " << key << " is not Present\n";

			}

		}
	}


	void Delete(int key)
	{
		int  possIn_hashBucket = hash(key);
		bool notfind = true;//agr element mil jyega tou false hojye.
		if (Hash_bucket[possIn_hashBucket].ChainStart == NULL)//hash table ka pointer null h ya nh,check kr rha.
		{
			cout << " The element " << key << " is not Present and Nothing to delete\n";
		}
		else if (Hash_bucket[possIn_hashBucket].ChainStart->data==key)//agr hash table null nh or table ka pointer 
			//phly node ko point kr or element usi node m mojod ho.
		{
			notfind = false;
			cout << " Element is Found " << key << " is now Deletd\n";

			if (Hash_bucket[possIn_hashBucket].ChainStart->next != NULL)
			{//ye check kr rha k jo jis node main mojod hai wo kso ko point out tu nh kr rh.
				//Agr kr rh tou usy hashtable k pointer m dal do.
				Node* temp = Hash_bucket[possIn_hashBucket].ChainStart->next;
				delete Hash_bucket[possIn_hashBucket].ChainStart;
				Hash_bucket[possIn_hashBucket].ChainStart->next = temp;
			}
			else
			{
				// yahan ka matlab elemnt chain main akela hai.
                delete Hash_bucket[possIn_hashBucket].ChainStart;
				Hash_bucket[possIn_hashBucket].ChainStart =NULL;
			}
		}
		else
		{//ye is lie k elemnt phly node pr ,mojod nh hai.
			Node* element_to_deleted_parent = NULL;
			Node* Bucket_addres = Hash_bucket[possIn_hashBucket].ChainStart;//chain ki phli node ka address l rha.
			while (Bucket_addres != NULL)
			{
				if (Bucket_addres->data == key)
				{
					
					notfind = false;
					cout << " Element is Found " << key << " is now Deletd\n";
					Node* temp;
					temp = Bucket_addres->next;
					delete Bucket_addres;
					Bucket_addres = NULL;
					element_to_deleted_parent->next = temp;
				}
				else
				{
					element_to_deleted_parent = Bucket_addres;
					Bucket_addres = Bucket_addres->next;
				}
			}
			if (notfind==true)
			{
				cout << " Element is Not found hence cant be deleted.\n";
			}
		}
	}
};

	int main()
	{
		Hash hash;
		hash.Insert(122);
		hash.Insert(12);
		hash.Insert(1222);
		hash.Search(122);
		hash.Search(10);
		hash.Search(12);
		hash.Search(1222);
		hash.Delete(12);
	    hash.Delete(122);
		hash.Delete(1222);
		hash.Delete(12);
		hash.Search(12);
		hash.Search(78);
		hash.Insert(1222);
		std::cout << "\nHello World!\n";
	}