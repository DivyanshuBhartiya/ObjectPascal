Program pascalObject; 
type 
 Ops = object
 parameter : integer;
 function Factorial(a:integer): integer;
 function Fibonacci(a:integer): integer;
 End;

function Ops.Factorial(a:integer):integer;
begin
	if(a=1) then
		Result := 1
	else
		Result := a *  Ops.Factorial(a-1);
End;

function Ops.Fibonacci(a:integer):integer;
begin
	if(a<=1) then
		Result := 1
	else
		Result :=  Ops.Fibonacci(a-1) +  Ops.Fibonacci(a-2);
End;

 type
 MoreOps= object(Ops) (*inherits Ops object*)
 function gcd(a,b:integer): integer;
 End;

function MoreOps.gcd(a,b:integer): integer;
begin
	if (a=0) then  Result := b
	else if(b=0) then  Result := a
	else if(a<b) then  Result := MoreOps.gcd(a, b-a)
	else Result := MoreOps.gcd(a-b,b);
		
End;

var
 x,y,res : integer;
 obj1 : Ops;
 obj2 : MoreOps;
begin

x := 6;
y := 4;

res := obj1.Factorial(x);
Writeln();
Writeln();
Writeln('Factorial(',x,') = ',res);
Writeln();


res := obj2.Fibonacci(x);
Writeln('Fibonacci(',x,') = ',res);
Writeln();


res := obj2.gcd(x,y);
Writeln('gcd(',x,',',y,') = ',res);
Writeln();

obj1.parameter := 1;
obj2.parameter := 2;
Writeln('Obj1.param = ',obj1.parameter,' and Obj2.param = ',obj2.parameter);
Writeln();


End.
 

