#ifndef _CLUSTER_H
#define _CLUSTER_H


#include <set>
#include <iostream>
using namespace std;


class Cluster
{
	public:
		void addItem(int id)
		{
			ids.insert(id);
		}

		bool same(Cluster* other)
		{
			if(ids.size() != other->ids.size()){
				return false;
			}

			set<int>::iterator iter1 = ids.begin();
			set<int>::iterator iter2 = other->ids.begin();
			while(iter1 != ids.end() && iter2 != other->ids.end()){
				if(*iter1 != *iter2){
					return false;
				}
				iter1++;
				iter2++;
			}
			return true;
		}

		bool contain(Cluster* other)
		{
			if(ids.size() <= other->ids.size()){
				return false;
			}

			set<int>::iterator iter2 = other->ids.begin();
			while(iter2 != other->ids.end()){
				if(ids.find(*iter2) == ids.end()){
					return false;
				}
				iter2++;
			}
			return true;
		}


		void print()
		{
			for(set<int>::iterator iter=ids.begin();iter != ids.end();iter++){
				cout<<*iter<<" ";
			}
			cout<<endl;
		}


		int size()
		{
			return ids.size();
		}

		set<int> ids;
};

#endif
