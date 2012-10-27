-module(magnitude).
-export([main/0]).

magnitude(0.0, Z) -> Z;
magnitude(Z, _) -> magnitude(Z / 2, Z).

main() ->
    M = magnitude(1,0),
    N = trunc(math:log(abs(math:log(M)/math:log(2)) + 1) / math:log(2)),
    io:fwrite("~ts: ~g~n", [<<"Magnitude">>, M]),
    io:fwrite("~ts: ~b~n", [<<"Número de bits do expoente">>, N]).

