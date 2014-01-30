program expressionTest;   {Sample tvi code here}
 var a ,b : integer;
	t : integer;
        c : array [1..10] of integer;
 begin
{$R+}
  Writeln('\n Welcome to Bubble Sort \n');
  for a:=1 to 10
  do
	begin
		Write('Enter num ',a,':');
		Read(c[a]);
	end;
  for a:=1 to 9
  do
	begin
	for b:=a+1 to 10
	do
	begin
		if(c[a] > c[b])
		then 
		begin
		t := c[a];
		c[a] := c[b];
		c[b] := t;
		end;
		
	end;
  end;
  
  
  Writeln('Sorted values are');
  for a:=1 to 10
  do
	begin
		Writeln(c[a]);
	end;
  Writeln();
 end.
