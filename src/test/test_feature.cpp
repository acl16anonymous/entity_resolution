#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <math.h>

#include "../util/io.h"
#include "../util/util.h"
#include "../util/cluster.h"


using namespace std;

int main(int argc, char** argv)
{
	map<string, Cluster*> clusters;

	string dataset = "paper";
	// read the data sources and match result
	vector<string> source1 = FileIO::readFileLines("data/"+dataset+"/source_1.txt");
	vector<string> features = FileIO::readFileLines(dataset+".sort_words");

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


	// for each cluster, we compare it with previous clusters.
	// if the same or containment, ignore.
	// if overlap, check coherence to determine merge
	vector<Cluster*> results;
	for(size_t i=0;i < features.size();i++){
		//cout<<features[i]<<"\t";
		Cluster* cluster = clusters[features[i]];
		if(cluster->size() < 2){
			continue;
		}

		if(results.size() == 0){
			results.push_back(cluster);
		}else{
			int containCount=0;
			for(size_t j=0;j < results.size();j++){
				if(cluster->contain(results[j])){
					containCount++;
				}
			}
			cout<<containCount<<endl;
			if(containCount < 2){
				results.push_back(cluster);
				cluster->print();
			}
		}
	}


	return 1;
}
