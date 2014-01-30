program scope;
type S = record f : real; k,u : integer end;
var V,T: S;

procedure P(x: integer);
     begin
	V.k:= x; 
	V.f:= 4.5;
	T.f := 5.5;
	T.u := 2 * V.k;
    end;

begin
	P(15);
	V.u:= 3 * V.k;
	T.k := V.u + T.u;
	Writeln();
	Writeln();
	Writeln('V.k = ',V.k,', V.u = ',V.u,' V.f = ',V.f);
	Writeln();
	Writeln('T.k = ',T.k,', T.u = ',T.u,' T.f = ',T.f);
	Writeln();
end.
