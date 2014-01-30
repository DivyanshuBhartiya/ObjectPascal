Program P;
var
 x: integer;
begin
x:= 2;
repeat
	begin
	x := x+1; 
	Writeln('x :',x);
	end;
until
 x>10;
{x := x;}
end.
