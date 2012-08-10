-module(precisao).
-export([main/0]).

precisao(1.0, P) -> P;
precisao(S, _) -> precisao((S + 1) / 2, S - 1).

main() ->
    P = precisao(2,0),
    D = abs(trunc(math:log10(P))),
    N = trunc(abs(math:log(P)/math:log(2))),
    io:fwrite("Precisao: ~g~n", [P]),
    io:fwrite("Num. digitos significativos decimais: ~b~n", [D]),
    io:fwrite("Num. bits da mantissa: ~b~n", [N]).

