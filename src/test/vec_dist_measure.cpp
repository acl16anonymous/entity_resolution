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


int main()
{
	string datasets[] = {"paper"};
	int N=100;

	for(int d=0;d < 1;d++){
		string dataset = datasets[d];

		// read the data sources and match result
		vector<double*> source1 = FileIO::readFileVecs("data/"+dataset+"/source_vec_1.txt", N);
		vector<double*> source2 = FileIO::readFileVecs("data/"+dataset+"/source_vec_2.txt",N);
		set<string> matches = FileIO::readMatch("data/"+dataset+"/match.txt");

		double MAX_DIST=0;
		for(size_t i=0;i < source1.size();i++){
			for(size_t j=0;j < source2.size();j++){
				double dist = Similarity::ED(source1[i],source2[j], N);
				if(dist > MAX_DIST){
					MAX_DIST = dist;
				}
			}
		}
		cout<<MAX_DIST<<endl;
		for(float T=0.005; T < 1;T+=0.005){
			// loop, calculate distance and store matching pairs
			set<string> pairs;
			double dist=0;
			for(size_t i=0;i < source1.size();i++){
				for(size_t j=0;j < source2.size();j++){
					dist = Similarity::ED(source1[i],source2[j], N);
					if(dist/MAX_DIST <= T){
						stringstream ss;
						ss<<i<<"_"<<j;
						//cout<<dist/MAX_DIST<<endl;
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
			cout<<dataset<<"\t"<<T<<"\t"<<precison<<"\t"<<recall<<"\t"<<f1<<endl;
		}
	}
	
}
