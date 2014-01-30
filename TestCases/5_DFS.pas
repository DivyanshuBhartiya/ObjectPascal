Program DFSProg;
var a,b,counter : integer;
    Graph : array [1..10] of array [1..10] of integer;
    Mark : array [1..10] of integer;

     Procedure DFS(i : integer);
	var j : integer;
	begin
		if( counter = 10)then 
			Write(i)
		else
			Write(i,'->'); (* Print the DFS*)
	
		Mark[i] := 1;
		for j:=1 to 10 do
		begin
			if((Graph[i,j]=1) and (Mark[j] <> 1)) then
				begin
					counter := counter + 1;
					DFS(j);
				end;
		end;
	end;

begin

	counter := 1;
	
	for a:=1 to 10
	do
	begin
		Mark[a] := 0;
		for b:=1 to 10
		do
		begin
			Graph[a,b] :=0;
		end;
	end;
	Graph[1,4] :=1;
	Graph[1,6] :=1;
	Graph[4,2] :=1;
	Graph[4,10] :=1;
	Graph[2,1] :=1;
	Graph[10,3] :=1;
	Graph[3,4] :=1;
	Graph[3,5] :=1;
	Graph[3,7] :=1;
	Graph[5,6] :=1;
	Graph[6,8] :=1;
	Graph[1,9] :=1;
	Writeln('\n Graph in form of adjacency list');
	for a:=1 to 10
	do
	begin
		Write('List ',a,':');
		for b:=1 to 10
		do
		begin
			if(Graph[a,b]=1) then
				Write(' ',b);
		end;
			Writeln();
	end;

	Write('\n\n DFS :');
	DFS(1); (*Call DFS*)
	Writeln();
	

	
End.
	
