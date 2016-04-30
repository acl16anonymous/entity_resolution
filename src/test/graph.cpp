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

// global parameters
double Alpha=20; // used in power normalization
int M=80;        // times of sampling expansion
int Step=20;     // maximum number of steps in an expansion


// global data structures
int N;           // number of entities/vertices in the graph
int** graph;     // two-dimensional array for quick graph edge deletion. N*(N+1) dimension with the last column for real length.
bool* edges;     // quickly determine whether two nodes are adjacent


double* p_score;  // the weight for each pair of edge
double* p_score_copy;  // the weight for each pair of edge
double* sum_prob; // a temporal buffer used in picking the next node
double max_score;
int total_edge=0;



/*
 * pick the next neighbor from a node using power normalization
 *
 */
int nextNode(int id1)
{
	int len = graph[id1][N];
	for(int i=0;i < len;i++){
		int id2 = graph[id1][i];
		if(i == 0){
			sum_prob[0] = pow(p_score[id1*N+id2], Alpha);
		}else{
			sum_prob[i] = sum_prob[i-1] + pow(p_score[id1*N+id2], Alpha);
		}
	}

	double r = (rand()/(double)(RAND_MAX));
	for(int i=0;i < len;i++){
		if(r <= sum_prob[i]/sum_prob[len-1]){
			return graph[id1][i];
		}
	}

	return graph[id1][len-1];
}



/*
 * When some edges are deleted, re-construct the graph.
 *
 */
void updateGraph()
{
	for(int id1=0;id1 < N;id1++){
		int idx=0, len = graph[id1][N];
		for(int i=0;i < len;i++){
			int id2 = graph[id1][i];
			if(edges[id1*N+id2]){
				graph[id1][idx] = id2;
				idx++;
			}else{
				graph[id1][N]--;
			}
		}
	}
}


void addEdge(int id1, int id2)
{
	graph[id1][graph[id1][N]] = id2;
	graph[id1][N]++;

	graph[id2][graph[id2][N]] = id1;
	graph[id2][N]++;

	edges[id1*N+id2] = true;
	edges[id2*N+id1] = true;

}


void deleteEdge(int id1, int id2)
{
	int len = graph[id1][N];
	bool flag = false;
	for(int i=0;i < len;i++){
		if(flag){
			graph[id1][i-1] = graph[id1][i];
		}
		if(graph[id1][i] == id2){
			flag = true;
		}
	}
	graph[id1][N]--;
			
		
	edges[id1*N+id2] = false;
	edges[id2*N+id1] = false;
}


int flipCoin(int origin, int cur)
{
	// Each coin will go at most Step steps
	for(int s=0;s < Step;s++){
		// construct the normalized probability array to determine which way to go
		int next = nextNode(cur);
		if(next == origin){
			return 1;
		}
		if(!edges[origin*N+next]){
			return 0;
		}
		cur=next;
	}
	return 0;
}

double iterate()
{
	double total_diff = 0.0;

	// we access the edge by increasing order of weights
	int B=50;
	double seg = max_score/B + 0.0001;
	vector<vector<int> > buckets(B);
	total_edge=0;
	for(int id1=0;id1 < N;id1++){
		for(int i=0;i < graph[id1][N];i++){
			int id2 = graph[id1][i];
			int bid = (int)(p_score[id1*N+id2]/seg);
			buckets[bid].push_back(id1*N+id2);
			total_edge++;
		}
	}

	
	// the graph may be updated in the iteration. We need to a buf to keep the set of original edges.
	for(int b=0;b < B;b++){
		for(size_t s=0;s < buckets[b].size();s++){
			int key = buckets[b][s];
			int id1 = key/N;
			int id2 = key%N;

			// flip a coin from id1 to id2 for M times
			int back = 0;
			for(int j=0;j < M;j++){
				if(rand() % 2 == 0){
					back += flipCoin(id1, id2);
				}else{
					back += flipCoin(id1, id2);
				}
			}
			cout<<id1<<"\t"<<id2<<"\t"<<p_score[id1*N+id2]<<"\t\t"<<(1.0*back/M)<<"\t"<<total_edge<<endl;

			p_score_copy[id1*N+id2] = (1.0*back/M);
			p_score_copy[id2*N+id1] = (1.0*back/M);
			total_diff += (1.0*back/M > p_score[id2*N+id1] ? 1.0*back/M - p_score[id2*N+id1] : p_score[id2*N+id1]-1.0*back/M);

			// break the edge in the current iteration for speed improvement
			if(back == 0){
				deleteEdge(id1, id2);
				total_edge--;
			}
		}
	}
	memcpy(p_score, p_score_copy, sizeof(double)*N*N);
	max_score=1;
	return total_diff;
}


/*
 * Construct cliques from a entity similarity graph
 *
 */
int main(int argc, char** argv)
{
	// read the similarity graph in array and init the global data structures
	srand(time(NULL));
	string dataset = "paper";
	ifstream fin((dataset+".graph").c_str());
	fin.read((char*)&N, sizeof(int));
	p_score = new double[N*N];
	fin.read((char*)p_score, sizeof(double)*N*N);

	edges = new bool[N*N]; // important data structures
	memset(edges, 0, sizeof(bool)*N*N);
	graph = new int*[N];
	for(int i=0;i < N;i++){
		graph[i] = new int[N+1];
		graph[i][N]=0;
	}
	sum_prob = new double[N];

	
	// update p_score to be a symmetric matrix and get the maximum score
	max_score=0;
	for(int i=0;i < N;i++){
		for(int j=i-1;j >=0;j--){
			p_score[i*N+j] = p_score[j*N+i];
			if(p_score[i*N+j] > max_score){
				max_score = p_score[i*N+j];
			}
		}
	}
	p_score_copy = new double[N*N];
	memcpy(p_score_copy, p_score, sizeof(double)*N*N);
	cout<<"max score : "<<max_score<<endl;

	
	// construct graph and edges by removing a few unpromising edges
	for(int id1=0;id1 < N;id1++){
		for(int id2=id1+1;id2 < N;id2++){
			if(p_score[id1*N+id2] >= 0.1*max_score){
				addEdge(id1, id2);
			}
		}
	}


	// split the edges into buckets and access the edges in increasing order 
	for(int iter=1;iter <= 10;iter++){
		cout<<"iteration "<<iter++<<endl;
		double diff = iterate();
		cout<<"Total Diff: "<<diff<<endl;
	}

	return 1;
}


