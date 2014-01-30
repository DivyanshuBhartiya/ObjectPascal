program Project1;
var
	TaxRate: integer;
	Price,ItemPrice : real;
begin
	ItemPrice := 5.0;
	TaxRate := 10;
	Price := (ItemPrice + TaxRate)/2;
	Writeln();
	Writeln('Price :',Price);
	Writeln();
end.
