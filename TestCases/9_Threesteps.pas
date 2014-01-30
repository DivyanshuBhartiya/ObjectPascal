Program steps;
var a: integer;
procedure P1(m1:integer);
var i1: integer;

	function P2(m2:integer) : integer;
	var i2: integer;
		Procedure P3(m3:integer);
		begin
					(* P3 *)
			i2 := 2 *m3;
		end;
	begin
		P3(i1);
		Writeln('i2 =',i2);
		Result := 2 * m2;	(* P2 *)
	end;
begin
		
		i1 := m1;
		Writeln('i1 = ',i1);		
		i1 := P2(10);		(* P1 *)
		Writeln('i1 = ',i1);
end;

begin
	Writeln('\n Welcome to a 3 step proc within func within proc program \n');

	P1(5);

	Writeln();
	
	
End.

