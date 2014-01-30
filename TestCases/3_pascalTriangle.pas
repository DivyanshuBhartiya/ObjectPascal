Program pascalTriangle;
var col,row,space : integer;
    PasArr : array [1..5] of array [1..5] of integer;

function c(n,k : integer) : integer;
begin
	if((k=0) or (n=k)) then
		Result := 1
	else
		Result := c(n-1,k) + c(n-1,k-1);
end;

begin 

	for row:=1 to 5
	do
	begin
		for col :=1 to row
		do
		begin
				PasArr[row,col] := c(row-1,col-1);
		end;
		
	end;	
    
	Writeln('\n\n Pascal Triangle \n');
	for row:=1 to 5
	do
	begin
		for space := 5 downto row
		do
		begin
			Write(' ');
		end;
		for col :=1 to row
		do
		begin
			Write(PasArr[row,col],' ');
		end;
		Writeln();
	end;

End.

