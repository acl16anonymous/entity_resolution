if [ 0 -eq 1 ]
then
awk '{
	if(flag == 1){
		str = tolower($0);
		str = gensub(/[<\/>]/, "", "g", str);
		if(length(str) > 10){
			print str;
		}
		flag=0;
	}
	if(/NEWREFERENCE/){
		flag=1;
	}
	
}' raw.txt > tmp
##########################################################
#### Need to manully remove the empty lines in tmp file
#### Using /^$ to find and replace ############


awk '{
	line="";
	for(i=2;i <= NF;i++){
		line=line""$i" ";
	}
	print line
}' tmp > source_1.txt
fi



awk '{
	if(!id[$1]){
		id[$1] = (NR-1);
	}else{
		id[$1] = id[$1]" "(NR-1);
	}
}END{
	for(str in id){
		n=split(id[str], segs, " ");
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				print segs[i]"\t"segs[j];
			}
		}
	}
}' tmp | sort -k 1 -k 2 -n > match.txt



if [ 0 -eq 1 ]
then

awk '{
	id=NR-1;
	if($1 != label){
		print line;
		line="";
	}
	line=line" "id;
	label=$1;
}' tmp > cliques.txt
fi


#cp source_1.txt source_2.txt
#cp source_1.txt source.txt
