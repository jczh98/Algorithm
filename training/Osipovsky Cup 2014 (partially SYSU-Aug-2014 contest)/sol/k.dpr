program Vedic;
uses
  SysUtils;

var
  T: array [1..9, 1..9] of Integer;
  V: array [0..9] of Integer;
  Found: Boolean;

procedure ReadData;
var
  I, J: Integer;
begin
  for I := 1 to 9 do
  begin
    for J := 1 to 9 do
      Read(T[I, J]);
    Readln;
  end;
end;

function GoDepth(I: Integer): Boolean;
var
  K, J: Integer;
  Ok: Boolean;
begin
  Result := I > 9;
  K := 1;
  while (K <= 9) and (not Result) do
  begin
    {ќтсекаем по квадратам - это сразу сокращает пребор - вместо 9 знаков придетс€
     перебрать 3 (корни 3,6,9) или 2 (остальные корни)}
    if ((K * K) mod 9) = T[I, I] then
    begin
      J := 1;
      Ok := TRUE;
      for J := 1 to I - 1 do
        if ((K * V[J]) mod 9) <> T[I, J] then
        begin
          Ok := FALSE;
          break;
        end;
      if Ok then
      begin
        V[I] := K;
        Result := GoDepth(I + 1);
      end;  
    end;
    Inc(K);
  end;
end;

procedure Solve;
var
  I, J: Integer;
begin
  for I := 1 to 9 do
    for J := 1 to 9 do
      T[I, J] := T[I, J] mod 9;
  Found := FALSE;
  for I := 1 to 9 do
    for J := 1 to I - 1 do
      if T[I, J] <> T[J, I] then
        exit;    
  Found := GoDepth(1);
end;

procedure WriteResult;
var
  I: Integer;
begin
  if not Found then
  begin
    Writeln('No solution');
    exit;
  end;
  // ѕриводим последовательность к неубывающему виду
  V[0] := 0;
  for I := 1 to 9 do
    while V[I] <= V[I - 1] do
      V[I] := V[I] + 9;
  for I := 1 to 8 do
    Write(V[I], ' ');
  Writeln(V[9]);
end;

begin
  ReadData;
  Solve;
  WriteResult;
  Close(Output);
  Close(Input);
end.
