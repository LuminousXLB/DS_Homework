var
  a: array[1..maxn, 1..maxn] of Integer;
  b, pre: array[1..maxn] of Integer; {pre[i]指最短路径上I的前驱结点}
  mark: array[1..maxn] of Boolean;

procedure dijkstra(v0: Integer);
begin
  FillChar(mark, SizeOf(mark), false);
  for i := 1 to n do
  begin
    d[i] := a[v0, i];
    if d[i] <> 0 then
      pre[i] := v0
    else
      pre[i] := 0;
  end;
  mark[v0] := true;
  repeat {每循环一次加入一个离1集合最近的结点并调整其他结点的参数}
    Min := MaxInt;
    u   := 0; {u记录离1集合最近的结点}
    for i := 1 to n do
      if (not mark[i]) and (d[i] < Min) then
      begin
        u := i;
        Min := d[i];
      end;
    if u <> 0 then
    begin
      mark[u] := true;
      for i := 1 to n do
        if (not mark[i]) and (a[u, i] + d[u] < d[i]) then
        begin
          d[i] := a[u, i] + d[u];
          pre[i] := u;
        end;
    end;
  until u = 0;
end.
