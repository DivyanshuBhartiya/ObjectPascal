program sort;

type T = array [1..10] of integer;
var A: T; k: integer;

procedure Quicksort(m, n: integer);
  var i,j: integer;

  procedure Partition;
    var r, w: integer;
    begin
    r:=A[(m+n) div 2];
    i:=m; j:=n;
    while i<=j do
      begin
      while A[i]<r do i:=i+1;
      while r<A[j] do j:=j-1;
      if i<=j then
        begin
        w:=A[i]; A[i]:=A[j]; A[j]:=w;
        i:=i+1; j:=j-1;
        end;
      end;
    end;

  begin
  if m<n then begin Partition; Quicksort(m, j); Quicksort(i, n) end;
  end;

begin
k:=1;
Writeln('\n Welcome to QuickSort \n');
while k<=10 do 
begin 
	Write('Enter num ',k,': '); 
	Read(A[k]); 
	k:=k+1 
end;
Quicksort(1, 10);
k:=1;
Writeln('\n After QuickSort \n');
while k<=10 do begin Writeln(A[k]); k:=k+1 end;
end.
