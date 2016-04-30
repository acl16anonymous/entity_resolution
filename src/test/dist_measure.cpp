/*
 * Test the F1-measure using different distance measures.
 * The tested distance measures include:
 *   1. Edit Distance
 *   2. Jaccard Similarity
 *   3. KL Divergency
 *   4. Needleman¨CWunsch
 *
 */


#include "../util/measure.h"
#include "../util/io.h"
#include <iostream>

using namespace std;

#define JACCARD 0
#define EDIT 1
#define NWD 2


int main()
{
	string datasets[] = {"paper"};

	for(int d=0;d < 1;d++){
		string dataset = datasets[d];

		// read the data sources and match result
		vector<string> source1 = FileIO::readFileLines("data/"+dataset+"/source_1.txt");
		vector<string> source2 = FileIO::readFileLines("data/"+dataset+"/source_2.txt");
		set<string> matches = FileIO::readMatch("data/"+dataset+"/match.txt");

		for(float T=0.05; T < 1;T+=0.05){
			for(int m=0;m < 3;m++){
				int measure = m;


				// loop, calculate distance and store matching pairs
				set<string> pairs;
				double dist=0;
				for(size_t i=0;i < source1.size();i++){
					for(size_t j=0;j < source2.size();j++){
						if(measure == JACCARD){
							dist = 1-Similarity::jaccard(source1[i],source2[j]);
						}
						if(measure == EDIT){
							dist = Similarity::EditDistance(source1[i],source2[j]);
						}
						if(measure == NWD){
							dist = 1 - Similarity::NW(source1[i],source2[j]);
						}
						if(dist <= T){
							stringstream ss;
							ss<<i<<"_"<<j;
							pairs.insert(ss.str());
						}
					}
				}

				// calculate the F1-measure
				int count=0;
				set<string>::iterator iter;
				for(iter=pairs.begin();iter!=pairs.end();iter++){
					if(matches.find(*iter) != matches.end()){
						count++;
					}
				}
				double precison = 1.0*count/pairs.size();
				double recall = 1.0*count/matches.size();
				double f1 = 2*precison*recall/(precison+recall);
				cout<<dataset<<"\t"<<m<<"\t"<<T<<"\t"<<precison<<"\t"<<recall<<"\t"<<f1<<endl;
			}
		}
	}
	
}
