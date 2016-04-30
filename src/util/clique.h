#ifndef _CLIQUE_H
#define _CLIQUE_H

#include <set>
#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include "../util/util.h"
#include <vector>

using namespace std;


class Clique
{
	public:
		Clique()
		{
		}

		Clique(string str)
		{
			vector<string> ids = split(str, '_');
			for(size_t i=0;i < ids.size();i++){
				nodes.insert(atoi(ids[i].c_str()));
			}
		}

		string toString()
		{
			stringstream ss;
			for(set<int>::iterator iter=nodes.begin();iter != nodes.end();iter++){
				ss<<*iter<<"_";
			}
			return ss.str();
		}

		void addNode(int n)
		{
			nodes.insert(n);
		}

		set<int> nodes;
};


#endif
