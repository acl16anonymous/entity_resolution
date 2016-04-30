awk '{
	if(NR == FNR){
		line[$0]=NR-1;
	}else{
		if(NF > 1){
			if($0 !~ /^#/){
				count++;
				if(count % 2 == 1){
					if(line[$0]){
						print line[$0];
					}else{
						print $0;
					}
				}
			}
		}
	}
	
}' zagats.txt match-pairs.txt  > tmp1

awk '{
	if(NR == FNR){
		line[$0]=NR-1;
	}else{
		if(NF > 1){
			if($0 !~ /^#/){
				count++;
				if(count % 2 == 0){
					if(line[$0]){
						print line[$0];
					}else{
						print $0;
					}
				}
			}
		}
	}
	
}' fodors.txt match-pairs.txt > tmp2

awk '{
	if(NR == FNR){
		line[NR]=$1;
	}else{
		print line[FNR]"\t"$1;
	}
}' tmp1 tmp2 > match.txt

awk '{
	line="";
	for(i=1;i <= NF;i++){
		line=line""$i" ";
	}
	print tolower(line);
}' zagats.txt > source_1.txt

awk '{
	line="";
	for(i=1;i <= NF;i++){
		line=line""$i" ";
	}
	print tolower(line);
}' fodors.txt > source_2.txt
