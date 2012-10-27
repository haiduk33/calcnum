-module(tabela).
-export([main/0]).
-import(math, [pi/0, exp/1, sin/1, cos/1, tan/1]).
-import(lists, [seq/2, nth/2, append/2, map/2, foldl/3]).

myfold(F, I, N) -> {_, R} = foldl(fun(T, {Z, A}) -> {Z * F(T), A + Z} end, {I, 0}, seq(1, N)), R.

mysin(X, N) -> myfold(fun(K) -> -X * X / (2 * K) / (2 * K + 1) end, X, N).
mycos(X, N) -> myfold(fun(K) -> -X * X / (2 * K) / (2 * K - 1) end, 1, N).
mytan(X, N) -> mysin(X, N) / mycos(X, N).
mypi(N)     -> myfold(fun(K) -> -(2 * K - 1) / (2 * K + 1) end, 4, N).
mye(N)      -> myfold(fun(K) -> 1 / K end, 1, N).

tabela(N) ->
    PIE = pi() /exp(1),
    MYPIE = mypi(N) / mye(N),
    map(fun(ROW) ->
            Ve = nth(2, ROW),
            Va = nth(3, ROW),
            append(ROW, [Va - Ve, 1 - Ve / Va]) end,
    [["pi",        pi(),     mypi(N)        ],
     ["e",         exp(1),   mye(N)         ],
     ["pi/e",      PIE,      MYPIE          ],
     ["sin(pi/e)", sin(PIE), mysin(MYPIE, N)],
     ["cos(pi/e)", cos(PIE), mycos(MYPIE, N)],
     ["tg(pi/e)",  tan(PIE), mytan(MYPIE, N)]]).

main() ->
    map(fun(N) -> pprint:ptable([[N, "Ve", "Va", "Eabs", "Erel"]|tabela(N)]) end,
        [3, 10, 30, 84, 10000]).


