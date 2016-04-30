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
#include "../util/measure.h"
#include "../util/Bipartite.h"
#include "../util/RandomWalk.h"


using namespace std;
int getWordId(string word, map<string,int>&word_id)
{
	if(word_id.find(word) != word_id.end()){
		return word_id[word];
	}

	/*
	for(map<string,int>::iterator iter=word_id.begin();iter != word_id.end();iter++)
	{
		if(Similarity::isSimilar(word, iter->first)){
			//cout<<word<<"\t"<<iter->first<<endl;
			return iter->second;

		}
	}
	*/
	return word_id.size();
}


/*
 * Construct the sorted features (words) for each dataset.
 *
 */
int main(int argc, char** argv)
{
	if(argc != 2){
		cout<<"please specify weight.."<<endl;
		exit(0);
	}
	int scale = atoi(argv[1]);

	// read the data source file
	string dataset = "paper";
	vector<string> source = FileIO::readFileLines("data/"+dataset+"/source.txt");
	int N = source.size();
	int pair_num = N*N;
	srand (time(NULL));
	cout<<"finish loading source fle..."<<endl;


	// scan the source file and hash the word from string to int
	map<string, int> word_id;
	map<int, string> id_word;
	for(size_t i=0;i < source.size();i++){
		vector<string> segs = split(source[i], ' ');
		for(size_t j=0;j < segs.size();j++){
			string word = format(segs[j]);
			int id = getWordId(word, word_id);
			if(word.compare("instance-based")==0){
				cout<<id<<endl;
			}
			word_id[word] = id;
			id_word[id] = word;
		}
	}
	cout<<"finish constructing word id..."<<endl;


	// construct the inverted lists. Each list is sorted by entity id.
	vector<set<int> > inv_lists(word_id.size());
	for(size_t i=0;i < source.size();i++){
		vector<string> segs = split(source[i], ' ');
		for(size_t j=0;j < segs.size();j++){
			string word = format(segs[j]);
			int id = word_id[word];
			if(id==262){
				cout<<i<<endl;
			}
			inv_lists[id].insert(i);
		}
	}
	cout<<"finish constructing inverted lists..."<<endl;


	// refine the inverted lists by removing stop-words. 
	for(size_t wid=0;wid < inv_lists.size();wid++){
		if(inv_lists[wid].size() == 1 || inv_lists[wid].size() > scale*0.1*N){
			inv_lists[wid].clear();
			cout<<"clear "<<wid<<endl;
		}
	}
	//exit(0);
	


	// construct the bipartite graph between entity-pairs and terms
	int max_id=N;
	int word_num = word_id.size();
	Bipartite *bigraph = new Bipartite(pair_num, word_num);
	cout<<"finish init bigraph"<<endl;
	for(size_t wid=0;wid < inv_lists.size();wid++){
		for(set<int>::iterator id1=inv_lists[wid].begin();id1!=inv_lists[wid].end();id1++){
			for(set<int>::iterator id2=inv_lists[wid].begin();id2!=inv_lists[wid].end();id2++){
				if((*id1) != (*id2)){
					if((*id1) < max_id && (*id2) < max_id){
						int pid = (*id1)*N+(*id2);
						bigraph->addEdge(pid, wid);
					}
				}
			}
		}
	}

	bigraph->init();
	

	bigraph->iterate();

	bigraph->output(id_word, inv_lists);
	cout<<"edge num: "<<bigraph->activePairNum()<<endl;

	RandomWalk* walker;
	for(int iter=0;;iter++){
		walker = new RandomWalk(bigraph->p_score, N, 20, 60, 10);
		for(int i=0;i < N;i++){
			for(int j=i+1;j < N;j++){
				if(bigraph->p_score[i*N+j]>0){
					if(i < max_id && j < max_id){
						walker->addEdge(i,j);
					}
				}
			}
		}
		cout<<"edge num: "<<bigraph->activePairNum()<<endl;

		walker->iterate();
		if(iter==2){
			break;
		}
		bigraph->updatePScore(walker->p_conf);
	}

	/*
	RandomWalk* walker = new RandomWalk(bigraph->p_score, N);
	for(int iter=1;iter <= 200;iter++){
		cout<<"iteration "<<iter++<<endl;
		if(walker->iterate()==0){
			break;
		}
	}
	*/


	set<string> matches = FileIO::readMatch("data/"+dataset+"/match.txt", max_id);

	int Num=1000;
	double max_weight=-1;
	vector<vector<int> > buckets(Num);
	for(int i=0;i < N;i++){
		int id1=i;
		for(int j=i+1;j < N;j++){
			int id2=j;
			double weight = walker->p_conf[id1*N+id2]*bigraph->p_score[id1*N+id2];
			if(weight > max_weight){
				max_weight=weight;
			}
		}
	}
	double seg = max_weight/Num+0.001;
	for(int i=0;i < N;i++){
		int id1=i;
		for(int j=i+1;j < N;j++){
			int id2=j;
			double weight = walker->p_conf[id1*N+id2]*bigraph->p_score[id1*N+id2];
			int idx=(int)(weight/seg);
			buckets[idx].push_back(id1*N+id2);
		}
	}
	vector<double> conf_vec;
	int count=0,total_pair=0;
	for(int i=Num-1;i>0;i--){
		for(size_t j=0;j < buckets[i].size();j++){
			int key = buckets[i][j];
			int id1 = key/N;
			int id2 = key%N;
			if(id1 < id2){
				stringstream ss;
				ss<<id1<<"_"<<id2;
				cout<<id1<<"\t"<<id2<<"\t"<<walker->p_conf[id1*N+id2]<<"\t"<<bigraph->p_score[id1*N+id2]<<"\t";
				if(matches.find(ss.str()) != matches.end()){
					cout<<"true";
				}else{
					cout<<"false";
				}
				conf_vec.push_back(walker->p_conf[id1*N+id2]);
				size_t C=10;
				if(conf_vec.size() > C){
					double avg_conf=0.0;
					for(size_t z=conf_vec.size()-1;z >= conf_vec.size()-C;z--){
						avg_conf += conf_vec[z];
					}
					//if(walker->p_conf[id1*N+id2]>0.9999 && avg_conf/C >= 0.98){
					if(walker->p_conf[id1*N+id2]>=0.7){
						total_pair++;
						if(matches.find(ss.str()) != matches.end()){
							count++;
						}
					}
					cout<<"\t"<<avg_conf/C;
				}else{
					total_pair++;
					if(matches.find(ss.str()) != matches.end()){
						count++;
					}
				}
				cout<<endl;
			}

		}
	}




	/*
	int count=0, total_pair=0;
	set<string> results;
	for(int i=0;i < N1;i++){
		int id1=i;
		for(int j=0;j < N2;j++){
			int id2=j+N1;
			if(walker->p_conf[id1*N+id2]>0.95){
				stringstream ss;
				ss<<id1<<"_"<<j;
				results.insert(ss.str());
				total_pair++;
				if(matches.find(ss.str()) != matches.end()){
					count++;
				}else{
					cout<<"not_match: "<<id1<<"\t"<<j<<"("<<(j+N1)<<")\t"<<bigraph->p_score[id1*N+id2]<<endl;
				}
			}
		}
	}
	for(set<string>::iterator iter=matches.begin();iter != matches.end();iter++){
		if(results.find(*iter) == results.end()){
			cout<<"miss\t"<<*iter<<endl;
		}
	}
	*/
	double precison = 1.0*count/total_pair;
	double recall = 1.0*count/matches.size();
	double f1 = 2*precison*recall/(precison+recall);

	cout<<"precision: "<<count<<"\t"<<total_pair<<"\t"<<precison<<"\t"<<recall<<"\t"<<f1<<endl;


	return 1;
}

	/*
	int count=0, total_pair=0;
	set<string> results;
	for(int id1=0;id1 < max_id;id1++){
		for(int id2=id1+1;id2 < max_id;id2++){
			if(walker->p_conf[id1*N+id2] > 0){
				stringstream ss;
				ss<<id1<<"_"<<id2;
				results.insert(ss.str());
				total_pair++;
				cout<<id1<<"\t"<<id2<<"\t"<<walker->p_conf[id1*N+id2]<<"\t"<<bigraph->p_score[id1*N+id2]<<"\t";
				if(matches.find(ss.str()) != matches.end()){
					cout<<"true\t";
					count++;
				}else{
					cout<<"false\t";
					if(walker->p_conf[id1*N+id2]>0){
						cout<<"[";
						for(size_t z=0;z < bigraph->edges[id1*N+id2].size();z++){
							int wid = bigraph->edges[id1*N+id2][z];
							cout<<"("<<id_word[wid]<<", "<<bigraph->t_score[wid]<<") ";
						}
						cout<<"]";
					}
				}
				cout<<endl;
			}
		}
	}
	for(set<string>::iterator iter=matches.begin();iter != matches.end();iter++){
		if(results.find(*iter) == results.end()){
			vector<string> segs = split(*iter, '_');
			int id1=atoi(segs[0].c_str());
			int id2=atoi(segs[1].c_str());
			cout<<"miss\t"<<id1<<"\t"<<id2<<"\t"<<walker->p_conf[id1*N+id2]<<"\t"<<bigraph->p_score[id1*N+id2]<<"\t";
			cout<<"[";
			for(size_t z=0;z < bigraph->edges[id1*N+id2].size();z++){
				int wid = bigraph->edges[id1*N+id2][z];
				cout<<"("<<id_word[wid]<<", "<<bigraph->t_score[wid]<<") ";
			}
			cout<<"]";
			cout<<endl;
		}
	}
	double precison = 1.0*count/total_pair;
	double recall = 1.0*count/matches.size();
	double f1 = 2*precison*recall/(precison+recall);

	cout<<"precision: "<<count<<"\t"<<total_pair<<"\t"<<precison<<"\t"<<recall<<"\t"<<f1<<endl;


	return 1;
}
	*/
