#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <math.h>

#include "../util/io.h"
#include "../util/util.h"
#include "../util/cluster.h"


using namespace std;


/*
 * Construct the sorted features (words) for each dataset.
 *
 */
int main(int argc, char** argv)
{
	map<string, Cluster*> clusters;
	int min_size, max_size=0, MAX;

	string dataset = "restaurant";
	// read the data sources and match result
	vector<string> source1 = FileIO::readFileLines("data/"+dataset+"/source.txt");
	min_size=source1.size();
	MAX=source1.size()+1;

	// construct inverted lists (clusters)
	for(size_t i=0;i < source1.size();i++){
		vector<string> segs1 = split(source1[i], ' ');
		for(size_t j=0;j < segs1.size();j++){
			string word = format(segs1[j]);
			if(clusters.find(word) == clusters.end()){
				clusters[word] = new Cluster();
			}
			clusters[word]->addItem(i);
		}
	}

	// set the min_size and max_size
	map<string, Cluster*>::iterator iter;
	for(iter=clusters.begin();iter != clusters.end();iter++){
		if(iter->second->size() >= max_size ){
			max_size = iter->second->size();
		}

		if(iter->second->size() <= min_size ){
			min_size = iter->second->size();
		}
	}


	// get the share terms between any pairs of entities
	map<int, set<string> > shareTerms;
	for(iter=clusters.begin();iter != clusters.end();iter++){
		set<int> entities = iter->second->ids;
		set<int>::iterator iter1,iter2;
		cout<<iter->first<<endl;
		for(iter1=entities.begin();iter1 != entities.end();iter1++){
			for(iter2=entities.begin();iter2 != entities.end();iter2++){
				if(iter1 != iter2){
					int key1 = min(*iter1, *iter2);
					int key2 = max(*iter1, *iter2);
					shareTerms[key1*MAX+key2].insert(iter->first);
				}
			}
		}
	}

	// initialize the score of each word to be 1
	map<string, double> scores;
	map<string, double> tmp_scores;
	for(iter=clusters.begin();iter != clusters.end();iter++){
		scores[iter->first]=1.0;
	}

	// the score of a word is determined by the coherence of its associated cluster.
	// In other words, we average the similarity scores of all the pairs of entities in a cluster
	for(int iteration=0;iteration < 100;iteration++){
		cout<<"iteration "<<iteration<<endl;
		for(int len=2;len <= max_size;len++){
			for(iter=clusters.begin();iter != clusters.end();iter++){
				// scan the clusters in the same level. Each cluster represents one word
				if(iter->second->size() == len){
					// scan each pair of entities
					set<int> entities = iter->second->ids;
					set<int>::iterator iter1,iter2;
					double score=0.0;
					int len=entities.size()*(entities.size()-1);
					for(iter1=entities.begin();iter1 != entities.end();iter1++){
						for(iter2=entities.begin();iter2 != entities.end();iter2++){
							if(iter1 != iter2){
								// for each pair, scan the common items
								int key1 = min(*iter1, *iter2);
								int key2 = max(*iter1, *iter2);
								set<string> commons = shareTerms[key1*MAX+key2];
								for(set<string>::iterator c_iter=commons.begin();c_iter != commons.end();c_iter++){
									score += scores[*c_iter]/len;
								}
							}
						}
					}
					// it's like sigmoid after log of score.
					tmp_scores[iter->first] = 1/(1+1/score);
					cout<<iteration<<"\t"<<iter->first<<"\t"<<tmp_scores[iter->first]<<"\t"<<score<<"\t"<<entities.size()<<"\t"<<len<<endl;
				}
			}
		}
		scores = tmp_scores;
	}

	ofstream out((dataset+".words").c_str());
	map<string, double>::iterator s_iter;
	for(s_iter=scores.begin();s_iter != scores.end();s_iter++){
		set<int> ids = clusters[s_iter->first]->ids;
		if(ids.size() > 1){
			out<<s_iter->first<<" "<<s_iter->second<<" ";
			for(set<int>::iterator i_iter=ids.begin();i_iter!=ids.end();i_iter++){
				out<<*i_iter<<" ";
			}
			out<<endl;
		}
	}
	out.close();

	return 1;
}
