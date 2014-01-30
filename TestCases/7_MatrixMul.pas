program expressionTest;   {Sample tvi code here}
 var a ,b,t ,k: integer;
        c,d ,e: array [1..3] of array [1..3] of integer;
 begin
{$R+}
	Writeln('\n Welcome to matrix multiplication of two 3x3 arrays');
	k:= 0;
	Writeln('\n Array 1 : \n');
	for a:=1 to 3
	do
	begin
		for b:=1 to 3
		do
		begin
			c[a,b] := k;
			k := k+1;
			Write(c[a,b],'  ');
		end;
		Writeln();
	end;

	k:=0;

	Writeln('\n Array 2 : \n');
	for a:=1 to 3
	do
	begin
		for b:=1 to 3
		do
		begin
			d[a,b] := k;
			k := k+1;
			Write(d[a,b],'  ');
		end;
		Writeln();
	end;
	
  
  for a:=1 to 3
  do
	begin
	for b:=1 to 3
	do
	begin
		e[a,b] := 0;
		for k:=1 to 3
		do
		begin
		      
		      e[a,b] :=  e[a,b] + c[a,k] * d[k,b];
		end;
		
	end;
	
  end;
 
Writeln('\n\n Result : \n');
for a:=1 to 3
do
begin
	for b:=1 to 3
	do
	begin
		Write(e[a,b],'  ');
	end;
	Writeln();

end;

 end.
