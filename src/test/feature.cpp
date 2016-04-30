#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdlib.h>    
#include <time.h> 

#include "../util/io.h"
#include "../util/util.h"


using namespace std;


/*
 * Construct the sorted features (words) for each dataset.
 *
 */
int main(int argc, char** argv)
{
	// read the data source file
	srand (time(NULL));
	string dataset = "restaurant";
	vector<string> source = FileIO::readFileLines("data/"+dataset+"/source.txt");
	int N = source.size();
	int pair_num = N*N;

	// scan the source file and hash the word from string to int
	map<string, int> word_id;
	map<int, string> id_word;
	for(size_t i=0;i < source.size();i++){
		vector<string> segs = split(source[i], ' ');
		for(size_t j=0;j < segs.size();j++){
			string word = format(segs[j]);
			if(word_id.find(word) == word_id.end()){
				int id = word_id.size();
				word_id[word] = id;
				id_word[id] = word;
			}
		}
	}


	// construct the inverted lists. Each list is sorted by entity id.
	vector<vector<int> > inv_lists(id_word.size());
	for(size_t i=0;i < source.size();i++){
		vector<string> segs = split(source[i], ' ');
		for(size_t j=0;j < segs.size();j++){
			string word = format(segs[j]);
			int id = word_id[word];
			inv_lists[id].push_back(i);
		}
	}


	// for each pair of entities, construct the shared terms
	vector<vector<int> > pair_terms(pair_num);
	for(size_t i=0;i < inv_lists.size();i++){
		if(inv_lists[i].size() > 1 ){
			for(size_t j=0;j < inv_lists[i].size();j++){
				int id1 = inv_lists[i][j];
				for(size_t k=j+1;k < inv_lists[i].size();k++){
					int id2 = inv_lists[i][k];
					pair_terms[id1*N+id2].push_back(i);
				}
			}
		}
	}


	// initialize the scores
	double* t_score = new double[word_id.size()];
	double* p_score = new double[pair_num];
	double sum=0.0;
	for(size_t i=0;i < word_id.size();i++){
		//t_score[i]=1.0;
		t_score[i] = (rand()/(double)(RAND_MAX));
		sum += t_score[i];
	}
	for(size_t i=0;i < word_id.size();i++){
		t_score[i] /= sum;
	}

	for(int i=0;i < pair_num;i++){
		p_score[i]=0;
	}
	
	// run the iterations
	for(int iter=0;iter < 20;iter++){
		cout<<"iteration "<<iter<<endl;
		cout<<"===============================\t"<<id_word[2]<<"\t"<<t_score[2]<<endl;
		cout<<"===============================\t"<<id_word[3]<<"\t"<<t_score[3]<<endl;
		// update p_score
		for(size_t i=0;i < source.size();i++){
			int id1 = i;
			for(size_t j=i+1;j < source.size();j++){
				int id2 = j;
				int key = id1*source.size()+id2;
				p_score[key]=0;
				for(size_t k=0;k < pair_terms[key].size();k++){
					int word = pair_terms[key][k];
					p_score[key] += t_score[word];
				}
			}
		}
		double loss = 0.0;
		for(size_t i=0;i < word_id.size();i++){
			for(size_t j=0;j < inv_lists[i].size();j++){
				int id1 = inv_lists[i][j];
				for(size_t k=j+1;k < inv_lists[i].size();k++){
					int id2 = inv_lists[i][k];
					int key = id1*source.size()+id2;
					int dj = pair_terms[key].size();
					loss += (t_score[i]-p_score[key]/dj)*(t_score[i]-p_score[key]/dj);
				}
			}
		}
		cout<<"loss score : "<<loss<<endl;

		// update t_score
		double total_diff = 0;
		for(size_t i=0;i < word_id.size();i++){
			if(inv_lists[i].size() > 1){
				double score = 0;

				for(size_t j=0;j < inv_lists[i].size();j++){
					int id1 = inv_lists[i][j];
					for(size_t k=j+1;k < inv_lists[i].size();k++){
						int id2 = inv_lists[i][k];
						int key = id1*source.size()+id2;
						//score += p_score[key]*1.0/pair_terms[key].size();
						score += p_score[key]*1.0;
					}
				}
				int num = inv_lists[i].size()*(inv_lists[i].size()-1)/2;
				score /= num;
				score = 1/(1+1/score);


				total_diff = (score > t_score[i] ? score-t_score[i] : t_score[i]-score);
				t_score[i] = score;

				/*
				   cout<<id_word[i]<<"\t"<<t_score[i]<<"\t";
				   for(size_t m=0;m < inv_lists[i].size();m++){
				   cout<<inv_lists[i][m]<<" ";
				   }
				   cout<<endl;
				   */
			}else{
				t_score[i] = 0;
			}
		}


		cout<<"total difference : "<<total_diff<<endl;
		if(total_diff == 0){
			break;
		}
	}

	ofstream out((dataset+".words").c_str());
	for(size_t i=0;i < word_id.size();i++){
		if(inv_lists[i].size() > 1){
			out<<id_word[i]<<"\t"<<t_score[i]<<"\t";
			for(size_t m=0;m < inv_lists[i].size();m++){
				out<<inv_lists[i][m]<<" ";
			}
			out<<endl;
		}
	}
	out.close();


	// construct the graph
	ofstream out2((dataset+".graph").c_str());
	out2.write((char*)&N, sizeof(int));
	out2.write((char*)p_score, sizeof(double)*pair_num);
	out2.close();
	/*
	for(size_t i=0;i < source.size();i++){
		int id1 = i;
		for(size_t j=i+1;j < source.size();j++){
			int id2 = j;
			int key = id1*source.size()+id2;
			cout<<id1<<"\t"<<id2<<"\t"<<p_score[key]<<endl;
		}
	}
	*/
	 	

	/*
	map<string, Cluster*> clusters;

	// read the data sources and match result
	min_size=source1.size();
	MAX=source1.size()+1;

	// construct inverted lists (clusters)

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
	*/

	return 1;
}
