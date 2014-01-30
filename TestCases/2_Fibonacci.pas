Program recur;
var 
	value,temp,p : integer;

function Fib(n : integer) : integer;
	function TakeVal(k : integer) : integer;
	begin
		Result:= k + 2;
	end;
begin
	if (n<=1) then
		Result:= temp + TakeVal(-4)
	else
		Result:= Fib(n-2) +  Fib(n-1);
end;


begin
	temp:=3;
	for p:=1 to 10
	do
	begin
		value := Fib(p);
		if(p>3) then
			Writeln(p,'th Fibonacci number :',value)
		else if(p=3) then
			Writeln(p,'rd Fibonacci number :',value)
		else if (p=2) then
			Writeln(p,'nd Fibonacci number :',value)
		else
			Writeln(p,'st Fibonacci number :',value);
	end;

end.
