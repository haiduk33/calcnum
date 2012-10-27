require "./newtonbairstow"

include Calcnum

@tol = 1e-10
@nmi = 100
@tabelar = true

aplicar :newtonbairstow, [1, 3, 3, 1]
aplicar :newtonbairstow, [1, 4, 6, 4, 1]
aplicar :newtonbairstow, [1, 5, 10, 10, 5, 1]

