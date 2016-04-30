#########################################
# The data input quality is important for our algorithm to work well.
# For this data file, we need to remove / and -
# These two symbols degrade the performance.
########################################
rm map.txt -f
sed 's/[",]/ /g' abt.csv | awk '{
	if(NR >= 2){
		line="";
		for(i=2;i<=NF;i++){
			line=line" "tolower($i);
		}
		print line;
		print "1_"$1","(NR-2) >> "map.txt"
	}
}' > source_1.txt


sed 's/[",]/ /g' buy.csv | awk '{
	if(NR >= 2){
		line="";
		for(i=2;i<=NF;i++){
			line=line" "tolower($i);
		}
		print line;
		print "2_"$1","(NR-2) >> "map.txt"
	}
}' > source_2.txt

awk -F "," '{
	if(NR == FNR){
		cache[$1] = $2;
	}else{
		if(FNR >= 2){
			print cache["1_"$1]"\t"cache["2_"$2];
		}
	}
}' map.txt match.csv | sort -k 1 -n > match.txt
